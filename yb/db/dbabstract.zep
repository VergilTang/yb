namespace Yb\Db;

use Yb\Std;

abstract class DbAbstract
{
    protected static nextFlag = 1;

    protected inTransaction = false;
    protected savepoints;
    protected queries;

    public static function nextFlag(string pre = "") -> string
    {
        long flag;

        let flag = (long) self::nextFlag;
        let self::nextFlag = flag + 1;

        return sprintf("%s%d", pre, flag);
    }

    abstract public function getInternalHandler();

    abstract public function quote(string value) -> string;

    abstract public function query(string sql, array params = null) -> void;
    abstract public function queryAll(string sql, array params = null) -> array;
    abstract public function queryRow(string sql, array params = null);
    abstract public function queryCell(string sql, array params = null) -> string;
    abstract public function queryColumns(string sql, array params = null) -> array;

    public function inTransaction() -> bool
    {
        return this->inTransaction;
    }

    public function begin() -> void
    {
        if unlikely !! this->inTransaction {
            throw new TransactionException("Cannot begin when already in transaction");
        }

        if unlikely ! this->tryToBegin() {
            throw new TransactionException("Cannot begin transaction");
        }

        let this->inTransaction = true;
    }

    public function commit() -> void
    {
        if unlikely ! this->inTransaction {
            throw new TransactionException("Cannot commit when not in transaction");
        }

        if unlikely ! this->tryToCommit() {
            throw new TransactionException("Cannot commit transaction");
        }

        let this->inTransaction = false;
    }

    public function rollback() -> void
    {
        if unlikely ! this->inTransaction {
            throw new TransactionException("Cannot rollback when not in transaction");
        }

        if unlikely ! this->tryToRollback() {
            throw new TransactionException("Cannot rollback transaction");
        }

        let this->inTransaction = false;
    }

    public function savepoint(string savepoint = "") -> string
    {
        if unlikely ! this->inTransaction {
            throw new TransactionException("Cannot acquire a savepoint when not in a transaction");
        }

        if savepoint->length() < 1 {
            let savepoint = (string) self::nextFlag("s");
        }

        if unlikely isset this->savepoints[savepoint] {
            throw new TransactionException("Duplicate savepoint: " . savepoint);
        }

        this->query("SAVEPOINT " . savepoint);

        let this->savepoints[savepoint] = savepoint;
        return savepoint;
    }

    public function releaseSavepoint(string savepoint) -> void
    {
        if unlikely ! this->inTransaction {
            throw new TransactionException("Cannot release a savepoint when not in a transaction");
        }

        if unlikely ! isset this->savepoints[savepoint] {
            throw new TransactionException("Cannot find savepoint: " . savepoint);
        }

        this->query("RELEASE SAVEPOINT " . savepoint);
        unset(this->savepoints[savepoint]);
    }

    public function releaseLastSavepoint() -> void
    {
        string savepoint;

        if unlikely ! this->inTransaction {
            throw new TransactionException("Cannot release last savepoint when not in a transaction");
        }

        if unlikely ! this->savepoints {
            throw new TransactionException("Empty savepoint stack");
        }

        let savepoint = (string) end(this->savepoints);

        this->query("RELEASE SAVEPOINT " . savepoint);
        unset(this->savepoints[savepoint]);
    }

    public function rollbackToSavepoint(string savepoint) -> void
    {
        if unlikely ! this->inTransaction {
            throw new TransactionException("Cannot rollback to a savepoint when not in a transaction");
        }

        if unlikely ! isset this->savepoints[savepoint] {
            throw new TransactionException("Cannot find savepoint: " . savepoint);
        }

        this->query("ROLLBACK TO SAVEPOINT " . savepoint);

        loop {
            if (string) array_pop(this->savepoints) === savepoint {
                let this->savepoints[savepoint] = savepoint;
                break;
            }
        }
    }

    public function rollbackToLastSavepoint() -> void
    {
        string savepoint;

        if unlikely ! this->inTransaction {
            throw new TransactionException("Cannot rollback to last savepoint when not in a transaction");
        }

        if unlikely ! this->savepoints {
            throw new TransactionException("Empty savepoint stack");
        }

        let savepoint = (string) end(this->savepoints);

        this->query("ROLLBACK TO SAVEPOINT " . savepoint);
    }

    public function getQueries() -> array
    {
        if this->queries {
            return this->queries;
        }

        return [];
    }

    public function insert(string table, array data, string returningId = "")
    {
        var k, ks = [], vs = [];
        string sql;

        for k in array_keys(data) {
            let ks[] = k;
            let vs[] = ":" . k;
        }

        let sql = "INSERT INTO " . table . " (" . join(", ", ks) . ") VALUES (" . join(", ", vs) . ")";

        if returningId->length() > 0 {
            let sql .= " RETURNING " . returningId;
            return this->queryCell(sql, data);
        }

        this->query(sql, data);
    }

    public function delete(string table, array where = []) -> void
    {
        string s, w;

        let s = "DELETE FROM " . table;
        let w = (string) this->parseWhere(where);
        if w->length() > 0 {
            let s .= " WHERE " . w;
        }

        this->query(s);
    }

    public function update(string table, array data, array where = []) -> void
    {
        var k, v, kvs = [], params = [];
        string s, w;

        for k, v in data {
            let kvs[k] = k . " = :" . k;
            let params[k] = v;
        }

        let s = "UPDATE " . table . " SET " . join(", ", kvs);
        let w = (string) this->parseWhere(where);
        if w->length() > 0 {
            let s .= " WHERE " . w;
        }

        this->query(s, params);
    }

    public function upsert(string table, array data, var primaryKey) -> void
    {
        var k, v, where = [];

        if typeof primaryKey == "array" {
            for k in primaryKey {
                if unlikely ! fetch v, data[k] {
                    throw new Exception("Cannot find primary key value in data: " . k);
                }
                let where[k] = v;
            }
            if unlikely ! where {
                throw new Exception("Cannot upsert with empty where");
            }
        } else {
            let k = (string) primaryKey;
            if unlikely ! fetch v, data[k] {
                throw new Exception("Cannot find primary key value in data: " . k);
            }
            let where[k] = v;
        }

        this->delete(table, where);
        this->insert(table, data);
    }

    public function parseSelect(string table, array options = []) -> string
    {
        string field, w;
        var where, orderBy;
        long limit, offset;
        bool forUpdate;

        string s = "SELECT ";

        let field = (string) Std::valueAt(options, "field", "*");
        let where = (array) Std::valueAt(options, "where", []);
        let orderBy = Std::valueAt(options, "orderBy", "");
        let limit = (long) Std::valueAt(options, "limit", 0);
        let offset = (long) Std::valueAt(options, "offset", 0);
        let forUpdate = (bool) Std::valueAt(options, "forUpdate", false);

        if field {
            let s .= field;
        } else {
            let s .= "*";
        }

        let s .= " FROM " . table;

        let w = (string) this->parseWhere(where);
        if w->length() > 0 {
            let s .= " WHERE " . w;
        }

        if orderBy {
            if orderBy === true {
                let s .= " ORDER BY " . (string) this->randomOrder();
                let offset = 0;
            } else {
                let s .= " ORDER BY " . (string) orderBy;
            }
        }

        if limit > 0 {
            let s = (string) this->paginateQuery(s, limit, offset);
        }

        if forUpdate {
            let s .= " FOR UPDATE";
        }

        return s;
    }

    public function selectAll(string table, array options = []) -> array
    {
        string s;

        let s = (string) this->parseSelect(table, options);
        return this->queryAll(s);
    }

    public function selectRow(string table, array options = []) -> array
    {
        string s;

        let s = (string) this->parseSelect(table, options);
        return this->queryRow(s);
    }

    public function selectCell(string table, array options = []) -> array
    {
        string s;

        let s = (string) this->parseSelect(table, options);
        return this->queryCell(s);
    }

    public function selectColumns(string table, array options = []) -> array
    {
        string s;

        let s = (string) this->parseSelect(table, options);
        return this->queryColumns(s);
    }

    public function countAndSelect(string table, array options = []) -> array
    {
        var where;
        long c;
        string s, w;

        let where = (array) Std::valueAt(options, "where", []);

        let s = "SELECT COUNT(*) FROM " . table;
        let w = (string) this->parseWhere(where);
        if w->length() > 0 {
            let s .= " WHERE " . w;
        }

        let c = (long) this->queryCell(s);
        if c < 1 {
            return [0, []];
        }

        return [
            c,
            this->selectAll(table, options)
        ];
    }

    public function parseUnionAll(array selects, var orderBy = null, long limit = 0, long offset = 0) -> string
    {
        var i, a = [];
        string s;

        if unlikely count(selects) < 1 {
            return "";
        }

        for i in selects {
            let a[] = "(" . i . ")";
        }

        let s = "SELECT * FROM (" . (string) join(" UNION ALL ", a) . ") AS " . (string) self::nextFlag("u");

        if orderBy {
            if orderBy === true {
                let s .= " ORDER BY " . (string) this->randomOrder();
                let offset = 0;
            } else {
                let s .= " ORDER BY " . (string) orderBy;
            }
        }

        if limit < 1 {
            return s;
        }

        return this->paginateQuery(s, limit, offset);
    }

    public function queryUnionAll(array selects, var orderBy = null, long limit = 0, long offset = 0) -> array
    {
        string s;

        let s = (string) this->parseUnionAll(selects, orderBy, limit, offset);
        return this->queryAll(s);
    }

    public function countAndQueryUnionAll(array selects, var orderBy = null, long limit = 0, long offset = 0) -> array
    {
        long c;
        string s;
        var i, a = [];

        if unlikely count(selects) < 1 {
            return [0, []];
        }

        for i in selects {
            let a[] = "(" . i . ")";
        }

        let s = "SELECT COUNT(*) FROM (" . (string) join(" UNION ALL ", a) . ") AS " . (string) self::nextFlag("u");
        let c = (long) this->queryCell(s);

        if c < 1 {
            return [0, []];
        }

        return [
            c,
            this->queryUnionAll(selects, orderBy, limit, offset)
        ];
    }

    public function parseAggregation(string table, array aggregations, array where = []) -> string
    {
        var k, v, a = [];
        string s, w;

        for k, v in aggregations {
            let a[] = v . " AS " . k;
        }

        let s = "SELECT " . join(", ", a) . " FROM " .table;

        let w = (string) this->parseWhere(where);
        if w->length() > 0 {
            let s .= " WHERE " . w;
        }

        return s;
    }

    public function queryAggregation(string table, array aggregations, array where = []) -> array
    {
        string s;

        let s = (string) this->parseAggregation(table, aggregations, where);
        return this->queryRow(s);
    }

    public function aggregate(string table, string column, string aggregation, array where = [])
    {
        string s, w;

        let s = "SELECT " . aggregation . "(" . column . ") FROM " .  table;

        let w = (string) this->parseWhere(where);
        if w->length() > 0 {
            let s .= " WHERE " . w;
        }

        return this->queryCell(s);
    }

    public function count(string table, string column = "*", array where = []) -> long
    {
        return (long) this->aggregate(table, column, "COUNT", where);
    }

    public function max(string table, string column, array where = [])
    {
        return this->aggregate(table, column, "MAX", where);
    }

    public function min(string table, string column, array where = [])
    {
        return this->aggregate(table, column, "MIN", where);
    }

    public function sum(string table, string column, array where = [])
    {
        return this->aggregate(table, column, "SUM", where);
    }

    public function parseGroupedAggregation(string table, string groupBy, array aggrs, array options = []) -> string
    {
        var where, having;
        var orderBy;
        var k, v, a = [];
        string s, w;

        let where = (array) Std::valueAt(options, "where", []);
        let having = (array) Std::valueAt(options, "having", []);
        let orderBy = Std::valueAt(options, "orderBy", "");

        let a[] = groupBy;

        for k, v in aggrs {
            let a[] = v . "(" . groupBy . ") AS " . k;
        }

        let s = "SELECT " . join(", ", a) . " FROM " .table;

        let w = (string) this->parseWhere(where);
        if w->length() > 0 {
            let s .= " WHERE " . w;
        }

        let s .= " GROUP BY " . groupBy;

        let w = (string) this->parseWhere(having);
        if w->length() > 0 {
            let s .= " HAVING " . w;
        }

        if orderBy {
            if orderBy === true {
                let s .= " ORDER BY " . (string) this->randomOrder();
            } else {
                let s .= " ORDER BY " . (string) orderBy;
            }
        }

        return s;
    }

    public function queryGroupedAggregation(string table, string groupBy, array aggrs, array options = []) -> array
    {
        string s;

        let s = (string) this->parseGroupedAggregation(table, groupBy, aggrs, options);
        return this->queryAll(s);
    }

    public function parseWhere(array where, string sep = " AND ") -> string
    {
        var k, v, ks, ws = [];
        string k1, k2, tmp;

        for k, v in where {
            let ks = explode("$", k);
            let k1 = (string) array_shift(ks);
            let k2 = (string) array_shift(ks);
            let tmp = "";

            switch k2 {
                case "":
                    if v === null {
                        let ws[] = k1 . " IS NULL";
                    } else {
                        let ws[] = k1 . " = " . this->quote(v);
                    }
                    break;
                case "neq":
                    if v === null {
                        let ws[] = k1 . "IS NOT NULL";
                    } else {
                        let ws[] = k1 . " <> " . this->quote(v);
                    }
                    break;
                case "lt":
                    let ws[] = k1 . " < " . this->quote(v);
                    break;
                case "lte":
                    let ws[] = k1 . " <= " . this->quote(v);
                    break;
                case "gt":
                    let ws[] = k1 . " > " . this->quote(v);
                    break;
                case "gte":
                    let ws[] = k1 . " >= " . this->quote(v);
                    break;
                case "notBetween":
                    let tmp = " NOT";
                case "between":
                    if unlikely typeof v != "array" || ! isset v[0] || ! isset v[1] {
                        throw new Exception("Invalid between");
                    }
                    let ws[] = k1 . tmp . " BETWEEN " . this->quote(v[0]) . " AND " . this->quote(v[1]);
                    break;
                case "notLike":
                    let tmp = " NOT";
                case "like":
                    let ws[] = k1 . tmp . " LIKE " . this->quote(v);
                    break;
                case "notIn":
                    let tmp = " NOT";
                case "in":
                    if unlikely typeof v != "array" || count(v) < 1 {
                        throw new Exception("Invalid in");
                    }
                    if strpos(k1, ",") === false {
                        let ws[] = k1 . tmp . " IN (" . implode(", ", array_map([this, "quote"], v)) . ")";
                    } else {
                        let ws[] = this->parseWhereMultipleIn(k1, v, tmp);
                    }
                    break;
                case "notInSelect":
                    let tmp = " NOT";
                case "inSelect":
                    if strpos(k1, ",") !== false {
                        let k1 = "(" . k1 . ")";
                    }
                    let ws[] = k1 . tmp . " IN (" . v . ")";
                    break;

                case "raw":
                    let ws[] = "(" . v . ")";
                    break;
                case "expression":
                    if unlikely typeof v != "array" || count(v) < 1 {
                        throw new Exception("Invalid expression");
                    }

                    let tmp = (string) str_replace(["%", "?"], ["%%", "%s"], (string) array_shift(v));
                    if unlikely tmp->length() > 0 {
                        let ws[] = "(" . vsprintf(tmp, array_map([this, "quote"], v)) . ")";
                    }
                    break;

                case "and":
                    if unlikely typeof v != "array" || count(v) < 1 {
                        throw new Exception("Invalid and");
                    }
                    let ws[] = "(" . this->parseWhere(v, " AND ") . ")";
                    break;
                case "or":
                    if unlikely typeof v != "array" || count(v) < 1 {
                        throw new Exception("Invalid or");
                    }
                    let ws[] = "(" . this->parseWhere(v, " OR ") . ")";
                    break;
                case "xor":
                    if unlikely typeof v != "array" || count(v) < 1 {
                        throw new Exception("Invalid xor");
                    }
                    let ws[] = "(" . this->parseWhere(v, " XOR ") . ")";
                    break;

                default:
                    throw new Exception("Invalid k2: " . k2);
            }
        }

        return implode(sep, ws);
    }

    public function parseWhereMultipleIn(string columns, array values, string isNot = "") -> array
    {
        long c;
        var k, v, vs = [], quoter;

        let c = 1 + (long) substr_count(columns, ",");
        if unlikely c < 2 {
            throw new Exception("Invalid multiple in columns: " . columns);
        }

        let quoter = [this, "quote"];

        for k, v in values {
            if unlikely typeof v != "array" || count(v) != 2 {
                throw new Exception("Invalid multiple in value at: " . k);
            }
            let vs[] = "(" . implode(", ", array_map(quoter, v)) . ")";
        }

        return "(" . columns . ")" . isNot . " in (" . implode(", ", vs) . ")";
    }

    abstract protected function tryToBegin() -> bool;
    abstract protected function tryToCommit() -> bool;
    abstract protected function tryToRollback() -> bool;

    abstract protected function paginateQuery(string query, long limit, long offset) -> string;
    abstract protected function randomOrder() -> string;

    protected function addQuery(string q, array p, double t) -> void
    {
        if count(p) > 0 {
            let this->queries[] = sprintf("%s # %0.3fms %s", q, t * 1000.0, json_encode(p));
        } else {
            let this->queries[] = sprintf("%s # %0.3fms", q, t * 1000.0);
        }
    }

}

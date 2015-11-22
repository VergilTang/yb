namespace Yb\Db;

class Oci8 extends DbAbstract
{
    protected oci;
    protected lastStatement;

    public function __construct(string dsn, string user, string passwd) -> void
    {
        var oci;

        if unlikely ! extension_loaded("oci8") {
            throw new Exception("Missing extension: oci8");
        }

        let oci = oci_connect(user, passwd, dsn, "utf8");
        if unlikely ! oci {
            throw new Exception("Cannot connect: " . dsn);
        }

        let this->oci = oci;
    }

    public function getInternalHandler()
    {
        return this->oci;
    }

    public function quote(string value) -> string
    {
        return "'" . str_replace("'", "''", value) . "'";
    }

    public function query(string sql, array params = null) -> void
    {
        var s, k, v, m, e, eMessage;
        double t;
        bool r;

        let t = (double) microtime(true);

        let s = oci_parse(this->oci, sql);
        let this->lastStatement = s;

        if count(params) > 0 {
            for k, v in params {
                oci_bind_by_name(s, ":" . k, v);
            }
        }

        if this->inTransaction {
            let m = OCI_NO_AUTO_COMMIT;
        } else {
            let m = OCI_COMMIT_ON_SUCCESS;
        }

        let r = (bool) oci_execute(s, m);
        this->addQuery(sql, params, (double) microtime(true) - t);

        if unlikely ! r {
            let e = oci_error(this->oci);
            if typeof e != "array" || ! fetch eMessage, e["message"] {
                let eMessage = "Unknown Error";
            }
            throw new QueryException(eMessage . " [SQL] " . sql);
        }
    }

    public function queryAll(string sql, array params = null) -> array
    {
        var m, d = [], r;

        this->query(sql, params);

        let m = OCI_RETURN_NULLS + OCI_RETURN_LOBS + OCI_ASSOC;
        loop {
            let r = oci_fetch_array(this->lastStatement, m);
            if ! r {
                break;
            }
            let d[] = array_change_key_case(r);
        }

        return d;
    }

    public function queryRow(string sql, array params = null)
    {
        var r;

        this->query(sql, params);

        let r = oci_fetch_array(this->lastStatement, OCI_RETURN_NULLS + OCI_RETURN_LOBS + OCI_ASSOC);
        if r {
            return array_change_key_case(r);
        }
    }

    public function queryCell(string sql, array params = null) -> string
    {
        var r, i;

        this->query(sql, params);

        let r = oci_fetch_array(this->lastStatement, OCI_RETURN_NULLS + OCI_RETURN_LOBS + OCI_NUM);
        if r && typeof r == "array" && fetch i, r[0] {
            return i;
        }

        return "";
    }

    public function queryColumns(string sql, array params = null) -> array
    {
        var m, d = [], r, i;

        this->query(sql, params);

        let m = OCI_RETURN_NULLS + OCI_RETURN_LOBS + OCI_NUM;
        loop {
            let r = oci_fetch_array(this->lastStatement, m);
            if ! r || typeof r != "array" || ! fetch i, r[0] {
                break;
            }
            let d[] = i;
        }

        return d;
    }

    protected function tryToBegin() -> bool
    {
        return true;
    }

    protected function tryToCommit() -> bool
    {
        return oci_commit(this->oci);
    }

    protected function tryToRollback() -> bool
    {
        return oci_rollback(this->oci);
    }

    protected function paginateQuery(string query, long limit, long offset) -> string
    {
        string s, t1, t2, r3;

        let t1 = (string) self::nextFlag("t");
        let s = (string) sprintf("SELECT %s.* FROM (%s) %s WHERE rownum <= %d", t1, query, t1, limit);

        if offset == 0 {
            return s;
        }

        let t2 = (string) self::nextFlag("t");
        let r3 = (string) self::nextFlag("r");

        return sprintf(
            "SELECT * FROM (SELECT %s.*, rownum %s FROM (%s) %s WHERE rownum <= %d) %s WHERE %s > %d",
            t1,
            r3,
            query,
            t1,
            limit,
            t2,
            r3,
            offset
        );
    }

    protected function randomOrder() -> string
    {
        return "dbms_random.value()";
    }

}

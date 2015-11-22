namespace Yb\Db;

class PdoMysql extends PdoAbstract
{
    public function insert(string table, array data, string returningId = "", bool upsert = false)
    {
        var k, v, ks = [], vs = [];
        string s;

        for k in array_keys(data) {
            let ks[] = k;
            let vs[] = ":" . k;
        }

        if upsert {
            let s = "REPLACE";
        } else {
            let s = "INSERT";
        }

        let s .= " INTO " . table . " (" . join(", ", ks) . ") VALUES (" . join(", ", vs) . ")";
        this->query(s, data);

        if returningId->length() < 1 {
            return;
        }

        if fetch v, data[returningId] {
            return v;
        }

        return this->queryCell("SELECT LAST_INSERT_ID()");
    }

    public function upsert(string table, array data, var primaryKey) -> void
    {
        var k;

        if typeof primaryKey == "array" {
            if unlikely ! primaryKey {
                throw new Exception("Cannot upsert with empty where");
            }
            for k in primaryKey {
                if unlikely ! isset data[k] {
                    throw new Exception("Cannot find primary key value in data: " . k);
                }
            }
        } else {
            let k = (string) primaryKey;
            if unlikely ! isset data[k] {
                throw new Exception("Cannot find primary key value in data: " . k);
            }
        }

        this->insert(table, data, "", true);
    }

    public function countAndSelect(string table, array options = []) -> array
    {
        string s;
        var d;

        let s = (string) this->parseSelect(table, options);
        let s = (string) preg_replace("/^SELECT /i", "SELECT SQL_CALC_FOUND_ROWS ", s);

        let d = this->queryAll(s);

        return [
            this->queryCell("SELECT FOUND_ROWS()"),
            d
        ];
    }

    protected function paginateQuery(string query, long limit, long offset) -> string
    {
        if offset == 0 {
            return sprintf("%s LIMIT %d", query, limit);
        }

        return sprintf("%s LIMIT %d, %d", query, offset, limit);
    }

    protected function randomOrder() -> string
    {
        return "RAND()";
    }

}

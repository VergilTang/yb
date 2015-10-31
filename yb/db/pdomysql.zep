namespace Yb\Db;

class PdoMysql extends PdoAbstract
{
    public function insert(string table, array data, string returningId = "")
    {
        var k, v, ks = [], vs = [];
        string s;

        for k in array_keys(data) {
            let ks[] = k;
            let vs[] = ":" . k;
        }

        let s = "INSERT INTO " . table . " (" . join(", ", ks) . ") VALUES (" . join(", ", vs) . ")";
        this->query(s, data);

        if returningId->length() < 1 {
            return;
        }

        if fetch v, data[returningId] {
            return v;
        }

        return this->queryCell("SELECT LAST_INSERT_ID()");
    }

    public function countAndSelect(array options) -> array
    {
        string s;
        var d;

        let s = (string) this->parseSelect(options);
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

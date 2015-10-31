namespace Yb\Db;

class PdoPgsql extends PdoAbstract
{
    protected function paginateQuery(string query, long limit, long offset) -> string
    {
        if offset == 0 {
            return sprintf("%s LIMIT %d", query, limit);
        }

        return sprintf("%s LIMIT %d OFFSET %d", query, limit, offset);
    }

    protected function randomOrder() -> string
    {
        return "RANDOM()";
    }

}

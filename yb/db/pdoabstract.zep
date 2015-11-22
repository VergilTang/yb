namespace Yb\Db;

abstract class PdoAbstract extends DbAbstract
{
    protected pdo;
    protected lastStatement;

    public function __construct() -> void
    {
        if unlikely ! extension_loaded("pdo") {
            throw new Exception("Missing extension: pdo");
        }

        let this->pdo = (new \ReflectionClass("PDO"))->newInstanceArgs(func_get_args());
    }

    public function getInternalHandler()
    {
        return this->pdo;
    }

    public function quote(string value) -> string
    {
        return this->pdo->quote(value);
    }

    public function query(string sql, array params = null) -> void
    {
        var s, k, v, e;
        double t;
        bool r;

        let t = (double) microtime(true);

        let s = this->pdo->prepare(sql);
        let this->lastStatement = s;

        if count(params) > 0 {
            for k, v in params {
                if typeof v == "string" {
                    s->bindParam(":" . k, "" . v, \Pdo::PARAM_STR, strlen(v));
                } else {
                    s->bindValue(":" . k, v);
                }
            }
        }

        let r = (bool) s->execute();
        this->addQuery(sql, params, (double) microtime(true) - t);

        if unlikely ! r {
            let e = s->errorInfo();
            throw new QueryException(e[2] . " [SQL] " . sql);
        }
    }

    public function queryAll(string sql, array params = null) -> array
    {
        this->query(sql, params);
        return this->lastStatement->fetchAll(\Pdo::FETCH_ASSOC);
    }

    public function queryRow(string sql, array params = null)
    {
        var r;

        this->query(sql, params);

        let r = this->lastStatement->$fetch(\Pdo::FETCH_ASSOC);
        if r {
            return r;
        }
    }

    public function queryCell(string sql, array params = null) -> string
    {
        this->query(sql, params);
        return this->lastStatement->fetchColumn();
    }

    public function queryColumns(string sql, array params = null) -> array
    {
        var d = [], i;

        this->query(sql, params);

        loop {
            let i = this->lastStatement->fetchColumn();
            if i === false || typeof i != "string" {
                break;
            }
            let d[] = i;
        }

        return d;
    }

    protected function tryToBegin() -> bool
    {
        return this->pdo->beginTransaction();
    }

    protected function tryToCommit() -> bool
    {
        return this->pdo->commit();
    }

    protected function tryToRollback() -> bool
    {
        return this->pdo->rollback();
    }

}

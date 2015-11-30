namespace Yb\Db;

class Model
{
    protected db;
    protected table;
    protected primaryKey;
    protected autoIncrement;

    public function __construct(<DbAbstract> db, string table, var primaryKey, string autoIncrement) -> void
    {
        let this->db = db;
        let this->table = table;
        let this->primaryKey = primaryKey;
        let this->autoIncrement = autoIncrement;
    }

    public function setDb(<DbAbstract> db) -> void
    {
        let this->db = db;
    }

    public function getDb() -> <DbAbstract>
    {
        return this->db;
    }

    public function insert(array row) -> array
    {
        var r;
        string autoIncrement, autoIncrementValue;

        let r = this->onStore(row);
        let autoIncrement = (string) this->autoIncrement;

        if autoIncrement->length() > 0 && ! isset r[autoIncrement] {
            let autoIncrementValue = (string) this->db->insert(this->table, r, autoIncrement);
            let r[autoIncrement] = autoIncrementValue;
        } else {
            this->db->insert(this->table, r);
        }

        // cache drop

        return r;
    }

    public function update(array updates, array where = []) -> array
    {
        var r;

        let r = this->onStore(updates, true, where);
        if count(r) > 0 {
            this->db->update(this->table, r, where);
        }

        // cache drop

        return r;
    }

    public function delete(array where = []) -> void
    {
        // cache write

        this->db->delete(this->table, where);
    }

    public function newEntity(array row = [], boolean isNew = true, <Collection> collection = null) -> <Entity>
    {
        var entity;

        let entity = new Entity(this, row, isNew);
        if collection {
            entity->setCollection(collection);
        }

        return entity;
    }

    public function create(array row) -> <Entity>
    {
        return this->newEntity(this->insert(row), false);
    }

    public function first(array where = [], var orderBy = null) -> <Entity>
    {
        var row;

        let row = this->db->selectRow(this->table, [
            "where": where,
            "orderBy": orderBy,
            "limit": 1
        ]);

        if ! row {
            return;
        }

        return this->newEntity(this->onFetch(row), false);
    }

    public function id(var id) -> <Entity>
    {
        return this->first(this->packPrimaryKeyValue(id));
    }

    public function newCollection(array data) -> <Collection>
    {
        return new Collection(this, data);
    }

    public function all(array where = [], var orderBy = null, long limit = 0, long offset = 0) -> <Collection>
    {
        return this->newCollection(array_map([this, "onFetch"], this->db->select(this->table, [
            "where": where,
            "orderBy": orderBy,
            "limit": limit,
            "offset": offset
        ])));
    }

    public function ids(array ids) -> <Collection>
    {
        return this->all(
            this->db->$in(this->primaryKey, ids)
        );
    }

    public function chunkByDynamicWhere(var processAndReturnNextWhere, var orderBy, long limit = 5000) -> void
    {
        var where = [], collection;
        long c;

        if unlikely limit < 1 {
            throw new Exception("Invalid limit");
        }

        loop {
            let collection = this->all(where, orderBy, limit);

            let c = (long) collection->count();
            if c < 1 {
                break;
            }

            let where = {processAndReturnNextWhere}(collection);
            if typeof where != "array" || c < limit {
                break;
            }
        }
    }

    public function chunkByFixedWhere(var delegate, array where = [], var orderBy = null, long limit = 5000) -> void
    {
        long offset = 0, c;
        var collection;

        if unlikely limit < 1 {
            throw new Exception("Invalid limit");
        }

        loop {
            let collection = this->all(where, orderBy, limit, offset);
            let c = (long) collection->count();

            if c < 1 || {delegate}(collection) === false || c < limit {
                break;
            }

            let offset += limit;
        }
    }

    public function aggregation(array aggregations, array where = []) -> array
    {
        return this->db->queryAggregation(this->table, aggregations, where);
    }

    public function countAll(array where = []) -> long
    {
        return this->count("*", where);
    }

    public function count(string column = "*", array where = []) -> long
    {
        return this->db->count(this->table, column, where);
    }

    public function max(string column, array where = [])
    {
        return this->db->max(this->table, column, where);
    }

    public function min(string column, array where = [])
    {
        return this->db->min(this->table, column, where);
    }

    public function sum(string column, array where = [])
    {
        return this->db->sum(this->table, column, where);
    }

    public function onStore(array row, boolean isUpdate = false, array where = []) -> array
    {
        return row;
    }

    public function onFetch(array row) -> array
    {
        return row;
    }

    public function pickPrimaryKeyValue(array row) -> array
    {
        var pk, k, v, a = [];

        let pk = this->primaryKey;

        if unlikely ! pk {
            throw new Exception("Empty primary key");
        }

        if typeof pk == "array" {
            for k in pk {
                if unlikely ! fetch v, row[k] {
                    throw new Exception("Cannot pick primary key values: " . k);
                }
                let a[k] = v;
            }
        } else {
            let k = (string) pk;
            if unlikely ! fetch v, row[k] {
                throw new Exception("Cannot pick primary key value: " . k);
            }
            let a[k] = v;
        }

        return a;
    }

    public function packPrimaryKeyValue(var id) -> array
    {
        var pk, a;

        let pk = this->primaryKey;

        if unlikely ! pk {
            throw new Exception("Empty primary key");
        }

        if typeof pk == "array" {
            if unlikely typeof id != "array" || count(id) != count(pk) {
                throw new Exception("Invalid id to pack");
            }

            return array_combine(pk, id);
        }

        let a = [];
        let a[(string) pk] = (string) id;

        return a;
    }

}

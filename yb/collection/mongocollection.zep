namespace Yb\Collection;

class MongoCollection implements CollectionInterface
{
    protected mongoCollection;

    public function __construct(var mongoCollection) -> void
    {
        let this->mongoCollection = mongoCollection;
    }

    public function set(string key, var value) -> void
    {
        this->mongoCollection->update([
            "_id": key
        ], [
            "$set": [
                "value": value
            ]
        ], [
            "upsert": true
        ]);
    }

    public function get(string key)
    {
        var row, value;

        let row = this->mongoCollection->findOne([
            "_id": key
        ]);

        if typeof row == "array" && fetch value, row["value"] {
            return value;
        }
    }

    public function delete(string key) -> void
    {
        this->mongoCollection->remove([
            "_id": key
        ]);
    }

    public function setMany(array keyValues) -> void
    {
        var k, v;

        for k, v in keyValues {
            this->set(k, v);
        }
    }

    public function getMany(array keys) -> array
    {
        var rows, row, a = [], k, v;

        if unlikely count(keys) < 1 {
            return a;
        }

        let rows = this->mongoCollection->find([
            "_id": [
                "$in": keys
            ]
        ]);

        for row in iterator_to_array(rows) {
            if fetch k, row["_id"] {
                if fetch v, row["value"] {
                    let a[k] = v;
                }
            }
        }

        return a;
    }

    public function deleteMany(array keys) -> void
    {
        this->mongoCollection->remove([
            "_id": [
                "$in": keys
            ]
        ]);
    }

    public function setAll(array keyValues) -> void
    {
        this->deleteAll();
        this->setMany(keyValues);
    }

    public function getAll() -> array
    {
        var rows, row, a = [], k, v;

        let rows = this->mongoCollection->find();

        for row in iterator_to_array(rows) {
            if fetch k, row["_id"] {
                if fetch v, row["value"] {
                    let a[k] = v;
                }
            }
        }

        return a;
    }

    public function deleteAll() -> void
    {
        this->mongoCollection->drop();
    }

}

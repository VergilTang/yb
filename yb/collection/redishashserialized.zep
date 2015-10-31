namespace Yb\Collection;

class RedisHashSerialized extends RedisHash
{
    public function serializeValue(var value) -> string
    {
        return serialize(value);
    }

    public function unserializeValue(string value)
    {
        return unserialize(value);
    }

    public function set(string key, var value) -> void
    {
        parent::set(key, this->serializeValue(value));
    }

    public function get(string key)
    {
        var value;

        let value = parent::get(key);
        if value === null {
            return;
        }

        return this->unserializeValue(value);
    }

    public function setMany(array keyValues) -> void
    {
        var k, v, data = [];

        for k, v in keyValues {
            let data[k] = this->serializeValue(v);
        }

        parent::setMany(data);
    }

    public function getMany(array keys) -> array
    {
        var a, k, v, data = [];

        let a = parent::getMany(keys);
        for k, v in a {
            let data[k] = this->unserializeValue(v);
        }

        return data;
    }

    public function setAll(array keyValues) -> void
    {
        var k, v, data = [];

        for k, v in keyValues {
            let data[k] = this->serializeValue(v);
        }

        parent::setAll(data);
    }

    public function getAll() -> array
    {
        var a, k, v, data = [];

        let a = parent::getAll();
        for k, v in a {
            let data[k] = this->unserializeValue(v);
        }

        return data;
    }

}

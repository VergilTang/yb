namespace Yb\Collection;

use Yb\Serializer\SerializerInterface;

class RedisHashSerialized extends RedisHash
{
    protected serializer;

    public function __construct(var redis, string hashName, <SerializerInterface> serializer) -> void
    {
        parent::__construct(redis, hashName);
        let this->serializer = serializer;
    }

    public function set(string key, var value) -> void
    {
        parent::set(key, this->serializer->serialize(value));
    }

    public function get(string key)
    {
        var value;

        let value = parent::get(key);
        if value === null {
            return;
        }

        return this->serializer->unserialize(value);
    }

    public function setMany(array keyValues) -> void
    {
        var k, v, data = [];

        for k, v in keyValues {
            let data[k] = this->serializer->serialize(v);
        }

        parent::setMany(data);
    }

    public function getMany(array keys) -> array
    {
        var a, k, v, data = [];

        let a = parent::getMany(keys);
        for k, v in a {
            let data[k] = this->serializer->unserialize(v);
        }

        return data;
    }

    public function setAll(array keyValues) -> void
    {
        var k, v, data = [];

        for k, v in keyValues {
            let data[k] = this->serializer->serialize(v);
        }

        parent::setAll(data);
    }

    public function getAll() -> array
    {
        var a, k, v, data = [];

        let a = parent::getAll();
        for k, v in a {
            let data[k] = this->serializer->unserialize(v);
        }

        return data;
    }

}

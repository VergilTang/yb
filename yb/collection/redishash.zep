namespace Yb\Collection;

class RedisHash implements CollectionInterface
{
    protected redis;
    protected hashName;

    public function __construct(var redis, string hashName) -> void
    {
        let this->redis = redis;
        let this->hashName = hashName;
    }

    public function set(string key, var value) -> void
    {
        this->redis->hset(this->hashName, key, value);
    }

    public function get(string key)
    {
        var value;

        let value = this->redis->hget(this->hashName, key);
        if value === false {
            return;
        }

        return value;
    }

    public function delete(string key) -> void
    {
        this->redis->hdel(this->hashName, key);
    }

    public function setMany(array keyValues) -> void
    {
        this->redis->hmset(this->hashName, keyValues);
    }

    public function getMany(array keys) -> array
    {
        var a, k, v, r = [];

        if unlikely count(keys) < 1 {
            return r;
        }

        let a = this->redis->hmget(this->hashName, keys);
        if unlikely typeof a != "array" {
            return r;
        }

        for k in keys {
            if fetch v, a[k] && v !== false {
                let r[k] = v;
            }
        }

        return r;
    }

    public function deleteMany(array keys) -> void
    {
        var k;

        for k in keys {
            this->redis->hdel(this->hashName, k);
        }
    }

    public function setAll(array keyValues) -> void
    {
        this->redis->multi()
            ->delete(this->hashName)
            ->hmset(this->hashName, keyValues)
            ->exec();
    }

    public function getAll() -> array
    {
        var a;

        let a = this->redis->hgetall(this->hashName);
        if typeof a != "array" {
            return [];
        }

        return a;
    }

    public function deleteAll() -> void
    {
        this->redis->delete(this->hashName);
    }

}

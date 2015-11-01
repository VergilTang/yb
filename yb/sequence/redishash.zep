namespace Yb\Sequence;

class RedisHash implements SequenceInterface
{
    const DEFAULT_HASH_NAME = "sequence";

    protected redis;
    protected hashName;

    public function __construct(var redis, string hashName = self::DEFAULT_HASH_NAME) -> void
    {
        let this->redis = redis;
        let this->hashName = hashName;
    }

    public function getNextSequence(string name) -> long
    {
        var s;

        let s = this->redis->hincrby(this->hashName, name, 1);
        if unlikely s === false {
            throw new Exception("Cannot get next sequence of: " . name);
        }

        return (long) s;
    }

    public function restoreSequences(array sequences) -> void
    {
        this->redis->hmset(this->hashName, sequences);
    }

}

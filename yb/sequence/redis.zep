namespace Yb\Sequence;

class Redis implements SequenceInterface
{
    const DEFAULT_PREFIX = "sequence:";

    protected redis;
    protected prefix;

    public function __construct(var redis, string prefix = self::DEFAULT_PREFIX) -> void
    {
        let this->redis = redis;
        let this->prefix = prefix;
    }

    public function getNextSequence(string name) -> long
    {
        var s;

        let s = this->redis->incr(this->prefix . name, 1);
        if unlikely s === false {
            throw new Exception("Cannot get next sequence of: " . name);
        }

        return (long) s;
    }

    public function restoreSequences(array sequences) -> void
    {
        var name, sequence;

        for name, sequence in sequences {
            this->redis->set(this->prefix . name, sequence);
        }
    }

}

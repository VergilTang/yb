namespace Yb\Redis;

class Client
{
    protected connections;

    public static function hashSlot(string s) -> int
    {
        int r;

        let r = yb_redis_cluster_hash_slot(s);
        return r;
    }

    public function __construct(<Connection> connection) -> void
    {
    }

}

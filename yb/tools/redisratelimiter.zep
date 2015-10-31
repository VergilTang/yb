namespace Yb\Tools;

class RedisRateLimiter
{
    const DEFAULT_KEY_PREFIX = "rate_limiter:";

    protected redis;
    protected keyPrefix;

    public function __construct(var redis, string keyPrefix = self::DEFAULT_KEY_PREFIX) -> void
    {
        let this->redis = redis;
        let this->keyPrefix = keyPrefix;
    }

    public function pass(string item, long seconds, long times) -> boolean
    {
        string key;
        var value, result;

        if seconds < 1 {
            let seconds = 1;
        }
        if times < 1 {
            let times = 1;
        }

        let key = this->keyPrefix . item . sprintf(":%d:%d", seconds, time() / seconds);
        let value = this->redis->get(key);

        if value === false {
            let result = this->redis->multi()
                ->incr(key, 1)
                ->expire(key, seconds + 1)
                ->exec();

            if typeof result == "array" && fetch value, result[0] && value <= times {
                return true;
            }

            return false;
        }

        if value >= times {
            return false;
        }

        let value = this->redis->incr(key, 1);
        if value > times {
            return false;
        }

        return true;
    }

}

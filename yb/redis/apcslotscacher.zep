namespace Yb\Redis;

class ApcSlotsCacher implements RedisSlotsCacherInterface
{
    const DEFAULT_CACHE_KEY = "redis-slots";

    protected cacheKey;

    public function __construct(string cacheKey = self::DEFAULT_CACHE_KEY) -> void
    {
        if unlikely ! extension_loaded("apc") {
            throw new Exception("Missing extension: apc");
        }

        let this->cacheKey = cacheKey;
    }

    public function storeSlots(array slots) -> void
    {
        if unlikely ! apc_store(this->cacheKey, slots) {
            throw new Exception("Cannot store slots: apc_store");
        }
    }

    public function fetchSlots() -> array
    {
        var slots, success = null;

        let slots = apc_fetch(this->cacheKey, success);
        if success {
            return slots;
        }
    }

}

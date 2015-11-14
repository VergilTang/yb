namespace Yb\Redis;

interface RedisSlotsCacherInterface
{
    public function storeSlots(array slots) -> void;
    public function fetchSlots() -> array;

}

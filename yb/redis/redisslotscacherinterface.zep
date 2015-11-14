namespace Yb\Redis;

interface RedisSlotsCacherInterface
{
    public function storeSlots(var slots) -> void;
    public function fetchSlots();

}

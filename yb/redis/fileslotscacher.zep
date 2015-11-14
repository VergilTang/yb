namespace Yb\Redis;

class FileSlotsCacher implements RedisSlotsCacherInterface
{
    protected path;

    public function __construct(string path) -> void
    {
        let this->path = path;
    }

    public function storeSlots(array slots) -> void
    {
        if unlikely ! file_put_contents(this->path, sprintf("<?php return %s;", var_export(slots, true)), LOCK_EX) {
            throw new Exception("Cannot write slots to path: " . this->path);
        }
    }

    public function fetchSlots() -> array
    {
        if file_exists(this->path) {
            return require this->path;
        }
    }

}

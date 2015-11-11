<?php
namespace YbApp\Core\Lib;

use Exception;

class RedisClusterSlotsCacherApc implements RedisClusterSlotsCacherInterface
{
    protected $name = 'redis-cluster-slots';

    public function store($value)
    {
        if (!apc_store($this->name, $value)) {
            throw new Exception("apc_store");
        }
    }

    public function retrieve()
    {
        $r = apc_fetch($this->name, $success);
        if ($success) {
            return $r;
        }
    }
}

<?php
namespace YbApp\Core\Lib;

interface RedisClusterSlotsCacherInterface
{
    public function store($value);
    public function retrieve();
}

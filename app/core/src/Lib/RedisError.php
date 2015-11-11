<?php
namespace YbApp\Core\Lib;

use Exception;

class RedisError
{
    protected $error;

    public function __construct($error)
    {
        $this->error = $error;
    }

    public function __toString()
    {
        return (string) $this->error;
    }

}

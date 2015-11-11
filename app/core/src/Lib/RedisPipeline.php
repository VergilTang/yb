<?php
namespace YbApp\Core\Lib;

use Exception;

class RedisPipeline
{
    protected $connection;
    protected $cmds;

    public function __construct($connection)
    {
        $this->connection = $connection;
    }

    public function __call($method, array $a)
    {
        array_unshift($a, $method);
        $this->cmds[] = $a;

        return $this;
    }

    public function __invoke()
    {
        return $this->connection->runCommands($this->cmds);
    }

}

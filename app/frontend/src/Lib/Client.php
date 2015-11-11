<?php
namespace YbApp\Frontend\Lib;

use Exception;
use Yb\Redis\Connection;
use Yb\Redis\RedisException;

class Client
{
    protected $defaultConnection;
    protected $connections;
    protected $clusterSlots;
    protected $slotConnections;

    public function __construct($host = '127.0.0.1', $port = 6379, $timeout = 5)
    {
        $connection = new Connection($host, $port, $timeout);

        $this->defaultConnection = $connection;
        $this->connections[sprintf("%s:%d", $host, $port)] = $connection;

        $this->initClusterSlots();
    }

    protected function initClusterSlots()
    {
    }

    protected function refleshClusterSlots()
    {
        static $i = 0;
        echo __FUNCTION__, '#', $i++, PHP_EOL;

        $this->clusterSlots = $this->defaultConnection->cluster('slots');
        $this->slotConnections = null;
    }

    protected function getConnectionByAddress($addr)
    {
        if (isset($this->connections[$addr])) {
            return $this->connections[$addr];
        }

        list($host, $port) = explode(':', $addr);
        return $this->connections[$addr] = new Connection($host, $port);
    }

    protected function getConnectionByHostAndPort($host, $port)
    {
        $addr = sprintf("%s:%d", $host, $port);
        if (isset($this->connections[$addr])) {
            return $this->connections[$addr];
        }

        return $this->connections[$addr] = new Connection($host, $port);
    }

    protected function getConnectionByKey($key)
    {
        $slot = \Yb\Redis\Client::hashSlot($key);
        $found = false;

        if (isset($this->slotConnections[$slot])) {
            $index = $this->slotConnections[$slot];

            return $this->getConnectionByAddress($index);
        }

        if ($this->clusterSlots) {
            foreach ($this->clusterSlots as $s) {
                if ($slot >= $s[0] && $slot <= $s[1]) {
                    $found = true;
                    break;
                }
            }
        }

        if ($found) {
            // timeout?
            list($host, $port) = $s[2];
            return $this->getConnectionByHostAndPort($host, $port);
        }

        return $this->defaultConnection;
    }

    public function get($key)
    {
        try {
            return $this->getConnectionByKey($key)->get($key);
        } catch (RedisException $ex) {

            // moved
            $match = null;
            if (preg_match('/^MOVED (\d+) ([\d\.\:]+)$/', $ex->getMessage(), $match)) {
                $this->refleshClusterSlots();
                $this->slotConnections[$match[1]] = $match[2];
                return $this->getConnectionByKey($key)->get($key);
            }

            // ask
            $match = null;
            if (preg_match('/^ASK (\d+) ([\d\.\:]+)$/', $ex->getMessage(), $match)) {
                $connection = $this->getConnectionByAddress($match[2]);
                // pipeline?
                $connection->asking();
                return $connection->get($key);
            }

            throw $ex;
        }
    }

}

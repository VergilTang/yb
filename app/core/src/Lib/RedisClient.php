<?php
namespace YbApp\Core\Lib;

use Exception;
use YbApp\Core\Lib\RedisConnection as Connection;
use Yb\Redis\RedisException;

class RedisClient
{
    protected $defaultConnection;
    protected $connections;

    protected $slotConnections;
    protected $clusterSlotsCacher;
    protected $clusterSlots;

    public static $tsLogs;
    protected static $ts = 0;

    public static function ts($name)
    {
        $ts = microtime(true);

        $diff = 0;
        if (self::$ts > 0) {
            $diff = $ts - self::$ts;
        }

        self::$tsLogs[] = sprintf("%0.6f#%s", $diff, $name);
        self::$ts = $ts;
    }

    public function __construct($host = '127.0.0.1', $port = 6379, $timeout = 5)
    {
        self::ts('DefaultConnectionConstructing');

        $connection = new Connection($host, $port, $timeout);

        self::ts('DefaultConnectionCreated');

        $this->defaultConnection = $connection;
        $this->connections[sprintf("%s:%d", $host, $port)] = $connection;

        $this->clusterSlotsCacher = new RedisClusterSlotsCacherApc();
        $this->initClusterSlots();
    }

    protected function initClusterSlots()
    {
        $this->clusterSlots = $this->clusterSlotsCacher->retrieve();
    }

    protected function refleshClusterSlots()
    {
        static $i = 0;
        echo __FUNCTION__, '#', $i++, PHP_EOL;

        self::ts('RefleshClusterSlotsStarted');

        $this->slotConnections = null;
        $this->clusterSlots = $this->defaultConnection->cluster('slots');
        $this->clusterSlotsCacher->store($this->clusterSlots);

        self::ts('RefleshClusterSlotsFinished');
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
        self::ts('GetStarted');

        try {
            $r = $this->getConnectionByKey($key)->get($key);

            self::ts('GetFinishedWithoutMOVED');

            return $r;
        } catch (RedisException $ex) {

            // moved
            $match = null;
            if (preg_match('/^MOVED (\d+) ([\d\.\:]+)$/', $ex->getMessage(), $match)) {

                self::ts('GetFinishedAndMOVED');

                $this->refleshClusterSlots();
                $this->slotConnections[$match[1]] = $match[2];

                self::ts('GetFinishedAndMOVEDNewConnectionStarted');

                $conn = $this->getConnectionByKey($key);

                self::ts('GetFinishedAndMOVEDNewConnectionFinished');

                $r = $conn->get($key);

                self::ts('GetFinishedAndMOVEDThenFinished');

                return $r;
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

<?php

namespace YbApp\Core\Lib\Data;

use Yb\Redis\Cluster;
use Yb\Data\RateLimiterBackendInterface;

class RedisCluster implements RateLimiterBackendInterface
{
    protected $redis;

    public function __construct(Cluster $redis)
    {
        $this->redis = $redis;
    }

    public function passRateLimiter($identifier, $item, $seconds, $times)
    {
        $redis = $this->redis;

        $key = sprintf(
            "%s:%s:%d:%d",
            $identifier,
            $item,
            $seconds,
            time() / $seconds
        );

        $value = $redis->runCommandByKey($key, [
            'get',
            $key,
        ]);

        if ($value === null) {
            $result = null;

            $value = $redis->runCommandsByKey($key, [
                [
                    'multi',
                ],
                [
                    'incr',
                    $key,
                ],
                [
                    'expire',
                    $key,
                    $seconds + 1,
                ],
                [
                    'exec',
                ],
            ], function($v, $k) use (&$result) {
                // !todo
                if ($k == 3) {
                    if (0) {
                        throw new Exception();
                    }
                }
                var_dump($v);
            });

            var_dump($result);

            if (is_array($result) && isset($result[0]) && $result[0] < $times) {
                return true;
            }

            return false;
        }

        if ($value >= $times) {
            return false;
        }

        $value = $redis->runCommandByKey($key, [
            'incr',
            $key,
        ]);

        if ($value > $times) {
            return false;
        }

        return true;
    }

}

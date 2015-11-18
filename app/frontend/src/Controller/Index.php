<?php
namespace YbApp\Frontend\Controller;

use YbApp\Frontend\ControllerBase;

class Index extends ControllerBase
{
    public function indexAction()
    {
        throw new \Exception();
    }

    public function socketAction()
    {
        $host = '172.16.1.140';
        $port = 6379;
        $timeout = 1;

        $errNo = null;
        $errStr = null;

        $socket = fsockopen($host, $port, $errNo, $errStr, $timeout);
        if (!$socket) {
            throw new \Exception('fsockopen');
        }
        if (!stream_set_blocking($socket, 1)) {
            throw new \Exception('stream_set_blocking');
        }
        if (!socket_set_option($socket, SOL_TCP, TCP_NODELAY, 1)) {
            throw new \Exception('socket_set_option');
        }

        return false;
    }

    public function streamAction()
    {
        $host = '172.16.1.140';
        $port = 6379;
        $timeout = 1;

        $errNo = null;
        $errStr = null;

        $stream = stream_socket_client(sprintf("tcp://%s:%d", $host, $port), $errNo, $errStr, $timeout);
        if (!$stream) {
            throw new \Exception('stream_socket_client');
        }
        if (!stream_set_blocking($stream, 1)) {
            throw new \Exception('stream_set_blocking');
        }

        if (1) {
            if (!socket_set_option($stream, SOL_TCP, TCP_NODELAY, 1)) {
                throw new \Exception("socket_set_option");
            }
        } else {
            if (!socket_set_option(socket_import_stream($stream), SOL_TCP, TCP_NODELAY, 1)) {
                throw new \Exception("Cannot set tcp_nodelay");
            }
        }

        return false;
    }

    public function testAction()
    {
        $this->app['viewData'] = [
            'hello' => json_encode(func_get_args()),
        ];

        // $this->app['viewData']['hello'] = 1;
    }

    protected function rl()
    {
        $redis = new \Yb\Redis\Client('192.168.255.11');

        $item = 'pre:test';
        $seconds = 5;
        $times = 2;

        $key = sprintf(
            '%s:%d:%d',
            $item,
            $seconds,
            time() / $seconds
        );

        $value = $redis->get($key);

        if ($value === null) {
            if (0) {
                $result = $redis->multi();
                var_dump($result);
                $result = $redis->incr($key);
                var_dump($result);
                $result = $redis->expire($key, $seconds + 1);
                var_dump($result);
                $result = $redis->exec();
                var_dump($result);
            }

            $redis->multi();
            $redis->incr($key);
            $redis->expire($key, $seconds + 1);
            $result = $redis->exec();

            if (is_array($result) && isset($result[0]) && $result[0] < $times) {
                return true;
            }

            return false;
        }

        if ($value >= $times) {
            return false;
        }

        $value = $redis->incr($key);
        if ($value > $times) {
            return false;
        }

        return true;
    }

    protected function rr()
    {
        $redis = new \Redis();
        $redis->connect('192.168.255.11', 6379);

        $rl = new \Yb\RateLimiter\Redis($redis, 'pre:');

        return $rl->passRateLimiter('test', 5, 2);
    }

    public function rlAction($type = '')
    {
        $type = $type === '' ? mt_rand() : (int) $type;

        if ($type % 2) {
            echo '#RE', PHP_EOL;
            var_dump($this->rr());
        } else {
            echo '#YB', PHP_EOL;
            var_dump($this->rl());
        }

        return false;
    }

    public function redisAction()
    {
        $r = new \Yb\Redis\Client('192.168.255.11');

        if (0) {
            $d = $r->echo(1);
            var_dump($d);
            return false;
        }

        if (0) {
            $d = $r->keys('*');
            var_dump($d);
            return false;
        }

        if (1) {
            return false;
        }
    }

    public function r1Action()
    {
        // $r = new \Yb\Redis\Client('192.168.255.11');

        $r = new \YbApp\Frontend\Lib\Redis('192.168.255.11');

        $d = $r->keys('*');
        var_dump($d);

        return false;
    }

    public function r0Action()
    {
        // $r = new \Yb\Redis\Client('192.168.255.11');

        $r = new \YbApp\Frontend\Lib\Redis('192.168.255.11');

        $d = $r->set('hello', 'world');
        var_dump($d);

        return false;
    }

    public function plAction()
    {
        $r = new \YbApp\Frontend\Lib\Redis('192.168.255.11');
        $d = $r->pipeline();
        var_dump($d);

        return false;
    }

}

<?php
namespace YbApp\Frontend\Controller;

use YbApp\Frontend\ControllerBase;

class Re extends ControllerBase
{
    public function __construct($app)
    {
        parent::__construct($app);

        $app('redisCluster', function($app) {
            try {
                $slotsCacher = new \Yb\DataCacher\Apc('redis-cluster');
            } catch (\Exception $ex) {
                $slotsCacher = new \Yb\DataCacher\File(__DIR__.'/../../data/redis-cluster.php');
            }
            return new \Yb\Redis\Cluster($slotsCacher, (array) $app->config('redis'));
        });

        $app('redisConnection', function($app) {
            return new \Yb\Redis\Connection((array) $app->config('redis'));
        });

        $app('redis', function($app) {
            $redis = new \Redis();
            $redis->connect($app->config('redis.host'), $app->config('redis.port'));
            return $redis;
        });
    }

    public function rlAction()
    {
        $redisCluster = $this->app->redisCluster;
        $rlBackend = new \YbApp\Core\Lib\Data\RedisCluster($redisCluster);
        $rl = new \Yb\Data\RateLimiter($rlBackend, '{rl}');

        $r = $rl->pass('test', 5, 2);
        var_dump($r);

        return false;
    }

    public function indexAction($type = 0)
    {
        $client = $this->app->redisCluster;

        $d = $client->runCommandByKey('', ['get', '']);
        var_dump($d);

        $d = $client->runCommandByKey('test', ['get', 'test']);
        var_dump($d);

        if ($type) {
            echo ':plain:', PHP_EOL;
            foreach (range(1, 9) as $i) {
                $d = $client->runCommandByKey('test', ['get', '{test}'.$i]);
                var_dump($d);
            }

        } else {
            echo ':pipeline:', PHP_EOL;
            $cmds = [];
            foreach (range(1, 9) as $i) {
                $cmds[$i] = ['get', '{test}'.$i];
            }
            $d = $client->runCommandsByKey('test', $cmds, function($v, $k) {
                echo $k, ': ', var_export($v, true), PHP_EOL;
            });
            // echo json_encode($d, JSON_PRETTY_PRINT);
            echo var_export($d, true), PHP_EOL;

        }

        // print_R($client);

        return false;
    }

    public function aAction()
    {
        $client = $this->app->redisConnection;

        $d = $client->get('');
        var_dump($d);

        $d = $client->get('test');
        var_dump($d);

        return false;

        foreach (range(1, 9) as $i) {
            $d = $client->get('{test}'.$i);
            var_dump($d);
        }

        return false;
    }

    public function bAction()
    {
        $client = $this->app->redis;

        $d = $client->get('');
        var_dump($d);

        $d = $client->get('test');
        var_dump($d);

        return false;

        foreach (range(1, 9) as $i) {
            $d = $client->get('{test}'.$i);
            var_dump($d);
        }

        return false;
    }

}

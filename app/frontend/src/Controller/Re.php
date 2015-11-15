<?php
namespace YbApp\Frontend\Controller;

use YbApp\Frontend\ControllerBase;

class Re extends ControllerBase
{
    public function __construct($app)
    {
        parent::__construct($app);

        $app('redisCluster', function() {
            $slotsCacher = new \Yb\Datacacher\Apc('redis-cluster');
            return new \Yb\RedisCluster\Client($slotsCacher, '192.168.1.12', 6380);
        });

        $app('redisConnection', function() {
            return new \Yb\RedisCluster\Connection('192.168.1.12', 6380);
        });

        $app('redis', function() {
            $redis = new \Redis();
            $redis->connect('192.168.1.12', 6380);
            return $redis;
        });
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
    }

    public function bAction()
    {
        $client = $this->app->redis;

        $d = $client->get('');
        var_dump($d);

        $d = $client->get('test');
        var_dump($d);

        return false;
    }

}

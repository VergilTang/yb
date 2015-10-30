<?php
namespace YbApp\Modules\Frontend\Controller;

class Test extends \YbApp\Modules\Frontend\ControllerBase
{
    public function redisAction()
    {
        $config = new \Yb\Application\Config([
            __DIR__.'/../config',
        ], [
            'php',
            'local.php',
        ]);

        $host = $config->get('redis.host');

        $redis = new \Redis();
        $redis->connect($host, 6379);

        // $c = new \Yb\Collection\RedisHash($redis, 'test');
        $c = new \Yb\Collection\RedisHashSerialized($redis, 'test', new \Yb\Serializer\Php());
        $c->setAll([
            'a' => 1,
            'b' => false,
        ]);

        $d = $c->getAll();
        var_dump($d);
    }

    public function mongoAction()
    {
        $mongo = new \MongoClient('mongodb://192.168.255.11:27017');
        $c = new \Yb\Collection\MongoCollection($mongo->test->test);
        $c->setAll([
            'a' => 1,
            'b' => false,
        ]);

        $d = $c->getAll();
        var_dump($d);
    }

}

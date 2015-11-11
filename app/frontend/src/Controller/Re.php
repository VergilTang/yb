<?php
namespace YbApp\Frontend\Controller;

use YbApp\Frontend\ControllerBase;

class Re extends ControllerBase
{
    public function indexAction($type = 0)
    {
        $client = new \YbApp\Core\Lib\RedisClient('192.168.255.11', 6380);

        $d = $client->get('');
        var_dump($d);

        $d = $client->get('test');
        var_dump($d);

        if ($type) {
            echo ':plain:', PHP_EOL;
            foreach (range(1, 9) as $i) {
                $d = $client->get('test'.$i);
                var_dump($d);
            }
        } else {
            echo ':pipeline:', PHP_EOL;
            $connection = new \YbApp\Core\Lib\RedisConnection('192.168.255.11', 6380);
            $pipeline = new \YbApp\Core\Lib\RedisPipeline($connection);
            foreach (range(1, 9) as $i) {
                $pipeline->get('test'.$i);
            }
            // echo json_encode($pipeline(), JSON_PRETTY_PRINT);
            echo var_export($pipeline(), true), PHP_EOL;
        }

        echo implode(PHP_EOL, $client::$tsLogs), PHP_EOL;
        // print_R($client);

        return false;
    }

    public function aAction()
    {
        $client = new \Redis();
        $client->connect('192.168.255.11', 6380);

        $d = $client->get('');
        var_dump($d);

        $d = $client->get('test');
        var_dump($d);

        return false;
    }

}

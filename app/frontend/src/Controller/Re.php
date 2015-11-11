<?php
namespace YbApp\Frontend\Controller;

use YbApp\Frontend\ControllerBase;

class Re extends ControllerBase
{
    protected function getRe()
    {
        static $re;

        if (!$re) {
            $re = new \Yb\Redis\Connection('172.16.1.139');
            // $re = new \YbApp\Frontend\Lib\Redis('172.16.1.139');
        }

        return $re;
    }

    public function indexAction()
    {
        throw new \Exception();
    }

    public function bAction()
    {
        $re = $this->getRe();

        $client = new \YbApp\Frontend\Lib\Client('172.16.1.139');

        $d = $client->get('');
        var_dump($d);

        /*
        foreach (range(1, 9) as $i) {
            $d = $client->get('test'.$i);
            var_dump($d);
        }
        */

        print_R($client);

        return false;
    }

    public function aAction()
    {
        $re = $this->getRe();

        $d = $re->cluster('nodes');
        var_export($d);
        echo PHP_EOL;

        $d = $re->cluster('slots');
        var_export($d);
        echo PHP_EOL;

        $d = $re->info();
        var_export($d);
        echo PHP_EOL;

        return false;
    }

}

<?php
namespace YbApp\Frontend\Controller;

use YbApp\Frontend\ControllerBase;

class Mongo extends ControllerBase
{
    public function __construct($app)
    {
        parent::__construct($app);

        $app('mongoModelManager', function($app) {
            return new \YbApp\Core\Lib\MongoModelManager('mongodb://172.16.1.120,172.16.1.121,172.16.1.122/?w=1');
        });
    }

    public function kkvAction()
    {
        $kkv = $this->app->mongoModelManager->get('test', 'kkv');

        $k1 = mt_rand(1, 9);
        $k2 = mt_rand(1, 9);

        $kk = [
            'k1' => $k1,
            'k2' => $k2,
        ];

        $d = $kkv->find($kk);
        print_R($d);
        echo PHP_EOL;

        $kkv->upsert($kk, [
            'v' => \Yb\Std::randString(6),
            'ts' => time(),
        ]);

        $d = $kkv->find($kk);
        print_R($d);
        echo PHP_EOL;

        return false;
    }

    public function dAction()
    {
        $m = $this->app->mongoModelManager;
        $test = $m->get('test', 'test');

        $d = $test->delete([]);
        var_dump($d);

        return false;
    }

    public function csAction()
    {
        $m = $this->app->mongoModelManager;
        $test = $m->get('test', 'test');

        $c = $test->countAndSelect([], [], 5, 5);
        print_R($c);

        return false;
    }

    public function cAction()
    {
        $m = $this->app->mongoModelManager;
        $test = $m->get('test', 'test');

        $c = $test->count();
        var_dump($c);

        return false;
    }

    public function indexAction()
    {
        $m = $this->app->mongoModelManager;
        $test = $m->get('test', 'test');

        if (10) {
            $id = '1';

            $d = $test->update([
                // '_id' => $id,
                'ts' => [
                    '$gt' => 0,
                ],
            ], [
                'uid' => mt_rand(100000, 999999),
                't' => \Yb\Std::uuid(),
                'ts' => time(),
            ]);
            var_dump($d);
        }

        if (0) {
            $id = $test::objectId('563cd3c7f462c7c11f8b45ae');
            $id = mt_rand(1, 9);

            $d = $test->upsert([
                '_id' => $id,
            ], [
                'uid' => mt_rand(100000, 999999),
                't' => \Yb\Std::uuid(),
                'ts' => time(),
            ]);
            var_dump($d);
        }

        if (0) {
            $id = $test::objectId('564b050b2687e42674003545');

            $d = $test->delete([
                '_id' => $id,
            ]);
            var_dump($d);
        }

        if (0) {
            $d = $test->insert([
                'uid' => mt_rand(100000, 999999),
                't' => \Yb\Std::uuid(),
                'ts' => time(),
            ]);

            var_dump($d);
        }

        return false;
    }

}

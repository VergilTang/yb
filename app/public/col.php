<?php
if (!isset($_SERVER['REQUEST_TIME_FLOAT'])) {
    $_SERVER['REQUEST_TIME_FLOAT'] = microtime(true);
}
header('Content-type: text/plain; charset=UTF-8');
set_error_handler(Yb\Std::THROW_ERROR);

$core = null;
try {
    $core = new Yb\Core();

    $core('redis', function() {
        $redis = new Redis();
        $redis->connect('192.168.255.11', 6379);
        return $redis;
    });

    $core('mongoDb', function() {
        return (new MongoClient('mongodb://192.168.255.11:27017'))->selectDb('yb');
    });

    $core('settingsMongo', function($core) {
        return new Yb\Collection\MongoCollection($core->mongoDb->selectCollection('settings'));
    });

    $core('settingsRedis', function($core) {
        return new Yb\Collection\RedisHashSerialized($core->redis, 'settings');
    });

    $core('settings', function($core) {
        return new Yb\Collection\Proxy($core->settingsRedis, $core->settingsMongo);
    });

    if (mt_rand(1, 9) < 3) {
        echo '#', PHP_EOL;
        $core->settings->setAll([
            'a' => 'aa',
            'b' => ['bbb' => false],
            'c' => ['ccc' => 213],
        ]);
    }

    if (1) {
        $r = $core->settingsRedis->getAll();
        var_dump($r);

        $r = $core->settings->getAll();
        var_dump($r);

        $r = $core->settings->getMany(['s', 'b', 'x', 'a']);
        var_dump($r);

        $r = $core->settings->get('a');
        var_dump($r);

        $r = $core->settings->get('z');
        var_dump($r);
    }

} catch (Exception $ex) {
    echo $ex, PHP_EOL;
}

echo PHP_EOL, str_repeat('-', 80), PHP_EOL;
echo sprintf('%0.3fs', microtime(true) - $_SERVER['REQUEST_TIME_FLOAT']), PHP_EOL;
echo Yb\Std::bytesToSize(memory_get_peak_usage()), PHP_EOL;
print_R(get_included_files());
print_R($core);

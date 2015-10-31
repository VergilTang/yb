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

    $core('rateLimiter', function($core) {
        return new Yb\Tools\RedisRateLimiter($core->redis);
    });

    $core('mongoClient', function() {
        return new MongoClient('mongodb://192.168.255.11:27017');
    });

    $core('mongoDb', function($core) {
        return $core->mongoClient->selectDb('yb');
    });

    $core('settingsMongo', function($core) {
        return new Yb\Collection\MongoCollection($core->mongoDb->selectCollection('settings'));
    });

    $core('settingsRedis', function($core) {
        return new Yb\Collection\RedisHashSerialized($core->redis, 'settings');
    });

    $core('logger', function() {
        $date = date('ymd');
        return new Yb\Logger\FileLogger(__DIR__."/{$date}.log");
    });

    $core('storage', function() {
        return new Yb\Upload\FileSystem(__DIR__.'/upload');
    });

    $core('uploader', function($core) {
        $uploader = new Yb\Upload\Uploader('jpg,jpeg,png,gif', '1m');
        $uploader->setStorage($core->storage);
        return $uploader;
    });

    $core('db', function() {
        return new Yb\Db\PdoMysql('mysql:host=192.168.255.11;port=3306;dbname=yb;charset=utf8', 'yb', 'yb');
    });

    if (0) {
        $db = $core->db;
        // print_R($db);

        $d = $db->countAndSelect([
            'table' => 'kv',
            'orderBy' => 'k',
            'limit' => 3,
        ]);
        print_R($d);

        $db->insert('kv', [
            'k' => mt_rand(1, 9),
            'v' => mt_rand(1, 9),
        ]);

        $d = $db->queryColumns("show tables");
        print_R($d);
    }

    if (0) {
        $uploadedFile = $core->uploader->pick('f');
        print_R($uploadedFile);

        var_dump($uploadedFile->isValid());
        $uri = $uploadedFile->save(date('ymd'));
        echo $uri, PHP_EOL;

        $uploadedFiles = $core->uploader->pickArray('fs');
        print_R($uploadedFiles);
    }

    if (0) {
        $core->logger->debug('{sb} {hehe}', [
            'sb' => 21,
        ]);
        $core->logger->notice('{sb} {fuck}', [
            'sb' => 66,
        ]);
    }

    if (0) {
        //
        $d = [
            'a' => 'a',
            'b' => false,
            'c' => 21,
        ];
        $core->settingsRedis->setAll($d);
        $r = $core->settingsRedis->get('c');
        var_dump($r);

        $core->settingsMongo->setAll($d);
        $r = $core->settingsMongo->get('c');
        var_dump($r);
    }

    if (0) {
        $r = $core->rateLimiter->pass('fuck', 3600, 3);
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

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

    $core('mongo', function() {
        return (new MongoClient('mongodb://192.168.255.11:27017'))->selectDb('yb');
    });

    $core('mysql', function() {
        return new Yb\Db\PdoMysql('mysql:host=127.0.0.1;port=3306;dbname=yb;charset=utf8', 'yb', 'yb');
    });

    $core('redisSeq', function($core) {
        return new Yb\Sequence\RedisHash($core->redis);
    });

    $core('mongoSeq', function($core) {
        return new Yb\Sequence\MongoCollection($core->mongo->sequence);
    });

    $core('mysqlSeq', function($core) {
        return new Yb\Sequence\DbPdoMysql($core->mysql);
    });

    if (1) {
        $name = array_rand(array_flip([
            'redisSeq',
            'mongoSeq',
            'mysqlSeq',
        ]));

        echo $name, PHP_EOL;

        $k = mt_rand(1, 9);
        echo $k, PHP_EOL;

        $r = $core->$name->getNextSequence($k);
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

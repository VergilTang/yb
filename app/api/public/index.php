<?php

if (!isset($_SERVER['REQUEST_TIME_FLOAT'])) {
    $_SERVER['REQUEST_TIME_FLOAT'] = microtime(true);
}

try {
    $app = new Yb\Application();

    $app->loader = new Yb\Loader\NamespaceDirectory(true, [
        'YbApp\Core'    => __DIR__.'/../../core/src',
        'YbApp\Api'     => __DIR__.'/../src',
    ]);

    new YbApp\Core\Bootstrap($app);

    new YbApp\Api\Bootstrap($app);

} catch (Exception $ex) {
    header('Content-type: text/plain; charset=UTF-8');
    echo $ex, PHP_EOL;
}

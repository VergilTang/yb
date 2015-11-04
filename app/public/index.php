<?php

if (!isset($_SERVER['REQUEST_TIME_FLOAT'])) {
    $_SERVER['REQUEST_TIME_FLOAT'] = microtime(true);
}

$_SERVER['DEBUG'] = 1;

if (!empty($_SERVER['DEBUG'])) {
    header('Content-type: text/plain; charset=UTF-8');
    set_error_handler(Yb\Std::THROW_ERROR);
    $app = null;
}

try {
    $app = new Yb\Application();

    $app->loader = new Yb\Loader\NamespaceDirectory(true, [
        'YbApp\Core'        => __DIR__.'/../core/src',
        'YbApp\Cli'         => __DIR__.'/../cli/src',
        'YbApp\Api'         => __DIR__.'/../api/src',
        'YbApp\Backend'     => __DIR__.'/../backend/src',
        'YbApp\Frontend'    => __DIR__.'/../frontend/src',
    ]);

    new YbApp\Core\Bootstrap($app);

    if (PHP_SAPI == 'cli') {
        new YbApp\Cli\Bootstrap($app);
    } else {
        $bootstrapClass = Yb\Std::valueAt([
            'admin.yb.dev' => 'YbApp\Backend\Bootstrap',
            'api.yb.dev' => 'YbApp\Api\Bootstrap',
        ], $_SERVER['HTTP_HOST'], 'YbApp\Frontend\Bootstrap');

        new $bootstrapClass($app);
    }

} catch (Exception $ex) {
    if (!empty($_SERVER['DEBUG'])) {
        header('Content-type: text/plain; charset=UTF-8');
        echo $ex, PHP_EOL;
    }
}

if (!empty($_SERVER['DEBUG'])) {
    echo PHP_EOL, str_repeat('-', 80), PHP_EOL;
    echo sprintf('%0.3fs', microtime(true) - $_SERVER['REQUEST_TIME_FLOAT']), PHP_EOL;
    echo Yb\Std::bytesToSize(memory_get_peak_usage()), PHP_EOL;
    print_R(get_included_files());
    print_R($app);
}

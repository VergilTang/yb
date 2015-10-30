<?php
if (!isset($_SERVER['REQUEST_TIME_FLOAT'])) {
    $_SERVER['REQUEST_TIME_FLOAT'] = microtime(true);
}
header('Content-type: text/plain; charset=UTF-8');

set_error_handler(Yb\Std::THROW_ERROR);

$app = null;
try {
    $app = new Yb\Application\Core();
    $app->loader = new Yb\Loader\NamespaceDirectory([
        'YbApp\Core'                => __DIR__.'/../src',
        'YbApp\Modules\Cli'         => __DIR__.'/../modules/cli/src',
        'YbApp\Modules\Backend'     => __DIR__.'/../modules/backend/src',
        'YbApp\Modules\Frontend'    => __DIR__.'/../modules/frontend/src',
    ]);
    $app->loader->register();
    $app('YbApp\Modules\Cli\Bootstrap');
    $app('YbApp\Modules\Backend\Bootstrap');
    $app('YbApp\Modules\Frontend\Bootstrap');
    (new Yb\Application\ModuleRouter([
        'cli'           => 'YbApp\Modules\Cli\Bootstrap',
        'admin.yb.dev'  => 'YbApp\Modules\Backend\Bootstrap',
        'yb.dev'        => 'YbApp\Modules\Frontend\Bootstrap',
        'default'       => 'YbApp\Modules\Frontend\Bootstrap',
    ]))->filterApplication($app);

} catch (Exception $ex) {
    echo $ex, PHP_EOL;
}

echo sprintf('%0.3fs', microtime(true) - $_SERVER['REQUEST_TIME_FLOAT']), PHP_EOL;
echo Yb\Std::bytesToSize(memory_get_peak_usage()), PHP_EOL;
print_R(get_included_files());
print_R($app);

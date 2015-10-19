<?php
$app = new Yb\Application\Core();
$app->loader = new Yb\Loader\NamespaceDirectory([
    'YbApp\Core'                => __DIR__.'/../src',
    'YbApp\Modules\Cli'         => __DIR__.'/../modules/cli/src',
    'YbApp\Modules\Backend'     => __DIR__.'/../modules/backend/src',
    'YbApp\Modules\Frontend'    => __DIR__.'/../modules/frontend/src',
]);
$app('YbApp\Modules\Cli\Bootstrap');
$app('YbApp\Modules\Backend\Bootstrap');
$app('YbApp\Modules\Frontend\Bootstrap');
(new Yb\Application\ModuleRouter([
    'cli'           => 'YbApp\Modules\Cli\Bootstrap',
    'admin.yb.dev'  => 'YbApp\Modules\Backend\Bootstrap',
    'yb.dev'        => 'YbApp\Modules\Frontend\Bootstrap',
    'default'       => 'YbApp\Modules\Frontend\Bootstrap',
]))->filterApplication($app);

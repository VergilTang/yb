<?php

// load configs
$config = new Yb\Config([
    __DIR__.'/../config',
]);

// loader
$loader = new Yb\Loader\NamespaceDirectory([
    'YbApp\Core' => __DIR__.'/../src',
]);

// module router
if (PHP_SAPI == 'cli') {
    $module == 'Cli';
} else {
    $hostModules = [
        'admin.yb.dev'  => 'Backend',
        'api.yb.dev'    => 'Api',
    ];
    if (isset($hostModules[$_SERVER['HTTP_HOST']])) {
        $module = $hostModules[$_SERVER['HTTP_HOST']];
    } else {
        $module = 'Frontend',
    }
}

// module init, in module, eg: frontend
$config->addDir(__DIR__.'/../modules/frontend/config');
$loader->add('YbApp\Modules\Frontend', __DIR__.'/../modules/frontend/src');

foreach ([
    'StartSession',
    'RouteRequest',
    'CheckPermission',
    'FilterInput',
    'InitView',
    'CallAction',
    'RenderTemplate',
] as ) {
}

$application->filters->add(
);

// module app filters
$application->on('session', function() {

});

// action router
$router = new Yb\Router\RequestUri();

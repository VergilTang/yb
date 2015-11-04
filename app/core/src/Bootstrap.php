<?php
namespace YbApp\Core;

use Yb\Application;

class Bootstrap
{
    public function __construct(Application $app)
    {
        $app->mergeConfigsInPathIfValid(__DIR__.'/../config.php');
        $app->mergeConfigsInPathIfValid(__DIR__.'/../config.local.php');
    }

}

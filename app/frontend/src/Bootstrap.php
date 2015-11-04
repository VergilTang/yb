<?php
namespace YbApp\Frontend;

use Yb\Application;

class Bootstrap
{
    public function __construct(Application $app)
    {
        $app->mergeConfigsInPathIfValid(__DIR__.'/../config.php');
        $app->mergeConfigsInPathIfValid(__DIR__.'/../config.local.php');

        $this->route();

        // route
        // session
        // permission
        // action
        // view
    }

    protected function route()
    {
        $router = new \Yb\Router\Uri($_SERVER['REQUEST_URI']);

        $c = __NAMESPACE__.'\\Controller\\'.\Yb\Std::pascalCase($router->getController());
        if (!class_exists($c)) {
            throw new \Exception('404.C.'.$c);
        }

        $a = [
            new $c(),
            \Yb\Std::camelCase($router->getAction()).'Action',
        ];

        if (!is_callable($a)) {
            throw new \Exception('404.A');
        }

        return call_user_func_array($a, $router->getParams());
    }

}

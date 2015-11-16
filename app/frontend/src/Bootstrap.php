<?php
namespace YbApp\Frontend;

use Yb\Std;
use Yb\Application;

class Bootstrap
{
    protected $app;

    public function __construct(Application $app)
    {
        $this->app = $app;

        $app->mergeConfigsInPathIfValid(__DIR__.'/../config.php');
        $app->mergeConfigsInPathIfValid(__DIR__.'/../config.local.php');

        // route
        $routerPatterns = new \Yb\Router\Patterns([
            'int' => '\d+',
        ]);
        $routerPatterns->alias('/{id:int}', '/index/{id}', '/re');
        $routerPatterns->alias('/p/{qid:int}/{aid:int}', '/index/test/{qid}/{aid}');

        // print_R($routerPatterns);
        $router = new \Yb\Router\Uri($_SERVER['REQUEST_URI'], $routerPatterns->getPatterns());

        $requestId = $router->getId();

        // session
        // session_start();

        // permission
        if (0) {
            throw new \Exception('Access denied');
        }

        // action
        $controllerFactory = new \Yb\Factory\Namespaced(__NAMESPACE__.'\Controller');
        $controllerFactory->args($this->app);
        $result = $router->dispatch($controllerFactory);

        // view
        if ($result === null) {
            $path = __DIR__.'/../view/'.$requestId.'.php';
            echo Std::renderScript($path, (array) $app['viewData']);
        }
    }

    public function get($name)
    {
        $class = $this->getClassName($name);
        return new $class($this->app);
    }

}

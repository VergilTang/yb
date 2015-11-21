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

        // router
        $router = new \Yb\Router\UriPatterns($_SERVER['REQUEST_URI'], [
            '' => [
                '/{tid:numbers}/{id:numbers}' => '/index/test/{tid}/{id}',
            ],
            '/re' => [
                '/{flag:numbers}' => '/index/{flag}',
            ],
        ], [
            'numbers' => '\d+',
        ]);

        $requestId = $router->getId();

        // session
        // session_start();

        // permission
        if (0) {
            throw new \Exception('Access denied');
        }

        // action
        $controllerFactory = new \Yb\Factory\Namespaced(__NAMESPACE__.'\Controller');
        $controllerFactory->setArgs($this->app);
        $result = $router->dispatch($controllerFactory);

        // view
        if ($result === null) {
            $path = __DIR__.'/../view/'.$requestId.'.php';
            echo Std::renderScript($path, (array) $app['viewData']);
        }
    }

}

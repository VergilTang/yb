<?php
namespace YbApp\Frontend;

use Yb\Std;
use Yb\Application;
use Yb\Factory\Namespaced;

class Bootstrap extends Namespaced
{
    protected $app;

    public function __construct(Application $app)
    {
        $this->app = $app;

        parent::__construct(__NAMESPACE__.'\Controller');

        $app->mergeConfigsInPathIfValid(__DIR__.'/../config.php');
        $app->mergeConfigsInPathIfValid(__DIR__.'/../config.local.php');

        // route
        $router = new \Yb\Router\Uri($_SERVER['REQUEST_URI'], (array) $app->config('routingPatterns'));

        $requestId = $router->getController().'/'.$router->getAction();

        // session
        // session_start();

        // permission
        if (0) {
            throw new \Exception('Access denied');
        }

        // action
        $result = $router->dispatch($this);

        // view
        if ($result === null) {
            $path = __DIR__.'/../view/'.$requestId.'.php';
            echo Std::renderScript($path, (array) $app['viewData']);
        }
    }

    public function get($name)
    {
        $o = parent::get($name);
        $o->setApplication($this->app);

        return $o;
    }

}

<?php
namespace YbApp\Modules\Frontend;

class Bootstrap implements \Yb\Application\ApplicationFilterInterface
{
    protected $core;

    public function filterApplication(\Yb\Application\Core $core)
    {
        $this->core = $core;

        $router = new \Yb\Application\RouterUri($_SERVER['REQUEST_URI']);
        $controllerClass = __NAMESPACE__.'\\Controller\\'.\Yb\Std::pascalCase($router->getController());
        if (!class_exists($controllerClass)) {
            throw new \Exception('404.C');
        }

        $action = [new $controllerClass(), \Yb\Std::camelCase($router->getAction()).'Action'];
        if (!is_callable($action)) {
            throw new \Exception('404.A');
        }

        call_user_func_array($action, $router->getParams());
    }

}

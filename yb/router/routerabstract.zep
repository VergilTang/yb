namespace Yb\Router;

abstract class RouterAbstract
{
    const DEFAULT_CONTROLLER = "index";
    const DEFAULT_ACTION = "index";

    protected controller;
    protected action;
    protected params;

    public function getController() -> string
    {
        return this->controller;
    }

    public function getAction() -> string
    {
        return this->action;
    }

    public function getParams() -> array
    {
        return this->params;
    }

}

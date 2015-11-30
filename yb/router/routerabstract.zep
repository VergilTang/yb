namespace Yb\Router;

use Yb\Std;
use Yb\Factory\FactoryInterface;

abstract class RouterAbstract
{
    const DEFAULT_CONTROLLER    = "index";
    const DEFAULT_ACTION        = "index";
    const DEFAULT_ACTION_SUFFIX = "Action";

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

    public function getId(string separator = "/") -> string
    {
        return this->controller . separator . this->action;
    }

    public function dispatch(<FactoryInterface> factory, string actionSuffix = self::DEFAULT_ACTION_SUFFIX)
    {
        string controllerClass;
        var actionMethod;

        let controllerClass = (string) Std::camelCase(this->controller);
        if unlikely ! factory->__isset(controllerClass) {
            throw new NotFoundException("Invalid controller: " . this->controller);
        }

        let actionMethod = [];
        let actionMethod[] = factory->__get(controllerClass);
        let actionMethod[] = Std::camelCase(this->action) . actionSuffix;

        if unlikely ! is_callable(actionMethod) {
            throw new NotFoundException("Invalid action: " . this->action);
        }

        return call_user_func_array(actionMethod, this->params);
    }

}

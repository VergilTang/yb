namespace Yb\Router;

use Yb\Std;
use Yb\Factory\FactoryInterface;

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

    public function dispatch(<FactoryInterface> factory)
    {
        string c;
        var i;

        let c = (string) Std::camelCase(this->controller);
        if unlikely ! factory->has(c) {
            throw new Exception("Invalid controller: " . this->controller);
        }

        let i = [];
        let i[] = factory->get(c);
        let i[] = Std::camelCase(this->action) . "Action";

        if unlikely ! is_callable(i) {
            throw new Exception("Invalid action: " . this->action);
        }

        return call_user_func_array(i, this->params);
    }

}

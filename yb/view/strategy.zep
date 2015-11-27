namespace Yb\View;

use Yb\Factory\Namespaced;

class Strategy implements \ArrayAccess
{
    protected options;
    protected data;
    protected view;

    public function __construct(array options = [], array data = [], var view = null) -> void
    {
        let this->options = options;
        let this->data = data;
        let this->view = view;
    }

    public function setView(var view) -> void
    {
        let this->view = view;
    }

    public function getView()
    {
        return this->view;
    }

    public function __invoke() -> void
    {
        var view;

        let view = this->view;

        if typeof view != "object" {
            let view = (new Namespaced(__NAMESPACE__))->__get((string) view);
        }

        if unlikely typeof view != "object" || ! (view instanceof ViewInterface) {
            throw new Exception("Invalid view");
        }

        view->run(this->data, this->options);
    }

    public function setOptions(array options) -> void
    {
        var k, v;

        for k, v in options {
            let this->options[k] = v;
        }
    }

    public function __set(string key, var value) -> void
    {
        let this->options[key] = value;
    }

    public function __get(string key)
    {
        var value;

        if fetch value, this->options[key] {
            return value;
        }
    }

    public function __isset(string key) -> bool
    {
        return isset this->options[key];
    }

    public function __unset(string key) -> void
    {
        unset this->options[key];
    }

    public function setData(array data) -> void
    {
        var k, v;

        for k, v in data {
            let this->data[k] = v;
        }
    }

    public function offsetSet(string key, var value) -> void
    {
        let this->data[key] = value;
    }

    public function offsetGet(string key)
    {
        var value;

        if fetch value, this->data[key] {
            return value;
        }
    }

    public function offsetExists(string key) -> bool
    {
        return isset this->data[key];
    }

    public function offsetUnset(string key) -> void
    {
        unset this->data[key];
    }

}

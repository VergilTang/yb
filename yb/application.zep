namespace Yb;

class Application
{
    protected serviceObjects;
    protected serviceConfigs;

    public function __invoke() -> void
    {
    }

    public function __call(string name, array config) -> void
    {
        let this->serviceConfigs[name] = config;
    }

    public function __get(string name)
    {
        var obj, config, closure, isShared;

        if fetch obj, this->serviceObjects[name] {
            return obj;
        }

        if unlikely ! fetch config, this->serviceConfigs[name] {
            throw new Exception("Invalid service: " . name);
        }

        let closure = array_shift(config);
        let isShared = array_shift(config);

        if unlikely ! is_callable(closure) {
            throw new Exception("Invalid service config: " . name);
        }

        let obj = call_user_func(closure, this);

        if isShared !== false {
            let this->serviceObjects[name] = obj;
        }

        return obj;
    }

    public function __set(string name, var obj) -> void
    {
        let this->serviceObjects[name] = obj;
    }

    public function __isset(string name) -> boolean
    {
        return isset this->serviceObjects[name] || isset this->serviceConfigs[name];
    }

    public function __unset(string name) -> void
    {
        unset(this->serviceObjects[name]);
        unset(this->serviceConfigs[name]);
    }

}

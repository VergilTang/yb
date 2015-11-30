namespace Yb;

class Application implements \ArrayAccess
{
    protected configs;
    protected data;
    protected services;
    protected serviceInitializers;

    public function __construct(array configs = []) -> void
    {
        let this->configs = configs;
    }

    public function config(string name, var defaultValue = null)
    {
        return Std::valueOf(this->configs, name, defaultValue);
    }

    public function mergeConfigs(array configs) -> void
    {
        let this->configs = array_replace_recursive(this->configs, configs);
    }

    public function mergeConfigsInPathIfValid(string path) -> void
    {
        var configs;

        if ! file_exists(path) {
            return;
        }

        let configs = require path;

        if typeof configs != "array" {
            return;
        }

        this->mergeConfigs(configs);
    }

    public function offsetGet(string key)
    {
        var value;

        if fetch value, this->data[key] {
            return value;
        }
    }

    public function offsetSet(string key, var value) -> void
    {
        let this->data[key] = value;
    }

    public function offsetExists(string key) -> bool
    {
        return isset this->data[key];
    }

    public function offsetUnset(string key) -> void
    {
        unset this->data[key];
    }

    public function __invoke(string name, var initializer = null) -> void
    {
        let this->serviceInitializers[name] = initializer;
    }

    public function __get(string name)
    {
        var service, initializer;

        if fetch service, this->services[name] {
            return service;
        }

        if unlikely ! fetch initializer, this->serviceInitializers[name] {
            throw new Exception("Invalid service: " . name);
        }

        loop {
            if initializer === null {
                let service = new {name}();
                break;
            }

            if typeof initializer == "object" && (initializer instanceof \Closure) {
                let service = {initializer}(this);
                break;
            }

            throw new Exception("Invalid service initializer: " . name);
        }

        let this->services[name] = service;

        return service;
    }

    public function __set(string name, var obj) -> void
    {
        let this->services[name] = obj;
    }

    public function __isset(string name) -> bool
    {
        return isset this->services[name] || isset this->serviceInitializers[name];
    }

    public function __unset(string name) -> void
    {
        unset(this->services[name]);
        unset(this->serviceInitializers[name]);
    }

}

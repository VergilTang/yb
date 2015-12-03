namespace Yb;

class Application extends Di
{
    protected configs;

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

}

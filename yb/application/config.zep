namespace Yb\Application;

class Config
{
    protected dirs;
    protected exts;
    protected configs;

    public function __construct(array dirs, array exts = ["php", "local.php"]) -> void
    {
        var i;

        if unlikely count(exts) < 1 {
            throw new Exception("Empty exts");
        }

        for i in dirs {
            let this->dirs[i] = i;
        }
        for i in exts {
            let this->exts[i] = i;
        }
    }

    public function addDir(string dir) -> void
    {
        let this->dirs[dir] = dir;
        let this->configs = [];
    }

    public function __get(string name)
    {
        var config;
        var d, e;
        string p;
        var c;

        if fetch config, this->configs[name] {
            return config;
        }

        let config = [];
        for d in this->dirs {
            for e in this->exts {
                let p = d . "/" . name . "." . e;
                if file_exists(p) {
                    let c = require p;
                    if typeof c == "array" {
                        let config = array_replace_recursive(config, c);
                    }
                }
            }
        }

        let this->configs[name] = config;
        return config;
    }

    public function get(string name, var defaultValue = null)
    {
        var parts, part, returnValue, tmpValue;

        let parts = explode('.', name);
        let returnValue = this->__get((string) array_shift(parts));

        for part in parts {
            if typeof returnValue != "array" || ! fetch tmpValue, returnValue[part] {
                return defaultValue;
            }

            let returnValue = tmpValue;
        }

        return returnValue;
    }

}

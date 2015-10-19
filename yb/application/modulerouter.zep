namespace Yb\Application;

class ModuleRouter implements ApplicationFilterInterface
{
    protected modules;

    public function __construct(array modules) -> void
    {
        let this->modules = modules;
    }

    public function filterApplication(<Core> core) -> void
    {
        var m, mo, httpHost;

        if PHP_SAPI == "cli" {
            if unlikely ! fetch m, this->modules["cli"] {
                throw new Exception("Cannot run application in cli mode");
            }
        } else {
            if unlikely ! fetch httpHost, _SERVER["HTTP_HOST"] {
                throw new Exception("Cannot find http host");
            }

            if ! fetch m, this->modules[httpHost] {
                if ! fetch m, this->modules["default"] {
                    throw new Exception("Cannot match module to http host and no default module");
                }
            }
        }

        let mo = core->__get(m);
        if typeof mo != "object" || ! (mo instanceof ApplicationFilterInterface) {
            throw new Exception("Invalid module: " . m);
        }

        core->__set("module", mo);
        mo->filterApplication(core);
    }

}

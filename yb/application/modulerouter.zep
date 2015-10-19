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
        var module, moduleObject, httpHost;

        if PHP_SAPI == "cli" {
            if unlikely ! fetch module, this->modules["cli"] {
                throw new Exception("Cannot run application in cli mode");
            }
        } else {
            if unlikely ! fetch httpHost, _SERVER["HTTP_HOST"] && ! fetch module, this->modules[httpHost]
                && ! fetch module, this->modules["default"] {
                throw new Exception("Cannot match module to http host and no default module");
            }
        }

        let moduleObject = core->__get((string) module);
        if typeof moduleObject != "object" || ! (moduleObject instanceof ApplicationFilterInterface) {
            throw new Exception("Invalid module: " . module);
        }

        core->__set("module", moduleObject);
        moduleObject->filterApplication(core);
    }

}

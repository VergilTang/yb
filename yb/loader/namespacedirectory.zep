namespace Yb\Loader;

class NamespaceDirectory extends LoaderAbstract
{
    protected namespaceDirectories;
    protected lowerCase;

    public function __construct(array namespaceDirectories = [], boolean lowerCase = false) -> void
    {
        var n, d;

        for n, d in namespaceDirectories {
            let this->namespaceDirectories[strtolower(n)] = d;
        }

        let this->lowerCase = lowerCase;
    }

    public function __invoke(string className) -> boolean
    {
        var match, pos, dir;
        boolean found = false;
        string path;

        let match = className->lower();
        loop {
            let pos = strrpos(match, "\\");
            if pos === false || pos < 1 {
                break;
            }
            let match = substr(match, 0, pos);
            if fetch dir, this->namespaceDirectories[match] {
                let found = true;
                break;
            }
        }

        if ! found {
            return false;
        }

        let path = (string) substr(className, pos + 1);
        if this->lowerCase {
            let path = path->lower();
        }
        let path = dir . "/" . str_replace("\\", "/", path) . ".php";

        if ! file_exists(path) {
            return false;
        }

        require path;

        if unlikely ! class_exists(className, false) {
            throw new Exception("Cannot find class: " . className . ", in path: " . path);
        }

        return true;
    }

    public function set(string ns, string dir) -> void
    {
        let this->namespaceDirectories[ns->lower()] = dir;
    }

}

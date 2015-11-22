namespace Yb\Upload;

use Yb\Std;

abstract class StorageAbstract
{
    const COPY                  = 0;
    const MOVE                  = 1;
    const MOVE_UPLOADED_FILE    = 2;

    abstract public function store(string source, string group = "", string extension = "", long flag = 0) -> string;
    abstract public function remove(string uri) -> bool;

    public function generateUri(string source, string group, string extension) -> string
    {
        string uri = "/";

        if group && preg_match("#^\\w+(/\\w+)*$#", group) {
            let uri .= group . "/";
        }

        let uri .= Std::uuid();

        if extension {
            let uri .= "." . extension;
        }

        return uri;
    }

}

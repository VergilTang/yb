namespace Yb\Upload;

use Yb\Std;

abstract class StorageAbstract
{
    const COPY                  = 0;
    const MOVE                  = 1;
    const MOVE_UPLOADED_FILE    = 2;

    abstract public function store(string source, string prefix = "", string extension = "", long flag = 0) -> string;
    abstract public function remove(string uri) -> bool;
    abstract public function exists(string uri) -> bool;

    public function generateUri(string source, string prefix, string extension) -> string
    {
        string uri = "/";

        if prefix->length() > 0 && preg_match("#^\\w[/\\w]+*$#", prefix) {
            let uri .= prefix;
        }

        let uri .= Std::uuid();

        if extension {
            let uri .= "." . extension;
        }

        return uri;
    }

}

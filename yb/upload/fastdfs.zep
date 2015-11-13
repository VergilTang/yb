namespace Yb\Upload;

class Fastdfs extends StorageAbstract
{
    protected groupStorages;

    public static function isSupported() -> boolean
    {
        return function_exists("fastdfs_client_version");
    }

    public function __construct(array groupStorages = []) -> void
    {
        if unlikely ! self::isSupported() {
            throw new Exception("Missing extension: fastdfs_client");
        }

        let this->groupStorages = groupStorages;
    }

    public function store(string source, string group = "", string extension = "", long flag = 0) -> string
    {
        var extensionArg = null, groupArg, destUri;

        if extension {
            let extensionArg = extension;
        }
        if ! fetch groupArg, this->groupStorages[group] {
            let groupArg = null;
        }

        let destUri = fastdfs_storage_upload_by_filename1(source, extensionArg, [], groupArg);
        if destUri === false {
            return "";
        }

        switch flag {
            case StorageAbstract::MOVE_UPLOADED_FILE:
            case StorageAbstract::MOVE:
                unlink(source);
                break;
        }

        return "/" . destUri;
    }

    public function remove(string uri) -> boolean
    {
        return fastdfs_storage_delete_file1(ltrim(uri, "/"));
    }

}
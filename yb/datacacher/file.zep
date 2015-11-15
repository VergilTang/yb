namespace Yb\DataCacher;

class File implements DataCacherInterface
{
    protected path;

    public function __construct(string path) -> void
    {
        let this->path = path;
    }

    public function storeData(var data) -> void
    {
        if unlikely ! file_put_contents(this->path, sprintf("<?php return %s;", var_export(data, true)), LOCK_EX) {
            throw new Exception("Cannot write data to path: " . this->path);
        }
    }

    public function fetchData()
    {
        if file_exists(this->path) {
            return require this->path;
        }
    }

    public function forgetData() -> void
    {
        if unlikely file_exists(this->path) && ! unlink(this->path) {
            throw new Exception("Cannot forget data in path: " . this->path);
        }
    }

}

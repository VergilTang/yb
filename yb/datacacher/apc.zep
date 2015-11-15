namespace Yb\DataCacher;

class Apc implements DataCacherInterface
{
    protected cacheKey;

    public function __construct(string cacheKey) -> void
    {
        if unlikely ! extension_loaded("apc") {
            throw new Exception("Missing extension: apc");
        }

        let this->cacheKey = cacheKey;
    }

    public function storeData(var data) -> void
    {
        if unlikely ! apc_store(this->cacheKey, data) {
            throw new Exception("Cannot store data: apc_store");
        }
    }

    public function fetchData()
    {
        var data, success = null;

        let data = apc_fetch(this->cacheKey, success);
        if success {
            return data;
        }
    }

    public function forgetData() -> void
    {
        if unlikely ! apc_delete(this->cacheKey) {
            throw new Exception("Cannot forget data: apc_delete");
        }
    }

}

namespace Yb\DataCacher;

interface DataCacherInterface
{
    public function storeData(var data) -> void;
    public function fetchData();
    public function forgetData() -> void;

}

namespace Yb\View;

interface ViewInterface
{
    public function run(array data, array options) -> void;

}

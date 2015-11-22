namespace Yb\Factory;

interface FactoryInterface
{
    public function has(string name) -> bool;
    public function get(string name);

}

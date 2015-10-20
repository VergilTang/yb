namespace Yb\Factory;

interface FactoryInterface
{
    public function has(string name) -> boolean;
    public function get(string name);

}

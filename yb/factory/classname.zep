namespace Yb\Factory;

abstract class ClassName implements FactoryInterface
{
    public function has(string name) -> boolean
    {
        return class_exists(this->getClassName(name));
    }

    public function get(string name)
    {
        string className;

        let className = (string) this->getClassName(name);
        if unlikely ! class_exists(className) {
            throw new Exception("Invalid product: " . name);
        }

        return new {className}();
    }

    abstract protected function getClassName(string name) -> string;

}

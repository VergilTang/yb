namespace Yb\Factory;

use Yb\Std;

abstract class ClassName implements FactoryInterface
{
    protected args;

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

        if count(this->args) < 1 {
            return new {className}();
        }

        return Std::newInstanceOf(className, this->args);
    }

    public function args() -> void
    {
        let this->args = func_get_args();
    }

    public function arg(var arg, long index = -1) -> void
    {
        long c;

        if index > -1 {
            let c = count(this->args);
            loop {
                if c >= index {
                    break;
                }
                let c++;
                let this->args[] = null;
            }
        }

        let this->args[] = arg;
    }

    public function getArgArray() -> array
    {
        if count(this->args) > 0 {
            return this->args;
        }

        return [];
    }

    abstract protected function getClassName(string name) -> string;

}

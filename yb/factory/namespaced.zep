namespace Yb\Factory;

class Namespaced extends ClassName
{
    protected ns;

    public function __construct(string ns) -> void
    {
        let this->ns = ns;
    }

    protected function getClassName(string name) -> string
    {
        return this->ns . "\\" . ucfirst(name);
    }

}

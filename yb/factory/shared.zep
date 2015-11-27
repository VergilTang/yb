namespace Yb\Factory;

class Shared implements FactoryInterface
{
    protected realFactory;
    protected productions;

    public function __construct(<FactoryInterface> realFactory) -> void
    {
        let this->realFactory = realFactory;
    }

    public function __isset(string name) -> bool
    {
        if isset this->productions[name] {
            return true;
        }

        return this->realFactory->__isset(name);
    }

    public function __get(string name)
    {
        var production;

        if fetch production, this->productions[name] {
            return production;
        }

        let production = this->realFactory->__get(name);
        let this->productions[name] = production;

        return production;
    }

}

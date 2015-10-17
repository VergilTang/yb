namespace Yb\Loader;

abstract class LoaderAbstract
{
    public function register() -> boolean
    {
        return spl_autoload_register(this);
    }

    public function unregister() -> boolean
    {
        return spl_autoload_unregister(this);
    }

    abstract public function __invoke(string className) -> boolean;

}

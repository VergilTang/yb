namespace Yb\Loader;

abstract class LoaderAbstract
{
    public static function isLoaded(string name) -> boolean
    {
        boolean x = false;

        if class_exists(name, x) {
            return true;
        }

        if interface_exists(name, x) {
            return true;
        }

        if function_exists("trait_exists") && trait_exists(name, x) {
            return true;
        }

        return x;
    }

    public function __construct(boolean registerSelf = false) -> void
    {
        if unlikely registerSelf && ! this->register() {
            throw new Exception("Cannot register loader");
        }
    }

    public function register() -> boolean
    {
        return spl_autoload_register(this);
    }

    public function unregister() -> boolean
    {
        return spl_autoload_unregister(this);
    }

    abstract public function __invoke(string name) -> boolean;

}

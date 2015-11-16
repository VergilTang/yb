namespace Yb\Factory;

class Generated extends ClassName
{
    protected classNameGenerator;

    public function __construct(var classNameGenerator) -> void
    {
        if unlikely ! is_callable(classNameGenerator) {
            throw new Exception("Class name generator is not callable");
        }

        let this->classNameGenerator = classNameGenerator;
    }

    protected function getClassName(string name) -> string
    {
        var classNameGenerator;

        let classNameGenerator = this->classNameGenerator;
        return (string) {classNameGenerator}(name);
    }

}

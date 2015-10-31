namespace Yb\Logger;

class NullLogger extends LoggerAbstract
{
    public function log(string level, string message, array context = []) -> void
    {
        return;
    }

}

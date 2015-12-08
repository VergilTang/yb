namespace Yb\Logger;

interface LoggerBackendInterface
{
    public function log(string level, string message, array context = []) -> void;

}

namespace Yb\Logger;

use Yb\Std;

class FileLogger extends LoggerAbstract
{
    protected path;

    public function __construct(string path) -> void
    {
        let this->path = path;
    }

    public function log(string level, string message, array context = []) -> void
    {
        let this->logs[] = sprintf(
            "[%s] [%s] %s\n",
            date("c"),
            level,
            Std::tr(message, context)
        );
    }

    public function flush() -> void
    {
        if ! this->logs {
            return;
        }

        if unlikely ! file_put_contents(this->path, implode("", this->logs), LOCK_EX | FILE_APPEND) {
            throw new Exception("Cannot append logs to file: " . this->path);
        }

        let this->logs = null;
    }

}

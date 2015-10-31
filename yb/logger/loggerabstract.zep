namespace Yb\Logger;

abstract class LoggerAbstract
{
    const EMERGENCY = "emergency";
    const ALERT     = "alert";
    const CRITICAL  = "critical";
    const ERROR     = "error";
    const WARNING   = "warning";
    const NOTICE    = "notice";
    const INFO      = "info";
    const DEBUG     = "debug";

    protected logs;

    public function emergency(string message, array context = []) -> void
    {
        this->log(self::EMERGENCY, message, context);
    }

    public function alert(string message, array context = []) -> void
    {
        this->log(self::ALERT, message, context);
    }

    public function critical(string message, array context = []) -> void
    {
        this->log(self::CRITICAL, message, context);
    }

    public function error(string message, array context = []) -> void
    {
        this->log(self::ERROR, message, context);
    }

    public function warning(string message, array context = []) -> void
    {
        this->log(self::WARNING, message, context);
    }

    public function notice(string message, array context = []) -> void
    {
        this->log(self::NOTICE, message, context);
    }

    public function info(string message, array context = []) -> void
    {
        this->log(self::INFO, message, context);
    }

    public function debug(string message, array context = []) -> void
    {
        this->log(self::DEBUG, message, context);
    }

    abstract public function log(string level, string message, array context = null) -> void;

    public function flush() -> void
    {
        return;
    }

    public function __destruct() -> void
    {
        try {
            this->flush();
        }

        return;
    }

}

namespace Yb\Redis;

use Yb\Std;
use Yb\Socket\TcpClient;

class Connection
{
    const DEFAULT_HOST              = "127.0.0.1";
    const DEFAULT_PORT              = 6379;
    const DEFAULT_CONNECT_TIMEOUT   = 5;
    const DEFAULT_TIMEOUT           = 2.0;
    const DEFAULT_PERSISTENT        = false;

    protected socket;

    public function __construct(array options = []) -> void
    {
        string host;
        long port, connectTimeout;
        boolean persistent;
        double timeout;
        var socket;

        let host = (string) Std::valueAt(options, "host", self::DEFAULT_HOST);
        let port = (long) Std::valueAt(options, "port", self::DEFAULT_PORT);
        let connectTimeout = (long) Std::valueAt(options, "connectTimeout", self::DEFAULT_CONNECT_TIMEOUT);
        let persistent = (boolean) Std::valueAt(options, "persistent", self::DEFAULT_PERSISTENT);
        let timeout = (double) Std::valueAt(options, "timeout", self::DEFAULT_TIMEOUT);

        let socket = new TcpClient(host, port, connectTimeout, persistent);
        socket->setTcpNodelay(true);
        socket->setBlocking(true);
        if timeout > 0 {
            socket->setTimeout(timeout);
        }

        let this->socket = socket;
    }

    public function getSocket()
    {
        return this->socket;
    }

    public function __call(string method, array args)
    {
        var cmd;

        let cmd = args;
        array_unshift(cmd, method);

        return this->runCommand(cmd);
    }

    public function runCommand(array cmd)
    {
        this->write(cmd);
        return this->read();
    }

    public function runCommands(array cmds) -> array
    {
        var index, cmd, results = [];

        for cmd in cmds {
            this->write(cmd);
        }

        for index, _ in cmds {
            let results[index] = this->read();
        }

        return results;
    }

    protected function write(var data) -> void
    {
        var d;

        if typeof data != "array" {
            let d = (string) data;
            this->socket->write(sprintf("$%d\r\n%s\r\n", strlen(d), d));

            return;
        }

        this->socket->write(sprintf("*%d\r\n", count(data)));

        for d in data {
            this->write(d);
        }
    }

    protected function read()
    {
        string line;
        char c;
        long l;
        var a;

        let line = (string) this->socket->readLine();
        let l = line->length();
        if unlikely l < 2 || line[l - 2] != '\r' || line[l - 1] != '\n' {
            throw new Exception("Invalid line end: " . json_encode(line));
        }
        let c = line[0];
        let line = (string) substr(line, 1, -2);

        switch c {
            case '+':
                return line;

            case '-':
                return this->newError(line);

            case ':':
                if line > PHP_INT_MAX {
                    return line;
                }
                return intval(line);

            case '$':
                let l = intval(line);
                if l < 0 {
                    return;
                }
                let line = (string) this->socket->readLength(l + 2);
                let l = line->length();
                if unlikely l < 2 || line[l - 2] != '\r' || line[l - 1] != '\n' {
                    throw new Exception("Invalid line end: " . json_encode(line));
                }
                return substr(line, 0, -2);

            case '*':
                let l = intval(line);
                if l < 0 {
                    return;
                }
                let a = [];
                loop {
                    if l <= 0 {
                        break;
                    }
                    let l--;
                    let a[] = this->read();
                }
                return a;

            default:
                throw new Exception("Invalid line type: " . json_encode(line));
        }
    }

    protected function newError(string error) -> <Error>
    {
        var m = null, e;

        if preg_match("#^(MOVED|ASK) (\\d+) ([\\d\\.]+):(\\d+)$#", error, m) {
            switch error[0] {
                case 'M':
                    let e = new ErrorMoved();
                    let e->error = error;
                    let e->slot = m[2];
                    let e->host = m[3];
                    let e->port = m[4];
                    return e;

                case 'A':
                    let e = new ErrorAsk();
                    let e->error = error;
                    let e->slot = m[2];
                    let e->host = m[3];
                    let e->port = m[4];
                    return e;
            }
        }

        let e = new Error();
        let e->error = error;
        return e;
    }

}

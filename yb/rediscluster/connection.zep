namespace Yb\RedisCluster;

use Yb\Std;

class Connection
{
    const DEFAULT_HOST          = "127.0.0.1";
    const DEFAULT_PORT          = 6379;
    const DEFAULT_TIMEOUT       = 5;
    const DEFAULT_PERSISTENT    = false;

    protected handler;

    public function __construct(array options = []) -> void
    {
        string host;
        long port, timeout;
        boolean persistent;
        var handler, errStr = null;

        let host = (string) Std::valueAt(options, "host", self::DEFAULT_HOST);
        let port = (long) Std::valueAt(options, "port", self::DEFAULT_PORT);
        let timeout = (long) Std::valueAt(options, "timeout", self::DEFAULT_TIMEOUT);
        let persistent = (boolean) Std::valueAt(options, "persistent", self::DEFAULT_PERSISTENT);

        if persistent {
            let handler = pfsockopen(host, port, null, errStr, timeout);
        } else {
            let handler = fsockopen(host, port, null, errStr, timeout);
        }

        if unlikely ! handler {
            throw new SocketException("Cannot open socket: " . errStr);
        }

        if unlikely ! stream_set_blocking(handler, 1) {
            throw new SocketException("Cannot set blocking socket");
        }

        let this->handler = handler;
    }

    public function getInternalHandler()
    {
        return this->handler;
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

    public function __destruct() -> void
    {
        if this->handler {
            fclose(this->handler);
        }
    }

    protected function write(var data) -> void
    {
        var d, s;

        if typeof data == "array" {
            let s = sprintf("*%d\r\n", count(data));

            if unlikely fwrite(this->handler, s) === false {
                throw new SocketException("Cannot write to socket");
            }

            for d in data {
                this->write(d);
            }

            return;
        }

        let d = (string) data;
        let s = sprintf("$%d\r\n%s\r\n", strlen(d), d);

        if unlikely fwrite(this->handler, s) === false {
            throw new SocketException("Cannot write to socket");
        }
    }

    protected function read()
    {
        string line;
        char c;
        long l;
        var a;

        let line = (string) this->readLine();

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
                let line = (string) this->readLine(l + 2);
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

    protected function readLine(long len = 0) -> string
    {
        var line;
        string s;

        if len > 0 {
            let line = stream_get_contents(this->handler, len);
        } else {
            let line = fgets(this->handler);
        }

        if line === false {
            throw new SocketException("Cannot read from socket");
        }

        let s = (string) line;
        let len = s->length();

        if unlikely s[len - 2] != '\r' || s[len - 1] != '\n' {
            throw new Exception("Invalid line end: " . json_encode(line));
        }

        return s;
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

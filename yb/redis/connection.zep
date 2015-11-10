namespace Yb\Redis;

class Connection
{
    protected handler;

    public function __construct(string host = "127.0.0.1", long port = 6379, long timeout = 5) -> void
    {
        var handler;

        let handler = fsockopen(host, port, null, null, timeout);
        if unlikely ! handler {
            throw new SocketException("Cannot open socket");
        }

        if unlikely ! stream_set_blocking(handler, 1) {
            throw new SocketException("Cannot set blocking socket");
        }

        let this->handler = handler;
    }

    public function __destruct() -> void
    {
        if this->handler {
            fclose(this->handler);
        }
    }

    public function __call(string method, array args)
    {
        var cmd;

        let cmd = args;
        array_unshift(cmd, method);
        this->write(cmd);

        return this->read();
    }

    public function __invoke(array cmds) -> array
    {
        var cmd, results = [];
        long c = 0;

        for cmd in cmds {
            this->write(cmd);
            let c++;
        }

        loop {
            if c <= 0 {
                break;
            }
            let c--;
            let results[] = this->read();
        }

        return results;
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
                throw new RedisException(line);

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
                let line = (string) this->readLine();
                if line->length() != l + 2 {
                    throw new Exception("Invalid bulk string");
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
                throw new Exception("Invalid line type: " . chr(c));
        }
    }

    protected function readLine() -> string
    {
        var line;
        string s;
        long len;

        let line = fgets(this->handler);
        if line === false {
            throw new SocketException("Cannot read from socket");
        }

        let s = (string) line;
        let len = s->length();

        if unlikely s[len - 2] != '\r' || s[len - 1] != '\n' {
            throw new Exception("Invalid line end");
        }

        return s;
    }

}

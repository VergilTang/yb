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

    public function getInternalHandler()
    {
        return this->handler;
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

    protected function newError(string error) -> <ErrorBase>
    {
        var m, e;

        if preg_match("#^(MOVED|ASK) (\d+) ([\\d\\.]+):(\\d+)$#", error, m) {
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

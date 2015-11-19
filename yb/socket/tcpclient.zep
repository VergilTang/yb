namespace Yb\Socket;

class TcpClient
{
    protected handler;

    public function __construct(string host, long port, long timeout = 5, boolean persistent = false) -> void
    {
        string address;
        long flags;
        var handler, errNo = null, errStr = null;

        let address = (string) sprintf("tcp://%s:%d", host, port);
        let flags = (long) STREAM_CLIENT_CONNECT;
        if persistent {
            let flags = flags | (long) STREAM_CLIENT_PERSISTENT;
        }

        let handler = stream_socket_client(address, errNo, errStr, timeout, flags);
        if unlikely ! handler {
            throw new Exception("Cannot connect to " . address . " [" . errNo . "]" . errStr);
        }

        let this->handler = handler;
    }

    public function __destruct() -> void
    {
        if this->handler {
            fclose(this->handler);
        }
    }

    public function getInternalHandler()
    {
        return this->handler;
    }

    public function setTcpNodelay(boolean on) -> void
    {
        var socket;

        if unlikely ! function_exists("socket_import_stream") {
            throw new Exception("Not supported: socket_import_stream");
        }

        let socket = socket_import_stream(this->handler);
        if unlikely ! socket {
            throw new Exception("Failed: socket_import_stream");
        }

        if unlikely ! socket_set_option(socket, SOL_TCP, TCP_NODELAY, on ? 1 : 0) {
            throw new Exception("Cannot set SOL_TCP TCP_NODELAY");
        }
    }

    public function setBlocking(boolean on) -> void
    {
        if unlikely ! stream_set_blocking(this->handler, on ? 1 : 0) {
            throw new Exception("Cannot set blocking");
        }
    }

    public function setIoTimeout(double ioTimeout) -> void
    {
        long ioTimeoutSeconds, ioTimeoutMicroSeconds;

        if unlikely ioTimeout < 0 {
            throw new Exception("Cannot set io timeout to negative value");
        }

        let ioTimeoutSeconds = (long) ioTimeout;
        let ioTimeoutMicroSeconds = (long) ((ioTimeout - ioTimeoutSeconds) * 1000000.0);

        if unlikely ! stream_set_timeout(this->handler, ioTimeoutSeconds, ioTimeoutMicroSeconds) {
            throw new Exception("Failed: stream_set_timeout");
        }
    }

    public function enableCrypto(var cryptoType) -> void
    {
        if unlikely ! stream_socket_enable_crypto(this->handler, true, cryptoType) {
            throw new Exception("Failed: stream_socket_enable_crypto");
        }
    }

    public function write(string data) -> void
    {
        if unlikely fwrite(this->handler, data) === false {
            throw new Exception("Cannot write");
        }
    }

    public function readLine() -> string
    {
        var line;

        let line = fgets(this->handler);
        if unlikely line === false {
            throw new Exception("Cannot read line");
        }

        return line;
    }

    public function readAll() -> string
    {
        var line;

        let line = stream_get_contents(this->handler);
        if unlikely line === false {
            throw new Exception("Cannot read all");
        }

        return line;
    }

    public function readLength(long len) -> string
    {
        var line;

        if unlikely len < 1 {
            throw new Exception("Invalid read length: " . strval(len));
        }

        let line = stream_get_contents(this->handler, len);
        if unlikely line === false {
            throw new Exception("Cannot read length");
        }

        return line;
    }

    public function readMaxLength(long len) -> string
    {
        var line;

        if unlikely len < 1 {
            throw new Exception("Invalid read max length: " . strval(len));
        }

        let line = fread(this->handler, len);
        if unlikely line === false {
            throw new Exception("Cannot read max length");
        }

        return line;
    }

}

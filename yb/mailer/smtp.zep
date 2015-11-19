namespace Yb\Mailer;

use Yb\Std;
use Yb\Socket\TcpClient;

class Smtp implements MailerInterface
{
    const CRLF = "\r\n";

    protected socket;
    protected from;

    public function __construct(array options) -> void
    {
        string host, user, passwd, from, name;
        long port, timeout;
        double ioTimeout;
        boolean secure;
        var socket;

        let host = (string) Std::valueAt(options, "host");
        let user = (string) Std::valueAt(options, "user");
        let passwd = (string) Std::valueAt(options, "passwd");

        let from = (string) Std::valueAt(options, "from", user);
        let name = (string) Std::valueAt(options, "name", "");
        let timeout = (long) Std::valueAt(options, "timeout", 10);
        let ioTimeout = (double) Std::valueAt(options, "ioTimeout", 5);
        let secure = (boolean) Std::valueAt(options, "secure", false);

        if secure {
            let port = (long) Std::valueAt(options, "port", 465);
        } else {
            let port = (long) Std::valueAt(options, "port", 25);
        }

        let socket = new TcpClient(host, port, timeout, false);

        socket->setTcpNodelay(true);
        socket->setBlocking(true);

        if ioTimeout > 0 {
            socket->setIoTimeout(ioTimeout);
        }
        if secure {
            socket->enableCrypto(constant("STREAM_CRYPTO_METHOD_SSLv23_CLIENT"));
        }

        let this->socket = socket;
        let this->from = this->pack(name, from);

        this->cmd("CONNECT", "", 220);
        this->cmd("EHLO HELO", "EHLO HELO", 250);
        this->cmd("AUTH LOGIN", "AUTH LOGIN", 334);
        this->cmd("AUTH USER", base64_encode(user), 334);
        this->cmd("AUTH PASSWD", base64_encode(passwd), 235);
    }

    public function sendMessageTo(array message, array to, array cc = [], array bcc = []) -> void
    {
        var data = [], temp, addr, name, attachments, path, mine, type, subject, plain;
        string boundary;

        this->cmd("MAIL FROM", "MAIL FROM: " . this->from, 250);
        let data[] = "FROM: " . this->from;

        if count(to) < 1 {
            throw new Exception("No one to send");
        }

        let temp = [];
        for addr, name in to {
            let name = this->pack(name, addr);
            let temp[] = name;
            this->cmd("RCPT TO", "RCPT TO: " . name, 250);
        }
        let data[] = "TO: " . join(",", temp);

        if count(cc) > 0 {
            let temp = [];
            for addr, name in cc {
                let name = this->pack(name, addr);
                let temp[] = name;
                this->cmd("RCPT TO", "RCPT TO: " . name, 250);
            }
            let data[] = "CC: " . join(",", temp);
        }
        if count(bcc) > 0 {
            let temp = [];
            for addr, name in bcc {
                let name = this->pack(name, addr);
                let temp[] = name;
                this->cmd("RCPT TO", "RCPT TO: " . name, 250);
            }
            let data[] = "BCC: " . join(",", temp);
        }

        if fetch subject, message["subject"] {
            let data[] = "Subject: " . this->pack(subject);
        }

        let data[] = "Date: " . gmdate("r");

        if fetch attachments, message["attachments"] && typeof attachments == "array" && count(attachments) > 0 {
            let data[] = "Content-Type: multipart/mixed;";
        } else {
            let attachments = [];
            let data[] = "Content-Type: multipart/alternative;";
        }

        let boundary = "Boundary-" . (string) md5(uniqid(mt_rand(), true));
        let data[] = "\tboundary=\"" . boundary . "\"";
        let boundary = "--" . boundary;

        let data[] = "MIME-Version: 1.0";
        let data[] = "";

        let data[] = boundary;
        if fetch plain, message["plain"] && plain {
            let data[] = "Content-Type: text/plain; charset=UTF-8";
        } else {
            let data[] = "Content-Type: text/html; charset=UTF-8";
        }
        let data[] = "Content-Transfer-Encoding: base64";
        let data[] = "";
        let data[] = chunk_split(base64_encode(message["body"])) . boundary;

        if attachments {
            let mine = finfo_open(FILEINFO_MIME_TYPE);
            for path in attachments {
                if unlikely ! file_exists(path) {
                    throw new Exception("Cannot find attachment: " . path);
                }

                let type = finfo_file(mine, path);
                if type {
                    let data[] = "Content-Type: " . type;
                } else {
                    let data[] = "Content-Type: application/octet-stream";
                }

                let data[] = "Content-Transfer-Encoding: base64";
                let data[] = "Content-Disposition: attachment; filename=\"" . this->pack(basename(path)) . "\"";
                let data[] = "";
                let data[] = chunk_split(base64_encode(file_get_contents(path))) . boundary;
            }

            finfo_close(mine);
        }

        let data[] = ".";

        this->cmd("DATA", "DATA", 354);
        this->cmd("END DATA", join(self::CRLF, data), 250);
    }

    public function __destruct() -> void
    {
        try {
            this->cmd("QUIT", "QUIT", 221);
        }
    }

    protected function cmd(string step, string cmd, string expected) -> void
    {
        string output;

        if cmd {
            this->socket->write(cmd . self::CRLF);
        }

        let output = (string) rtrim(this->socket->readMaxLength(1024));

        if expected && strpos(output, expected) !== 0 {
            throw new Exception("Unexpected response on step: " . step . ", with output: " . output);
        }
    }

    protected function pack(string name = "", string addr = "") -> string
    {
        string s = "";

        if name {
            let s .= "=?UTF-8?B?" . base64_encode(name) . "?=";
        }
        if addr {
            let s .= "<" . addr . ">";
        }

        return s;
    }

}

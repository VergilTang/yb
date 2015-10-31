namespace Yb\Tools;

use Yb\Std;

class SmtpMailer
{
    const EOL = "\r\n";

    protected socket;
    protected from;

    public function __construct(array options) -> void
    {
        string host, user, passwd, from, name;
        long timeout, port;
        boolean secure;
        var socket;

        let host = (string) Std::valueAt(options, "host");
        let user = (string) Std::valueAt(options, "user");
        let passwd = (string) Std::valueAt(options, "passwd");
        let from = (string) Std::valueAt(options, "from", user);
        let name = (string) Std::valueAt(options, "name", "");
        let timeout = (long) Std::valueAt(options, "timeout", 10);
        let secure = (boolean) Std::valueAt(options, "secure", false);

        if secure {
            let port = (long) Std::valueAt(options, "port", 465);
            let socket = stream_socket_client(sprintf("tcp://%s:%d", host, port), null, null, timeout);
        } else {
            let port = (long) Std::valueAt(options, "port", 25);
            let socket = fsockopen(host, port, null, null, timeout);
        }

        if unlikely ! socket {
            throw new Exception("Cannot connect to mail server");
        }

        if unlikely secure
            && ! stream_socket_enable_crypto(socket, true, constant("STREAM_CRYPTO_METHOD_SSLv23_CLIENT")) {
            throw new Exception("Cannot enable crypto socket");
        }

        if unlikely ! stream_set_blocking(socket, 1) {
            throw new Exception("Cannot set blocking socket");
        }

        let this->socket = socket;
        let this->from = this->pack(name, from);

        this->cmd("CONNECT", "", 220);
        this->cmd("EHLO HELO", "EHLO HELO", 250);
        this->cmd("AUTH LOGIN", "AUTH LOGIN", 334);
        this->cmd("AUTH USER", base64_encode(user), 334);
        this->cmd("AUTH PASSWD", base64_encode(passwd), 235);
    }

    public function sendTo(array message, array to, array cc = null, array bcc = null) -> void
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
        this->cmd("END DATA", join(self::EOL, data), 250);
    }

    public function __destruct() -> void
    {
        try {
            this->cmd("QUIT", "QUIT", 221);
        }

        fclose(this->socket);
    }

    protected function cmd(string step, string cmd, string expected) -> void
    {
        string output;

        if unlikely cmd && ! fputs(this->socket, cmd . self::EOL) {
            throw new Exception("Cannot fputs to socket on step: " . step);
        }

        let output = rtrim(fread(this->socket, 1024));

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

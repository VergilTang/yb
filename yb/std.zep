namespace Yb;

class Std
{
    const CHARSET       = "UTF-8";
    const CHAR_LIST     = "0123456789abcdefghijklmnopqrstuvwxyz";

    const IGNORE_ERROR  = "Yb\\Std::ignoreError";
    const THROW_ERROR   = "Yb\\Std::throwError";

    public static function sizeToBytes(string size) -> double
    {
        var match = null;

        if preg_match("/^([\\d\\.]+)([KMGT])B?$/", size->upper(), match) {
            switch match[2] {
                case "T":
                    return 1099511627776.0 * (double) match[1];
                case "G":
                    return 1073741824.0 * (double) match[1];
                case "M":
                    return 1048576.0 * (double) match[1];
                case "K":
                    return 1024.0 * (double) match[1];
            }
        }

        return floatval(size);
    }

    public static function bytesToSize(double bytes, long decimal = 3) -> string
    {
        if decimal < 0 || decimal > 6 {
            let decimal = 3;
        }

        if bytes > 1099511627776.0 {
            return sprintf(sprintf("%%0.%dfT", decimal), bytes / 1099511627776.0);
        }
        if bytes > 1073741824.0 {
            return sprintf(sprintf("%%0.%dfG", decimal), bytes / 1073741824.0);
        }
        if bytes > 1048576.0 {
            return sprintf(sprintf("%%0.%dfM", decimal), bytes / 1048576.0);
        }
        if bytes > 1024.0 {
            return sprintf(sprintf("%%0.%dfK", decimal), bytes / 1024.0);
        }
        if bytes > 1.0 {
            return sprintf(sprintf("%%0.%dfB", decimal), bytes);
        }

        return strval(0);
    }

    public static function pascalCase(string from) -> string
    {
        string to = "";
        char c;
        boolean found = false;
        boolean upper = true;

        for c in from {
            if c >= '0' && c <= '9' {
                if found {
                    let to .= c;
                }
                continue;
            }
            if c >= 'a' && c <= 'z' {
                if upper {
                    let upper = false;
                    let c -= 32;
                }
                let to .= c;
                let found = true;
                continue;
            }
            if c >= 'A' && c <= 'Z' {
                if upper {
                    let upper = false;
                } else {
                    let c += 32;
                }
                let to .= c;
                let found = true;
                continue;
            }
            if found {
                let upper = true;
            }
        }

        return to;
    }

    public static function camelCase(string from) -> string
    {
        string to = "";
        char c;
        boolean found = false;
        boolean upper = false;

        for c in from {
            if c >= '0' && c <= '9' {
                if found {
                    let to .= c;
                }
                continue;
            }
            if c >= 'a' && c <= 'z' {
                if upper {
                    let upper = false;
                    let c -= 32;
                }
                let to .= c;
                let found = true;
                continue;
            }
            if c >= 'A' && c <= 'Z' {
                if upper {
                    let upper = false;
                } else {
                    let c += 32;
                }
                let to .= c;
                let found = true;
                continue;
            }
            if found {
                let upper = true;
            }
        }

        return to;
    }

    public static function normalCase(string from, string sep = "-") -> string
    {
        string to = "";
        char c;
        boolean found = false;

        for c in from {
            if (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') {
                let to .= c;
                let found = true;
                continue;
            }
            if c >= 'A' && c <= 'Z' {
                if found {
                    let to .= sep;
                }
                let c += 32;
                let to .= c;
                let found = true;
                continue;
            }
        }

        return to;
    }

    public static function uuid(string salt = "") -> string
    {
        return md5(uniqid(mt_rand(), true) . salt);
    }

    public static function randString(long len, string charList = "") -> string
    {
        string result = "";
        long maxIndex;

        if unlikely len < 1 {
            return "";
        }

        if charList->length() < 1 {
            let charList = self::CHAR_LIST;
        }

        let maxIndex = (long) mb_strlen(charList, self::CHARSET) - 1;

        while len {
            let len--;
            let result .= mb_substr(charList, mt_rand(0, maxIndex), 1, self::CHARSET);
        }

        return result;
    }

    public static function newInstanceOf(string className, array args = null)
    {
        long c;
        var a;

        let c = count(args);
        if c < 1 {
            return new {className}();
        }
        if c > 5 {
            return (new \ReflectionClass(className))->newInstanceArgs(args);
        }

        let a = array_values(args);
        switch c {
            case 1:
                return new {className}(a[0]);
            case 2:
                return new {className}(a[0], a[1]);
            case 3:
                return new {className}(a[0], a[1], a[2]);
            case 4:
                return new {className}(a[0], a[1], a[2], a[3]);
            case 5:
                return new {className}(a[0], a[1], a[2], a[3], a[4]);
        }

        throw new Exception("Fail to fetch a new instance of class: " . className);
    }

    public static function ignoreError(long n, string s, string f, string l, array context = null) -> void
    {
        return;
    }

    public static function throwError(long n, string s, string f, string l, array context = null) -> void
    {
        throw new \ErrorException(s . " (" . f . ":" . l . ")", n);
    }

    public static function outputScript(string path, array data) -> void
    {
        if unlikely ! file_exists(path) {
            throw new Exception("Cannot find script path: " . path);
        }

        extract(data, EXTR_PREFIX_INVALID, "");
        require path;
    }

    public static function renderScript(string path, array data) -> string
    {
        var ex;

        ob_start();
        ob_implicit_flush(false);

        try {
            self::outputScript(path, data);
            return ob_get_clean();
        } catch \Exception, ex {
            ob_end_clean();
            throw ex;
        }

        return "";
    }

}

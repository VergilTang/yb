namespace Yb\Image;

abstract class ImageBackendAbstract
{
    const DEFAULT_FONT = "";
    const DEFAULT_FONT_SIZE = 24;
    const DEFAULT_COLOR = "#000000";
    const DEFAULT_RED = 0;
    const DEFAULT_GREEN = 0;
    const DEFAULT_BLUE = 0;
    const DEFAULT_OPACITY = 0.5;
    const DEFAULT_PADDING = 5;
    const DEFAULT_R_PADDING = 0.2;
    const DEFAULT_R_OVERLAP = 0.2;

    const LEFT_TOP = 7;
    const TOP = 8;
    const RIGHT_TOP = 9;
    const LEFT = 4;
    const CENTER = 5;
    const RIGHT = 6;
    const LEFT_BOTTOM = 1;
    const BOTTOM = 2;
    const RIGHT_BOTTOM = 3;

    protected defaults;

    public function __construct(array defaults) -> void
    {
        if count(defaults) > 0 {
            this->setDefaults(defaults);
        }
    }

    public function setDefaults(array defaults) -> void
    {
        var k, v;

        for k, v in defaults {
            let this->defaults[k] = v;
        }
    }

    public function setDefault(string name, var value) -> void
    {
        let this->defaults[name] = value;
    }

    abstract public function text(string text, array options = []) -> <Text>;
    abstract public function captcha(string code, long width, long height, array options = []) -> <Image>;
    abstract public function fromImage(<Image> im) -> <Image>;
    abstract public function fromSize(long width, long height = 0, string extension = "") -> <Image>;
    abstract public function fromPath(string path, string extension = "") -> <Image>;
    abstract public function fromString(string data, string extension = "") -> <Image>;

    abstract public function resize(<Image> im, long width, long height) -> <Image>;
    abstract public function crop(<Image> im, long x, long y, long w, long h) -> <Image>;
    abstract public function thumbnail(<Image> im, long width, long height, boolean cropped) -> <Image>;
    abstract public function draw(<Image> destIm, <ImageAbstract> srcIm, long x, long y) -> <Image>;

    abstract public function save(<Image> im, string destPath) -> void;
    abstract public function destroy(<ImageAbstract> im) -> void;

    protected function validTextOptions(array options) -> array
    {
        var valid = [], merged, v, m = null;
        string s;
        long l;
        double d;

        if typeof this->defaults == "array" {
            let merged = array_merge(this->defaults, options);
        } else {
            let merged = options;
        }

        let valid["font"] = ImageBackendAbstract::DEFAULT_FONT;
        let valid["fontSize"] = ImageBackendAbstract::DEFAULT_FONT_SIZE;
        let valid["color"] = ImageBackendAbstract::DEFAULT_COLOR;
        let valid["red"] = ImageBackendAbstract::DEFAULT_RED;
        let valid["green"] = ImageBackendAbstract::DEFAULT_GREEN;
        let valid["blue"] = ImageBackendAbstract::DEFAULT_BLUE;
        let valid["opacity"] = ImageBackendAbstract::DEFAULT_OPACITY;
        let valid["padding"] = ImageBackendAbstract::DEFAULT_PADDING;

        if fetch v, merged["font"] {
            let s = (string) v;
            if s {
                let valid["font"] = s;
            }
        }
        if fetch v, merged["fontSize"] {
            let l = (long) v;
            if l > 7 {
                let valid["fontSize"] = l;
            }
        }
        if fetch v, merged["color"] {
            let s = (string) v;
            if s && preg_match("/^#([0-9a-fA-F]{2})([0-9a-fA-F]{2})([0-9a-fA-F]{2})/", s, m) {
                let valid["color"] = s;
                let valid["red"] = (long) hexdec(m[1]);
                let valid["green"] = (long) hexdec(m[2]);
                let valid["blue"] = (long) hexdec(m[3]);
            }
        }
        if fetch v, merged["opacity"] {
            let d = (double) v;
            if d >= 0 && d <= 1 {
                let valid["opacity"] = d;
            }
        }
        if fetch v, merged["padding"] {
            let l = (long) v;
            if l >= 0 {
                let valid["padding"] = l;
            }
        }

        return valid;
    }

    protected function validCaptchaOptions(array options) -> array
    {
        var valid = [], merged, v;
        string s;
        double d;

        if typeof this->defaults == "array" {
            let merged = array_merge(this->defaults, options);
        } else {
            let merged = options;
        }

        let valid["font"] = ImageBackendAbstract::DEFAULT_FONT;
        let valid["rPadding"] = ImageBackendAbstract::DEFAULT_R_PADDING;
        let valid["rOverlap"] = ImageBackendAbstract::DEFAULT_R_OVERLAP;

        if fetch v, merged["font"] {
            let s = (string) v;
            if s {
                let valid["font"] = s;
            }
        }
        if fetch v, merged["rPadding"] {
            let d = (double) v;
            if d > 0 && d < 1 {
                let valid["rPadding"] = d;
            }
        }
        if fetch v, merged["rOverlap"] {
            let d = (double) v;
            if d > 0 && d < 1 {
                let valid["rOverlap"] = d;
            }
        }

        return valid;
    }
}

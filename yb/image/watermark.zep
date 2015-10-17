namespace Yb\Image;

class Watermark extends ImageAbstract
{
    public text         = "";

    public font         = ImageAbstract::DEFAULT_FONT;
    public fontSize     = 24;
    public color        = "#000000";
    public colorRed     = 0;
    public colorGreen   = 0;
    public colorBlue    = 0;
    public opacity      = 0.5;
    public padding      = 5;

    public function setOptions(array options) -> void
    {
        var opt, m = null;
        string s;
        long l;
        double d;

        if fetch opt, options["font"] {
            let s = (string) opt;
            if s {
                let this->font = s;
            }
        }

        if fetch opt, options["fontSize"] {
            let l = (long) opt;
            if l > 7 {
                let this->fontSize = l;
            }
        }

        if fetch opt, options["color"] {
            let s = (string) opt;
            if s && preg_match("/^#([0-9a-fA-F]{2})([0-9a-fA-F]{2})([0-9a-fA-F]{2})/", s, m) {
                let this->color         = s->upper();
                let this->colorRed      = (long) hexdec(m[1]);
                let this->colorGreen    = (long) hexdec(m[2]);
                let this->colorBlue     = (long) hexdec(m[3]);
            }
        }

        if fetch opt, options["opacity"] {
            let d = (double) opt;
            if d >= 0 && d <= 1 {
                let this->opacity = d;
            }
        }

        if fetch opt, options["padding"] {
            let l = (long) opt;
            if l >= 0 {
                let this->padding = l;
            }
        }
    }

}

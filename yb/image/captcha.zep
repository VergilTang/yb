namespace Yb\Image;

class Captcha extends Image
{
    public text     = "";

    public font     = ImageAbstract::DEFAULT_FONT;
    public rPadding = 0.2;
    public rOverlap = 0.2;

    public function setOptions(array options) -> void
    {
        var opt;
        string s;
        double d;

        if fetch opt, options["font"] {
            let s = (string) opt;
            if s {
                let this->font = s;
            }
        }

        if fetch opt, options["rPadding"] {
            let d = (double) opt;
            if d > 0 && d < 1 {
                let this->rPadding = d;
            }
        }

        if fetch opt, options["rOverlap"] {
            let d = (double) opt;
            if d > 0 && d < 1 {
                let this->rOverlap = d;
            }
        }
    }

}

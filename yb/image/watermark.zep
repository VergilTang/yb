namespace Yb\Image;

class Watermark extends ImageAbstract
{
    public text     = "";

    public font     = ImageBackendAdapter::DEFAULT_FONT;
    public fontSize = ImageBackendAdapter::DEFAULT_FONTSIZE;
    public color    = ImageBackendAdapter::DEFAULT_COLOR;
    public opacity  = ImageBackendAdapter::DEFAULT_OPACITY;
    public padding  = ImageBackendAdapter::DEFAULT_PADDING;

    public function setOptions(array options) -> void
    {
        var mergedOptions, opt, m = null;
        string s;
        long l;
        double d;

        let mergedOptions = array_merge(this->backend->getDefaultOptions(), options);

        if fetch opt, mergedOptions["font"] {
            let s = (string) opt;
            if s {
                let this->font = s;
            }
        }

        if fetch opt, mergedOptions["fontSize"] {
            let l = (long) opt;
            if l > 7 {
                let this->fontSize = l;
            }
        }

        if fetch opt, mergedOptions["color"] {
            let s = (string) opt;
            if s && preg_match("/^#([0-9a-fA-F]{2})([0-9a-fA-F]{2})([0-9a-fA-F]{2})/", s, m) {
                let this->color = s->upper();
            }
        }

        if fetch opt, mergedOptions["opacity"] {
            let d = (double) opt;
            if d >= 0 && d <= 1 {
                let this->opacity = d;
            }
        }

        if fetch opt, mergedOptions["padding"] {
            let l = (long) opt;
            if l >= 0 {
                let this->padding = l;
            }
        }
    }

}

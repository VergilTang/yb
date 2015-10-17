namespace Yb\Image;

interface ImageBackendInterface
{
    public function watermark(string text, array options = []) -> <Watermark>;

    public function fromImage(<Image> im) -> <Image>;
    public function fromSize(long width, long height = 0, string extension = "") -> <Image>;
    public function fromPath(string path, string extension = "") -> <Image>;
    public function fromString(string data, string extension = "") -> <Image>;

    public function captcha(string text, long width, long height, array options = []) -> <Captcha>;

    public function resize(<Image> im, long width, long height) -> <Image>;
    public function crop(<Image> im, long x, long y, long w, long h) -> <Image>;
    public function thumbnail(<Image> im, long width, long height, boolean cropped) -> <Image>;
    public function draw(<Image> destIm, <ImageAbstract> srcIm, long x, long y) -> <Image>;

    public function save(<Image> im, string destPath) -> void;
    public function destroy(<ImageAbstract> im) -> void;

}

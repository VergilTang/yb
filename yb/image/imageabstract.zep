namespace Yb\Image;

abstract class ImageAbstract
{
    const DEFAULT_FONT = "simhei.ttf";

    const LEFT_TOP = 7;
    const TOP = 8;
    const RIGHT_TOP = 9;
    const LEFT = 4;
    const CENTER = 5;
    const RIGHT = 6;
    const LEFT_BOTTOM = 1;
    const BOTTOM = 2;
    const RIGHT_BOTTOM = 3;

    public width;
    public height;

    protected backend;

    public function __construct(<ImageBackendAbstract> backend) -> void
    {
        let this->backend = backend;
    }

    public function __destruct() -> void
    {
        this->backend->destroy(this);
    }

}

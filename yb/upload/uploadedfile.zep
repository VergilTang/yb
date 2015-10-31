namespace Yb\Upload;

class UploadedFile
{
    public error;
    public size;
    public name;
    public extension;
    public tmpName;

    protected uploader;

    public function __construct(<Uploader> uploader) -> void
    {
        let this->uploader = uploader;
    }

    public function isValid() -> boolean
    {
        return this->error === 0;
    }

    public function save(string group = "", boolean keep = false) -> string
    {
        if unlikely this->error !== 0 {
            throw new Exception("Invalid uploaded file cannot be saved");
        }

        return this->uploader->saveUploadedFile(this, group, keep);
    }

}

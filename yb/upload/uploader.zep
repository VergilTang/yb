namespace Yb\Upload;

use Yb\Std;

class Uploader
{
    const INVALID_UPLOAD    = -1;
    const SIZE_TOO_LARGE    = -2;
    const INVALID_EXTENSION = -3;

    protected validExtensions;
    protected maxSize;
    protected storage;

    public function __construct(string validExtensions, string maxSize = "2M") -> void
    {
        let this->validExtensions = array_flip(
            preg_split("#[,/\\s\\|\\.]+#", validExtensions->lower(), -1, PREG_SPLIT_NO_EMPTY)
        );

        let this->maxSize = Std::sizeToBytes(maxSize);
    }

    public function setStorage(<StorageAbstract> storage) -> void
    {
        let this->storage = storage;
    }

    public function getStorage() -> <StorageAbstract>
    {
        return this->storage;
    }

    public function newUploadedFile() -> <UploadedFile>
    {
        return new UploadedFile(this);
    }

    public function saveUploadedFile(<UploadedFile> uploadedFile, string prefix, bool keep) -> string
    {
        long flag;

        if keep {
            let flag = StorageAbstract::COPY;
        } else {
            let flag = StorageAbstract::MOVE_UPLOADED_FILE;
        }

        return this->storage->store(uploadedFile->tmpName, prefix, uploadedFile->extension, flag);
    }

    public function pick(string index) -> <UploadedFile>
    {
        var f, a, error, size, name, tmpName;

        let f = this->newUploadedFile();

        loop {
            if unlikely ! fetch a, _FILES[index] || typeof a != "array" {
                let f->error = self::INVALID_UPLOAD;
                break;
            }

            if unlikely ! fetch error, a["error"] || typeof error != "int" {
                let f->error = self::INVALID_UPLOAD;
                break;
            }
            let f->error = error;
            if unlikely error != 0 {
                break;
            }

            if unlikely ! fetch size, a["size"] || typeof size != "int" || size < 1 {
                let f->error = self::INVALID_UPLOAD;
                break;
            }
            let f->size = size;
            if unlikely this->maxSize > 0 && size > this->maxSize {
                let f->error = self::SIZE_TOO_LARGE;
                break;
            }

            if unlikely ! fetch name, a["name"] || typeof name != "string" {
                let f->error = self::INVALID_UPLOAD;
                break;
            }
            let f->name = name;

            if unlikely ! fetch tmpName, a["tmp_name"] || typeof tmpName != "string" {
                let f->error = self::INVALID_UPLOAD;
                break;
            }
            let f->tmpName = tmpName;

            let f->extension = (string) this->guessExtension(tmpName, name);
            if unlikely ! isset this->validExtensions[f->extension] {
                let f->error = self::INVALID_EXTENSION;
                break;
            }

            break;
        }

        return f;
    }

    public function pickArray(string index) -> array
    {
        var files = [], a, errors, i, e, f, size, name, tmpName;

        if unlikely ! fetch a, _FILES[index] && typeof a != "array" {
            return files;
        }

        if unlikely ! fetch errors, a["error"] && typeof errors != "array" {
            return files;
        }

        for i, e in errors {
            let f = this->newUploadedFile();

            loop {
                let f->error = e;
                if unlikely e != 0 {
                    break;
                }

                if unlikely ! fetch size, a["size"][i] || typeof size != "int" || size < 1 {
                    let f->error = self::INVALID_UPLOAD;
                    break;
                }
                let f->size = size;
                if unlikely this->maxSize > 0 && size > this->maxSize {
                    let f->error = self::SIZE_TOO_LARGE;
                    break;
                }

                if unlikely ! fetch name, a["name"][i] || typeof name != "string" {
                    let f->error = self::INVALID_UPLOAD;
                    break;
                }
                let f->name = name;

                if unlikely ! fetch tmpName, a["tmp_name"][i] || typeof tmpName != "string" {
                    let f->error = self::INVALID_UPLOAD;
                    break;
                }
                let f->tmpName = tmpName;

                let f->extension = (string) this->guessExtension(tmpName, name);
                if unlikely ! isset this->validExtensions[f->extension] {
                    let f->error = self::INVALID_EXTENSION;
                    break;
                }

                break;
            }

            let files[i] = f;
        }

        return files;
    }

    protected function guessExtension(string tmpName, string name) -> string
    {
        var eit;

        let eit = exif_imagetype(tmpName);
        if eit !== false {
            return image_type_to_extension(eit, false);
        }

        return strtolower(pathinfo(name, PATHINFO_EXTENSION));
    }

}

namespace Yb\View;

use Yb\Std;

class ReadFile implements ViewInterface
{
    public function run(array data, array options) -> void
    {
        string readFile, readFileContentType;
        var size;

        let readFile = (string) Std::valueAt(options, "readFile", "");
        if unlikely readFile->length() < 1 {
            throw new Exception("Missing option: readFile");
        }

        if unlikely ! file_exists(readFile) {
            throw new Exception("Cannot find file in path: " . readFile);
        }

        let size = filesize(readFile);
        if unlikely size === false {
            throw new Exception("Cannot get file size: " . readFile);
        }
        header("Content-Length: " . size);

        let readFileContentType = (string) Std::valueAt(options, "readFileContentType", "");
        if readFileContentType->length() > 0 {
            header("Content-Type: " . readFileContentType);
        } else {
            header("Content-Description: File Transfer");
            header("Content-Type: application/octet-stream");
            header("Content-Transfer-Encoding: binary");
        }

        if unlikely readfile(readFile) === false {
            throw new Exception("Cannot read file: " . readFile);
        }
    }

}

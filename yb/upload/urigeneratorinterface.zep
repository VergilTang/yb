namespace Yb\Upload;

interface UriGeneratorInterface
{
    public function generateUri(string source, string prefix, string extension) -> string;

}

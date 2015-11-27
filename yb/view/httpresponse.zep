namespace Yb\View;

use Yb\Std;

class HttpResponse implements ViewInterface
{
    public function run(array data, array options) -> void
    {
        long httpResponseCode;
        string httpResponseOutput;

        if unlikely ! function_exists("http_response_code") {
            throw new Exception("Not supported: http_response_code");
        }

        let httpResponseCode = (long) Std::valueAt(options, "httpResponseCode", 200);
        http_response_code(httpResponseCode);

        let httpResponseOutput = (string) Std::valueAt(options, "httpResponseOutput", "");
        echo httpResponseOutput;
    }

}

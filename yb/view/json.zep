namespace Yb\View;

use Yb\Std;

class Json implements ViewInterface
{
    public function run(array data, array options) -> void
    {
        var jsonFlag;
        string jsonCallback;
        bool jsonCors, jsonTextPlain;

        let jsonFlag = Std::valueAt(options, "jsonFlag", 0);
        let jsonCallback = (string) Std::valueAt(options, "jsonCallback", "");
        let jsonCors = (bool) Std::valueAt(options, "jsonCors", false);
        let jsonTextPlain = (bool) Std::valueAt(options, "jsonTextPlain", false);

        if jsonCors {
            header("Access-Control-Allow-Origin: *");
        }
        if jsonTextPlain {
            header("Content-type: text/plain; charset=UTF-8");
        }

        if jsonCallback->length() > 0 {
            echo sprintf("%s(%s);", jsonCallback, json_encode(data, jsonFlag));
        } else {
            echo json_encode(data, jsonFlag);
        }
    }

}

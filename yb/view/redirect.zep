namespace Yb\View;

use Yb\Std;

class Redirect implements ViewInterface
{
    public function run(array data, array options) -> void
    {
        string redirectUrl, query;
        bool dataQuery;

        let redirectUrl = (string) Std::valueAt(options, "redirectUrl", "");
        if unlikely redirectUrl->length() < 1 {
            throw new Exception("Missing option: redirectUrl");
        }

        let dataQuery = (bool) Std::valueAt(options, "dataQuery", false);
        if dataQuery {
            let query = (string) http_build_query(data);
            if query->length() > 0 {
                if strpos(redirectUrl, "?") === false {
                    let redirectUrl .= "?";
                } else {
                    let redirectUrl .= "&";
                }
                let redirectUrl .= query;
            }
        }

        header("Location: " . redirectUrl);
    }

}

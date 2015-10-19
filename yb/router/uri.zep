namespace Yb\Router;

class Uri extends RouterAbstract
{
    public function __construct(string uri) -> void
    {
        long len;
        var m = null, params;

        if preg_match("/^([^\\.\\?]+)/", uri, m) {
            let params = preg_split("#/+#", (string) m[1], null, PREG_SPLIT_NO_EMPTY);
        } else {
            let params = [];
        }

        switch count(params) {
            case 0:
                let this->controller = RouterAbstract::DEFAULT_CONTROLLER;
                let this->action = RouterAbstract::DEFAULT_ACTION;
                break;
            case 1:
                let this->controller = array_shift(params);
                let this->action = RouterAbstract::DEFAULT_ACTION;
                break;
            default:
                let this->controller = array_shift(params);
                let this->action = array_shift(params);
                break;
        }

        let this->params = params;
    }

}

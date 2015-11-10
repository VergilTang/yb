namespace Yb\Redis;

class Pipeline
{
    protected client;
    protected cmds;

    public function __construct(<Client> client) -> void
    {
        let this->client = client;
    }

    public function __call(string method, array args)
    {
        var cmd;

        let cmd = args;
        array_unshift(cmd, method);

        // Or write to connection directly?
        let this->cmds[] = cmd;

        return this;
    }

}

namespace Yb\Redis;

class ErrorAsk extends Error
{
    public slot;
    public host;
    public port;

}

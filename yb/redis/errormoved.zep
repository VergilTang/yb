namespace Yb\Redis;

class ErrorMoved extends Error
{
    public slot;
    public host;
    public port;

}

namespace Yb\RedisCluster;

class ErrorMoved extends Error
{
    public slot;
    public host;
    public port;

}

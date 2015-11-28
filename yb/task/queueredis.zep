namespace Yb\Task;

class QueueRedis extends TaskManagerAbstract
{
    protected redis;
    protected queueKey;

    public function __construct(var redis, string queueKey) -> void
    {
        let this->redis = redis;
        let this->queueKey = queueKey;
    }

    public function produce(<TaskInterface> task) -> void
    {
        if unlikely ! this->redis->lpush(this->queueKey, serialize(task)) {
            throw new Exception("Fail when redis lpush");
        }
    }

    public function consume() -> null|<TaskInterface>
    {
        var task;

        let task = this->redis->rpop(this->queueKey);
        if ! task {
            return;
        }

        let task = unserialize(task);
        if unlikely typeof task != "object" || ! (task instanceof TaskInterface) {
            throw new Exception("Invalid task from redis");
        }

        return task;
    }

}

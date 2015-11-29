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

    public function produce(array taskData) -> void
    {
        if unlikely ! this->redis->lpush(this->queueKey, this->serializeTaskData(taskData)) {
            throw new Exception("Fail when redis lpush");
        }
    }

    public function consume() -> null|array
    {
        var taskData;

        let taskData = this->redis->rpop(this->queueKey);
        if ! taskData {
            return;
        }

        let taskData = this->unserializeTaskData(taskData);
        if unlikely typeof taskData != "array" {
            throw new Exception("Invalid task from redis");
        }

        return taskData;
    }

}

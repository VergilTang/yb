namespace Yb\Task;

abstract class TaskManagerAbstract
{
    protected taskExecutor;
    protected sleep = -1;

    abstract public function produce(array task) -> void;
    abstract public function consume() -> null|array;

    public function setTaskExecutor(<TaskExecutorInterface> taskExecutor) -> void
    {
        let this->taskExecutor = taskExecutor;
    }

    public function setSleep(long sleep) -> void
    {
        let this->sleep = sleep;
    }

    public function getSleep() -> long
    {
        return this->sleep;
    }

    public function runTask(array task) -> void
    {
        var re, ex;

        if unlikely ! this->taskExecutor {
            throw new Exception("Missing task executor");
        }

        try {
            let re = this->taskExecutor->executeTask(task);
            this->taskExecutor->onTaskReturn(task, re);
        } catch \Exception, ex {
            this->taskExecutor->onTaskException(task, ex);
        }
    }

    public function __invoke() -> void
    {
        var task;

        loop {
            let task = this->consume();
            if task !== null {
                this->runTask(task);
                continue;
            }

            if this->sleep < 0 {
                return;
            }

            sleep(this->sleep);
        }
    }

    public function serializeTask(array task) -> string
    {
        return json_encode(task);
    }

    public function unserializeTask(string task) -> array
    {
        return json_decode(task, true);
    }

}

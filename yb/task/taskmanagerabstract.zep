namespace Yb\Task;

use Yb\Factory\FactoryInterface;
use Yb\Std;

abstract class TaskManagerAbstract implements TaskManagerInterface
{
    protected sleep = -1;
    protected taskFactory;

    public function setSleep(long sleep) -> void
    {
        let this->sleep = sleep;
    }

    public function getSleep() -> long
    {
        return this->sleep;
    }

    public function setTaskFactory(<FactoryInterface> taskFactory) -> void
    {
        let this->taskFactory = taskFactory;
    }

    public function getTaskFactory() -> <FactoryInterface>
    {
        return this->taskFactory;
    }

    public function hasTask(string name) -> bool
    {
        return this->taskFactory->__isset(name);
    }

    public function getTask(string name) -> <TaskInterface>
    {
        return this->taskFactory->__get(name);
    }

    public function runTask(array taskData) -> void
    {
        string name;
        var task, input, re, ex;

        try {
            let name = (string) Std::valueAt(taskData, "name", "defaultTask");
            if unlikely ! this->hasTask(name) {
                throw new Exception("Cannot find task: " . name);
            }

            let task = this->getTask(name);
            if unlikely typeof task != "object" || ! (task instanceof TaskInterface) {
                throw new Exception("Invalid task: " . name);
            }

            let input = Std::valueAt(taskData, "input", []);
            let re = task->__invoke(input);

            task->onReturn(this, re);
        } catch \Exception, ex {
            task->onException(this, ex);
        }
    }

    public function __invoke() -> void
    {
        var taskData;

        loop {
            let taskData = this->consume();
            if taskData !== null {
                this->runTask(taskData);
            }

            if this->sleep < 0 {
                return;
            }

            sleep(this->sleep);
        }
    }

    public function serializeTaskData(array taskData) -> string
    {
        return json_encode(taskData);
    }

    public function unserializeTaskData(string taskData) -> array
    {
        return json_decode(taskData, true);
    }

}

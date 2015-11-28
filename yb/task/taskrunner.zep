namespace Yb\Task;

class TaskRunner
{
    protected taskManager;
    protected sleep;

    public function __construct(<TaskManagerInterface> taskManager, long sleep = 0) -> void
    {
        let this->taskManager = taskManager;
        let this->sleep = sleep;
    }

    public function __invoke() -> void
    {
        var task, r, e;

        loop {
            let task = this->taskManager->consume();
            if task !== null {
                try {
                    let r = task->__invoke();
                    this->taskManager->onReturn(task, r);
                } catch \Exception, e {
                    this->taskManager->onException(task, e);
                }
            }

            if this->sleep < 0 {
                return;
            }

            sleep(this->sleep);
        }
    }

}

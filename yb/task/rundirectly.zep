namespace Yb\Task;

class RunDirectly extends TaskManagerAbstract
{
    public function produce(<TaskInterface> task) -> void
    {
        var r, e;

        try {
            let r = task->__invoke();
            this->onReturn(task, r);
        } catch \Exception, e {
            this->onException(task, e);
        }
    }

    public function consume() -> null|<TaskInterface>
    {
        return;
    }

}

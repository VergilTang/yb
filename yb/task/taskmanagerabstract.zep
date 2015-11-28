namespace Yb\Task;

abstract class TaskManagerAbstract implements TaskManagerInterface
{
    public function onReturn(<TaskInterface> task, var r) -> void
    {
        return;
    }

    public function onException(<TaskInterface> task, <\Exception> e) -> void
    {
        throw e;
    }

}

namespace Yb\Task;

interface TaskManagerInterface
{
    public function produce(<TaskInterface> task) -> void;
    public function consume() -> null|<TaskInterface>;

    public function onReturn(<TaskInterface> task, var r) -> void;
    public function onException(<TaskInterface> task, <\Exception> e) -> void;

}

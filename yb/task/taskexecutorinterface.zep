namespace Yb\Task;

interface TaskExecutorInterface
{
    public function executeTask(array task);

    public function onTaskReturn(<TaskManagerAbstract> taskManager, array task, var re) -> void;
    public function onTaskException(<TaskManagerAbstract> taskManager, array task, <\Exception> ex) -> void;

}

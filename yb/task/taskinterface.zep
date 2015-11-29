namespace Yb\Task;

interface TaskInterface
{
    public function __invoke(var input);

    public function onReturn(<TaskManagerInterface> taskManager, var re) -> void;
    public function onException(<TaskManagerInterface> taskManager, <\Exception> ex) -> void;

}

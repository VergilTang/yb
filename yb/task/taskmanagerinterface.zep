namespace Yb\Task;

interface TaskManagerInterface
{
    public function produce(array taskData) -> void;
    public function consume() -> null|array;

    public function hasTask(string name) -> bool;
    public function getTask(string name) -> <TaskInterface>;
    public function runTask(array taskData) -> void;
    public function __invoke() -> void;

    public function serializeTaskData(array taskData) -> string;
    public function unserializeTaskData(string taskData) -> array;

}

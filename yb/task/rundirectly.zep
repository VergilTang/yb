namespace Yb\Task;

class RunDirectly extends TaskManagerAbstract
{
    public function produce(array taskData) -> void
    {
        this->runTask(taskData);
    }

    public function consume() -> null|array
    {
        return;
    }

}

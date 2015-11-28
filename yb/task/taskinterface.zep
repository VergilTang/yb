namespace Yb\Task;

interface TaskInterface extends \Serializable
{
    public function __invoke();

}

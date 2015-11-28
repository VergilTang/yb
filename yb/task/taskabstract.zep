namespace Yb\Task;

abstract class TaskAbstract implements TaskInterface
{
    protected data;

    public function serialize() -> string
    {
        return json_encode(this->data);
    }

    public function unserialize(string data) -> void
    {
        let this->data = json_decode(data, true);
    }

}

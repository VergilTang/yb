namespace Yb\Collection;

interface CollectionInterface
{
    public function set(string key, var value) -> void;
    public function get(string key);
    public function delete(string key) -> void;

    public function setMany(array keyValues) -> void;
    public function getMany(array keys) -> array;
    public function deleteMany(array keys) -> void;

    public function setAll(array keyValues) -> void;
    public function getAll() -> array;
    public function deleteAll() -> void;

}

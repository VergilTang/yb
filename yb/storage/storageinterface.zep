namespace Yb\Storage;

interface StorageInterface
{
    public function set(string group, string key, var value) -> void;
    public function get(string group, string key);
    public function remove(string group, string key) -> void;

    public function setMany(string group, array keyValues) -> void;
    public function getMany(string group, array keys) -> array;
    public function removeMany(string group, array keys) -> void;

    public function setAll(string group, array keyValues) -> void;
    public function getAll(string group) -> array;
    public function removeAll(string group) -> void;

}

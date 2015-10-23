namespace Yb\Storage;

abstract StorageAbstract
{
    public function setMany(string group, array keyValues) -> void
    {
        var k, v;

        for k, v in keyValues {
            this->set(group, k, v);
        }
    }

    public function getMany(string group, array keys) -> array
    {
        var r = [], k, v;

        for k in keys {
            let v = this->get(group, k);
            if v !== null {
                let r[k] = v;
            }
        }

        return r;
    }

    public function removeMany(string group, array keys) -> void
    {
        var k;

        for k in keys {
            this->remove(group, k);
        }
    }

}

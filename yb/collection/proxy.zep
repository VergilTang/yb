namespace Yb\Collection;

class Proxy implements CollectionInterface
{
    const NON_EXISTENT_VALUE = null;

    protected frontend;
    protected backend;

    public function __construct(<CollectionInterface> frontend, <CollectionInterface> backend) -> void
    {
        let this->frontend = frontend;
        let this->backend = backend;
    }

    public function set(string key, var value) -> void
    {
        this->frontend->delete(key);
        this->backend->set(key, value);
    }

    public function get(string key)
    {
        var value;

        let value = this->frontend->get(key);
        if value !== null {
            if value !== self::NON_EXISTENT_VALUE {
                return value;
            }
            return;
        }

        let value = this->backend->get(key);
        if value !== null {
            this->frontend->set(key, value);
            return value;
        }

        this->frontend->set(key, self::NON_EXISTENT_VALUE);
    }

    public function delete(string key) -> void
    {
        this->frontend->set(key, self::NON_EXISTENT_VALUE);
        this->backend->delete(key);
    }

    public function setMany(array keyValues) -> void
    {
        var k;

        for k, _ in keyValues {
            this->frontend->delete(k);
        }

        this->backend->setMany(keyValues);
    }

    public function getMany(array keys) -> array
    {
        var k, v, a, r = [], x = [];

        let a = this->frontend->getMany(keys);
        for k in keys {
            if fetch v, a[k] {
                if v !== self::NON_EXISTENT_VALUE {
                    let r[k] = v;
                }
            } else {
                let x[] = k;
                let r[k] = null;
            }
        }

        if x {
            let a = this->backend->getMany(x);
            for k in x {
                if fetch v, a[k] {
                    let r[k] = v;
                    this->frontend->set(k, v);
                } else {
                    unset r[k];
                    this->frontend->set(k, self::NON_EXISTENT_VALUE);
                }
            }
        }

        return r;
    }

    public function deleteMany(array keys) -> void
    {
        var k;

        for k in keys {
            this->frontend->set(k, self::NON_EXISTENT_VALUE);
        }

        this->backend->deleteMany(keys);
    }

    public function setAll(array keyValues) -> void
    {
        var k;

        for k, _ in keyValues {
            this->frontend->delete(k);
        }

        this->backend->setAll(keyValues);
    }

    public function getAll() -> array
    {
        return this->backend->getAll();
    }

    public function deleteAll() -> void
    {
        this->frontend->deleteAll();
        this->backend->deleteAll();
    }

}

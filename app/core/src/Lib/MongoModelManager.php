<?php

namespace YbApp\Core\Lib;

use MongoDb\Driver\Manager;

class MongoModelManager
{
    protected $mongodbManager;
    protected $models;

    public function __construct($uri)
    {
        $this->mongodbManager = new Manager($uri);
    }

    public function get($name)
    {
        if (isset($this->models[$name])) {
            return $this->models[$name];
        }

        return $this->models[$name] = $this->newModel($name);
    }

    public function newModel($name)
    {
        return new MongoModel($this->mongodbManager, $name);
    }

}

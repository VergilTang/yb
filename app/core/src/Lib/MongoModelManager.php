<?php

namespace YbApp\Core\Lib;

class MongoModelManager
{
    protected $dbManager;
    protected $models;

    public function __construct($uri)
    {
        $this->dbManager = new \MongoDb\Driver\Manager($uri);
    }

    public function get($db, $collection)
    {
        if (isset($this->models[$db][$collection])) {
            return $this->models[$db][$collection];
        }

        return $this->models[$db][$collection] = $this->newModel($db, $collection);
    }

    public function newModel($db, $collection)
    {
        return new MongoModel($this->dbManager, $db, $collection);
    }

}

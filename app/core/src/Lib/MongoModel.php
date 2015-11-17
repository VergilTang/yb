<?php

namespace YbApp\Core\Lib;

use MongoDb\Driver\Manager;

class MongoModel implements MongoModelInterface
{
    protected static $typeMap = [
        'root' => 'array',
        'document' => 'array',
        'array' => 'array',
    ];

    protected $mongodbManager;
    protected $collection;

    public static function objectId($objectId)
    {
        if (is_object($objectId) && ($objectId instanceof \MongoDb\Bson\ObjectId)) {
            return $objectId;
        }

        $objectId = (string) $objectId;
        if (!preg_match('/^[0-9a-f]{24}$/', $objectId)) {
            throw new Exception("Invalid object id: " . $objectId);
        }

        return new \MongoDb\Bson\ObjectId($objectId);
    }

    public function __construct(Manager $mongodbManager, $collection)
    {
        $this->mongodbManager = $mongodbManager;
        $this->collection = $collection;
    }

    public function insert(array $data)
    {
        $bulkWrite = new \MongoDb\Driver\BulkWrite();

        if (isset($data['_id'])) {
            $insertId = $data['_id'];
            $bulkWrite->insert($data);
        } else {
            $insertId = $bulkWrite->insert($data);
        }

        $this->mongodbManager->executeBulkWrite($this->collection, $bulkWrite);
        return $insertId;
    }

    public function delete(array $criteria)
    {
        $bulkWrite = new \MongoDb\Driver\BulkWrite();

        $bulkWrite->delete($criteria, [
            'limit' => 0,
        ]);

        $this->mongodbManager->executeBulkWrite($this->collection, $bulkWrite);
    }

    protected function packUpdates(array $set, array $extra)
    {
        $updates = [];

        if ($set) {
            $updates['$set'] = $set;
        }

        if ($extra) {
            if (isset($extra['$set'])) {
                $set = $extra['$set'];
                if (!is_array($set)) {
                    throw new Exception('Invalid extra set, array required');
                }
                if (isset($updates['$set'])) {
                    $updates['$set'] = $set + $updates['$set'];
                } else {
                    $updates['$set'] = $set;
                }
                unset($extra['$set']);
            }
            $updates += $extra;
        }

        return $updates;
    }

    public function update(array $criteria, array $set = [], array $extra = [])
    {
        $bulkWrite = new \MongoDb\Driver\BulkWrite();

        $updates = $this->packUpdates($set, $extra);
        if (!$updates) {
            throw new Exception('Nothing to update');
        }

        $bulkWrite->update($criteria, $updates, [
            'multi' => true,
        ]);

        $this->mongodbManager->executeBulkWrite($this->collection, $bulkWrite);
    }

    public function upsert(array $criteria, array $set = [], array $extra = [])
    {
        $bulkWrite = new \MongoDb\Driver\BulkWrite();

        $updates = $this->packUpdates($set, $extra);
        if (!$updates) {
            throw new Exception('Nothing to upsert');
        }

        $bulkWrite->update($criteria, $updates, [
            'upsert' => true,
        ]);

        $r = $this->mongodbManager->executeBulkWrite($this->collection, $bulkWrite);
        print_R($r);
    }

    public function find(array $criteria)
    {
        $query = new \MongoDb\Driver\Query($criteria, [
            'limit' => 1,
        ]);

        $cursor = $this->mongodbManager->executeQuery($this->collection, $query);
        $cursor->setTypeMap(self::$typeMap);

        $data = $cursor->toArray();
        if (isset($data[0])) {
            return $data[0];
        }
    }

    public function count(array $criteria = [])
    {
        return 0;
    }

    public function select(array $criteria, $sort = [], $limit = 0, $skip = 0)
    {
        $query = new \MongoDb\Driver\Query($criteria, [
            'limit' => 1,
            'sort' => $sort,
            'limit' => $limit,
            'skip' => $skip,
        ]);

        $cursor = $this->mongodbManager->executeQuery($this->collection, $query);
        $cursor->setTypeMap(self::$typeMap);

        return $cursor->toArray();
    }

    public function countAndSelect(array $criteria, $sort = [], $limit = 0, $skip = 0)
    {
        $c = $this->count($criteria);

        if ($c > 0 && true) {
            return [$c, $this->select($criteria, $sort, $limit, $skip)];
        }

        return [0, []];
    }

}

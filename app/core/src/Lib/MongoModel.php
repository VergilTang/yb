<?php

namespace YbApp\Core\Lib;

class MongoModel implements MongoModelInterface
{
    protected static $typeMap = [
        'root'      => 'array',
        'document'  => 'array',
        'array'     => 'array',
    ];

    protected $dbManager;
    protected $db;
    protected $collection;
    protected $ns;

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

    public function __construct(\MongoDb\Driver\Manager $dbManager, $db, $collection)
    {
        $this->dbManager = $dbManager;
        $this->db = $db;
        $this->collection = $collection;
        $this->ns = $db.'.'.$collection;
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

        $this->dbManager->executeBulkWrite($this->ns, $bulkWrite);
        return $insertId;
    }

    public function delete(array $criteria)
    {
        $bulkWrite = new \MongoDb\Driver\BulkWrite();

        $bulkWrite->delete($criteria, [
            'limit' => 0,
        ]);

        $writeResult = $this->dbManager->executeBulkWrite($this->ns, $bulkWrite);
        return $writeResult->getDeletedCount();
    }

    public function update(array $criteria, array $set = [], array $extra = [])
    {
        $bulkWrite = new \MongoDb\Driver\BulkWrite();

        $updates = self::packUpdates($set, $extra);
        if (!$updates) {
            throw new Exception('Nothing to update');
        }

        $bulkWrite->update($criteria, $updates, [
            'multi' => true,
        ]);

        $writeResult = $this->dbManager->executeBulkWrite($this->ns, $bulkWrite);
        return $writeResult->getModifiedCount();
    }

    public function upsert(array $criteria, array $set = [], array $extra = [])
    {
        $bulkWrite = new \MongoDb\Driver\BulkWrite();

        $updates = self::packUpdates($set, $extra);
        if (!$updates) {
            throw new Exception('Nothing to upsert');
        }

        $bulkWrite->update($criteria, $updates, [
            'upsert' => true,
        ]);

        $writeResult = $this->dbManager->executeBulkWrite($this->ns, $bulkWrite);
        return $writeResult->getUpsertedCount();
    }

    public function find(array $criteria, array $sort = [])
    {
        $query = new \MongoDb\Driver\Query($criteria, [
            'limit' => 1,
            'sort' => $sort,
        ]);

        $cursor = $this->dbManager->executeQuery($this->ns, $query);
        $cursor->setTypeMap(self::$typeMap);

        $data = $cursor->toArray();
        if (isset($data[0])) {
            return $data[0];
        }
    }

    public function count(array $criteria = [])
    {
        $command = new \MongoDb\Driver\Command([
            'count' => $this->collection,
            'query' => $criteria,
            'hint' => '_id',
        ]);

        $cursor = $this->dbManager->executeCommand($this->db, $command);
        $cursor->setTypeMap(self::$typeMap);
        $result = $cursor->toArray();

        if (isset($result[0]['n'])) {
            return $result[0]['n'];
        }

        return 0;
    }

    public function select(array $criteria, array $sort = [], $limit = 10, $skip = 0)
    {
        $query = new \MongoDb\Driver\Query($criteria, [
            'limit' => 1,
            'sort' => $sort,
            'limit' => $limit,
            'skip' => $skip,
        ]);

        $cursor = $this->dbManager->executeQuery($this->ns, $query);
        $cursor->setTypeMap(self::$typeMap);

        return $cursor->toArray();
    }

    public function countAndSelect(array $criteria, array $sort = [], $limit = 10, $skip = 0)
    {
        $c = $this->count($criteria);

        if ($c > 0 && $skip < $c) {
            return [$c, $this->select($criteria, $sort, $limit, $skip)];
        }

        return [$c, []];
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

}

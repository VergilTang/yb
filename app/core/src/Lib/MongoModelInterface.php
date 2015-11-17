<?php

namespace YbApp\Core\Lib;

interface MongoModelInterface
{
    public function insert(array $data);
    public function delete(array $criteria);
    public function update(array $criteria, array $set = null, array $extra = null);
    public function upsert(array $criteria, array $set = null, array $extra = null);

    public function find(array $criteria);

    public function count(array $criteria = null);
    public function select(array $criteria, $sort = null, $limit = 0, $skip = 0);
    public function countAndSelect(array $criteria, $sort = null, $limit = 0, $skip = 0);

}

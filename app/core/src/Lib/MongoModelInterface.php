<?php

namespace YbApp\Core\Lib;

interface MongoModelInterface
{
    public function insert(array $data);
    public function delete(array $criteria);
    public function update(array $criteria, array $set = [], array $extra = []);
    public function upsert(array $criteria, array $set = [], array $extra = []);

    public function find(array $criteria, array $sort = []);

    public function count(array $criteria = []);
    public function select(array $criteria, array $sort = [], $limit = 10, $skip = 0);
    public function countAndSelect(array $criteria, array $sort = [], $limit = 10, $skip = 0);

}


extern zend_class_entry *yb_collection_redishash_ce;

ZEPHIR_INIT_CLASS(Yb_Collection_RedisHash);

PHP_METHOD(Yb_Collection_RedisHash, __construct);
PHP_METHOD(Yb_Collection_RedisHash, set);
PHP_METHOD(Yb_Collection_RedisHash, get);
PHP_METHOD(Yb_Collection_RedisHash, delete);
PHP_METHOD(Yb_Collection_RedisHash, setMany);
PHP_METHOD(Yb_Collection_RedisHash, getMany);
PHP_METHOD(Yb_Collection_RedisHash, deleteMany);
PHP_METHOD(Yb_Collection_RedisHash, setAll);
PHP_METHOD(Yb_Collection_RedisHash, getAll);
PHP_METHOD(Yb_Collection_RedisHash, deleteAll);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_collection_redishash___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, redis)
	ZEND_ARG_INFO(0, hashName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_collection_redishash_set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_collection_redishash_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_collection_redishash_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_collection_redishash_setmany, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keyValues, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_collection_redishash_getmany, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_collection_redishash_deletemany, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_collection_redishash_setall, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keyValues, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_collection_redishash_method_entry) {
	PHP_ME(Yb_Collection_RedisHash, __construct, arginfo_yb_collection_redishash___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_Collection_RedisHash, set, arginfo_yb_collection_redishash_set, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Collection_RedisHash, get, arginfo_yb_collection_redishash_get, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Collection_RedisHash, delete, arginfo_yb_collection_redishash_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Collection_RedisHash, setMany, arginfo_yb_collection_redishash_setmany, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Collection_RedisHash, getMany, arginfo_yb_collection_redishash_getmany, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Collection_RedisHash, deleteMany, arginfo_yb_collection_redishash_deletemany, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Collection_RedisHash, setAll, arginfo_yb_collection_redishash_setall, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Collection_RedisHash, getAll, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Collection_RedisHash, deleteAll, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

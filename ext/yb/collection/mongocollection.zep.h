
extern zend_class_entry *yb_collection_mongocollection_ce;

ZEPHIR_INIT_CLASS(Yb_Collection_MongoCollection);

PHP_METHOD(Yb_Collection_MongoCollection, __construct);
PHP_METHOD(Yb_Collection_MongoCollection, set);
PHP_METHOD(Yb_Collection_MongoCollection, get);
PHP_METHOD(Yb_Collection_MongoCollection, delete);
PHP_METHOD(Yb_Collection_MongoCollection, setMany);
PHP_METHOD(Yb_Collection_MongoCollection, getMany);
PHP_METHOD(Yb_Collection_MongoCollection, deleteMany);
PHP_METHOD(Yb_Collection_MongoCollection, setAll);
PHP_METHOD(Yb_Collection_MongoCollection, getAll);
PHP_METHOD(Yb_Collection_MongoCollection, deleteAll);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_collection_mongocollection___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, mongoCollection)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_collection_mongocollection_set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_collection_mongocollection_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_collection_mongocollection_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_collection_mongocollection_setmany, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keyValues, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_collection_mongocollection_getmany, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_collection_mongocollection_deletemany, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_collection_mongocollection_setall, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keyValues, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_collection_mongocollection_method_entry) {
	PHP_ME(Yb_Collection_MongoCollection, __construct, arginfo_yb_collection_mongocollection___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_Collection_MongoCollection, set, arginfo_yb_collection_mongocollection_set, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Collection_MongoCollection, get, arginfo_yb_collection_mongocollection_get, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Collection_MongoCollection, delete, arginfo_yb_collection_mongocollection_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Collection_MongoCollection, setMany, arginfo_yb_collection_mongocollection_setmany, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Collection_MongoCollection, getMany, arginfo_yb_collection_mongocollection_getmany, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Collection_MongoCollection, deleteMany, arginfo_yb_collection_mongocollection_deletemany, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Collection_MongoCollection, setAll, arginfo_yb_collection_mongocollection_setall, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Collection_MongoCollection, getAll, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Collection_MongoCollection, deleteAll, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};


extern zend_class_entry *yb_collection_redishashserialized_ce;

ZEPHIR_INIT_CLASS(Yb_Collection_RedisHashSerialized);

PHP_METHOD(Yb_Collection_RedisHashSerialized, serializeValue);
PHP_METHOD(Yb_Collection_RedisHashSerialized, unserializeValue);
PHP_METHOD(Yb_Collection_RedisHashSerialized, set);
PHP_METHOD(Yb_Collection_RedisHashSerialized, get);
PHP_METHOD(Yb_Collection_RedisHashSerialized, setMany);
PHP_METHOD(Yb_Collection_RedisHashSerialized, getMany);
PHP_METHOD(Yb_Collection_RedisHashSerialized, setAll);
PHP_METHOD(Yb_Collection_RedisHashSerialized, getAll);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_collection_redishashserialized_serializevalue, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_collection_redishashserialized_unserializevalue, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_collection_redishashserialized_set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_collection_redishashserialized_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_collection_redishashserialized_setmany, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keyValues, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_collection_redishashserialized_getmany, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_collection_redishashserialized_setall, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keyValues, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_collection_redishashserialized_method_entry) {
	PHP_ME(Yb_Collection_RedisHashSerialized, serializeValue, arginfo_yb_collection_redishashserialized_serializevalue, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Collection_RedisHashSerialized, unserializeValue, arginfo_yb_collection_redishashserialized_unserializevalue, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Collection_RedisHashSerialized, set, arginfo_yb_collection_redishashserialized_set, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Collection_RedisHashSerialized, get, arginfo_yb_collection_redishashserialized_get, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Collection_RedisHashSerialized, setMany, arginfo_yb_collection_redishashserialized_setmany, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Collection_RedisHashSerialized, getMany, arginfo_yb_collection_redishashserialized_getmany, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Collection_RedisHashSerialized, setAll, arginfo_yb_collection_redishashserialized_setall, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Collection_RedisHashSerialized, getAll, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

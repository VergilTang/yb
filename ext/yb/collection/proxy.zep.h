
extern zend_class_entry *yb_collection_proxy_ce;

ZEPHIR_INIT_CLASS(Yb_Collection_Proxy);

PHP_METHOD(Yb_Collection_Proxy, __construct);
PHP_METHOD(Yb_Collection_Proxy, set);
PHP_METHOD(Yb_Collection_Proxy, get);
PHP_METHOD(Yb_Collection_Proxy, delete);
PHP_METHOD(Yb_Collection_Proxy, setMany);
PHP_METHOD(Yb_Collection_Proxy, getMany);
PHP_METHOD(Yb_Collection_Proxy, deleteMany);
PHP_METHOD(Yb_Collection_Proxy, setAll);
PHP_METHOD(Yb_Collection_Proxy, getAll);
PHP_METHOD(Yb_Collection_Proxy, deleteAll);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_collection_proxy___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, frontend, Yb\\Collection\\CollectionInterface, 0)
	ZEND_ARG_OBJ_INFO(0, backend, Yb\\Collection\\CollectionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_collection_proxy_set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_collection_proxy_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_collection_proxy_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_collection_proxy_setmany, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keyValues, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_collection_proxy_getmany, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_collection_proxy_deletemany, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_collection_proxy_setall, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keyValues, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_collection_proxy_method_entry) {
	PHP_ME(Yb_Collection_Proxy, __construct, arginfo_yb_collection_proxy___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_Collection_Proxy, set, arginfo_yb_collection_proxy_set, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Collection_Proxy, get, arginfo_yb_collection_proxy_get, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Collection_Proxy, delete, arginfo_yb_collection_proxy_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Collection_Proxy, setMany, arginfo_yb_collection_proxy_setmany, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Collection_Proxy, getMany, arginfo_yb_collection_proxy_getmany, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Collection_Proxy, deleteMany, arginfo_yb_collection_proxy_deletemany, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Collection_Proxy, setAll, arginfo_yb_collection_proxy_setall, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Collection_Proxy, getAll, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Collection_Proxy, deleteAll, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

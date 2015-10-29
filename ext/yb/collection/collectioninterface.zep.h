
extern zend_class_entry *yb_collection_collectioninterface_ce;

ZEPHIR_INIT_CLASS(Yb_Collection_CollectionInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_collection_collectioninterface_set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_collection_collectioninterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_collection_collectioninterface_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_collection_collectioninterface_setmany, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keyValues, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_collection_collectioninterface_getmany, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_collection_collectioninterface_deletemany, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_collection_collectioninterface_setall, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keyValues, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_collection_collectioninterface_method_entry) {
	PHP_ABSTRACT_ME(Yb_Collection_CollectionInterface, set, arginfo_yb_collection_collectioninterface_set)
	PHP_ABSTRACT_ME(Yb_Collection_CollectionInterface, get, arginfo_yb_collection_collectioninterface_get)
	PHP_ABSTRACT_ME(Yb_Collection_CollectionInterface, delete, arginfo_yb_collection_collectioninterface_delete)
	PHP_ABSTRACT_ME(Yb_Collection_CollectionInterface, setMany, arginfo_yb_collection_collectioninterface_setmany)
	PHP_ABSTRACT_ME(Yb_Collection_CollectionInterface, getMany, arginfo_yb_collection_collectioninterface_getmany)
	PHP_ABSTRACT_ME(Yb_Collection_CollectionInterface, deleteMany, arginfo_yb_collection_collectioninterface_deletemany)
	PHP_ABSTRACT_ME(Yb_Collection_CollectionInterface, setAll, arginfo_yb_collection_collectioninterface_setall)
	PHP_ABSTRACT_ME(Yb_Collection_CollectionInterface, getAll, NULL)
	PHP_ABSTRACT_ME(Yb_Collection_CollectionInterface, deleteAll, NULL)
	PHP_FE_END
};


extern zend_class_entry *yb_db_entity_ce;

ZEPHIR_INIT_CLASS(Yb_Db_Entity);

PHP_METHOD(Yb_Db_Entity, __construct);
PHP_METHOD(Yb_Db_Entity, getModel);
PHP_METHOD(Yb_Db_Entity, asArray);
PHP_METHOD(Yb_Db_Entity, isNew);
PHP_METHOD(Yb_Db_Entity, isDirty);
PHP_METHOD(Yb_Db_Entity, setCollection);
PHP_METHOD(Yb_Db_Entity, hasCollection);
PHP_METHOD(Yb_Db_Entity, getCollection);
PHP_METHOD(Yb_Db_Entity, primaryKeyValue);
PHP_METHOD(Yb_Db_Entity, set);
PHP_METHOD(Yb_Db_Entity, __set);
PHP_METHOD(Yb_Db_Entity, __get);
PHP_METHOD(Yb_Db_Entity, save);
PHP_METHOD(Yb_Db_Entity, drop);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_entity___construct, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, model, Yb\\Db\\Model, 0)
	ZEND_ARG_ARRAY_INFO(0, row, 0)
	ZEND_ARG_INFO(0, isNew)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_entity_setcollection, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, collection, Yb\\Db\\Collection, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_entity_set, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, updates, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_entity___set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_entity___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_db_entity_method_entry) {
	PHP_ME(Yb_Db_Entity, __construct, arginfo_yb_db_entity___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_Db_Entity, getModel, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Entity, asArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Entity, isNew, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Entity, isDirty, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Entity, setCollection, arginfo_yb_db_entity_setcollection, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Entity, hasCollection, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Entity, getCollection, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Entity, primaryKeyValue, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Entity, set, arginfo_yb_db_entity_set, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Entity, __set, arginfo_yb_db_entity___set, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Entity, __get, arginfo_yb_db_entity___get, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Entity, save, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Entity, drop, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

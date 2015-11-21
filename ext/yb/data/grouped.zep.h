
extern zend_class_entry *yb_data_grouped_ce;

ZEPHIR_INIT_CLASS(Yb_Data_Grouped);

PHP_METHOD(Yb_Data_Grouped, set);
PHP_METHOD(Yb_Data_Grouped, get);
PHP_METHOD(Yb_Data_Grouped, delete);
PHP_METHOD(Yb_Data_Grouped, setMany);
PHP_METHOD(Yb_Data_Grouped, getMany);
PHP_METHOD(Yb_Data_Grouped, deleteMany);
PHP_METHOD(Yb_Data_Grouped, setAll);
PHP_METHOD(Yb_Data_Grouped, getAll);
PHP_METHOD(Yb_Data_Grouped, deleteAll);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_data_grouped_set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_data_grouped_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_data_grouped_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_data_grouped_setmany, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keyValues, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_data_grouped_getmany, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_data_grouped_deletemany, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_data_grouped_setall, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keyValues, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_data_grouped_method_entry) {
	PHP_ME(Yb_Data_Grouped, set, arginfo_yb_data_grouped_set, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Data_Grouped, get, arginfo_yb_data_grouped_get, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Data_Grouped, delete, arginfo_yb_data_grouped_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Data_Grouped, setMany, arginfo_yb_data_grouped_setmany, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Data_Grouped, getMany, arginfo_yb_data_grouped_getmany, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Data_Grouped, deleteMany, arginfo_yb_data_grouped_deletemany, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Data_Grouped, setAll, arginfo_yb_data_grouped_setall, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Data_Grouped, getAll, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Data_Grouped, deleteAll, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

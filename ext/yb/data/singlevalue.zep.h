
extern zend_class_entry *yb_data_singlevalue_ce;

ZEPHIR_INIT_CLASS(Yb_Data_SingleValue);

PHP_METHOD(Yb_Data_SingleValue, set);
PHP_METHOD(Yb_Data_SingleValue, get);
PHP_METHOD(Yb_Data_SingleValue, delete);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_data_singlevalue_set, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_data_singlevalue_method_entry) {
	PHP_ME(Yb_Data_SingleValue, set, arginfo_yb_data_singlevalue_set, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Data_SingleValue, get, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Data_SingleValue, delete, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};


extern zend_class_entry *yb_data_dataabstract_ce;

ZEPHIR_INIT_CLASS(Yb_Data_DataAbstract);

PHP_METHOD(Yb_Data_DataAbstract, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_data_dataabstract___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, backend)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_data_dataabstract_method_entry) {
	PHP_ME(Yb_Data_DataAbstract, __construct, arginfo_yb_data_dataabstract___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};


extern zend_class_entry *yb_datacacher_file_ce;

ZEPHIR_INIT_CLASS(Yb_DataCacher_File);

PHP_METHOD(Yb_DataCacher_File, __construct);
PHP_METHOD(Yb_DataCacher_File, storeData);
PHP_METHOD(Yb_DataCacher_File, fetchData);
PHP_METHOD(Yb_DataCacher_File, forgetData);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_datacacher_file___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_datacacher_file_storedata, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_datacacher_file_method_entry) {
	PHP_ME(Yb_DataCacher_File, __construct, arginfo_yb_datacacher_file___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_DataCacher_File, storeData, arginfo_yb_datacacher_file_storedata, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_DataCacher_File, fetchData, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_DataCacher_File, forgetData, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

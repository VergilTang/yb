
extern zend_class_entry *yb_datacacher_apc_ce;

ZEPHIR_INIT_CLASS(Yb_DataCacher_Apc);

PHP_METHOD(Yb_DataCacher_Apc, __construct);
PHP_METHOD(Yb_DataCacher_Apc, storeData);
PHP_METHOD(Yb_DataCacher_Apc, fetchData);
PHP_METHOD(Yb_DataCacher_Apc, forgetData);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_datacacher_apc___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, cacheKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_datacacher_apc_storedata, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_datacacher_apc_method_entry) {
	PHP_ME(Yb_DataCacher_Apc, __construct, arginfo_yb_datacacher_apc___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_DataCacher_Apc, storeData, arginfo_yb_datacacher_apc_storedata, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_DataCacher_Apc, fetchData, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_DataCacher_Apc, forgetData, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

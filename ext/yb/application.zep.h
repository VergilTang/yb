
extern zend_class_entry *yb_application_ce;

ZEPHIR_INIT_CLASS(Yb_Application);

PHP_METHOD(Yb_Application, __construct);
PHP_METHOD(Yb_Application, config);
PHP_METHOD(Yb_Application, mergeConfigs);
PHP_METHOD(Yb_Application, mergeConfigsInPathIfValid);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_application___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, configs, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_application_config, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_application_mergeconfigs, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, configs, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_application_mergeconfigsinpathifvalid, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_application_method_entry) {
	PHP_ME(Yb_Application, __construct, arginfo_yb_application___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_Application, config, arginfo_yb_application_config, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Application, mergeConfigs, arginfo_yb_application_mergeconfigs, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Application, mergeConfigsInPathIfValid, arginfo_yb_application_mergeconfigsinpathifvalid, ZEND_ACC_PUBLIC)
	PHP_FE_END
};


extern zend_class_entry *yb_application_ce;

ZEPHIR_INIT_CLASS(Yb_Application);

PHP_METHOD(Yb_Application, __construct);
PHP_METHOD(Yb_Application, config);
PHP_METHOD(Yb_Application, mergeConfigs);
PHP_METHOD(Yb_Application, mergeConfigsInPathIfValid);
PHP_METHOD(Yb_Application, offsetGet);
PHP_METHOD(Yb_Application, offsetSet);
PHP_METHOD(Yb_Application, offsetExists);
PHP_METHOD(Yb_Application, offsetUnset);
PHP_METHOD(Yb_Application, __invoke);
PHP_METHOD(Yb_Application, __get);
PHP_METHOD(Yb_Application, __set);
PHP_METHOD(Yb_Application, __isset);
PHP_METHOD(Yb_Application, __unset);

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

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_application_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_application_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_application_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_application_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_application___invoke, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, initializer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_application___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_application___set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, obj)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_application___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_application___unset, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_application_method_entry) {
	PHP_ME(Yb_Application, __construct, arginfo_yb_application___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_Application, config, arginfo_yb_application_config, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Application, mergeConfigs, arginfo_yb_application_mergeconfigs, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Application, mergeConfigsInPathIfValid, arginfo_yb_application_mergeconfigsinpathifvalid, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Application, offsetGet, arginfo_yb_application_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Application, offsetSet, arginfo_yb_application_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Application, offsetExists, arginfo_yb_application_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Application, offsetUnset, arginfo_yb_application_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Application, __invoke, arginfo_yb_application___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Application, __get, arginfo_yb_application___get, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Application, __set, arginfo_yb_application___set, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Application, __isset, arginfo_yb_application___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Application, __unset, arginfo_yb_application___unset, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

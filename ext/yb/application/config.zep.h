
extern zend_class_entry *yb_application_config_ce;

ZEPHIR_INIT_CLASS(Yb_Application_Config);

PHP_METHOD(Yb_Application_Config, __construct);
PHP_METHOD(Yb_Application_Config, addDir);
PHP_METHOD(Yb_Application_Config, __get);
PHP_METHOD(Yb_Application_Config, get);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_application_config___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, dirs, 0)
	ZEND_ARG_ARRAY_INFO(0, exts, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_application_config_adddir, 0, 0, 1)
	ZEND_ARG_INFO(0, dir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_application_config___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_application_config_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_application_config_method_entry) {
	PHP_ME(Yb_Application_Config, __construct, arginfo_yb_application_config___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_Application_Config, addDir, arginfo_yb_application_config_adddir, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Application_Config, __get, arginfo_yb_application_config___get, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Application_Config, get, arginfo_yb_application_config_get, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

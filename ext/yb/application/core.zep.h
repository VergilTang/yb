
extern zend_class_entry *yb_application_core_ce;

ZEPHIR_INIT_CLASS(Yb_Application_Core);

PHP_METHOD(Yb_Application_Core, offsetGet);
PHP_METHOD(Yb_Application_Core, offsetSet);
PHP_METHOD(Yb_Application_Core, offsetExists);
PHP_METHOD(Yb_Application_Core, offsetUnset);
PHP_METHOD(Yb_Application_Core, __invoke);
PHP_METHOD(Yb_Application_Core, __get);
PHP_METHOD(Yb_Application_Core, __set);
PHP_METHOD(Yb_Application_Core, __isset);
PHP_METHOD(Yb_Application_Core, __unset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_application_core_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_application_core_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_application_core_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_application_core_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_application_core___invoke, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, initializer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_application_core___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_application_core___set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, obj)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_application_core___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_application_core___unset, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_application_core_method_entry) {
	PHP_ME(Yb_Application_Core, offsetGet, arginfo_yb_application_core_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Application_Core, offsetSet, arginfo_yb_application_core_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Application_Core, offsetExists, arginfo_yb_application_core_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Application_Core, offsetUnset, arginfo_yb_application_core_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Application_Core, __invoke, arginfo_yb_application_core___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Application_Core, __get, arginfo_yb_application_core___get, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Application_Core, __set, arginfo_yb_application_core___set, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Application_Core, __isset, arginfo_yb_application_core___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Application_Core, __unset, arginfo_yb_application_core___unset, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

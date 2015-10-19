
extern zend_class_entry *yb_application_ce;

ZEPHIR_INIT_CLASS(Yb_Application);

PHP_METHOD(Yb_Application, __invoke);
PHP_METHOD(Yb_Application, __call);
PHP_METHOD(Yb_Application, __get);
PHP_METHOD(Yb_Application, __set);
PHP_METHOD(Yb_Application, __isset);
PHP_METHOD(Yb_Application, __unset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_application___call, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, config, 0)
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
	PHP_ME(Yb_Application, __invoke, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Application, __call, arginfo_yb_application___call, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Application, __get, arginfo_yb_application___get, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Application, __set, arginfo_yb_application___set, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Application, __isset, arginfo_yb_application___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Application, __unset, arginfo_yb_application___unset, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

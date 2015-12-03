
extern zend_class_entry *yb_di_ce;

ZEPHIR_INIT_CLASS(Yb_Di);

PHP_METHOD(Yb_Di, __invoke);
PHP_METHOD(Yb_Di, __get);
PHP_METHOD(Yb_Di, __set);
PHP_METHOD(Yb_Di, __isset);
PHP_METHOD(Yb_Di, __unset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_di___invoke, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, initializer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_di___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_di___set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, obj)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_di___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_di___unset, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_di_method_entry) {
	PHP_ME(Yb_Di, __invoke, arginfo_yb_di___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Di, __get, arginfo_yb_di___get, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Di, __set, arginfo_yb_di___set, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Di, __isset, arginfo_yb_di___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Di, __unset, arginfo_yb_di___unset, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

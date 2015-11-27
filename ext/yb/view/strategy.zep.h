
extern zend_class_entry *yb_view_strategy_ce;

ZEPHIR_INIT_CLASS(Yb_View_Strategy);

PHP_METHOD(Yb_View_Strategy, __construct);
PHP_METHOD(Yb_View_Strategy, setView);
PHP_METHOD(Yb_View_Strategy, getView);
PHP_METHOD(Yb_View_Strategy, __invoke);
PHP_METHOD(Yb_View_Strategy, setOptions);
PHP_METHOD(Yb_View_Strategy, __set);
PHP_METHOD(Yb_View_Strategy, __get);
PHP_METHOD(Yb_View_Strategy, __isset);
PHP_METHOD(Yb_View_Strategy, __unset);
PHP_METHOD(Yb_View_Strategy, setData);
PHP_METHOD(Yb_View_Strategy, offsetSet);
PHP_METHOD(Yb_View_Strategy, offsetGet);
PHP_METHOD(Yb_View_Strategy, offsetExists);
PHP_METHOD(Yb_View_Strategy, offsetUnset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_view_strategy___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 1)
	ZEND_ARG_INFO(0, view)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_view_strategy_setview, 0, 0, 1)
	ZEND_ARG_INFO(0, view)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_view_strategy_setoptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_view_strategy___set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_view_strategy___get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_view_strategy___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_view_strategy___unset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_view_strategy_setdata, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_view_strategy_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_view_strategy_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_view_strategy_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_view_strategy_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_view_strategy_method_entry) {
	PHP_ME(Yb_View_Strategy, __construct, arginfo_yb_view_strategy___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_View_Strategy, setView, arginfo_yb_view_strategy_setview, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_View_Strategy, getView, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_View_Strategy, __invoke, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_View_Strategy, setOptions, arginfo_yb_view_strategy_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_View_Strategy, __set, arginfo_yb_view_strategy___set, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_View_Strategy, __get, arginfo_yb_view_strategy___get, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_View_Strategy, __isset, arginfo_yb_view_strategy___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_View_Strategy, __unset, arginfo_yb_view_strategy___unset, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_View_Strategy, setData, arginfo_yb_view_strategy_setdata, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_View_Strategy, offsetSet, arginfo_yb_view_strategy_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_View_Strategy, offsetGet, arginfo_yb_view_strategy_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_View_Strategy, offsetExists, arginfo_yb_view_strategy_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_View_Strategy, offsetUnset, arginfo_yb_view_strategy_offsetunset, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

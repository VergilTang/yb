
extern zend_class_entry *yb_router_uri_ce;

ZEPHIR_INIT_CLASS(Yb_Router_Uri);

PHP_METHOD(Yb_Router_Uri, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_router_uri___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_ARRAY_INFO(0, patterns, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_router_uri_method_entry) {
	PHP_ME(Yb_Router_Uri, __construct, arginfo_yb_router_uri___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};

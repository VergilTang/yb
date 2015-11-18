
extern zend_class_entry *yb_router_uripatterns_ce;

ZEPHIR_INIT_CLASS(Yb_Router_UriPatterns);

PHP_METHOD(Yb_Router_UriPatterns, __construct);
PHP_METHOD(Yb_Router_UriPatterns, onPregReplaceCallback);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_router_uripatterns___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_ARRAY_INFO(0, rules, 1)
	ZEND_ARG_ARRAY_INFO(0, typePatterns, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_router_uripatterns_onpregreplacecallback, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, matches, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_router_uripatterns_method_entry) {
	PHP_ME(Yb_Router_UriPatterns, __construct, arginfo_yb_router_uripatterns___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_Router_UriPatterns, onPregReplaceCallback, arginfo_yb_router_uripatterns_onpregreplacecallback, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

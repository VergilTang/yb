
extern zend_class_entry *yb_router_patterns_ce;

ZEPHIR_INIT_CLASS(Yb_Router_Patterns);

PHP_METHOD(Yb_Router_Patterns, __construct);
PHP_METHOD(Yb_Router_Patterns, getPatterns);
PHP_METHOD(Yb_Router_Patterns, aliases);
PHP_METHOD(Yb_Router_Patterns, alias);
PHP_METHOD(Yb_Router_Patterns, replaceMatches);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_router_patterns___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, types, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_router_patterns_aliases, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, aliases, 0)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_router_patterns_alias, 0, 0, 2)
	ZEND_ARG_INFO(0, from)
	ZEND_ARG_INFO(0, to)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_router_patterns_replacematches, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, m, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_router_patterns_method_entry) {
	PHP_ME(Yb_Router_Patterns, __construct, arginfo_yb_router_patterns___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_Router_Patterns, getPatterns, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Router_Patterns, aliases, arginfo_yb_router_patterns_aliases, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Router_Patterns, alias, arginfo_yb_router_patterns_alias, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Router_Patterns, replaceMatches, arginfo_yb_router_patterns_replacematches, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

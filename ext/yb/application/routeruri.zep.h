
extern zend_class_entry *yb_application_routeruri_ce;

ZEPHIR_INIT_CLASS(Yb_Application_RouterUri);

PHP_METHOD(Yb_Application_RouterUri, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_application_routeruri___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_application_routeruri_method_entry) {
	PHP_ME(Yb_Application_RouterUri, __construct, arginfo_yb_application_routeruri___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};

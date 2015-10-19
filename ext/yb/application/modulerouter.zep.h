
extern zend_class_entry *yb_application_modulerouter_ce;

ZEPHIR_INIT_CLASS(Yb_Application_ModuleRouter);

PHP_METHOD(Yb_Application_ModuleRouter, __construct);
PHP_METHOD(Yb_Application_ModuleRouter, filterApplication);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_application_modulerouter___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, modules, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_application_modulerouter_filterapplication, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, core, Yb\\Application\\Core, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_application_modulerouter_method_entry) {
	PHP_ME(Yb_Application_ModuleRouter, __construct, arginfo_yb_application_modulerouter___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_Application_ModuleRouter, filterApplication, arginfo_yb_application_modulerouter_filterapplication, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

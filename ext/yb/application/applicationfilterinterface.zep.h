
extern zend_class_entry *yb_application_applicationfilterinterface_ce;

ZEPHIR_INIT_CLASS(Yb_Application_ApplicationFilterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_application_applicationfilterinterface_filterapplication, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, core, Yb\\Application\\Core, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_application_applicationfilterinterface_method_entry) {
	PHP_ABSTRACT_ME(Yb_Application_ApplicationFilterInterface, filterApplication, arginfo_yb_application_applicationfilterinterface_filterapplication)
	PHP_FE_END
};

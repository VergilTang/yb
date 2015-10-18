
extern zend_class_entry *yb_loader_loaderabstract_ce;

ZEPHIR_INIT_CLASS(Yb_Loader_LoaderAbstract);

PHP_METHOD(Yb_Loader_LoaderAbstract, register);
PHP_METHOD(Yb_Loader_LoaderAbstract, unregister);
PHP_METHOD(Yb_Loader_LoaderAbstract, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_loader_loaderabstract___invoke, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_loader_loaderabstract_method_entry) {
	PHP_ME(Yb_Loader_LoaderAbstract, register, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Loader_LoaderAbstract, unregister, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Loader_LoaderAbstract, __invoke, arginfo_yb_loader_loaderabstract___invoke, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};


extern zend_class_entry *yb_loader_loaderabstract_ce;

ZEPHIR_INIT_CLASS(Yb_Loader_LoaderAbstract);

PHP_METHOD(Yb_Loader_LoaderAbstract, isLoaded);
PHP_METHOD(Yb_Loader_LoaderAbstract, __construct);
PHP_METHOD(Yb_Loader_LoaderAbstract, register);
PHP_METHOD(Yb_Loader_LoaderAbstract, unregister);
PHP_METHOD(Yb_Loader_LoaderAbstract, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_loader_loaderabstract_isloaded, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_loader_loaderabstract___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, registerSelf)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_loader_loaderabstract___invoke, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_loader_loaderabstract_method_entry) {
	PHP_ME(Yb_Loader_LoaderAbstract, isLoaded, arginfo_yb_loader_loaderabstract_isloaded, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yb_Loader_LoaderAbstract, __construct, arginfo_yb_loader_loaderabstract___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_Loader_LoaderAbstract, register, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Loader_LoaderAbstract, unregister, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Loader_LoaderAbstract, __invoke, arginfo_yb_loader_loaderabstract___invoke, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};

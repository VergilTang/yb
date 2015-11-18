
extern zend_class_entry *yb_router_routerabstract_ce;

ZEPHIR_INIT_CLASS(Yb_Router_RouterAbstract);

PHP_METHOD(Yb_Router_RouterAbstract, getController);
PHP_METHOD(Yb_Router_RouterAbstract, getAction);
PHP_METHOD(Yb_Router_RouterAbstract, getParams);
PHP_METHOD(Yb_Router_RouterAbstract, getId);
PHP_METHOD(Yb_Router_RouterAbstract, dispatch);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_router_routerabstract_getid, 0, 0, 0)
	ZEND_ARG_INFO(0, separator)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_router_routerabstract_dispatch, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, factory, Yb\\Factory\\FactoryInterface, 0)
	ZEND_ARG_INFO(0, actionSuffix)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_router_routerabstract_method_entry) {
	PHP_ME(Yb_Router_RouterAbstract, getController, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Router_RouterAbstract, getAction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Router_RouterAbstract, getParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Router_RouterAbstract, getId, arginfo_yb_router_routerabstract_getid, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Router_RouterAbstract, dispatch, arginfo_yb_router_routerabstract_dispatch, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

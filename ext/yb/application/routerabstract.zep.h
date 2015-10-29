
extern zend_class_entry *yb_application_routerabstract_ce;

ZEPHIR_INIT_CLASS(Yb_Application_RouterAbstract);

PHP_METHOD(Yb_Application_RouterAbstract, getController);
PHP_METHOD(Yb_Application_RouterAbstract, getAction);
PHP_METHOD(Yb_Application_RouterAbstract, getParams);

ZEPHIR_INIT_FUNCS(yb_application_routerabstract_method_entry) {
	PHP_ME(Yb_Application_RouterAbstract, getController, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Application_RouterAbstract, getAction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Application_RouterAbstract, getParams, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

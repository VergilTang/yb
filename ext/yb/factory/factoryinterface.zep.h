
extern zend_class_entry *yb_factory_factoryinterface_ce;

ZEPHIR_INIT_CLASS(Yb_Factory_FactoryInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_factory_factoryinterface_has, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_factory_factoryinterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_factory_factoryinterface_method_entry) {
	PHP_ABSTRACT_ME(Yb_Factory_FactoryInterface, has, arginfo_yb_factory_factoryinterface_has)
	PHP_ABSTRACT_ME(Yb_Factory_FactoryInterface, get, arginfo_yb_factory_factoryinterface_get)
	PHP_FE_END
};


extern zend_class_entry *yb_factory_factoryinterface_ce;

ZEPHIR_INIT_CLASS(Yb_Factory_FactoryInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_factory_factoryinterface___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_factory_factoryinterface___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_factory_factoryinterface_method_entry) {
	PHP_ABSTRACT_ME(Yb_Factory_FactoryInterface, __isset, arginfo_yb_factory_factoryinterface___isset)
	PHP_ABSTRACT_ME(Yb_Factory_FactoryInterface, __get, arginfo_yb_factory_factoryinterface___get)
	PHP_FE_END
};


extern zend_class_entry *yb_factory_factories_ce;

ZEPHIR_INIT_CLASS(Yb_Factory_Factories);

PHP_METHOD(Yb_Factory_Factories, set);
PHP_METHOD(Yb_Factory_Factories, offsetSet);
PHP_METHOD(Yb_Factory_Factories, offsetGet);
PHP_METHOD(Yb_Factory_Factories, offsetExists);
PHP_METHOD(Yb_Factory_Factories, offsetUnset);
PHP_METHOD(Yb_Factory_Factories, __isset);
PHP_METHOD(Yb_Factory_Factories, __get);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_factory_factories_set, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_OBJ_INFO(0, factory, Yb\\Factory\\FactoryInterface, 0)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_factory_factories_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, factory)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_factory_factories_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_factory_factories_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_factory_factories_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_factory_factories___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_factory_factories___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_factory_factories_method_entry) {
	PHP_ME(Yb_Factory_Factories, set, arginfo_yb_factory_factories_set, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Factory_Factories, offsetSet, arginfo_yb_factory_factories_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Factory_Factories, offsetGet, arginfo_yb_factory_factories_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Factory_Factories, offsetExists, arginfo_yb_factory_factories_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Factory_Factories, offsetUnset, arginfo_yb_factory_factories_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Factory_Factories, __isset, arginfo_yb_factory_factories___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Factory_Factories, __get, arginfo_yb_factory_factories___get, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

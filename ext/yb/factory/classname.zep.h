
extern zend_class_entry *yb_factory_classname_ce;

ZEPHIR_INIT_CLASS(Yb_Factory_ClassName);

PHP_METHOD(Yb_Factory_ClassName, has);
PHP_METHOD(Yb_Factory_ClassName, get);
PHP_METHOD(Yb_Factory_ClassName, getClassName);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_factory_classname_has, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_factory_classname_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_factory_classname_getclassname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_factory_classname_method_entry) {
	PHP_ME(Yb_Factory_ClassName, has, arginfo_yb_factory_classname_has, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Factory_ClassName, get, arginfo_yb_factory_classname_get, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Factory_ClassName, getClassName, arginfo_yb_factory_classname_getclassname, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_FE_END
};

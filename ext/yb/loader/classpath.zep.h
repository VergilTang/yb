
extern zend_class_entry *yb_loader_classpath_ce;

ZEPHIR_INIT_CLASS(Yb_Loader_ClassPath);

PHP_METHOD(Yb_Loader_ClassPath, __construct);
PHP_METHOD(Yb_Loader_ClassPath, __invoke);
PHP_METHOD(Yb_Loader_ClassPath, set);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_loader_classpath___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, classPaths, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_loader_classpath___invoke, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_loader_classpath_set, 0, 0, 2)
	ZEND_ARG_INFO(0, className)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_loader_classpath_method_entry) {
	PHP_ME(Yb_Loader_ClassPath, __construct, arginfo_yb_loader_classpath___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_Loader_ClassPath, __invoke, arginfo_yb_loader_classpath___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Loader_ClassPath, set, arginfo_yb_loader_classpath_set, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

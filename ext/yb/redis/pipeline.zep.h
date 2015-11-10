
extern zend_class_entry *yb_redis_pipeline_ce;

ZEPHIR_INIT_CLASS(Yb_Redis_Pipeline);

PHP_METHOD(Yb_Redis_Pipeline, __construct);
PHP_METHOD(Yb_Redis_Pipeline, __call);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_redis_pipeline___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, client, Yb\\Redis\\Client, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_redis_pipeline___call, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_redis_pipeline_method_entry) {
	PHP_ME(Yb_Redis_Pipeline, __construct, arginfo_yb_redis_pipeline___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_Redis_Pipeline, __call, arginfo_yb_redis_pipeline___call, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

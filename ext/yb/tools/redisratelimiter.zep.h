
extern zend_class_entry *yb_tools_redisratelimiter_ce;

ZEPHIR_INIT_CLASS(Yb_Tools_RedisRateLimiter);

PHP_METHOD(Yb_Tools_RedisRateLimiter, __construct);
PHP_METHOD(Yb_Tools_RedisRateLimiter, pass);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_tools_redisratelimiter___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, redis)
	ZEND_ARG_INFO(0, keyPrefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_tools_redisratelimiter_pass, 0, 0, 3)
	ZEND_ARG_INFO(0, item)
	ZEND_ARG_INFO(0, seconds)
	ZEND_ARG_INFO(0, times)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_tools_redisratelimiter_method_entry) {
	PHP_ME(Yb_Tools_RedisRateLimiter, __construct, arginfo_yb_tools_redisratelimiter___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_Tools_RedisRateLimiter, pass, arginfo_yb_tools_redisratelimiter_pass, ZEND_ACC_PUBLIC)
	PHP_FE_END
};


extern zend_class_entry *yb_ratelimiter_redis_ce;

ZEPHIR_INIT_CLASS(Yb_RateLimiter_Redis);

PHP_METHOD(Yb_RateLimiter_Redis, __construct);
PHP_METHOD(Yb_RateLimiter_Redis, passRateLimiter);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_ratelimiter_redis___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, redis)
	ZEND_ARG_INFO(0, keyPrefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_ratelimiter_redis_passratelimiter, 0, 0, 3)
	ZEND_ARG_INFO(0, item)
	ZEND_ARG_INFO(0, seconds)
	ZEND_ARG_INFO(0, times)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_ratelimiter_redis_method_entry) {
	PHP_ME(Yb_RateLimiter_Redis, __construct, arginfo_yb_ratelimiter_redis___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_RateLimiter_Redis, passRateLimiter, arginfo_yb_ratelimiter_redis_passratelimiter, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

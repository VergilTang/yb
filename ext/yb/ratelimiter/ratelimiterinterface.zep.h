
extern zend_class_entry *yb_ratelimiter_ratelimiterinterface_ce;

ZEPHIR_INIT_CLASS(Yb_RateLimiter_RateLimiterInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_ratelimiter_ratelimiterinterface_passratelimiter, 0, 0, 3)
	ZEND_ARG_INFO(0, item)
	ZEND_ARG_INFO(0, seconds)
	ZEND_ARG_INFO(0, times)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_ratelimiter_ratelimiterinterface_method_entry) {
	PHP_ABSTRACT_ME(Yb_RateLimiter_RateLimiterInterface, passRateLimiter, arginfo_yb_ratelimiter_ratelimiterinterface_passratelimiter)
	PHP_FE_END
};


extern zend_class_entry *yb_data_ratelimiterbackendinterface_ce;

ZEPHIR_INIT_CLASS(Yb_Data_RateLimiterBackendInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_data_ratelimiterbackendinterface_passratelimiter, 0, 0, 4)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, item)
	ZEND_ARG_INFO(0, seconds)
	ZEND_ARG_INFO(0, times)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_data_ratelimiterbackendinterface_method_entry) {
	PHP_ABSTRACT_ME(Yb_Data_RateLimiterBackendInterface, passRateLimiter, arginfo_yb_data_ratelimiterbackendinterface_passratelimiter)
	PHP_FE_END
};

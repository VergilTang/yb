
extern zend_class_entry *yb_data_ratelimiter_ce;

ZEPHIR_INIT_CLASS(Yb_Data_RateLimiter);

PHP_METHOD(Yb_Data_RateLimiter, pass);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_data_ratelimiter_pass, 0, 0, 3)
	ZEND_ARG_INFO(0, item)
	ZEND_ARG_INFO(0, seconds)
	ZEND_ARG_INFO(0, times)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_data_ratelimiter_method_entry) {
	PHP_ME(Yb_Data_RateLimiter, pass, arginfo_yb_data_ratelimiter_pass, ZEND_ACC_PUBLIC)
	PHP_FE_END
};


extern zend_class_entry *yb_logger_nil_ce;

ZEPHIR_INIT_CLASS(Yb_Logger_Nil);

PHP_METHOD(Yb_Logger_Nil, log);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_logger_nil_log, 0, 0, 2)
	ZEND_ARG_INFO(0, level)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_logger_nil_method_entry) {
	PHP_ME(Yb_Logger_Nil, log, arginfo_yb_logger_nil_log, ZEND_ACC_PUBLIC)
	PHP_FE_END
};


extern zend_class_entry *yb_logger_loggerabstract_ce;

ZEPHIR_INIT_CLASS(Yb_Logger_LoggerAbstract);

PHP_METHOD(Yb_Logger_LoggerAbstract, emergency);
PHP_METHOD(Yb_Logger_LoggerAbstract, alert);
PHP_METHOD(Yb_Logger_LoggerAbstract, critical);
PHP_METHOD(Yb_Logger_LoggerAbstract, error);
PHP_METHOD(Yb_Logger_LoggerAbstract, warning);
PHP_METHOD(Yb_Logger_LoggerAbstract, notice);
PHP_METHOD(Yb_Logger_LoggerAbstract, info);
PHP_METHOD(Yb_Logger_LoggerAbstract, debug);
PHP_METHOD(Yb_Logger_LoggerAbstract, log);
PHP_METHOD(Yb_Logger_LoggerAbstract, flush);
PHP_METHOD(Yb_Logger_LoggerAbstract, __destruct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_logger_loggerabstract_emergency, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_logger_loggerabstract_alert, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_logger_loggerabstract_critical, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_logger_loggerabstract_error, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_logger_loggerabstract_warning, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_logger_loggerabstract_notice, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_logger_loggerabstract_info, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_logger_loggerabstract_debug, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_logger_loggerabstract_log, 0, 0, 2)
	ZEND_ARG_INFO(0, level)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_logger_loggerabstract_method_entry) {
	PHP_ME(Yb_Logger_LoggerAbstract, emergency, arginfo_yb_logger_loggerabstract_emergency, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Logger_LoggerAbstract, alert, arginfo_yb_logger_loggerabstract_alert, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Logger_LoggerAbstract, critical, arginfo_yb_logger_loggerabstract_critical, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Logger_LoggerAbstract, error, arginfo_yb_logger_loggerabstract_error, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Logger_LoggerAbstract, warning, arginfo_yb_logger_loggerabstract_warning, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Logger_LoggerAbstract, notice, arginfo_yb_logger_loggerabstract_notice, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Logger_LoggerAbstract, info, arginfo_yb_logger_loggerabstract_info, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Logger_LoggerAbstract, debug, arginfo_yb_logger_loggerabstract_debug, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Logger_LoggerAbstract, log, arginfo_yb_logger_loggerabstract_log, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Logger_LoggerAbstract, flush, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Logger_LoggerAbstract, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_FE_END
};

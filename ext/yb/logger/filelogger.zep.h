
extern zend_class_entry *yb_logger_filelogger_ce;

ZEPHIR_INIT_CLASS(Yb_Logger_FileLogger);

PHP_METHOD(Yb_Logger_FileLogger, __construct);
PHP_METHOD(Yb_Logger_FileLogger, log);
PHP_METHOD(Yb_Logger_FileLogger, flush);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_logger_filelogger___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_logger_filelogger_log, 0, 0, 2)
	ZEND_ARG_INFO(0, level)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_logger_filelogger_method_entry) {
	PHP_ME(Yb_Logger_FileLogger, __construct, arginfo_yb_logger_filelogger___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_Logger_FileLogger, log, arginfo_yb_logger_filelogger_log, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Logger_FileLogger, flush, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

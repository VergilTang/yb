
extern zend_class_entry *yb_redis_connection_ce;

ZEPHIR_INIT_CLASS(Yb_Redis_Connection);

PHP_METHOD(Yb_Redis_Connection, __construct);
PHP_METHOD(Yb_Redis_Connection, __destruct);
PHP_METHOD(Yb_Redis_Connection, __call);
PHP_METHOD(Yb_Redis_Connection, __invoke);
PHP_METHOD(Yb_Redis_Connection, write);
PHP_METHOD(Yb_Redis_Connection, read);
PHP_METHOD(Yb_Redis_Connection, readLine);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_redis_connection___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, host)
	ZEND_ARG_INFO(0, port)
	ZEND_ARG_INFO(0, timeout)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_redis_connection___call, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_redis_connection___invoke, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, cmds, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_redis_connection_write, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_redis_connection_method_entry) {
	PHP_ME(Yb_Redis_Connection, __construct, arginfo_yb_redis_connection___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_Redis_Connection, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(Yb_Redis_Connection, __call, arginfo_yb_redis_connection___call, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Redis_Connection, __invoke, arginfo_yb_redis_connection___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Redis_Connection, write, arginfo_yb_redis_connection_write, ZEND_ACC_PROTECTED)
	PHP_ME(Yb_Redis_Connection, read, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Yb_Redis_Connection, readLine, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

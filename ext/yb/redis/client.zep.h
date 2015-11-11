
extern zend_class_entry *yb_redis_client_ce;

ZEPHIR_INIT_CLASS(Yb_Redis_Client);

PHP_METHOD(Yb_Redis_Client, hashSlot);
PHP_METHOD(Yb_Redis_Client, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_redis_client_hashslot, 0, 0, 1)
	ZEND_ARG_INFO(0, s)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_redis_client___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, connection, Yb\\Redis\\Connection, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_redis_client_method_entry) {
	PHP_ME(Yb_Redis_Client, hashSlot, arginfo_yb_redis_client_hashslot, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yb_Redis_Client, __construct, arginfo_yb_redis_client___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};

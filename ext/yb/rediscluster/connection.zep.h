
extern zend_class_entry *yb_rediscluster_connection_ce;

ZEPHIR_INIT_CLASS(Yb_RedisCluster_Connection);

PHP_METHOD(Yb_RedisCluster_Connection, __construct);
PHP_METHOD(Yb_RedisCluster_Connection, getInternalHandler);
PHP_METHOD(Yb_RedisCluster_Connection, __call);
PHP_METHOD(Yb_RedisCluster_Connection, runCommand);
PHP_METHOD(Yb_RedisCluster_Connection, runCommands);
PHP_METHOD(Yb_RedisCluster_Connection, __destruct);
PHP_METHOD(Yb_RedisCluster_Connection, write);
PHP_METHOD(Yb_RedisCluster_Connection, read);
PHP_METHOD(Yb_RedisCluster_Connection, readBlock);
PHP_METHOD(Yb_RedisCluster_Connection, newError);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_rediscluster_connection___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_rediscluster_connection___call, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_rediscluster_connection_runcommand, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, cmd, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_rediscluster_connection_runcommands, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, cmds, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_rediscluster_connection_write, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_rediscluster_connection_readblock, 0, 0, 0)
	ZEND_ARG_INFO(0, len)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_rediscluster_connection_newerror, 0, 0, 1)
	ZEND_ARG_INFO(0, error)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_rediscluster_connection_method_entry) {
	PHP_ME(Yb_RedisCluster_Connection, __construct, arginfo_yb_rediscluster_connection___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_RedisCluster_Connection, getInternalHandler, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_RedisCluster_Connection, __call, arginfo_yb_rediscluster_connection___call, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_RedisCluster_Connection, runCommand, arginfo_yb_rediscluster_connection_runcommand, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_RedisCluster_Connection, runCommands, arginfo_yb_rediscluster_connection_runcommands, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_RedisCluster_Connection, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(Yb_RedisCluster_Connection, write, arginfo_yb_rediscluster_connection_write, ZEND_ACC_PROTECTED)
	PHP_ME(Yb_RedisCluster_Connection, read, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Yb_RedisCluster_Connection, readBlock, arginfo_yb_rediscluster_connection_readblock, ZEND_ACC_PROTECTED)
	PHP_ME(Yb_RedisCluster_Connection, newError, arginfo_yb_rediscluster_connection_newerror, ZEND_ACC_PROTECTED)
	PHP_FE_END
};


extern zend_class_entry *yb_rediscluster_client_ce;

ZEPHIR_INIT_CLASS(Yb_RedisCluster_Client);

PHP_METHOD(Yb_RedisCluster_Client, __construct);
PHP_METHOD(Yb_RedisCluster_Client, runCommandByKey);
PHP_METHOD(Yb_RedisCluster_Client, runCommandsByKey);
PHP_METHOD(Yb_RedisCluster_Client, runCommandsByKeyInternally);
PHP_METHOD(Yb_RedisCluster_Client, getConnectionBySlot);
PHP_METHOD(Yb_RedisCluster_Client, getConnection);
PHP_METHOD(Yb_RedisCluster_Client, newConnection);
PHP_METHOD(Yb_RedisCluster_Client, refleshSlots);
PHP_METHOD(Yb_RedisCluster_Client, onMoved);
PHP_METHOD(Yb_RedisCluster_Client, onAsk);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_rediscluster_client___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, slotsCacher, Yb\\DataCacher\\DataCacherInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_rediscluster_client_runcommandbykey, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_ARRAY_INFO(0, cmd, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_rediscluster_client_runcommandsbykey, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_ARRAY_INFO(0, cmds, 0)
	ZEND_ARG_INFO(0, resultProcessor)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_rediscluster_client_runcommandsbykeyinternally, 0, 0, 4)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_ARRAY_INFO(0, cmds, 0)
	ZEND_ARG_INFO(0, resultProcessor)
	ZEND_ARG_INFO(0, twice)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_rediscluster_client_getconnectionbyslot, 0, 0, 1)
	ZEND_ARG_INFO(0, slot)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_rediscluster_client_getconnection, 0, 0, 2)
	ZEND_ARG_INFO(0, host)
	ZEND_ARG_INFO(0, port)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_rediscluster_client_newconnection, 0, 0, 2)
	ZEND_ARG_INFO(0, host)
	ZEND_ARG_INFO(0, port)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_rediscluster_client_refleshslots, 0, 0, 2)
	ZEND_ARG_INFO(0, host)
	ZEND_ARG_INFO(0, port)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_rediscluster_client_onmoved, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, error, Yb\\RedisCluster\\ErrorMoved, 0)
	ZEND_ARG_ARRAY_INFO(0, cmd, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_rediscluster_client_onask, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, error, Yb\\RedisCluster\\ErrorAsk, 0)
	ZEND_ARG_ARRAY_INFO(0, cmd, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_rediscluster_client_method_entry) {
	PHP_ME(Yb_RedisCluster_Client, __construct, arginfo_yb_rediscluster_client___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_RedisCluster_Client, runCommandByKey, arginfo_yb_rediscluster_client_runcommandbykey, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_RedisCluster_Client, runCommandsByKey, arginfo_yb_rediscluster_client_runcommandsbykey, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_RedisCluster_Client, runCommandsByKeyInternally, arginfo_yb_rediscluster_client_runcommandsbykeyinternally, ZEND_ACC_PROTECTED)
	PHP_ME(Yb_RedisCluster_Client, getConnectionBySlot, arginfo_yb_rediscluster_client_getconnectionbyslot, ZEND_ACC_PROTECTED)
	PHP_ME(Yb_RedisCluster_Client, getConnection, arginfo_yb_rediscluster_client_getconnection, ZEND_ACC_PROTECTED)
	PHP_ME(Yb_RedisCluster_Client, newConnection, arginfo_yb_rediscluster_client_newconnection, ZEND_ACC_PROTECTED)
	PHP_ME(Yb_RedisCluster_Client, refleshSlots, arginfo_yb_rediscluster_client_refleshslots, ZEND_ACC_PROTECTED)
	PHP_ME(Yb_RedisCluster_Client, onMoved, arginfo_yb_rediscluster_client_onmoved, ZEND_ACC_PROTECTED)
	PHP_ME(Yb_RedisCluster_Client, onAsk, arginfo_yb_rediscluster_client_onask, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

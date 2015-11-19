
extern zend_class_entry *yb_redis_cluster_ce;

ZEPHIR_INIT_CLASS(Yb_Redis_Cluster);

PHP_METHOD(Yb_Redis_Cluster, __construct);
PHP_METHOD(Yb_Redis_Cluster, runCommandByKey);
PHP_METHOD(Yb_Redis_Cluster, runCommandsByKey);
PHP_METHOD(Yb_Redis_Cluster, runCommandsByKeyInternally);
PHP_METHOD(Yb_Redis_Cluster, getConnectionBySlot);
PHP_METHOD(Yb_Redis_Cluster, getConnection);
PHP_METHOD(Yb_Redis_Cluster, newConnection);
PHP_METHOD(Yb_Redis_Cluster, refleshSlots);
PHP_METHOD(Yb_Redis_Cluster, onMoved);
PHP_METHOD(Yb_Redis_Cluster, onAsk);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_redis_cluster___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, slotsCacher, Yb\\DataCacher\\DataCacherInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_redis_cluster_runcommandbykey, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_ARRAY_INFO(0, cmd, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_redis_cluster_runcommandsbykey, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_ARRAY_INFO(0, cmds, 0)
	ZEND_ARG_INFO(0, resultProcessor)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_redis_cluster_runcommandsbykeyinternally, 0, 0, 4)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_ARRAY_INFO(0, cmds, 0)
	ZEND_ARG_INFO(0, resultProcessor)
	ZEND_ARG_INFO(0, twice)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_redis_cluster_getconnectionbyslot, 0, 0, 1)
	ZEND_ARG_INFO(0, slot)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_redis_cluster_getconnection, 0, 0, 2)
	ZEND_ARG_INFO(0, host)
	ZEND_ARG_INFO(0, port)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_redis_cluster_newconnection, 0, 0, 2)
	ZEND_ARG_INFO(0, host)
	ZEND_ARG_INFO(0, port)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_redis_cluster_refleshslots, 0, 0, 2)
	ZEND_ARG_INFO(0, host)
	ZEND_ARG_INFO(0, port)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_redis_cluster_onmoved, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, error, Yb\\Redis\\ErrorMoved, 0)
	ZEND_ARG_ARRAY_INFO(0, cmd, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_redis_cluster_onask, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, error, Yb\\Redis\\ErrorAsk, 0)
	ZEND_ARG_ARRAY_INFO(0, cmd, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_redis_cluster_method_entry) {
	PHP_ME(Yb_Redis_Cluster, __construct, arginfo_yb_redis_cluster___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_Redis_Cluster, runCommandByKey, arginfo_yb_redis_cluster_runcommandbykey, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Redis_Cluster, runCommandsByKey, arginfo_yb_redis_cluster_runcommandsbykey, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Redis_Cluster, runCommandsByKeyInternally, arginfo_yb_redis_cluster_runcommandsbykeyinternally, ZEND_ACC_PROTECTED)
	PHP_ME(Yb_Redis_Cluster, getConnectionBySlot, arginfo_yb_redis_cluster_getconnectionbyslot, ZEND_ACC_PROTECTED)
	PHP_ME(Yb_Redis_Cluster, getConnection, arginfo_yb_redis_cluster_getconnection, ZEND_ACC_PROTECTED)
	PHP_ME(Yb_Redis_Cluster, newConnection, arginfo_yb_redis_cluster_newconnection, ZEND_ACC_PROTECTED)
	PHP_ME(Yb_Redis_Cluster, refleshSlots, arginfo_yb_redis_cluster_refleshslots, ZEND_ACC_PROTECTED)
	PHP_ME(Yb_Redis_Cluster, onMoved, arginfo_yb_redis_cluster_onmoved, ZEND_ACC_PROTECTED)
	PHP_ME(Yb_Redis_Cluster, onAsk, arginfo_yb_redis_cluster_onask, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

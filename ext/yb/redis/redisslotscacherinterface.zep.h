
extern zend_class_entry *yb_redis_redisslotscacherinterface_ce;

ZEPHIR_INIT_CLASS(Yb_Redis_RedisSlotsCacherInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_redis_redisslotscacherinterface_storeslots, 0, 0, 1)
	ZEND_ARG_INFO(0, slots)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_redis_redisslotscacherinterface_method_entry) {
	PHP_ABSTRACT_ME(Yb_Redis_RedisSlotsCacherInterface, storeSlots, arginfo_yb_redis_redisslotscacherinterface_storeslots)
	PHP_ABSTRACT_ME(Yb_Redis_RedisSlotsCacherInterface, fetchSlots, NULL)
	PHP_FE_END
};

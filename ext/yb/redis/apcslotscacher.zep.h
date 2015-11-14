
extern zend_class_entry *yb_redis_apcslotscacher_ce;

ZEPHIR_INIT_CLASS(Yb_Redis_ApcSlotsCacher);

PHP_METHOD(Yb_Redis_ApcSlotsCacher, __construct);
PHP_METHOD(Yb_Redis_ApcSlotsCacher, storeSlots);
PHP_METHOD(Yb_Redis_ApcSlotsCacher, fetchSlots);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_redis_apcslotscacher___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, cacheKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_redis_apcslotscacher_storeslots, 0, 0, 1)
	ZEND_ARG_INFO(0, slots)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_redis_apcslotscacher_method_entry) {
	PHP_ME(Yb_Redis_ApcSlotsCacher, __construct, arginfo_yb_redis_apcslotscacher___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_Redis_ApcSlotsCacher, storeSlots, arginfo_yb_redis_apcslotscacher_storeslots, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Redis_ApcSlotsCacher, fetchSlots, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

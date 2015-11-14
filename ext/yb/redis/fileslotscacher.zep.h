
extern zend_class_entry *yb_redis_fileslotscacher_ce;

ZEPHIR_INIT_CLASS(Yb_Redis_FileSlotsCacher);

PHP_METHOD(Yb_Redis_FileSlotsCacher, __construct);
PHP_METHOD(Yb_Redis_FileSlotsCacher, storeSlots);
PHP_METHOD(Yb_Redis_FileSlotsCacher, fetchSlots);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_redis_fileslotscacher___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_redis_fileslotscacher_storeslots, 0, 0, 1)
	ZEND_ARG_INFO(0, slots)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_redis_fileslotscacher_method_entry) {
	PHP_ME(Yb_Redis_FileSlotsCacher, __construct, arginfo_yb_redis_fileslotscacher___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_Redis_FileSlotsCacher, storeSlots, arginfo_yb_redis_fileslotscacher_storeslots, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Redis_FileSlotsCacher, fetchSlots, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

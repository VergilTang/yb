
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Yb_Redis_RedisSlotsCacherInterface) {

	ZEPHIR_REGISTER_INTERFACE(Yb\\Redis, RedisSlotsCacherInterface, yb, redis_redisslotscacherinterface, yb_redis_redisslotscacherinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Yb_Redis_RedisSlotsCacherInterface, storeSlots);

ZEPHIR_DOC_METHOD(Yb_Redis_RedisSlotsCacherInterface, fetchSlots);


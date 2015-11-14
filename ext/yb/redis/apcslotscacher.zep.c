
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Yb_Redis_ApcSlotsCacher) {

	ZEPHIR_REGISTER_CLASS(Yb\\Redis, ApcSlotsCacher, yb, redis_apcslotscacher, yb_redis_apcslotscacher_method_entry, 0);

	zend_declare_property_null(yb_redis_apcslotscacher_ce, SL("cacheKey"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(yb_redis_apcslotscacher_ce, SL("DEFAULT_CACHE_KEY"), "redis-slots" TSRMLS_CC);

	zend_class_implements(yb_redis_apcslotscacher_ce TSRMLS_CC, 1, yb_redis_redisslotscacherinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Yb_Redis_ApcSlotsCacher, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *cacheKey_param = NULL, _0, *_1 = NULL;
	zval *cacheKey = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &cacheKey_param);

	if (!cacheKey_param) {
		ZEPHIR_INIT_VAR(cacheKey);
		ZVAL_STRING(cacheKey, "redis-slots", 1);
	} else {
		zephir_get_strval(cacheKey, cacheKey_param);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "apc", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 11, &_0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_redis_exception_ce, "Missing extension: apc", "yb/redis/apcslotscacher.zep", 12);
		return;
	}
	zephir_update_property_this(this_ptr, SL("cacheKey"), cacheKey TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Redis_ApcSlotsCacher, storeSlots) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *slots, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &slots);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("cacheKey"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "apc_store", NULL, 92, _0, slots);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_redis_exception_ce, "Cannot store slots: apc_store", "yb/redis/apcslotscacher.zep", 21);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Redis_ApcSlotsCacher, fetchSlots) {

	zval *slots = NULL, *success = NULL, *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(success);
	ZVAL_NULL(success);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("cacheKey"), PH_NOISY_CC);
	ZEPHIR_MAKE_REF(success);
	ZEPHIR_CALL_FUNCTION(&slots, "apc_fetch", NULL, 93, _0, success);
	ZEPHIR_UNREF(success);
	zephir_check_call_status();
	if (zephir_is_true(success)) {
		RETURN_CCTOR(slots);
	}
	ZEPHIR_MM_RESTORE();

}


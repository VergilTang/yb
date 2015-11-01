
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/time.h"
#include "kernel/fcall.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Yb_RateLimiter_Redis) {

	ZEPHIR_REGISTER_CLASS(Yb\\RateLimiter, Redis, yb, ratelimiter_redis, yb_ratelimiter_redis_method_entry, 0);

	zend_declare_property_null(yb_ratelimiter_redis_ce, SL("redis"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_ratelimiter_redis_ce, SL("keyPrefix"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(yb_ratelimiter_redis_ce, SL("DEFAULT_KEY_PREFIX"), "rate_limiter:" TSRMLS_CC);

	zend_class_implements(yb_ratelimiter_redis_ce TSRMLS_CC, 1, yb_ratelimiter_ratelimiterinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Yb_RateLimiter_Redis, __construct) {

	zval *keyPrefix = NULL;
	zval *redis, *keyPrefix_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &redis, &keyPrefix_param);

	if (!keyPrefix_param) {
		ZEPHIR_INIT_VAR(keyPrefix);
		ZVAL_STRING(keyPrefix, "rate_limiter:", 1);
	} else {
		zephir_get_strval(keyPrefix, keyPrefix_param);
	}


	zephir_update_property_this(this_ptr, SL("redis"), redis TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("keyPrefix"), keyPrefix TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_RateLimiter_Redis, passRateLimiter) {

	zend_bool _13$$5, _14$$5;
	int ZEPHIR_LAST_CALL_STATUS;
	long seconds, times;
	zval *item_param = NULL, *seconds_param = NULL, *times_param = NULL, *value = NULL, *result = NULL, *_0, *_1, _2, _3, _4, *_5 = NULL, *_6, *_7, *_15, *_16, *_8$$5, *_9$$5 = NULL, *_10$$5 = NULL, *_11$$5 = NULL, *_12$$5 = NULL;
	zval *item = NULL, *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &item_param, &seconds_param, &times_param);

	zephir_get_strval(item, item_param);
	seconds = zephir_get_intval(seconds_param);
	times = zephir_get_intval(times_param);


	if (seconds < 1) {
		seconds = 1;
	}
	if (times < 1) {
		times = 1;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("keyPrefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_time(_1);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, ":%d:%d", 0);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, seconds);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_DOUBLE(&_4, zephir_safe_div_zval_long(_1, seconds TSRMLS_CC));
	ZEPHIR_CALL_FUNCTION(&_5, "sprintf", NULL, 1, &_2, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_CONCAT_VVV(_6, _0, item, _5);
	zephir_get_strval(key, _6);
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&value, _7, "get", NULL, 0, key);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(value)) {
		_8$$5 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_9$$5, _8$$5, "multi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_11$$5);
		ZVAL_LONG(_11$$5, 1);
		ZEPHIR_CALL_METHOD(&_10$$5, _9$$5, "incr", NULL, 0, key, _11$$5);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_11$$5);
		ZVAL_LONG(_11$$5, (seconds + 1));
		ZEPHIR_CALL_METHOD(&_12$$5, _10$$5, "expire", NULL, 0, key, _11$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&result, _12$$5, "exec", NULL, 0);
		zephir_check_call_status();
		_13$$5 = Z_TYPE_P(result) == IS_ARRAY;
		if (_13$$5) {
			ZEPHIR_OBS_NVAR(value);
			_13$$5 = zephir_array_isset_long_fetch(&value, result, 0, 0 TSRMLS_CC);
		}
		_14$$5 = _13$$5;
		if (_14$$5) {
			_14$$5 = ZEPHIR_LE_LONG(value, times);
		}
		if (_14$$5) {
			RETURN_MM_BOOL(1);
		}
		RETURN_MM_BOOL(0);
	}
	if (ZEPHIR_GE_LONG(value, times)) {
		RETURN_MM_BOOL(0);
	}
	_15 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_16);
	ZVAL_LONG(_16, 1);
	ZEPHIR_CALL_METHOD(&value, _15, "incr", NULL, 0, key, _16);
	zephir_check_call_status();
	if (ZEPHIR_GT_LONG(value, times)) {
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}


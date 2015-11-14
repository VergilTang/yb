
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/variables.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/require.h"


ZEPHIR_INIT_CLASS(Yb_Redis_FileSlotsCacher) {

	ZEPHIR_REGISTER_CLASS(Yb\\Redis, FileSlotsCacher, yb, redis_fileslotscacher, yb_redis_fileslotscacher_method_entry, 0);

	zend_declare_property_null(yb_redis_fileslotscacher_ce, SL("path"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(yb_redis_fileslotscacher_ce TSRMLS_CC, 1, yb_redis_redisslotscacherinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Yb_Redis_FileSlotsCacher, __construct) {

	zval *path_param = NULL;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(path, path_param);


	zephir_update_property_this(this_ptr, SL("path"), path TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Redis_FileSlotsCacher, storeSlots) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *slots, *_0, *_1 = NULL, _2 = zval_used_for_init, *_3 = NULL, *_4 = NULL, *_5$$3, *_6$$3, *_7$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &slots);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("path"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_INIT_NVAR(_1);
	zephir_var_export_ex(_1, &slots TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "<?php return %s;", 0);
	ZEPHIR_CALL_FUNCTION(&_3, "sprintf", NULL, 1, &_2, _1);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_LONG(&_2, 2);
	ZEPHIR_CALL_FUNCTION(&_4, "file_put_contents", NULL, 76, _0, _3, &_2);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_4))) {
		ZEPHIR_INIT_VAR(_5$$3);
		object_init_ex(_5$$3, yb_redis_exception_ce);
		_6$$3 = zephir_fetch_nproperty_this(this_ptr, SL("path"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_7$$3);
		ZEPHIR_CONCAT_SV(_7$$3, "Cannot write slots to path: ", _6$$3);
		ZEPHIR_CALL_METHOD(NULL, _5$$3, "__construct", NULL, 2, _7$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_5$$3, "yb/redis/fileslotscacher.zep", 15 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Redis_FileSlotsCacher, fetchSlots) {

	zval *_0, *_1$$3, *_2$$3 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("path"), PH_NOISY_CC);
	if ((zephir_file_exists(_0 TSRMLS_CC) == SUCCESS)) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("path"), PH_NOISY_CC);
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_2$$3);
		if (zephir_require_zval_ret(&_2$$3, _1$$3 TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
		RETURN_CCTOR(_2$$3);
	}
	ZEPHIR_MM_RESTORE();

}


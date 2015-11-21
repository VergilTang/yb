
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


ZEPHIR_INIT_CLASS(Yb_DataCacher_Apc) {

	ZEPHIR_REGISTER_CLASS(Yb\\DataCacher, Apc, yb, datacacher_apc, yb_datacacher_apc_method_entry, 0);

	zend_declare_property_null(yb_datacacher_apc_ce, SL("cacheKey"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(yb_datacacher_apc_ce TSRMLS_CC, 1, yb_datacacher_datacacherinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Yb_DataCacher_Apc, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *cacheKey_param = NULL, _0, *_1 = NULL;
	zval *cacheKey = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cacheKey_param);

	zephir_get_strval(cacheKey, cacheKey_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "apc", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 11, &_0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_datacacher_exception_ce, "Missing extension: apc", "yb/datacacher/apc.zep", 10);
		return;
	}
	zephir_update_property_this(this_ptr, SL("cacheKey"), cacheKey TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_DataCacher_Apc, storeData) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("cacheKey"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "apc_store", NULL, 37, _0, data);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_datacacher_exception_ce, "Cannot store data: apc_store", "yb/datacacher/apc.zep", 19);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_DataCacher_Apc, fetchData) {

	zval *data = NULL, *success = NULL, *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(success);
	ZVAL_NULL(success);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("cacheKey"), PH_NOISY_CC);
	ZEPHIR_MAKE_REF(success);
	ZEPHIR_CALL_FUNCTION(&data, "apc_fetch", NULL, 38, _0, success);
	ZEPHIR_UNREF(success);
	zephir_check_call_status();
	if (zephir_is_true(success)) {
		RETURN_CCTOR(data);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_DataCacher_Apc, forgetData) {

	zval *_0, *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("cacheKey"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "apc_delete", NULL, 39, _0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_datacacher_exception_ce, "Cannot forget data: apc_delete", "yb/datacacher/apc.zep", 36);
		return;
	}
	ZEPHIR_MM_RESTORE();

}


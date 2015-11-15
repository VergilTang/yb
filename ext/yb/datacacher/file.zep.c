
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


ZEPHIR_INIT_CLASS(Yb_DataCacher_File) {

	ZEPHIR_REGISTER_CLASS(Yb\\DataCacher, File, yb, datacacher_file, yb_datacacher_file_method_entry, 0);

	zend_declare_property_null(yb_datacacher_file_ce, SL("path"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(yb_datacacher_file_ce TSRMLS_CC, 1, yb_datacacher_datacacherinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Yb_DataCacher_File, __construct) {

	zval *path_param = NULL;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(path, path_param);


	zephir_update_property_this(this_ptr, SL("path"), path TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_DataCacher_File, storeData) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data, *_0, *_1 = NULL, _2 = zval_used_for_init, *_3 = NULL, *_4 = NULL, *_5$$3, *_6$$3, *_7$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("path"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_INIT_NVAR(_1);
	zephir_var_export_ex(_1, &data TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "<?php return %s;", 0);
	ZEPHIR_CALL_FUNCTION(&_3, "sprintf", NULL, 1, &_2, _1);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_LONG(&_2, 2);
	ZEPHIR_CALL_FUNCTION(&_4, "file_put_contents", NULL, 37, _0, _3, &_2);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_4))) {
		ZEPHIR_INIT_VAR(_5$$3);
		object_init_ex(_5$$3, yb_datacacher_exception_ce);
		_6$$3 = zephir_fetch_nproperty_this(this_ptr, SL("path"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_7$$3);
		ZEPHIR_CONCAT_SV(_7$$3, "Cannot write data to path: ", _6$$3);
		ZEPHIR_CALL_METHOD(NULL, _5$$3, "__construct", NULL, 2, _7$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_5$$3, "yb/datacacher/file.zep", 15 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_DataCacher_File, fetchData) {

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

PHP_METHOD(Yb_DataCacher_File, forgetData) {

	zend_bool _1;
	zval *_0, *_2, *_3 = NULL, *_4$$3, *_5$$3, *_6$$3;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("path"), PH_NOISY_CC);
	_1 = (zephir_file_exists(_0 TSRMLS_CC) == SUCCESS);
	if (_1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("path"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_3, "unlink", NULL, 38, _2);
		zephir_check_call_status();
		_1 = !zephir_is_true(_3);
	}
	if (unlikely(_1)) {
		ZEPHIR_INIT_VAR(_4$$3);
		object_init_ex(_4$$3, yb_datacacher_exception_ce);
		_5$$3 = zephir_fetch_nproperty_this(this_ptr, SL("path"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_6$$3);
		ZEPHIR_CONCAT_SV(_6$$3, "Cannot forget data in path: ", _5$$3);
		ZEPHIR_CALL_METHOD(NULL, _4$$3, "__construct", NULL, 2, _6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_4$$3, "yb/datacacher/file.zep", 29 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}


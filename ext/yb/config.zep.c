
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/require.h"
#include "kernel/fcall.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Yb_Config) {

	ZEPHIR_REGISTER_CLASS(Yb, Config, yb, config, yb_config_method_entry, 0);

	zend_declare_property_null(yb_config_ce, SL("dirs"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_config_ce, SL("exts"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_config_ce, SL("configs"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Yb_Config, __construct) {

	HashTable *_1, *_4;
	HashPosition _0, _3;
	zval *dirs_param = NULL, *exts_param = NULL, *i = NULL, **_2, **_5;
	zval *dirs = NULL, *exts = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &dirs_param, &exts_param);

	zephir_get_arrval(dirs, dirs_param);
	if (!exts_param) {
		ZEPHIR_INIT_VAR(exts);
		array_init(exts);
	} else {
		zephir_get_arrval(exts, exts_param);
	}


	if (unlikely(zephir_fast_count_int(exts TSRMLS_CC) < 1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_exception_ce, "Empty exts", "yb/config.zep", 14);
		return;
	}
	zephir_is_iterable(dirs, &_1, &_0, 0, 0, "yb/config.zep", 20);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(i, _2);
		zephir_update_property_array(this_ptr, SL("dirs"), i, i TSRMLS_CC);
	}
	zephir_is_iterable(exts, &_4, &_3, 0, 0, "yb/config.zep", 23);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HVALUE(i, _5);
		zephir_update_property_array(this_ptr, SL("exts"), i, i TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Config, addDir) {

	zval *dir_param = NULL, *_0;
	zval *dir = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dir_param);

	zephir_get_strval(dir, dir_param);


	zephir_update_property_array(this_ptr, SL("dirs"), dir, dir TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("configs"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Config, __get) {

	HashTable *_3, *_7$$4;
	HashPosition _2, _6$$4;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_12 = NULL;
	zval *name_param = NULL, *config = NULL, *d = NULL, *e = NULL, *c = NULL, *_0, *_1, **_4, *_5$$4, **_8$$4, *_9$$5 = NULL, *_10$$6 = NULL, *_11$$7 = NULL;
	zval *name = NULL, *p = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	ZEPHIR_OBS_VAR(config);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("configs"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&config, _0, name, 0 TSRMLS_CC)) {
		RETURN_CCTOR(config);
	}
	ZEPHIR_INIT_NVAR(config);
	array_init(config);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("dirs"), PH_NOISY_CC);
	zephir_is_iterable(_1, &_3, &_2, 0, 0, "yb/config.zep", 55);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(d, _4);
		_5$$4 = zephir_fetch_nproperty_this(this_ptr, SL("exts"), PH_NOISY_CC);
		zephir_is_iterable(_5$$4, &_7$$4, &_6$$4, 0, 0, "yb/config.zep", 53);
		for (
		  ; zephir_hash_get_current_data_ex(_7$$4, (void**) &_8$$4, &_6$$4) == SUCCESS
		  ; zephir_hash_move_forward_ex(_7$$4, &_6$$4)
		) {
			ZEPHIR_GET_HVALUE(e, _8$$4);
			ZEPHIR_INIT_LNVAR(_9$$5);
			ZEPHIR_CONCAT_VSVSV(_9$$5, d, "/", name, ".", e);
			zephir_get_strval(p, _9$$5);
			if ((zephir_file_exists(p TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_10$$6);
				if (zephir_require_zval_ret(&_10$$6, p TSRMLS_CC) == FAILURE) {
					RETURN_MM_NULL();
				}
				ZEPHIR_CPY_WRT(c, _10$$6);
				if (Z_TYPE_P(c) == IS_ARRAY) {
					ZEPHIR_CALL_FUNCTION(&_11$$7, "array_replace_recursive", &_12, 2, config, c);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(config, _11$$7);
				}
			}
		}
	}
	zephir_update_property_array(this_ptr, SL("configs"), name, config TSRMLS_CC);
	RETURN_CCTOR(config);

}

PHP_METHOD(Yb_Config, get) {

	zend_bool _6$$3;
	HashTable *_4;
	HashPosition _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *defaultValue = NULL, *parts = NULL, *part = NULL, *returnValue = NULL, *tmpValue = NULL, _0, *_1 = NULL, **_5;
	zval *name = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &defaultValue);

	zephir_get_strval(name, name_param);
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, '.');
	ZEPHIR_INIT_VAR(parts);
	zephir_fast_explode(parts, &_0, name, LONG_MAX TSRMLS_CC);
	ZEPHIR_MAKE_REF(parts);
	ZEPHIR_CALL_FUNCTION(&_1, "array_shift", NULL, 3, parts);
	ZEPHIR_UNREF(parts);
	zephir_check_call_status();
	zephir_get_strval(_2, _1);
	ZEPHIR_CALL_METHOD(&returnValue, this_ptr, "__get", NULL, 0, _2);
	zephir_check_call_status();
	zephir_is_iterable(parts, &_4, &_3, 0, 0, "yb/config.zep", 74);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HVALUE(part, _5);
		_6$$3 = Z_TYPE_P(returnValue) != IS_ARRAY;
		if (!(_6$$3)) {
			_6$$3 = !(zephir_array_isset_fetch(&tmpValue, returnValue, part, 1 TSRMLS_CC));
		}
		if (_6$$3) {
			RETVAL_ZVAL(defaultValue, 1, 0);
			RETURN_MM();
		}
		ZEPHIR_CPY_WRT(returnValue, tmpValue);
	}
	RETURN_CCTOR(returnValue);

}


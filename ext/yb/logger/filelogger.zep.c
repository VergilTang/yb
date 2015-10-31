
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
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Yb_Logger_FileLogger) {

	ZEPHIR_REGISTER_CLASS_EX(Yb\\Logger, FileLogger, yb, logger_filelogger, yb_logger_loggerabstract_ce, yb_logger_filelogger_method_entry, 0);

	zend_declare_property_null(yb_logger_filelogger_ce, SL("path"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Yb_Logger_FileLogger, __construct) {

	zval *path_param = NULL;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(path, path_param);


	zephir_update_property_this(this_ptr, SL("path"), path TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Logger_FileLogger, log) {

	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *level_param = NULL, *message_param = NULL, *context_param = NULL, *k = NULL, *v = NULL, *replace = NULL, **_2, _5 = zval_used_for_init, *_6 = NULL, *_7 = NULL, *_8 = NULL, *_4$$3 = NULL;
	zval *level = NULL, *message = NULL, *_3$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &level_param, &message_param, &context_param);

	zephir_get_strval(level, level_param);
	zephir_get_strval(message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_INIT_VAR(replace);
	array_init(replace);
	zephir_is_iterable(context, &_1, &_0, 0, 0, "yb/logger/filelogger.zep", 20);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		zephir_get_strval(_3$$3, v);
		ZEPHIR_INIT_LNVAR(_4$$3);
		ZEPHIR_CONCAT_SVS(_4$$3, "{", k, "}");
		zephir_array_update_zval(&replace, _4$$3, &_3$$3, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_STRING(&_5, "c", 0);
	ZEPHIR_CALL_FUNCTION(&_6, "date", NULL, 71, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_7, "strtr", NULL, 72, message, replace);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_STRING(&_5, "[%s] [%s] %s\n", 0);
	ZEPHIR_CALL_FUNCTION(&_8, "sprintf", NULL, 1, &_5, _6, level, _7);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("logs"), _8 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Logger_FileLogger, flush) {

	zval *_0, *_1, *_2, *_3, _4, *_5 = NULL, *_6$$4, *_7$$4, *_8$$4;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("logs"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		RETURN_MM_NULL();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("path"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("logs"), PH_NOISY_CC);
	zephir_fast_join_str(_2, SL(""), _3 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, (2 | 8));
	ZEPHIR_CALL_FUNCTION(&_5, "file_put_contents", NULL, 73, _1, _2, &_4);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_5))) {
		ZEPHIR_INIT_VAR(_6$$4);
		object_init_ex(_6$$4, yb_logger_exception_ce);
		_7$$4 = zephir_fetch_nproperty_this(this_ptr, SL("path"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_8$$4);
		ZEPHIR_CONCAT_SV(_8$$4, "Cannot append logs to file: ", _7$$4);
		ZEPHIR_CALL_METHOD(NULL, _6$$4, "__construct", NULL, 2, _8$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_6$$4, "yb/logger/filelogger.zep", 35 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_this(this_ptr, SL("logs"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}


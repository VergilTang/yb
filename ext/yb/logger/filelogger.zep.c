
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
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


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

	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *level_param = NULL, *message_param = NULL, *context_param = NULL, _0 = zval_used_for_init, *_1 = NULL, *_2 = NULL, *_4 = NULL;
	zval *level = NULL, *message = NULL;

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


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "c", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "date", NULL, 74, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_2, yb_std_ce, "tr", &_3, 75, message, context);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "[%s] [%s] %s\n", 0);
	ZEPHIR_CALL_FUNCTION(&_4, "sprintf", NULL, 1, &_0, _1, level, _2);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("logs"), _4 TSRMLS_CC);
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
	ZEPHIR_CALL_FUNCTION(&_5, "file_put_contents", NULL, 76, _1, _2, &_4);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_5))) {
		ZEPHIR_INIT_VAR(_6$$4);
		object_init_ex(_6$$4, yb_logger_exception_ce);
		_7$$4 = zephir_fetch_nproperty_this(this_ptr, SL("path"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_8$$4);
		ZEPHIR_CONCAT_SV(_8$$4, "Cannot append logs to file: ", _7$$4);
		ZEPHIR_CALL_METHOD(NULL, _6$$4, "__construct", NULL, 2, _8$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_6$$4, "yb/logger/filelogger.zep", 31 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_this(this_ptr, SL("logs"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}


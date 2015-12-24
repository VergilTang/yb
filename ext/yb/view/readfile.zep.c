
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
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/file.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Yb_View_ReadFile) {

	ZEPHIR_REGISTER_CLASS(Yb\\View, ReadFile, yb, view_readfile, yb_view_readfile_method_entry, 0);

	zend_class_implements(yb_view_readfile_ce TSRMLS_CC, 1, yb_view_viewinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Yb_View_ReadFile, run) {

	zval *readFile = NULL, *readFileContentType = NULL, *_4 = NULL, *_13 = NULL, *_7$$4, *_9$$5, *_15$$6, *_19$$8;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_11 = NULL;
	zval *data_param = NULL, *options_param = NULL, *size = NULL, *_0 = NULL, *_2 = NULL, *_3 = NULL, *_5 = NULL, *_10, *_12 = NULL, *_14 = NULL, *_17 = NULL, *_6$$4, *_8$$5, _16$$7 = zval_used_for_init, *_18$$8;
	zval *data = NULL, *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &data_param, &options_param);

	zephir_get_arrval(data, data_param);
	zephir_get_arrval(options, options_param);


	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "readFile", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_0, yb_std_ce, "valueat", &_1, 5, options, _2, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_get_strval(_4, _0);
	ZEPHIR_CPY_WRT(readFile, _4);
	if (unlikely(zephir_fast_strlen_ev(readFile) < 1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_view_exception_ce, "Missing option: readFile", "yb/view/readfile.zep", 14);
		return;
	}
	if (unlikely(!((zephir_file_exists(readFile TSRMLS_CC) == SUCCESS)))) {
		ZEPHIR_INIT_VAR(_6$$4);
		object_init_ex(_6$$4, yb_view_exception_ce);
		ZEPHIR_INIT_VAR(_7$$4);
		ZEPHIR_CONCAT_SV(_7$$4, "Cannot find file in path: ", readFile);
		ZEPHIR_CALL_METHOD(NULL, _6$$4, "__construct", NULL, 2, _7$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_6$$4, "yb/view/readfile.zep", 18 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&size, "filesize", NULL, 117, readFile);
	zephir_check_call_status();
	if (unlikely(ZEPHIR_IS_FALSE_IDENTICAL(size))) {
		ZEPHIR_INIT_VAR(_8$$5);
		object_init_ex(_8$$5, yb_view_exception_ce);
		ZEPHIR_INIT_VAR(_9$$5);
		ZEPHIR_CONCAT_SV(_9$$5, "Cannot get file size: ", readFile);
		ZEPHIR_CALL_METHOD(NULL, _8$$5, "__construct", NULL, 2, _9$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_8$$5, "yb/view/readfile.zep", 23 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_10);
	ZEPHIR_CONCAT_SV(_10, "Content-Length: ", size);
	ZEPHIR_CALL_FUNCTION(NULL, "header", &_11, 113, _10);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "readFileContentType", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_12, yb_std_ce, "valueat", &_1, 5, options, _2, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_get_strval(_13, _12);
	ZEPHIR_CPY_WRT(readFileContentType, _13);
	if (zephir_fast_strlen_ev(readFileContentType) > 0) {
		ZEPHIR_INIT_VAR(_15$$6);
		ZEPHIR_CONCAT_SV(_15$$6, "Content-Type: ", readFileContentType);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_11, 113, _15$$6);
		zephir_check_call_status();
	} else {
		ZEPHIR_SINIT_VAR(_16$$7);
		ZVAL_STRING(&_16$$7, "Content-Description: File Transfer", 0);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_11, 113, &_16$$7);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_16$$7);
		ZVAL_STRING(&_16$$7, "Content-Type: application/octet-stream", 0);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_11, 113, &_16$$7);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_16$$7);
		ZVAL_STRING(&_16$$7, "Content-Transfer-Encoding: binary", 0);
		ZEPHIR_CALL_FUNCTION(NULL, "header", &_11, 113, &_16$$7);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(&_17, "readfile", NULL, 118, readFile);
	zephir_check_call_status();
	if (unlikely(ZEPHIR_IS_FALSE_IDENTICAL(_17))) {
		ZEPHIR_INIT_VAR(_18$$8);
		object_init_ex(_18$$8, yb_view_exception_ce);
		ZEPHIR_INIT_VAR(_19$$8);
		ZEPHIR_CONCAT_SV(_19$$8, "Cannot read file: ", readFile);
		ZEPHIR_CALL_METHOD(NULL, _18$$8, "__construct", NULL, 2, _19$$8);
		zephir_check_call_status();
		zephir_throw_exception_debug(_18$$8, "yb/view/readfile.zep", 37 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}


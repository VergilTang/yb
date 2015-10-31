
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
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/hash.h"


ZEPHIR_INIT_CLASS(Yb_Upload_Ftp) {

	ZEPHIR_REGISTER_CLASS_EX(Yb\\Upload, Ftp, yb, upload_ftp, yb_upload_storageabstract_ce, yb_upload_ftp_method_entry, 0);

	zend_declare_property_null(yb_upload_ftp_ce, SL("ftp"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_upload_ftp_ce, SL("baseDirectory"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Yb_Upload_Ftp, __construct) {

	zend_bool ssl = 0, _20;
	long port = 0, timeout = 0;
	zval *host = NULL, *user = NULL, *passwd = NULL, *baseDirectory = NULL, *_3 = NULL, *_6 = NULL, *_8 = NULL, *_10 = NULL, *_19$$7, *_22$$8;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *options_param = NULL, *ftp = NULL, *_0 = NULL, *_2 = NULL, *_4 = NULL, *_5 = NULL, *_7 = NULL, *_9 = NULL, *_11 = NULL, *_12 = NULL, *_13 = NULL, *_23 = NULL, _14$$3, _15$$3, _16$$5, _17$$5, *_18$$7, *_21$$8;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	zephir_get_arrval(options, options_param);


	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "host", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_0, yb_std_ce, "valueat", &_1, 9, options, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_get_strval(_3, _0);
	ZEPHIR_CPY_WRT(host, _3);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "user", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_STRING(_5, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_4, yb_std_ce, "valueat", &_1, 9, options, _2, _5);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_5);
	zephir_check_call_status();
	zephir_get_strval(_6, _4);
	ZEPHIR_CPY_WRT(user, _6);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "passwd", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_STRING(_5, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_7, yb_std_ce, "valueat", &_1, 9, options, _2, _5);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_5);
	zephir_check_call_status();
	zephir_get_strval(_8, _7);
	ZEPHIR_CPY_WRT(passwd, _8);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "baseDirectory", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_STRING(_5, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_9, yb_std_ce, "valueat", &_1, 9, options, _2, _5);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_5);
	zephir_check_call_status();
	zephir_get_strval(_10, _9);
	ZEPHIR_CPY_WRT(baseDirectory, _10);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "port", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_LONG(_5, 21);
	ZEPHIR_CALL_CE_STATIC(&_11, yb_std_ce, "valueat", &_1, 9, options, _2, _5);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	port = zephir_get_intval(_11);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "timeout", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_LONG(_5, 10);
	ZEPHIR_CALL_CE_STATIC(&_12, yb_std_ce, "valueat", &_1, 9, options, _2, _5);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	timeout = zephir_get_intval(_12);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "ssl", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_5);
	ZVAL_BOOL(_5, 0);
	ZEPHIR_CALL_CE_STATIC(&_13, yb_std_ce, "valueat", &_1, 9, options, _2, _5);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ssl = zephir_get_boolval(_13);
	if (ssl) {
		if (unlikely(!((zephir_function_exists_ex(SS("ftp_ssl_connect") TSRMLS_CC) == SUCCESS)))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_upload_exception_ce, "Missing ssl ftp support", "yb/upload/ftp.zep", 27);
			return;
		}
		ZEPHIR_SINIT_VAR(_14$$3);
		ZVAL_LONG(&_14$$3, port);
		ZEPHIR_SINIT_VAR(_15$$3);
		ZVAL_LONG(&_15$$3, timeout);
		ZEPHIR_CALL_FUNCTION(&ftp, "ftp_ssl_connect", NULL, 101, host, &_14$$3, &_15$$3);
		zephir_check_call_status();
	} else {
		if (unlikely(!((zephir_function_exists_ex(SS("ftp_connect") TSRMLS_CC) == SUCCESS)))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_upload_exception_ce, "Missing ftp support", "yb/upload/ftp.zep", 33);
			return;
		}
		ZEPHIR_SINIT_VAR(_16$$5);
		ZVAL_LONG(&_16$$5, port);
		ZEPHIR_SINIT_VAR(_17$$5);
		ZVAL_LONG(&_17$$5, timeout);
		ZEPHIR_CALL_FUNCTION(&ftp, "ftp_connect", NULL, 102, host, &_16$$5, &_17$$5);
		zephir_check_call_status();
	}
	if (unlikely(!zephir_is_true(ftp))) {
		ZEPHIR_INIT_VAR(_18$$7);
		object_init_ex(_18$$7, yb_upload_exception_ce);
		ZEPHIR_INIT_VAR(_19$$7);
		ZEPHIR_CONCAT_SV(_19$$7, "Cannot connect to ftp server: ", host);
		ZEPHIR_CALL_METHOD(NULL, _18$$7, "__construct", NULL, 2, _19$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(_18$$7, "yb/upload/ftp.zep", 40 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_20 = zephir_is_true(user);
	if (_20) {
		ZEPHIR_CALL_FUNCTION(&_13, "ftp_login", NULL, 103, ftp, user, passwd);
		zephir_check_call_status();
		_20 = !zephir_is_true(_13);
	}
	if (unlikely(_20)) {
		ZEPHIR_INIT_VAR(_21$$8);
		object_init_ex(_21$$8, yb_upload_exception_ce);
		ZEPHIR_INIT_VAR(_22$$8);
		ZEPHIR_CONCAT_SVSV(_22$$8, "Cannot login ftp server: ", user, "@", host);
		ZEPHIR_CALL_METHOD(NULL, _21$$8, "__construct", NULL, 2, _22$$8);
		zephir_check_call_status();
		zephir_throw_exception_debug(_21$$8, "yb/upload/ftp.zep", 44 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&_23, "ftp_pasv", NULL, 104, ftp, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_23))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_upload_exception_ce, "Cannot set PASV mode", "yb/upload/ftp.zep", 48);
		return;
	}
	zephir_update_property_this(this_ptr, SL("ftp"), ftp TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("baseDirectory"), baseDirectory TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Upload_Ftp, store) {

	int ZEPHIR_LAST_CALL_STATUS;
	long flag;
	zval *source_param = NULL, *group_param = NULL, *extension_param = NULL, *flag_param = NULL, *_0 = NULL, *_2, *_3, *_4 = NULL, *_5, _6, *_7 = NULL;
	zval *source = NULL, *group = NULL, *extension = NULL, *destUri = NULL, *destPath = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &source_param, &group_param, &extension_param, &flag_param);

	zephir_get_strval(source, source_param);
	if (!group_param) {
		ZEPHIR_INIT_VAR(group);
		ZVAL_STRING(group, "", 1);
	} else {
		zephir_get_strval(group, group_param);
	}
	if (!extension_param) {
		ZEPHIR_INIT_VAR(extension);
		ZVAL_STRING(extension, "", 1);
	} else {
		zephir_get_strval(extension, extension_param);
	}
	if (!flag_param) {
		flag = 0;
	} else {
		flag = zephir_get_intval(flag_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "generateuri", NULL, 0, source, group, extension);
	zephir_check_call_status();
	zephir_get_strval(_1, _0);
	ZEPHIR_CPY_WRT(destUri, _1);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("baseDirectory"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_VV(_3, _2, destUri);
	zephir_get_strval(destPath, _3);
	ZEPHIR_CALL_FUNCTION(&_4, "dirname", NULL, 94, destPath);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "mkdirifnotexists", NULL, 0, _4);
	zephir_check_call_status();
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("ftp"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_LONG(&_6, 2);
	ZEPHIR_CALL_FUNCTION(&_7, "ftp_put", NULL, 105, _5, destPath, source, &_6);
	zephir_check_call_status();
	if (zephir_is_true(_7)) {
		do {
			if (flag == 2 || flag == 1) {
				ZEPHIR_CALL_FUNCTION(NULL, "unlink", NULL, 100, source);
				zephir_check_call_status();
				break;
			}
		} while(0);

		RETURN_CTOR(destUri);
	}
	RETURN_MM_STRING("", 1);

}

PHP_METHOD(Yb_Upload_Ftp, remove) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, *_0;
	zval *uri = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);

	zephir_get_strval(uri, uri_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("ftp"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("ftp_delete", NULL, 106, _0, uri);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Upload_Ftp, __destruct) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("ftp"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "ftp_close", NULL, 107, _0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Upload_Ftp, mkDirIfNotExists) {

	HashTable *_9;
	HashPosition _8;
	zephir_fcall_cache_entry *_6 = NULL, *_7 = NULL, *_11 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *dir_param = NULL, *ftp = NULL, *parts = NULL, *cur = NULL, *stack = NULL, *_0, _1 = zval_used_for_init, _2, _3, **_10, *_4$$3 = NULL, *_5$$3 = NULL;
	zval *dir = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dir_param);

	zephir_get_strval(dir, dir_param);


	ZEPHIR_INIT_VAR(stack);
	array_init(stack);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("ftp"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(ftp, _0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "#/+#", 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, -1);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, 1);
	ZEPHIR_CALL_FUNCTION(&parts, "preg_split", NULL, 108, &_1, dir, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_STRING(&_1, "Yb\\Std::ignoreError", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 109, &_1);
	zephir_check_call_status();
	while (1) {
		if (!(zephir_is_true(parts))) {
			break;
		}
		ZEPHIR_INIT_NVAR(_4$$3);
		zephir_fast_join_str(_4$$3, SL("/"), parts TSRMLS_CC);
		ZEPHIR_INIT_NVAR(cur);
		ZEPHIR_CONCAT_SV(cur, "/", _4$$3);
		ZEPHIR_CALL_FUNCTION(&_5$$3, "ftp_chdir", &_6, 110, ftp, cur);
		zephir_check_call_status();
		if (!(zephir_is_true(_5$$3))) {
			zephir_array_append(&stack, cur, PH_SEPARATE, "yb/upload/ftp.zep", 100);
		}
		ZEPHIR_MAKE_REF(parts);
		ZEPHIR_CALL_FUNCTION(NULL, "array_pop", &_7, 4, parts);
		ZEPHIR_UNREF(parts);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(NULL, "restore_error_handler", NULL, 111);
	zephir_check_call_status();
	zephir_is_iterable(stack, &_9, &_8, 0, 1, "yb/upload/ftp.zep", 110);
	for (
	  ; zephir_hash_get_current_data_ex(_9, (void**) &_10, &_8) == SUCCESS
	  ; zephir_hash_move_backwards_ex(_9, &_8)
	) {
		ZEPHIR_GET_HVALUE(cur, _10);
		ZEPHIR_CALL_FUNCTION(NULL, "ftp_mkdir", &_11, 112, ftp, cur);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}



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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Yb_Upload_Fastdfs) {

	ZEPHIR_REGISTER_CLASS_EX(Yb\\Upload, Fastdfs, yb, upload_fastdfs, yb_upload_storageabstract_ce, yb_upload_fastdfs_method_entry, 0);

	zend_declare_property_null(yb_upload_fastdfs_ce, SL("groupStorages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Yb_Upload_Fastdfs, isSupported) {

	

	RETURN_BOOL((zephir_function_exists_ex(SS("fastdfs_client_version") TSRMLS_CC) == SUCCESS));

}

PHP_METHOD(Yb_Upload_Fastdfs, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *groupStorages_param = NULL, *_0 = NULL;
	zval *groupStorages = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &groupStorages_param);

	if (!groupStorages_param) {
		ZEPHIR_INIT_VAR(groupStorages);
		array_init(groupStorages);
	} else {
		zephir_get_arrval(groupStorages, groupStorages_param);
	}


	ZEPHIR_CALL_SELF(&_0, "issupported", NULL, 0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_upload_exception_ce, "Missing extension: fastdfs_client", "yb/upload/fastdfs.zep", 15);
		return;
	}
	zephir_update_property_this(this_ptr, SL("groupStorages"), groupStorages TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Upload_Fastdfs, store) {

	int ZEPHIR_LAST_CALL_STATUS;
	long flag;
	zval *source_param = NULL, *group_param = NULL, *extension_param = NULL, *flag_param = NULL, *extensionArg = NULL, *groupArg = NULL, *destUri = NULL, *_0, *_1;
	zval *source = NULL, *group = NULL, *extension = NULL;

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


	ZEPHIR_INIT_VAR(extensionArg);
	ZVAL_NULL(extensionArg);
	if (!(!extension) && Z_STRLEN_P(extension)) {
		ZEPHIR_CPY_WRT(extensionArg, extension);
	}
	ZEPHIR_OBS_VAR(groupArg);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("groupStorages"), PH_NOISY_CC);
	if (!(zephir_array_isset_fetch(&groupArg, _0, group, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(groupArg);
		ZVAL_NULL(groupArg);
	}
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	ZEPHIR_CALL_FUNCTION(&destUri, "fastdfs_storage_upload_by_filename1", NULL, 0, source, extensionArg, _1, groupArg);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(destUri)) {
		RETURN_MM_STRING("", 1);
	}
	do {
		if (flag == 2 || flag == 1) {
			ZEPHIR_CALL_FUNCTION(NULL, "unlink", NULL, 107, source);
			zephir_check_call_status();
			break;
		}
	} while(0);

	ZEPHIR_CONCAT_SV(return_value, "/", destUri);
	RETURN_MM();

}

PHP_METHOD(Yb_Upload_Fastdfs, remove) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, *_0, _1;
	zval *uri = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);

	zephir_get_strval(uri, uri_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "/", 0);
	zephir_fast_trim(_0, uri, &_1, ZEPHIR_TRIM_LEFT TSRMLS_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("fastdfs_storage_delete_file1", NULL, 0, _0);
	zephir_check_call_status();
	RETURN_MM();

}


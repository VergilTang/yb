
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
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/hash.h"


ZEPHIR_INIT_CLASS(Yb_Upload_Uploader) {

	ZEPHIR_REGISTER_CLASS(Yb\\Upload, Uploader, yb, upload_uploader, yb_upload_uploader_method_entry, 0);

	zend_declare_property_null(yb_upload_uploader_ce, SL("validExtensions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_upload_uploader_ce, SL("validImageExtensions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_upload_uploader_ce, SL("maxSize"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_upload_uploader_ce, SL("storage"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(yb_upload_uploader_ce, SL("INVALID_UPLOAD"), -1 TSRMLS_CC);

	zend_declare_class_constant_long(yb_upload_uploader_ce, SL("SIZE_TOO_LARGE"), -2 TSRMLS_CC);

	zend_declare_class_constant_long(yb_upload_uploader_ce, SL("INVALID_EXTENSION"), -3 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Yb_Upload_Uploader, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL, *_14 = NULL;
	zval *validExtensions_param = NULL, *validImageExtensions_param = NULL, *maxSize_param = NULL, *_0 = NULL, *_1, _2 = zval_used_for_init, _3 = zval_used_for_init, _4 = zval_used_for_init, *_5 = NULL, *_7 = NULL, *_9 = NULL, *_10, *_11 = NULL, *_12 = NULL, *_13 = NULL;
	zval *validExtensions = NULL, *validImageExtensions = NULL, *maxSize = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &validExtensions_param, &validImageExtensions_param, &maxSize_param);

	zephir_get_strval(validExtensions, validExtensions_param);
	zephir_get_strval(validImageExtensions, validImageExtensions_param);
	if (!maxSize_param) {
		ZEPHIR_INIT_VAR(maxSize);
		ZVAL_STRING(maxSize, "2M", 1);
	} else {
		zephir_get_strval(maxSize, maxSize_param);
	}


	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strtolower(_1, validExtensions);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "#[,/\\s\\|\\.]+#", 0);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, -1);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, 1);
	ZEPHIR_CALL_FUNCTION(&_5, "preg_split", &_6, 82, &_2, _1, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_7, "array_flip", &_8, 112, _5);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("validExtensions"), _7 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_10);
	zephir_fast_strtolower(_10, validImageExtensions);
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_STRING(&_2, "#[,/\\s\\|\\.]+#", 0);
	ZEPHIR_SINIT_NVAR(_3);
	ZVAL_LONG(&_3, -1);
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_LONG(&_4, 1);
	ZEPHIR_CALL_FUNCTION(&_11, "preg_split", &_6, 82, &_2, _10, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_12, "array_flip", &_8, 112, _11);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("validImageExtensions"), _12 TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_13, yb_std_ce, "sizetobytes", &_14, 113, maxSize);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("maxSize"), _13 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Upload_Uploader, setStorage) {

	zval *storage;

	zephir_fetch_params(0, 1, 0, &storage);



	zephir_update_property_this(this_ptr, SL("storage"), storage TSRMLS_CC);

}

PHP_METHOD(Yb_Upload_Uploader, getStorage) {

	

	RETURN_MEMBER(this_ptr, "storage");

}

PHP_METHOD(Yb_Upload_Uploader, newUploadedFile) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, yb_upload_uploadedfile_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 114, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Upload_Uploader, saveUploadedFile) {

	long flag = 0;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool keep;
	zval *prefix = NULL;
	zval *uploadedFile, *prefix_param = NULL, *keep_param = NULL, *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &uploadedFile, &prefix_param, &keep_param);

	zephir_get_strval(prefix, prefix_param);
	keep = zephir_get_boolval(keep_param);


	if (keep) {
		flag = 0;
	} else {
		flag = 2;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("storage"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property(&_1, uploadedFile, SL("tmpName"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property(&_2, uploadedFile, SL("extension"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, flag);
	ZEPHIR_RETURN_CALL_METHOD(_0, "store", NULL, 0, _1, prefix, _2, _3);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Upload_Uploader, pick) {

	zend_bool _0$$3, _2$$3, _4$$3, _5$$3, _8$$3, _11$$3, _13$$3;
	zephir_fcall_cache_entry *_16 = NULL, *_24 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *index_param = NULL, *_FILES, *f = NULL, *a = NULL, *error = NULL, *size = NULL, *name = NULL, *tmpName = NULL, *_7$$3, *_9$$3, *_15$$3 = NULL, *_18$$3 = NULL, *_1$$4, *_3$$5, *_6$$7, *_10$$8, *_12$$9, *_14$$10, *_19$$11, *_20$$12, *_21$$13 = NULL, _22$$13 = zval_used_for_init, *_23$$13 = NULL, *_26$$13, *_27$$14;
	zval *index = NULL, *extension = NULL, *_17$$3 = NULL, *_25$$13 = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_FILES, SS("_FILES") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &index_param);

	zephir_get_strval(index, index_param);


	ZEPHIR_CALL_METHOD(&f, this_ptr, "newuploadedfile", NULL, 0);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_OBS_NVAR(a);
		_0$$3 = !(zephir_array_isset_fetch(&a, _FILES, index, 0 TSRMLS_CC));
		if (!(_0$$3)) {
			_0$$3 = Z_TYPE_P(a) != IS_ARRAY;
		}
		if (unlikely(_0$$3)) {
			ZEPHIR_INIT_ZVAL_NREF(_1$$4);
			ZVAL_LONG(_1$$4, -1);
			zephir_update_property_zval(f, SL("error"), _1$$4 TSRMLS_CC);
			break;
		}
		ZEPHIR_OBS_NVAR(error);
		_2$$3 = !(zephir_array_isset_string_fetch(&error, a, SS("error"), 0 TSRMLS_CC));
		if (!(_2$$3)) {
			_2$$3 = Z_TYPE_P(error) != IS_LONG;
		}
		if (unlikely(_2$$3)) {
			ZEPHIR_INIT_ZVAL_NREF(_3$$5);
			ZVAL_LONG(_3$$5, -1);
			zephir_update_property_zval(f, SL("error"), _3$$5 TSRMLS_CC);
			break;
		}
		zephir_update_property_zval(f, SL("error"), error TSRMLS_CC);
		if (unlikely(!ZEPHIR_IS_LONG(error, 0))) {
			break;
		}
		ZEPHIR_OBS_NVAR(size);
		_4$$3 = !(zephir_array_isset_string_fetch(&size, a, SS("size"), 0 TSRMLS_CC));
		if (!(_4$$3)) {
			_4$$3 = Z_TYPE_P(size) != IS_LONG;
		}
		_5$$3 = _4$$3;
		if (!(_5$$3)) {
			_5$$3 = ZEPHIR_LT_LONG(size, 1);
		}
		if (unlikely(_5$$3)) {
			ZEPHIR_INIT_ZVAL_NREF(_6$$7);
			ZVAL_LONG(_6$$7, -1);
			zephir_update_property_zval(f, SL("error"), _6$$7 TSRMLS_CC);
			break;
		}
		zephir_update_property_zval(f, SL("size"), size TSRMLS_CC);
		_7$$3 = zephir_fetch_nproperty_this(this_ptr, SL("maxSize"), PH_NOISY_CC);
		_8$$3 = ZEPHIR_GT_LONG(_7$$3, 0);
		if (_8$$3) {
			_9$$3 = zephir_fetch_nproperty_this(this_ptr, SL("maxSize"), PH_NOISY_CC);
			_8$$3 = ZEPHIR_GT(size, _9$$3);
		}
		if (unlikely(_8$$3)) {
			ZEPHIR_INIT_ZVAL_NREF(_10$$8);
			ZVAL_LONG(_10$$8, -2);
			zephir_update_property_zval(f, SL("error"), _10$$8 TSRMLS_CC);
			break;
		}
		ZEPHIR_OBS_NVAR(name);
		_11$$3 = !(zephir_array_isset_string_fetch(&name, a, SS("name"), 0 TSRMLS_CC));
		if (!(_11$$3)) {
			_11$$3 = Z_TYPE_P(name) != IS_STRING;
		}
		if (unlikely(_11$$3)) {
			ZEPHIR_INIT_ZVAL_NREF(_12$$9);
			ZVAL_LONG(_12$$9, -1);
			zephir_update_property_zval(f, SL("error"), _12$$9 TSRMLS_CC);
			break;
		}
		zephir_update_property_zval(f, SL("name"), name TSRMLS_CC);
		ZEPHIR_OBS_NVAR(tmpName);
		_13$$3 = !(zephir_array_isset_string_fetch(&tmpName, a, SS("tmp_name"), 0 TSRMLS_CC));
		if (!(_13$$3)) {
			_13$$3 = Z_TYPE_P(tmpName) != IS_STRING;
		}
		if (unlikely(_13$$3)) {
			ZEPHIR_INIT_ZVAL_NREF(_14$$10);
			ZVAL_LONG(_14$$10, -1);
			zephir_update_property_zval(f, SL("error"), _14$$10 TSRMLS_CC);
			break;
		}
		zephir_update_property_zval(f, SL("tmpName"), tmpName TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_15$$3, this_ptr, "getimageextension", &_16, 0, tmpName);
		zephir_check_call_status();
		zephir_get_strval(_17$$3, _15$$3);
		ZEPHIR_CPY_WRT(extension, _17$$3);
		if (zephir_fast_strlen_ev(extension) > 0) {
			if (1) {
				zephir_update_property_zval(f, SL("isImage"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
			} else {
				zephir_update_property_zval(f, SL("isImage"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
			}
			_19$$11 = zephir_fetch_nproperty_this(this_ptr, SL("validImageExtensions"), PH_NOISY_CC);
			if (unlikely(!(zephir_array_isset(_19$$11, extension)))) {
				ZEPHIR_INIT_ZVAL_NREF(_20$$12);
				ZVAL_LONG(_20$$12, -3);
				zephir_update_property_zval(f, SL("error"), _20$$12 TSRMLS_CC);
				break;
			}
		} else {
			if (0) {
				zephir_update_property_zval(f, SL("isImage"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
			} else {
				zephir_update_property_zval(f, SL("isImage"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
			}
			ZEPHIR_INIT_NVAR(_21$$13);
			ZEPHIR_SINIT_NVAR(_22$$13);
			ZVAL_LONG(&_22$$13, 4);
			ZEPHIR_CALL_FUNCTION(&_23$$13, "pathinfo", &_24, 77, name, &_22$$13);
			zephir_check_call_status();
			zephir_fast_strtolower(_21$$13, _23$$13);
			zephir_get_strval(_25$$13, _21$$13);
			ZEPHIR_CPY_WRT(extension, _25$$13);
			_26$$13 = zephir_fetch_nproperty_this(this_ptr, SL("validExtensions"), PH_NOISY_CC);
			if (unlikely(!(zephir_array_isset(_26$$13, extension)))) {
				ZEPHIR_INIT_ZVAL_NREF(_27$$14);
				ZVAL_LONG(_27$$14, -3);
				zephir_update_property_zval(f, SL("error"), _27$$14 TSRMLS_CC);
				break;
			}
		}
		zephir_update_property_zval(f, SL("extension"), extension TSRMLS_CC);
		break;
	}
	RETURN_CCTOR(f);

}

PHP_METHOD(Yb_Upload_Uploader, pickArray) {

	HashTable *_3;
	HashPosition _2;
	zend_bool _0, _1, _7$$6, _8$$6, _11$$6, _15$$6, _18$$6;
	zephir_fcall_cache_entry *_5 = NULL, *_21 = NULL, *_29 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *index_param = NULL, *_FILES, *files = NULL, *a = NULL, *errors = NULL, *i = NULL, *e = NULL, *f = NULL, *size = NULL, *name = NULL, *tmpName = NULL, **_4, *_6$$6, *_10$$6, *_12$$6, *_14$$6, *_17$$6, *_20$$6 = NULL, *_23$$6 = NULL, *_9$$8, *_13$$9, *_16$$10, *_19$$11, *_24$$12, *_25$$13, *_26$$14 = NULL, _27$$14 = zval_used_for_init, *_28$$14 = NULL, *_31$$14, *_32$$15;
	zval *index = NULL, *extension = NULL, *_22$$6 = NULL, *_30$$14 = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_FILES, SS("_FILES") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &index_param);

	zephir_get_strval(index, index_param);


	ZEPHIR_INIT_VAR(files);
	array_init(files);
	ZEPHIR_OBS_VAR(a);
	_0 = !(zephir_array_isset_fetch(&a, _FILES, index, 0 TSRMLS_CC));
	if (_0) {
		_0 = Z_TYPE_P(a) != IS_ARRAY;
	}
	if (unlikely(_0)) {
		RETURN_CCTOR(files);
	}
	ZEPHIR_OBS_VAR(errors);
	_1 = !(zephir_array_isset_string_fetch(&errors, a, SS("error"), 0 TSRMLS_CC));
	if (_1) {
		_1 = Z_TYPE_P(errors) != IS_ARRAY;
	}
	if (unlikely(_1)) {
		RETURN_CCTOR(files);
	}
	zephir_is_iterable(errors, &_3, &_2, 0, 0, "yb/upload/uploader.zep", 191);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(i, _3, _2);
		ZEPHIR_GET_HVALUE(e, _4);
		ZEPHIR_CALL_METHOD(&f, this_ptr, "newuploadedfile", &_5, 0);
		zephir_check_call_status();
		while (1) {
			zephir_update_property_zval(f, SL("error"), e TSRMLS_CC);
			if (unlikely(!ZEPHIR_IS_LONG(e, 0))) {
				break;
			}
			ZEPHIR_OBS_NVAR(size);
			zephir_array_fetch_string(&_6$$6, a, SL("size"), PH_READONLY, "yb/upload/uploader.zep", 146 TSRMLS_CC);
			_7$$6 = !(zephir_array_isset_fetch(&size, _6$$6, i, 0 TSRMLS_CC));
			if (!(_7$$6)) {
				_7$$6 = Z_TYPE_P(size) != IS_LONG;
			}
			_8$$6 = _7$$6;
			if (!(_8$$6)) {
				_8$$6 = ZEPHIR_LT_LONG(size, 1);
			}
			if (unlikely(_8$$6)) {
				ZEPHIR_INIT_ZVAL_NREF(_9$$8);
				ZVAL_LONG(_9$$8, -1);
				zephir_update_property_zval(f, SL("error"), _9$$8 TSRMLS_CC);
				break;
			}
			zephir_update_property_zval(f, SL("size"), size TSRMLS_CC);
			_10$$6 = zephir_fetch_nproperty_this(this_ptr, SL("maxSize"), PH_NOISY_CC);
			_11$$6 = ZEPHIR_GT_LONG(_10$$6, 0);
			if (_11$$6) {
				_12$$6 = zephir_fetch_nproperty_this(this_ptr, SL("maxSize"), PH_NOISY_CC);
				_11$$6 = ZEPHIR_GT(size, _12$$6);
			}
			if (unlikely(_11$$6)) {
				ZEPHIR_INIT_ZVAL_NREF(_13$$9);
				ZVAL_LONG(_13$$9, -2);
				zephir_update_property_zval(f, SL("error"), _13$$9 TSRMLS_CC);
				break;
			}
			ZEPHIR_OBS_NVAR(name);
			zephir_array_fetch_string(&_14$$6, a, SL("name"), PH_READONLY, "yb/upload/uploader.zep", 156 TSRMLS_CC);
			_15$$6 = !(zephir_array_isset_fetch(&name, _14$$6, i, 0 TSRMLS_CC));
			if (!(_15$$6)) {
				_15$$6 = Z_TYPE_P(name) != IS_STRING;
			}
			if (unlikely(_15$$6)) {
				ZEPHIR_INIT_ZVAL_NREF(_16$$10);
				ZVAL_LONG(_16$$10, -1);
				zephir_update_property_zval(f, SL("error"), _16$$10 TSRMLS_CC);
				break;
			}
			zephir_update_property_zval(f, SL("name"), name TSRMLS_CC);
			ZEPHIR_OBS_NVAR(tmpName);
			zephir_array_fetch_string(&_17$$6, a, SL("tmp_name"), PH_READONLY, "yb/upload/uploader.zep", 162 TSRMLS_CC);
			_18$$6 = !(zephir_array_isset_fetch(&tmpName, _17$$6, i, 0 TSRMLS_CC));
			if (!(_18$$6)) {
				_18$$6 = Z_TYPE_P(tmpName) != IS_STRING;
			}
			if (unlikely(_18$$6)) {
				ZEPHIR_INIT_ZVAL_NREF(_19$$11);
				ZVAL_LONG(_19$$11, -1);
				zephir_update_property_zval(f, SL("error"), _19$$11 TSRMLS_CC);
				break;
			}
			zephir_update_property_zval(f, SL("tmpName"), tmpName TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_20$$6, this_ptr, "getimageextension", &_21, 0, tmpName);
			zephir_check_call_status();
			zephir_get_strval(_22$$6, _20$$6);
			ZEPHIR_CPY_WRT(extension, _22$$6);
			if (zephir_fast_strlen_ev(extension) > 0) {
				if (1) {
					zephir_update_property_zval(f, SL("isImage"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
				} else {
					zephir_update_property_zval(f, SL("isImage"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
				}
				_24$$12 = zephir_fetch_nproperty_this(this_ptr, SL("validImageExtensions"), PH_NOISY_CC);
				if (unlikely(!(zephir_array_isset(_24$$12, extension)))) {
					ZEPHIR_INIT_ZVAL_NREF(_25$$13);
					ZVAL_LONG(_25$$13, -3);
					zephir_update_property_zval(f, SL("error"), _25$$13 TSRMLS_CC);
					break;
				}
			} else {
				if (0) {
					zephir_update_property_zval(f, SL("isImage"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
				} else {
					zephir_update_property_zval(f, SL("isImage"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
				}
				ZEPHIR_INIT_NVAR(_26$$14);
				ZEPHIR_SINIT_NVAR(_27$$14);
				ZVAL_LONG(&_27$$14, 4);
				ZEPHIR_CALL_FUNCTION(&_28$$14, "pathinfo", &_29, 77, name, &_27$$14);
				zephir_check_call_status();
				zephir_fast_strtolower(_26$$14, _28$$14);
				zephir_get_strval(_30$$14, _26$$14);
				ZEPHIR_CPY_WRT(extension, _30$$14);
				_31$$14 = zephir_fetch_nproperty_this(this_ptr, SL("validExtensions"), PH_NOISY_CC);
				if (unlikely(!(zephir_array_isset(_31$$14, extension)))) {
					ZEPHIR_INIT_ZVAL_NREF(_32$$15);
					ZVAL_LONG(_32$$15, -3);
					zephir_update_property_zval(f, SL("error"), _32$$15 TSRMLS_CC);
					break;
				}
			}
			zephir_update_property_zval(f, SL("extension"), extension TSRMLS_CC);
			break;
		}
		zephir_array_update_zval(&files, i, &f, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(files);

}

PHP_METHOD(Yb_Upload_Uploader, getImageExtension) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *eit = NULL;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(path, path_param);


	ZEPHIR_CALL_FUNCTION(&eit, "exif_imagetype", NULL, 50, path);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(eit)) {
		RETURN_MM_STRING("", 1);
	}
	if (ZEPHIR_IS_LONG(eit, 2)) {
		RETURN_MM_STRING("jpg", 1);
	}
	ZEPHIR_RETURN_CALL_FUNCTION("image_type_to_extension", NULL, 58, eit, ZEPHIR_GLOBAL(global_false));
	zephir_check_call_status();
	RETURN_MM();

}


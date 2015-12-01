
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Yb_Upload_StorageAbstract) {

	ZEPHIR_REGISTER_CLASS(Yb\\Upload, StorageAbstract, yb, upload_storageabstract, yb_upload_storageabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(yb_upload_storageabstract_ce, SL("uriGenerator"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(yb_upload_storageabstract_ce, SL("COPY"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(yb_upload_storageabstract_ce, SL("MOVE"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(yb_upload_storageabstract_ce, SL("MOVE_UPLOADED_FILE"), 2 TSRMLS_CC);

	zend_class_implements(yb_upload_storageabstract_ce TSRMLS_CC, 1, yb_upload_urigeneratorinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Yb_Upload_StorageAbstract, setUriGenerator) {

	zval *uriGenerator;

	zephir_fetch_params(0, 1, 0, &uriGenerator);



	zephir_update_property_this(this_ptr, SL("uriGenerator"), uriGenerator TSRMLS_CC);

}

PHP_METHOD(Yb_Upload_StorageAbstract, getUriGenerator) {

	

	RETURN_MEMBER(this_ptr, "uriGenerator");

}

PHP_METHOD(Yb_Upload_StorageAbstract, store) {

}

PHP_METHOD(Yb_Upload_StorageAbstract, remove) {

}

PHP_METHOD(Yb_Upload_StorageAbstract, exists) {

}

PHP_METHOD(Yb_Upload_StorageAbstract, generateUri) {

	unsigned char _6, _7, _8, _9;
	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *source_param = NULL, *prefix_param = NULL, *extension_param = NULL, *_0, *_2 = NULL, *_1$$3;
	zval *source = NULL, *prefix = NULL, *extension = NULL, *uri, *uuid = NULL, *_4, *_5 = NULL, *_10$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &source_param, &prefix_param, &extension_param);

	zephir_get_strval(source, source_param);
	zephir_get_strval(prefix, prefix_param);
	zephir_get_strval(extension, extension_param);


	ZEPHIR_INIT_VAR(uri);
	ZVAL_STRING(uri, "/", 1);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("uriGenerator"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("uriGenerator"), PH_NOISY_CC);
		ZEPHIR_RETURN_CALL_METHOD(_1$$3, "generateuri", NULL, 0, source, prefix, extension);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_VVV(_4, source, prefix, extension);
	ZEPHIR_CALL_CE_STATIC(&_2, yb_std_ce, "uuid", &_3, 11, _4);
	zephir_check_call_status();
	zephir_get_strval(_5, _2);
	ZEPHIR_CPY_WRT(uuid, _5);
	_6 = ZEPHIR_STRING_OFFSET(uuid, 0);
	zephir_concat_self_char(&uri, _6 TSRMLS_CC);
	_7 = ZEPHIR_STRING_OFFSET(uuid, 1);
	zephir_concat_self_char(&uri, _7 TSRMLS_CC);
	zephir_concat_self_str(&uri, "/", sizeof("/")-1 TSRMLS_CC);
	_8 = ZEPHIR_STRING_OFFSET(uuid, 2);
	zephir_concat_self_char(&uri, _8 TSRMLS_CC);
	_9 = ZEPHIR_STRING_OFFSET(uuid, 3);
	zephir_concat_self_char(&uri, _9 TSRMLS_CC);
	zephir_concat_self_str(&uri, "/", sizeof("/")-1 TSRMLS_CC);
	zephir_concat_self(&uri, uuid TSRMLS_CC);
	if (!(!extension) && Z_STRLEN_P(extension)) {
		ZEPHIR_INIT_VAR(_10$$4);
		ZEPHIR_CONCAT_SV(_10$$4, ".", extension);
		zephir_concat_self(&uri, _10$$4 TSRMLS_CC);
	}
	RETURN_CTOR(uri);

}


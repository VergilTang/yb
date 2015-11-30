
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Yb_Upload_StorageAbstract) {

	ZEPHIR_REGISTER_CLASS(Yb\\Upload, StorageAbstract, yb, upload_storageabstract, yb_upload_storageabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_class_constant_long(yb_upload_storageabstract_ce, SL("COPY"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(yb_upload_storageabstract_ce, SL("MOVE"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(yb_upload_storageabstract_ce, SL("MOVE_UPLOADED_FILE"), 2 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Yb_Upload_StorageAbstract, store) {

}

PHP_METHOD(Yb_Upload_StorageAbstract, remove) {

}

PHP_METHOD(Yb_Upload_StorageAbstract, exists) {

}

PHP_METHOD(Yb_Upload_StorageAbstract, generateUri) {

	zend_bool _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_6 = NULL;
	zval *source_param = NULL, *prefix_param = NULL, *extension_param = NULL, *_0 = NULL, *_2, *_3, _4, *_5 = NULL;
	zval *source = NULL, *prefix = NULL, *extension = NULL, *uri, *_7$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &source_param, &prefix_param, &extension_param);

	zephir_get_strval(source, source_param);
	zephir_get_strval(prefix, prefix_param);
	zephir_get_strval(extension, extension_param);


	ZEPHIR_INIT_VAR(uri);
	ZVAL_STRING(uri, "/", 1);
	_1 = zephir_fast_strlen_ev(prefix) > 0;
	if (_1) {
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_STRING(&_4, "#^\\w[/\\w]*$#", 0);
		zephir_preg_match(_3, &_4, prefix, _2, 0, 0 , 0  TSRMLS_CC);
		_1 = zephir_is_true(_3);
	}
	if (_1) {
		zephir_concat_self(&uri, prefix TSRMLS_CC);
	}
	ZEPHIR_CALL_CE_STATIC(&_5, yb_std_ce, "uuid", &_6, 10);
	zephir_check_call_status();
	zephir_concat_self(&uri, _5 TSRMLS_CC);
	if (!(!extension) && Z_STRLEN_P(extension)) {
		ZEPHIR_INIT_VAR(_7$$4);
		ZEPHIR_CONCAT_SV(_7$$4, ".", extension);
		zephir_concat_self(&uri, _7$$4 TSRMLS_CC);
	}
	RETURN_CTOR(uri);

}


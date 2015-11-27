
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
#include "Zend/zend_closures.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Yb_View_Facade) {

	ZEPHIR_REGISTER_CLASS(Yb\\View, Facade, yb, view_facade, yb_view_facade_method_entry, 0);

	zend_declare_property_null(yb_view_facade_ce, SL("options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_view_facade_ce, SL("data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_view_facade_ce, SL("view"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(yb_view_facade_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	return SUCCESS;

}

PHP_METHOD(Yb_View_Facade, __construct) {

	zval *options_param = NULL, *data_param = NULL, *view = NULL;
	zval *options = NULL, *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &options_param, &data_param, &view);

	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}
	if (!data_param) {
		ZEPHIR_INIT_VAR(data);
		array_init(data);
	} else {
		zephir_get_arrval(data, data_param);
	}
	if (!view) {
		view = ZEPHIR_GLOBAL(global_null);
	}


	zephir_update_property_this(this_ptr, SL("options"), options TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("data"), data TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("view"), view TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_View_Facade, content) {

	zval *content_param = NULL, *contentType_param = NULL, *_0, *_1, *_2;
	zval *content = NULL, *contentType = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &content_param, &contentType_param);

	zephir_get_strval(content, content_param);
	if (!contentType_param) {
		ZEPHIR_INIT_VAR(contentType);
		ZVAL_STRING(contentType, "", 1);
	} else {
		zephir_get_strval(contentType, contentType_param);
	}


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_STRING(_0, "content", 1);
	zephir_update_property_this(this_ptr, SL("view"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "content", 1);
	zephir_update_property_array(this_ptr, SL("options"), _1, content TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "contentType", 1);
	zephir_update_property_array(this_ptr, SL("options"), _2, contentType TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_View_Facade, httpResponse) {

	zval *httpResponseOutput = NULL;
	zval *httpResponseCode_param = NULL, *httpResponseOutput_param = NULL, *_0, *_1, *_2, *_3;
	long httpResponseCode;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &httpResponseCode_param, &httpResponseOutput_param);

	httpResponseCode = zephir_get_intval(httpResponseCode_param);
	if (!httpResponseOutput_param) {
		ZEPHIR_INIT_VAR(httpResponseOutput);
		ZVAL_STRING(httpResponseOutput, "", 1);
	} else {
		zephir_get_strval(httpResponseOutput, httpResponseOutput_param);
	}


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_STRING(_0, "httpResponse", 1);
	zephir_update_property_this(this_ptr, SL("view"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "httpResponseCode", 1);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, httpResponseCode);
	zephir_update_property_array(this_ptr, SL("options"), _1, _2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "httpResponseOutput", 1);
	zephir_update_property_array(this_ptr, SL("options"), _3, httpResponseOutput TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_View_Facade, json) {

	zend_bool jsonCors;
	zval *jsonCallback_param = NULL, *jsonCors_param = NULL, *_0, *_1;
	zval *jsonCallback = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &jsonCallback_param, &jsonCors_param);

	if (!jsonCallback_param) {
		ZEPHIR_INIT_VAR(jsonCallback);
		ZVAL_STRING(jsonCallback, "", 1);
	} else {
		zephir_get_strval(jsonCallback, jsonCallback_param);
	}
	if (!jsonCors_param) {
		jsonCors = 0;
	} else {
		jsonCors = zephir_get_boolval(jsonCors_param);
	}


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_STRING(_0, "json", 1);
	zephir_update_property_this(this_ptr, SL("view"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "jsonCallback", 1);
	zephir_update_property_array(this_ptr, SL("options"), _1, jsonCallback TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_View_Facade, nil) {

	zval *_0;


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_STRING(_0, "nil", 1);
	zephir_update_property_this(this_ptr, SL("view"), _0 TSRMLS_CC);

}

PHP_METHOD(Yb_View_Facade, readFile) {

	zval *readFile_param = NULL, *_0, *_1;
	zval *readFile = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &readFile_param);

	zephir_get_strval(readFile, readFile_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_STRING(_0, "readFile", 1);
	zephir_update_property_this(this_ptr, SL("view"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "readFile", 1);
	zephir_update_property_array(this_ptr, SL("options"), _1, readFile TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_View_Facade, redirect) {

	zend_bool redirectDataAsQueries;
	zval *redirectUrl_param = NULL, *redirectDataAsQueries_param = NULL, *_0, *_1, *_2, *_3;
	zval *redirectUrl = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &redirectUrl_param, &redirectDataAsQueries_param);

	zephir_get_strval(redirectUrl, redirectUrl_param);
	if (!redirectDataAsQueries_param) {
		redirectDataAsQueries = 0;
	} else {
		redirectDataAsQueries = zephir_get_boolval(redirectDataAsQueries_param);
	}


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_STRING(_0, "redirect", 1);
	zephir_update_property_this(this_ptr, SL("view"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "redirectUrl", 1);
	zephir_update_property_array(this_ptr, SL("options"), _1, redirectUrl TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "redirectDataAsQueries", 1);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_BOOL(_3, redirectDataAsQueries);
	zephir_update_property_array(this_ptr, SL("options"), _2, _3 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_View_Facade, tpl) {

	zval *tplId_param = NULL, *_0, *_1;
	zval *tplId = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &tplId_param);

	zephir_get_strval(tplId, tplId_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_STRING(_0, "tpl", 1);
	zephir_update_property_this(this_ptr, SL("view"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "tplId", 1);
	zephir_update_property_array(this_ptr, SL("options"), _1, tplId TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_View_Facade, setView) {

	zval *view;

	zephir_fetch_params(0, 1, 0, &view);



	zephir_update_property_this(this_ptr, SL("view"), view TSRMLS_CC);

}

PHP_METHOD(Yb_View_Facade, getView) {

	

	RETURN_MEMBER(this_ptr, "view");

}

PHP_METHOD(Yb_View_Facade, __invoke) {

	zval *_1$$3 = NULL;
	zend_bool _12;
	zval *view = NULL, *_13, *_14, *_0$$3, _2$$3 = zval_used_for_init, *_3$$3 = NULL, *_9$$3 = NULL, *_10$$3 = NULL, *_11$$3 = NULL, *_4$$6 = NULL, *_5$$6 = NULL, *_7$$6 = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	while (1) {
		_0$$3 = zephir_fetch_nproperty_this(this_ptr, SL("view"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(view, _0$$3);
		if (Z_TYPE_P(view) == IS_OBJECT) {
			if (zephir_instance_of_ev(view, zend_ce_closure TSRMLS_CC)) {
				ZEPHIR_CALL_ZVAL_FUNCTION(&view, view, NULL, 0);
				zephir_check_call_status();
			}
			break;
		}
		zephir_get_strval(_1$$3, view);
		ZEPHIR_CPY_WRT(view, _1$$3);
		ZEPHIR_SINIT_NVAR(_2$$3);
		ZVAL_STRING(&_2$$3, "\\", 0);
		ZEPHIR_INIT_NVAR(_3$$3);
		zephir_fast_strpos(_3$$3, view, &_2$$3, 0 );
		if (ZEPHIR_IS_FALSE_IDENTICAL(_3$$3)) {
			ZEPHIR_INIT_NVAR(_4$$6);
			object_init_ex(_4$$6, yb_factory_namespaced_ce);
			ZEPHIR_INIT_NVAR(_5$$6);
			ZVAL_STRING(_5$$6, "Yb\\View", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _4$$6, "__construct", &_6, 140, _5$$6);
			zephir_check_temp_parameter(_5$$6);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_7$$6, _4$$6, "__get", &_8, 141, view);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(view, _7$$6);
			break;
		}
		ZEPHIR_INIT_NVAR(_9$$3);
		object_init_ex(_9$$3, yb_factory_namespaced_ce);
		ZEPHIR_INIT_NVAR(_10$$3);
		ZVAL_STRING(_10$$3, "", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _9$$3, "__construct", &_6, 140, _10$$3);
		zephir_check_temp_parameter(_10$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_11$$3, _9$$3, "__get", &_8, 141, view);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(view, _11$$3);
		break;
	}
	_12 = Z_TYPE_P(view) != IS_OBJECT;
	if (!(_12)) {
		_12 = !((zephir_instance_of_ev(view, yb_view_viewinterface_ce TSRMLS_CC)));
	}
	if (unlikely(_12)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_view_exception_ce, "Invalid view", "yb/view/facade.zep", 98);
		return;
	}
	_13 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	_14 = zephir_fetch_nproperty_this(this_ptr, SL("options"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, view, "run", NULL, 0, _13, _14);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_View_Facade, setOptions) {

	HashTable *_1;
	HashPosition _0;
	zval *options_param = NULL, *k = NULL, *v = NULL, **_2;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	zephir_get_arrval(options, options_param);


	zephir_is_iterable(options, &_1, &_0, 0, 0, "yb/view/facade.zep", 111);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		zephir_update_property_array(this_ptr, SL("options"), k, v TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_View_Facade, __set) {

	zval *key_param = NULL, *value;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(key, key_param);


	zephir_update_property_array(this_ptr, SL("options"), key, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_View_Facade, __get) {

	zval *key_param = NULL, *value = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("options"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&value, _0, key, 1 TSRMLS_CC)) {
		RETURN_CTOR(value);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_View_Facade, __isset) {

	zval *key_param = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("options"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, key));

}

PHP_METHOD(Yb_View_Facade, __unset) {

	zval *key_param = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("options"), PH_NOISY_CC);
	zephir_array_unset(&_0, key, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_View_Facade, setData) {

	HashTable *_1;
	HashPosition _0;
	zval *data_param = NULL, *k = NULL, *v = NULL, **_2;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_arrval(data, data_param);


	zephir_is_iterable(data, &_1, &_0, 0, 0, "yb/view/facade.zep", 144);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		zephir_update_property_array(this_ptr, SL("data"), k, v TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_View_Facade, offsetSet) {

	zval *key_param = NULL, *value;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(key, key_param);


	zephir_update_property_array(this_ptr, SL("data"), key, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_View_Facade, offsetGet) {

	zval *key_param = NULL, *value = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&value, _0, key, 1 TSRMLS_CC)) {
		RETURN_CTOR(value);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_View_Facade, offsetExists) {

	zval *key_param = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, key));

}

PHP_METHOD(Yb_View_Facade, offsetUnset) {

	zval *key_param = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	zephir_array_unset(&_0, key, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}


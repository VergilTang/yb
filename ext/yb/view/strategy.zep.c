
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
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Yb_View_Strategy) {

	ZEPHIR_REGISTER_CLASS(Yb\\View, Strategy, yb, view_strategy, yb_view_strategy_method_entry, 0);

	zend_declare_property_null(yb_view_strategy_ce, SL("options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_view_strategy_ce, SL("data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_view_strategy_ce, SL("view"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(yb_view_strategy_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	return SUCCESS;

}

PHP_METHOD(Yb_View_Strategy, __construct) {

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

PHP_METHOD(Yb_View_Strategy, setView) {

	zval *view;

	zephir_fetch_params(0, 1, 0, &view);



	zephir_update_property_this(this_ptr, SL("view"), view TSRMLS_CC);

}

PHP_METHOD(Yb_View_Strategy, getView) {

	

	RETURN_MEMBER(this_ptr, "view");

}

PHP_METHOD(Yb_View_Strategy, __invoke) {

	zval *_3$$3 = NULL;
	zend_bool _4;
	zval *view = NULL, *_0, *_5, *_1$$3, *_2$$3;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("view"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(view, _0);
	if (Z_TYPE_P(view) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, yb_factory_namespaced_ce);
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_STRING(_2$$3, "Yb\\View", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 143, _2$$3);
		zephir_check_temp_parameter(_2$$3);
		zephir_check_call_status();
		zephir_get_strval(_3$$3, view);
		ZEPHIR_CALL_METHOD(&view, _1$$3, "__get", NULL, 144, _3$$3);
		zephir_check_call_status();
	}
	_4 = Z_TYPE_P(view) != IS_OBJECT;
	if (!(_4)) {
		_4 = !((zephir_instance_of_ev(view, yb_view_viewinterface_ce TSRMLS_CC)));
	}
	if (unlikely(_4)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_view_exception_ce, "Invalid view", "yb/view/strategy.zep", 39);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("options"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, view, "run", NULL, 0, _0, _5);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_View_Strategy, setOptions) {

	HashTable *_1;
	HashPosition _0;
	zval *options_param = NULL, *k = NULL, *v = NULL, **_2;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	zephir_get_arrval(options, options_param);


	zephir_is_iterable(options, &_1, &_0, 0, 0, "yb/view/strategy.zep", 52);
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

PHP_METHOD(Yb_View_Strategy, __set) {

	zval *key_param = NULL, *value;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(key, key_param);


	zephir_update_property_array(this_ptr, SL("options"), key, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_View_Strategy, __get) {

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

PHP_METHOD(Yb_View_Strategy, __isset) {

	zval *key_param = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("options"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, key));

}

PHP_METHOD(Yb_View_Strategy, __unset) {

	zval *key_param = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("options"), PH_NOISY_CC);
	zephir_array_unset(&_0, key, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_View_Strategy, setData) {

	HashTable *_1;
	HashPosition _0;
	zval *data_param = NULL, *k = NULL, *v = NULL, **_2;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_arrval(data, data_param);


	zephir_is_iterable(data, &_1, &_0, 0, 0, "yb/view/strategy.zep", 85);
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

PHP_METHOD(Yb_View_Strategy, offsetSet) {

	zval *key_param = NULL, *value;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(key, key_param);


	zephir_update_property_array(this_ptr, SL("data"), key, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_View_Strategy, offsetGet) {

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

PHP_METHOD(Yb_View_Strategy, offsetExists) {

	zval *key_param = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, key));

}

PHP_METHOD(Yb_View_Strategy, offsetUnset) {

	zval *key_param = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	zephir_array_unset(&_0, key, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}


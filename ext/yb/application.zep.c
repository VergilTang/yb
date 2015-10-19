
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Yb_Application) {

	ZEPHIR_REGISTER_CLASS(Yb, Application, yb, application, yb_application_method_entry, 0);

	zend_declare_property_null(yb_application_ce, SL("serviceObjects"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_application_ce, SL("serviceConfigs"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Yb_Application, __invoke) {

	


}

PHP_METHOD(Yb_Application, __call) {

	zval *config = NULL;
	zval *name_param = NULL, *config_param = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &config_param);

	zephir_get_strval(name, name_param);
	zephir_get_arrval(config, config_param);


	zephir_update_property_array(this_ptr, SL("serviceConfigs"), name, config TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Application, __get) {

	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *obj = NULL, *config = NULL, *closure = NULL, *isShared = NULL, *_0, *_1, *_2$$4, *_5$$5;
	zval *name = NULL, *_3$$4, *_6$$5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	ZEPHIR_OBS_VAR(obj);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("serviceObjects"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&obj, _0, name, 0 TSRMLS_CC)) {
		RETURN_CCTOR(obj);
	}
	ZEPHIR_OBS_VAR(config);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("serviceConfigs"), PH_NOISY_CC);
	if (unlikely(!(zephir_array_isset_fetch(&config, _1, name, 0 TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(_2$$4);
		object_init_ex(_2$$4, yb_exception_ce);
		ZEPHIR_INIT_VAR(_3$$4);
		ZEPHIR_CONCAT_SV(_3$$4, "Invalid service: ", name);
		ZEPHIR_CALL_METHOD(NULL, _2$$4, "__construct", NULL, 3, _3$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2$$4, "yb/application.zep", 26 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MAKE_REF(config);
	ZEPHIR_CALL_FUNCTION(&closure, "array_shift", &_4, 8, config);
	ZEPHIR_UNREF(config);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(config);
	ZEPHIR_CALL_FUNCTION(&isShared, "array_shift", &_4, 8, config);
	ZEPHIR_UNREF(config);
	zephir_check_call_status();
	if (unlikely(!(zephir_is_callable(closure TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(_5$$5);
		object_init_ex(_5$$5, yb_exception_ce);
		ZEPHIR_INIT_VAR(_6$$5);
		ZEPHIR_CONCAT_SV(_6$$5, "Invalid service config: ", name);
		ZEPHIR_CALL_METHOD(NULL, _5$$5, "__construct", NULL, 3, _6$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_5$$5, "yb/application.zep", 33 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&obj, "call_user_func", NULL, 9, closure, this_ptr);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(isShared)) {
		zephir_update_property_array(this_ptr, SL("serviceObjects"), name, obj TSRMLS_CC);
	}
	RETURN_CCTOR(obj);

}

PHP_METHOD(Yb_Application, __set) {

	zval *name_param = NULL, *obj;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &obj);

	zephir_get_strval(name, name_param);


	zephir_update_property_array(this_ptr, SL("serviceObjects"), name, obj TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Application, __isset) {

	zend_bool _1;
	zval *name_param = NULL, *_0, *_2;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("serviceObjects"), PH_NOISY_CC);
	_1 = zephir_array_isset(_0, name);
	if (!(_1)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("serviceConfigs"), PH_NOISY_CC);
		_1 = zephir_array_isset(_2, name);
	}
	RETURN_MM_BOOL(_1);

}

PHP_METHOD(Yb_Application, __unset) {

	zval *name_param = NULL, *_0, *_1;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("serviceObjects"), PH_NOISY_CC);
	zephir_array_unset(&_0, name, PH_SEPARATE);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("serviceConfigs"), PH_NOISY_CC);
	zephir_array_unset(&_1, name, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}



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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/file.h"
#include "kernel/require.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "Zend/zend_closures.h"


ZEPHIR_INIT_CLASS(Yb_Application) {

	ZEPHIR_REGISTER_CLASS(Yb, Application, yb, application, yb_application_method_entry, 0);

	zend_declare_property_null(yb_application_ce, SL("configs"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_application_ce, SL("data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_application_ce, SL("services"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_application_ce, SL("serviceInitializers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(yb_application_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	return SUCCESS;

}

PHP_METHOD(Yb_Application, __construct) {

	zval *configs_param = NULL;
	zval *configs = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &configs_param);

	if (!configs_param) {
		ZEPHIR_INIT_VAR(configs);
		array_init(configs);
	} else {
		zephir_get_arrval(configs, configs_param);
	}


	zephir_update_property_this(this_ptr, SL("configs"), configs TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Application, config) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *name_param = NULL, *defaultValue = NULL, *_1;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &defaultValue);

	zephir_get_strval(name, name_param);
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	_1 = zephir_fetch_nproperty_this(this_ptr, SL("configs"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_CE_STATIC(yb_std_ce, "valueof", &_0, 29, _1, name, defaultValue);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Application, mergeConfigs) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *configs_param = NULL, *_0, *_1 = NULL;
	zval *configs = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &configs_param);

	zephir_get_arrval(configs, configs_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("configs"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "array_replace_recursive", NULL, 30, _0, configs);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("configs"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Application, mergeConfigsInPathIfValid) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *configs = NULL, *_0 = NULL;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(path, path_param);


	if (!((zephir_file_exists(path TSRMLS_CC) == SUCCESS))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_0);
	if (zephir_require_zval_ret(&_0, path TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CPY_WRT(configs, _0);
	if (Z_TYPE_P(configs) != IS_ARRAY) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "mergeconfigs", NULL, 0, configs);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Application, offsetGet) {

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

PHP_METHOD(Yb_Application, offsetSet) {

	zval *key_param = NULL, *value;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(key, key_param);


	zephir_update_property_array(this_ptr, SL("data"), key, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Application, offsetExists) {

	zval *key_param = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, key));

}

PHP_METHOD(Yb_Application, offsetUnset) {

	zval *key_param = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	zephir_array_unset(&_0, key, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Application, __invoke) {

	zval *name_param = NULL, *initializer = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &initializer);

	zephir_get_strval(name, name_param);
	if (!initializer) {
		initializer = ZEPHIR_GLOBAL(global_null);
	}


	zephir_update_property_array(this_ptr, SL("serviceInitializers"), name, initializer TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Application, __get) {

	zend_bool _6$$5;
	zend_class_entry *_5$$6;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *service = NULL, *initializer = NULL, *_0, *_1, *_2$$4, *_4$$6 = NULL, *_7$$5 = NULL;
	zval *name = NULL, *_3$$4, *_8$$5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	ZEPHIR_OBS_VAR(service);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("services"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&service, _0, name, 0 TSRMLS_CC)) {
		RETURN_CCTOR(service);
	}
	ZEPHIR_OBS_VAR(initializer);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("serviceInitializers"), PH_NOISY_CC);
	if (unlikely(!(zephir_array_isset_fetch(&initializer, _1, name, 0 TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(_2$$4);
		object_init_ex(_2$$4, yb_exception_ce);
		ZEPHIR_INIT_VAR(_3$$4);
		ZEPHIR_CONCAT_SV(_3$$4, "Invalid service: ", name);
		ZEPHIR_CALL_METHOD(NULL, _2$$4, "__construct", NULL, 2, _3$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2$$4, "yb/application.zep", 80 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	while (1) {
		if (Z_TYPE_P(initializer) == IS_NULL) {
			ZEPHIR_INIT_NVAR(service);
			zephir_fetch_safe_class(_4$$6, name);
				_5$$6 = zend_fetch_class(Z_STRVAL_P(_4$$6), Z_STRLEN_P(_4$$6), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(service, _5$$6);
			if (zephir_has_constructor(service TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, service, "__construct", NULL, 0);
				zephir_check_call_status();
			}
			break;
		}
		_6$$5 = Z_TYPE_P(initializer) == IS_OBJECT;
		if (_6$$5) {
			_6$$5 = (zephir_instance_of_ev(initializer, zend_ce_closure TSRMLS_CC));
		}
		if (_6$$5) {
			ZEPHIR_CALL_ZVAL_FUNCTION(&service, initializer, NULL, 0, this_ptr);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_INIT_NVAR(_7$$5);
		object_init_ex(_7$$5, yb_exception_ce);
		ZEPHIR_INIT_LNVAR(_8$$5);
		ZEPHIR_CONCAT_SV(_8$$5, "Invalid service initializer: ", name);
		ZEPHIR_CALL_METHOD(NULL, _7$$5, "__construct", NULL, 2, _8$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_7$$5, "yb/application.zep", 94 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_array(this_ptr, SL("services"), name, service TSRMLS_CC);
	RETURN_CCTOR(service);

}

PHP_METHOD(Yb_Application, __set) {

	zval *name_param = NULL, *obj;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &obj);

	zephir_get_strval(name, name_param);


	zephir_update_property_array(this_ptr, SL("services"), name, obj TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Application, __isset) {

	zend_bool _1;
	zval *name_param = NULL, *_0, *_2;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("services"), PH_NOISY_CC);
	_1 = zephir_array_isset(_0, name);
	if (!(_1)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("serviceInitializers"), PH_NOISY_CC);
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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("services"), PH_NOISY_CC);
	zephir_array_unset(&_0, name, PH_SEPARATE);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("serviceInitializers"), PH_NOISY_CC);
	zephir_array_unset(&_1, name, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}


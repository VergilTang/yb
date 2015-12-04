
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
#include "Zend/zend_closures.h"


ZEPHIR_INIT_CLASS(Yb_Di) {

	ZEPHIR_REGISTER_CLASS(Yb, Di, yb, di, yb_di_method_entry, 0);

	zend_declare_property_null(yb_di_ce, SL("services"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_di_ce, SL("serviceInitializers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Yb_Di, __invoke) {

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

PHP_METHOD(Yb_Di, __get) {

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
		zephir_throw_exception_debug(_2$$4, "yb/di.zep", 22 TSRMLS_CC);
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
		zephir_throw_exception_debug(_7$$5, "yb/di.zep", 36 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_array(this_ptr, SL("services"), name, service TSRMLS_CC);
	RETURN_CCTOR(service);

}

PHP_METHOD(Yb_Di, __set) {

	zval *name_param = NULL, *obj;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &obj);

	zephir_get_strval(name, name_param);


	zephir_update_property_array(this_ptr, SL("services"), name, obj TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Di, __isset) {

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

PHP_METHOD(Yb_Di, __unset) {

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

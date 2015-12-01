
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
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Yb_Router_RouterAbstract) {

	ZEPHIR_REGISTER_CLASS(Yb\\Router, RouterAbstract, yb, router_routerabstract, yb_router_routerabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(yb_router_routerabstract_ce, SL("controller"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_router_routerabstract_ce, SL("action"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_router_routerabstract_ce, SL("params"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(yb_router_routerabstract_ce, SL("DEFAULT_CONTROLLER"), "index" TSRMLS_CC);

	zend_declare_class_constant_string(yb_router_routerabstract_ce, SL("DEFAULT_ACTION"), "index" TSRMLS_CC);

	zend_declare_class_constant_string(yb_router_routerabstract_ce, SL("DEFAULT_ACTION_SUFFIX"), "Action" TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Yb_Router_RouterAbstract, getController) {

	

	RETURN_MEMBER(this_ptr, "controller");

}

PHP_METHOD(Yb_Router_RouterAbstract, getAction) {

	

	RETURN_MEMBER(this_ptr, "action");

}

PHP_METHOD(Yb_Router_RouterAbstract, getParams) {

	

	RETURN_MEMBER(this_ptr, "params");

}

PHP_METHOD(Yb_Router_RouterAbstract, getId) {

	zval *separator_param = NULL, *_0, *_1;
	zval *separator = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &separator_param);

	if (!separator_param) {
		ZEPHIR_INIT_VAR(separator);
		ZVAL_STRING(separator, "/", 1);
	} else {
		zephir_get_strval(separator, separator_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("controller"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("action"), PH_NOISY_CC);
	ZEPHIR_CONCAT_VVV(return_value, _0, separator, _1);
	RETURN_MM();

}

PHP_METHOD(Yb_Router_RouterAbstract, dispatch) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *actionSuffix = NULL, *controllerClass = NULL, *_3 = NULL;
	zval *factory, *actionSuffix_param = NULL, *actionMethod = NULL, *_0 = NULL, *_2, *_4 = NULL, *_8 = NULL, *_9 = NULL, *_10, *_11, *_15, *_5$$3, *_6$$3, *_7$$3, *_12$$4, *_13$$4, *_14$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &factory, &actionSuffix_param);

	if (!actionSuffix_param) {
		ZEPHIR_INIT_VAR(actionSuffix);
		ZVAL_STRING(actionSuffix, "Action", 1);
	} else {
		zephir_get_strval(actionSuffix, actionSuffix_param);
	}


	_2 = zephir_fetch_nproperty_this(this_ptr, SL("controller"), PH_NOISY_CC);
	ZEPHIR_CALL_CE_STATIC(&_0, yb_std_ce, "camelcase", &_1, 20, _2);
	zephir_check_call_status();
	zephir_get_strval(_3, _0);
	ZEPHIR_CPY_WRT(controllerClass, _3);
	ZEPHIR_CALL_METHOD(&_4, factory, "__isset", NULL, 0, controllerClass);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_4))) {
		ZEPHIR_INIT_VAR(_5$$3);
		object_init_ex(_5$$3, yb_router_notfoundexception_ce);
		_6$$3 = zephir_fetch_nproperty_this(this_ptr, SL("controller"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_7$$3);
		ZEPHIR_CONCAT_SV(_7$$3, "Invalid controller: ", _6$$3);
		ZEPHIR_CALL_METHOD(NULL, _5$$3, "__construct", NULL, 2, _7$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_5$$3, "yb/router/routerabstract.zep", 43 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(actionMethod);
	array_init(actionMethod);
	ZEPHIR_CALL_METHOD(&_8, factory, "__get", NULL, 0, controllerClass);
	zephir_check_call_status();
	zephir_array_append(&actionMethod, _8, PH_SEPARATE, "yb/router/routerabstract.zep", 47);
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("action"), PH_NOISY_CC);
	ZEPHIR_CALL_CE_STATIC(&_9, yb_std_ce, "camelcase", &_1, 20, _10);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_11);
	ZEPHIR_CONCAT_VV(_11, _9, actionSuffix);
	zephir_array_append(&actionMethod, _11, PH_SEPARATE, "yb/router/routerabstract.zep", 48);
	if (unlikely(!(zephir_is_callable(actionMethod TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(_12$$4);
		object_init_ex(_12$$4, yb_router_notfoundexception_ce);
		_13$$4 = zephir_fetch_nproperty_this(this_ptr, SL("action"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_14$$4);
		ZEPHIR_CONCAT_SV(_14$$4, "Invalid action: ", _13$$4);
		ZEPHIR_CALL_METHOD(NULL, _12$$4, "__construct", NULL, 2, _14$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_12$$4, "yb/router/routerabstract.zep", 51 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_15 = zephir_fetch_nproperty_this(this_ptr, SL("params"), PH_NOISY_CC);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, actionMethod, _15);
	zephir_check_call_status();
	RETURN_MM();

}


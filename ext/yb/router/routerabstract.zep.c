
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
#include "kernel/concat.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Yb_Router_RouterAbstract) {

	ZEPHIR_REGISTER_CLASS(Yb\\Router, RouterAbstract, yb, router_routerabstract, yb_router_routerabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(yb_router_routerabstract_ce, SL("controller"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_router_routerabstract_ce, SL("action"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_router_routerabstract_ce, SL("params"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(yb_router_routerabstract_ce, SL("DEFAULT_CONTROLLER"), "index" TSRMLS_CC);

	zend_declare_class_constant_string(yb_router_routerabstract_ce, SL("DEFAULT_ACTION"), "index" TSRMLS_CC);

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

PHP_METHOD(Yb_Router_RouterAbstract, dispatch) {

	zval *c = NULL, *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *factory, *i = NULL, *_0 = NULL, *_2, *_4 = NULL, *_8 = NULL, *_9 = NULL, *_10, *_11, *_15, *_5$$3, *_6$$3, *_7$$3, *_12$$4, *_13$$4, *_14$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &factory);



	_2 = zephir_fetch_nproperty_this(this_ptr, SL("controller"), PH_NOISY_CC);
	ZEPHIR_CALL_CE_STATIC(&_0, yb_std_ce, "camelcase", &_1, 22, _2);
	zephir_check_call_status();
	zephir_get_strval(_3, _0);
	ZEPHIR_CPY_WRT(c, _3);
	ZEPHIR_CALL_METHOD(&_4, factory, "has", NULL, 0, c);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_4))) {
		ZEPHIR_INIT_VAR(_5$$3);
		object_init_ex(_5$$3, yb_router_exception_ce);
		_6$$3 = zephir_fetch_nproperty_this(this_ptr, SL("controller"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_7$$3);
		ZEPHIR_CONCAT_SV(_7$$3, "Invalid controller: ", _6$$3);
		ZEPHIR_CALL_METHOD(NULL, _5$$3, "__construct", NULL, 2, _7$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_5$$3, "yb/router/routerabstract.zep", 37 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(i);
	array_init(i);
	ZEPHIR_CALL_METHOD(&_8, factory, "get", NULL, 0, c);
	zephir_check_call_status();
	zephir_array_append(&i, _8, PH_SEPARATE, "yb/router/routerabstract.zep", 41);
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("action"), PH_NOISY_CC);
	ZEPHIR_CALL_CE_STATIC(&_9, yb_std_ce, "camelcase", &_1, 22, _10);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_11);
	ZEPHIR_CONCAT_VS(_11, _9, "Action");
	zephir_array_append(&i, _11, PH_SEPARATE, "yb/router/routerabstract.zep", 42);
	if (unlikely(!(zephir_is_callable(i TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(_12$$4);
		object_init_ex(_12$$4, yb_router_exception_ce);
		_13$$4 = zephir_fetch_nproperty_this(this_ptr, SL("action"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_14$$4);
		ZEPHIR_CONCAT_SV(_14$$4, "Invalid action: ", _13$$4);
		ZEPHIR_CALL_METHOD(NULL, _12$$4, "__construct", NULL, 2, _14$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_12$$4, "yb/router/routerabstract.zep", 45 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_15 = zephir_fetch_nproperty_this(this_ptr, SL("params"), PH_NOISY_CC);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, i, _15);
	zephir_check_call_status();
	RETURN_MM();

}


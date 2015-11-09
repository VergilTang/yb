
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
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Yb_Router_Uri) {

	ZEPHIR_REGISTER_CLASS_EX(Yb\\Router, Uri, yb, router_uri, yb_router_routerabstract_ce, yb_router_uri_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Yb_Router_Uri, __construct) {

	zephir_fcall_cache_entry *_13 = NULL;
	int ZEPHIR_LAST_CALL_STATUS, _10;
	zval *patterns = NULL;
	zval *uri_param = NULL, *patterns_param = NULL, *m = NULL, *params = NULL, *_4, _5, *_0$$3, *_1$$3 = NULL, *_2$$3 = NULL, *_6$$4, _8$$4, _9$$4, *_11$$6, *_12$$7 = NULL, *_14$$7, *_15$$8 = NULL, *_16$$8 = NULL;
	zval *uri = NULL, *_3$$3 = NULL, *_7$$4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &uri_param, &patterns_param);

	zephir_get_strval(uri, uri_param);
	if (!patterns_param) {
		ZEPHIR_INIT_VAR(patterns);
		array_init(patterns);
	} else {
		zephir_get_arrval(patterns, patterns_param);
	}


	ZEPHIR_INIT_VAR(m);
	ZVAL_NULL(m);
	if (zephir_fast_count_int(patterns TSRMLS_CC) > 0) {
		ZEPHIR_INIT_VAR(_0$$3);
		zephir_array_keys(_0$$3, patterns TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_1$$3, "array_values", NULL, 92, patterns);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_2$$3, "preg_replace", NULL, 43, _0$$3, _1$$3, uri);
		zephir_check_call_status();
		zephir_get_strval(_3$$3, _2$$3);
		ZEPHIR_CPY_WRT(uri, _3$$3);
	}
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_STRING(&_5, "/^([^\\.\\?]+)/", 0);
	zephir_preg_match(_4, &_5, uri, m, 0, 0 , 0  TSRMLS_CC);
	if (zephir_is_true(_4)) {
		ZEPHIR_OBS_VAR(_6$$4);
		zephir_array_fetch_long(&_6$$4, m, 1, PH_NOISY, "yb/router/uri.zep", 18 TSRMLS_CC);
		zephir_get_strval(_7$$4, _6$$4);
		ZEPHIR_SINIT_VAR(_8$$4);
		ZVAL_STRING(&_8$$4, "#/+#", 0);
		ZEPHIR_SINIT_VAR(_9$$4);
		ZVAL_LONG(&_9$$4, 1);
		ZEPHIR_CALL_FUNCTION(&params, "preg_split", NULL, 93, &_8$$4, _7$$4, ZEPHIR_GLOBAL(global_null), &_9$$4);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(params);
		array_init(params);
	}
	do {
		_10 = zephir_fast_count_int(params TSRMLS_CC);
		if (_10 == 0) {
			ZEPHIR_INIT_ZVAL_NREF(_11$$6);
			ZVAL_STRING(_11$$6, "index", 1);
			zephir_update_property_this(this_ptr, SL("controller"), _11$$6 TSRMLS_CC);
			ZEPHIR_INIT_ZVAL_NREF(_11$$6);
			ZVAL_STRING(_11$$6, "index", 1);
			zephir_update_property_this(this_ptr, SL("action"), _11$$6 TSRMLS_CC);
			break;
		}
		if (_10 == 1) {
			ZEPHIR_MAKE_REF(params);
			ZEPHIR_CALL_FUNCTION(&_12$$7, "array_shift", &_13, 6, params);
			ZEPHIR_UNREF(params);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("controller"), _12$$7 TSRMLS_CC);
			ZEPHIR_INIT_ZVAL_NREF(_14$$7);
			ZVAL_STRING(_14$$7, "index", 1);
			zephir_update_property_this(this_ptr, SL("action"), _14$$7 TSRMLS_CC);
			break;
		}
		ZEPHIR_MAKE_REF(params);
		ZEPHIR_CALL_FUNCTION(&_15$$8, "array_shift", &_13, 6, params);
		ZEPHIR_UNREF(params);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("controller"), _15$$8 TSRMLS_CC);
		ZEPHIR_MAKE_REF(params);
		ZEPHIR_CALL_FUNCTION(&_16$$8, "array_shift", &_13, 6, params);
		ZEPHIR_UNREF(params);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("action"), _16$$8 TSRMLS_CC);
		break;
	} while(0);

	zephir_update_property_this(this_ptr, SL("params"), params TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}


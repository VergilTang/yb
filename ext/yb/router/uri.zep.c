
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
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Yb_Router_Uri) {

	ZEPHIR_REGISTER_CLASS_EX(Yb\\Router, Uri, yb, router_uri, yb_router_routerabstract_ce, yb_router_uri_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Yb_Router_Uri, __construct) {

	zephir_fcall_cache_entry *_9 = NULL;
	int ZEPHIR_LAST_CALL_STATUS, _6;
	zval *uri_param = NULL, *m = NULL, *params = NULL, *_0, _1, *_2$$3, _4$$3, _5$$3, *_7$$5, *_8$$6 = NULL, *_10$$6, *_11$$7 = NULL, *_12$$7 = NULL;
	zval *uri = NULL, *_3$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);

	zephir_get_strval(uri, uri_param);


	ZEPHIR_INIT_VAR(m);
	ZVAL_NULL(m);
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "/^([^\\.\\?]+)/", 0);
	zephir_preg_match(_0, &_1, uri, m, 0, 0 , 0  TSRMLS_CC);
	if (zephir_is_true(_0)) {
		ZEPHIR_OBS_VAR(_2$$3);
		zephir_array_fetch_long(&_2$$3, m, 1, PH_NOISY, "yb/router/uri.zep", 10 TSRMLS_CC);
		zephir_get_strval(_3$$3, _2$$3);
		ZEPHIR_SINIT_VAR(_4$$3);
		ZVAL_STRING(&_4$$3, "#/+#", 0);
		ZEPHIR_SINIT_VAR(_5$$3);
		ZVAL_LONG(&_5$$3, 1);
		ZEPHIR_CALL_FUNCTION(&params, "preg_split", NULL, 43, &_4$$3, _3$$3, ZEPHIR_GLOBAL(global_null), &_5$$3);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(params);
		array_init(params);
	}
	do {
		_6 = zephir_fast_count_int(params TSRMLS_CC);
		if (_6 == 0) {
			ZEPHIR_INIT_ZVAL_NREF(_7$$5);
			ZVAL_STRING(_7$$5, "index", 1);
			zephir_update_property_this(this_ptr, SL("controller"), _7$$5 TSRMLS_CC);
			ZEPHIR_INIT_ZVAL_NREF(_7$$5);
			ZVAL_STRING(_7$$5, "index", 1);
			zephir_update_property_this(this_ptr, SL("action"), _7$$5 TSRMLS_CC);
			break;
		}
		if (_6 == 1) {
			ZEPHIR_MAKE_REF(params);
			ZEPHIR_CALL_FUNCTION(&_8$$6, "array_shift", &_9, 9, params);
			ZEPHIR_UNREF(params);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("controller"), _8$$6 TSRMLS_CC);
			ZEPHIR_INIT_ZVAL_NREF(_10$$6);
			ZVAL_STRING(_10$$6, "index", 1);
			zephir_update_property_this(this_ptr, SL("action"), _10$$6 TSRMLS_CC);
			break;
		}
		ZEPHIR_MAKE_REF(params);
		ZEPHIR_CALL_FUNCTION(&_11$$7, "array_shift", &_9, 9, params);
		ZEPHIR_UNREF(params);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("controller"), _11$$7 TSRMLS_CC);
		ZEPHIR_MAKE_REF(params);
		ZEPHIR_CALL_FUNCTION(&_12$$7, "array_shift", &_9, 9, params);
		ZEPHIR_UNREF(params);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("action"), _12$$7 TSRMLS_CC);
		break;
	} while(0);

	zephir_update_property_this(this_ptr, SL("params"), params TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}


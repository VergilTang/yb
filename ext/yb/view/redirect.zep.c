
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Yb_View_Redirect) {

	ZEPHIR_REGISTER_CLASS(Yb\\View, Redirect, yb, view_redirect, yb_view_redirect_method_entry, 0);

	zend_class_implements(yb_view_redirect_ce TSRMLS_CC, 1, yb_view_viewinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Yb_View_Redirect, run) {

	zend_bool dataQuery = 0;
	zval *redirectUrl = NULL, *query = NULL, *_4 = NULL, *_12, *_8$$4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *data_param = NULL, *options_param = NULL, *_0 = NULL, *_2 = NULL, *_3 = NULL, *_5 = NULL, *_6 = NULL, *_7$$4 = NULL, *_9$$4 = NULL, _10$$5, *_11$$5;
	zval *data = NULL, *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &data_param, &options_param);

	zephir_get_arrval(data, data_param);
	zephir_get_arrval(options, options_param);


	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "redirectUrl", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_0, yb_std_ce, "valueat", &_1, 9, options, _2, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_get_strval(_4, _0);
	ZEPHIR_CPY_WRT(redirectUrl, _4);
	if (unlikely(zephir_fast_strlen_ev(redirectUrl) < 1)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_view_exception_ce, "Missing option: redirectUrl", "yb/view/redirect.zep", 14);
		return;
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "dataQuery", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_BOOL(_3, 0);
	ZEPHIR_CALL_CE_STATIC(&_6, yb_std_ce, "valueat", &_1, 9, options, _2, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	dataQuery = zephir_get_boolval(_6);
	if (dataQuery) {
		ZEPHIR_CALL_FUNCTION(&_7$$4, "http_build_query", NULL, 142, data);
		zephir_check_call_status();
		zephir_get_strval(_8$$4, _7$$4);
		ZEPHIR_CPY_WRT(query, _8$$4);
		if (zephir_fast_strlen_ev(query) > 0) {
			ZEPHIR_SINIT_VAR(_10$$5);
			ZVAL_STRING(&_10$$5, "?", 0);
			ZEPHIR_INIT_VAR(_11$$5);
			zephir_fast_strpos(_11$$5, redirectUrl, &_10$$5, 0 );
			if (ZEPHIR_IS_FALSE_IDENTICAL(_11$$5)) {
				zephir_concat_self_str(&redirectUrl, "?", sizeof("?")-1 TSRMLS_CC);
			} else {
				zephir_concat_self_str(&redirectUrl, "&", sizeof("&")-1 TSRMLS_CC);
			}
			zephir_concat_self(&redirectUrl, query TSRMLS_CC);
		}
	}
	ZEPHIR_INIT_VAR(_12);
	ZEPHIR_CONCAT_SV(_12, "Location: ", redirectUrl);
	ZEPHIR_CALL_FUNCTION(NULL, "header", NULL, 140, _12);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}


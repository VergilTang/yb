
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
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Yb_Router_UriPatterns) {

	ZEPHIR_REGISTER_CLASS_EX(Yb\\Router, UriPatterns, yb, router_uripatterns, yb_router_uri_ce, yb_router_uripatterns_method_entry, 0);

	zend_declare_property_null(yb_router_uripatterns_ce, SL("typePatterns"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_router_uripatterns_ce, SL("replacements"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(yb_router_uripatterns_ce, SL("DEFAULT_PATTERN"), "\\w+" TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Yb_Router_UriPatterns, __construct) {

	HashTable *_2, *_12$$3;
	HashPosition _1, _11$$3;
	zephir_fcall_cache_entry *_6 = NULL, *_10 = NULL, *_18 = NULL, *_20 = NULL, *_24 = NULL, *_31 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *rules = NULL, *typePatterns = NULL;
	zval *uri_param = NULL, *rules_param = NULL, *typePatterns_param = NULL, *callback = NULL, *prefix = NULL, *aliasGroup = NULL, *from = NULL, *to = NULL, *kvs = NULL, *_0, **_3, *_4$$4 = NULL, *_5$$4 = NULL, **_13$$3, _8$$5 = zval_used_for_init, *_9$$5 = NULL, *_14$$6 = NULL, *_16$$6 = NULL, *_17$$6 = NULL, _19$$6 = zval_used_for_init, *_22$$6, *_23$$6 = NULL, *_25$$6, _26$$6 = zval_used_for_init, *_27$$7, *_28$$7 = NULL, *_29$$7 = NULL;
	zval *uri = NULL, *_7$$3 = NULL, *_15$$6 = NULL, *_21$$6 = NULL, *_30$$7 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &uri_param, &rules_param, &typePatterns_param);

	zephir_get_strval(uri, uri_param);
	if (!rules_param) {
		ZEPHIR_INIT_VAR(rules);
		array_init(rules);
	} else {
		zephir_get_arrval(rules, rules_param);
	}
	if (!typePatterns_param) {
		ZEPHIR_INIT_VAR(typePatterns);
		array_init(typePatterns);
	} else {
		zephir_get_arrval(typePatterns, typePatterns_param);
	}


	ZEPHIR_INIT_VAR(kvs);
	array_init(kvs);
	zephir_update_property_this(this_ptr, SL("typePatterns"), typePatterns TSRMLS_CC);
	ZEPHIR_INIT_VAR(callback);
	zephir_create_array(callback, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(callback, this_ptr);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "onPregReplaceCallback", 1);
	zephir_array_fast_append(callback, _0);
	zephir_is_iterable(rules, &_2, &_1, 0, 0, "yb/router/uripatterns.zep", 48);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(prefix, _2, _1);
		ZEPHIR_GET_HVALUE(aliasGroup, _3);
		if (unlikely(Z_TYPE_P(aliasGroup) != IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(_4$$4);
			object_init_ex(_4$$4, yb_router_exception_ce);
			ZEPHIR_INIT_LNVAR(_5$$4);
			ZEPHIR_CONCAT_SV(_5$$4, "Invalid alias group for prefix: ", prefix);
			ZEPHIR_CALL_METHOD(NULL, _4$$4, "__construct", &_6, 2, _5$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_4$$4, "yb/router/uripatterns.zep", 20 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_get_strval(_7$$3, prefix);
		ZEPHIR_CPY_WRT(prefix, _7$$3);
		if (zephir_fast_strlen_ev(prefix) > 0) {
			ZEPHIR_SINIT_NVAR(_8$$5);
			ZVAL_STRING(&_8$$5, "#", 0);
			ZEPHIR_CALL_FUNCTION(&_9$$5, "preg_quote", &_10, 100, prefix, &_8$$5);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(prefix, _9$$5);
		}
		zephir_is_iterable(aliasGroup, &_12$$3, &_11$$3, 0, 0, "yb/router/uripatterns.zep", 46);
		for (
		  ; zephir_hash_get_current_data_ex(_12$$3, (void**) &_13$$3, &_11$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_12$$3, &_11$$3)
		) {
			ZEPHIR_GET_HMKEY(from, _12$$3, _11$$3);
			ZEPHIR_GET_HVALUE(to, _13$$3);
			ZEPHIR_INIT_NVAR(_14$$6);
			array_init(_14$$6);
			zephir_update_property_this(this_ptr, SL("replacements"), _14$$6 TSRMLS_CC);
			zephir_get_strval(_15$$6, from);
			ZEPHIR_INIT_NVAR(_16$$6);
			ZVAL_STRING(_16$$6, "#/\\{(\\w+)(\\:\\w+)?\\}#", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_FUNCTION(&_17$$6, "preg_replace_callback", &_18, 101, _16$$6, callback, _15$$6);
			zephir_check_temp_parameter(_16$$6);
			zephir_check_call_status();
			ZEPHIR_SINIT_NVAR(_19$$6);
			ZVAL_STRING(&_19$$6, "#^%s%s($|[/\\?])#", 0);
			ZEPHIR_CALL_FUNCTION(&from, "sprintf", &_20, 1, &_19$$6, prefix, _17$$6);
			zephir_check_call_status();
			zephir_get_strval(_21$$6, to);
			_22$$6 = zephir_fetch_nproperty_this(this_ptr, SL("replacements"), PH_NOISY_CC);
			ZEPHIR_CALL_FUNCTION(&_23$$6, "strtr", &_24, 102, _21$$6, _22$$6);
			zephir_check_call_status();
			_25$$6 = zephir_fetch_nproperty_this(this_ptr, SL("replacements"), PH_NOISY_CC);
			ZEPHIR_SINIT_NVAR(_19$$6);
			ZVAL_STRING(&_19$$6, "%s%s${%d}", 0);
			ZEPHIR_SINIT_NVAR(_26$$6);
			ZVAL_LONG(&_26$$6, (zephir_fast_count_int(_25$$6 TSRMLS_CC) + 1));
			ZEPHIR_CALL_FUNCTION(&to, "sprintf", &_20, 1, &_19$$6, prefix, _23$$6, &_26$$6);
			zephir_check_call_status();
			zephir_array_update_zval(&kvs, from, &to, PH_COPY | PH_SEPARATE);
		}
	}
	if (zephir_is_true(kvs)) {
		ZEPHIR_INIT_VAR(_27$$7);
		zephir_array_keys(_27$$7, kvs TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_28$$7, "array_values", NULL, 20, kvs);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_29$$7, "preg_replace", NULL, 51, _27$$7, _28$$7, uri);
		zephir_check_call_status();
		zephir_get_strval(_30$$7, _29$$7);
		ZEPHIR_CPY_WRT(uri, _30$$7);
	}
	ZEPHIR_CALL_PARENT(NULL, yb_router_uripatterns_ce, this_ptr, "__construct", &_31, 103, uri);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Router_UriPatterns, onPregReplaceCallback) {

	zval *_8$$5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *matches_param = NULL, *name = NULL, *type = NULL, *pattern = NULL, *_0, *_1, *_4, _5, _6, *_7 = NULL, *_2$$4, *_3$$4, _9$$5 = zval_used_for_init, *_10$$5;
	zval *matches = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &matches_param);

	zephir_get_arrval(matches, matches_param);


	ZEPHIR_OBS_VAR(name);
	if (unlikely(!(zephir_array_isset_long_fetch(&name, matches, 1, 0 TSRMLS_CC)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_router_exception_ce, "Invalid matches", "yb/router/uripatterns.zep", 60);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SVS(_0, "{", name, "}");
	ZEPHIR_CPY_WRT(name, _0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("replacements"), PH_NOISY_CC);
	if (unlikely(zephir_array_isset(_1, name))) {
		ZEPHIR_INIT_VAR(_2$$4);
		object_init_ex(_2$$4, yb_router_exception_ce);
		ZEPHIR_INIT_VAR(_3$$4);
		ZEPHIR_CONCAT_SV(_3$$4, "Duplicate name: ", name);
		ZEPHIR_CALL_METHOD(NULL, _2$$4, "__construct", NULL, 2, _3$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2$$4, "yb/router/uripatterns.zep", 65 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("replacements"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_STRING(&_5, "${%d}", 0);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_LONG(&_6, (zephir_fast_count_int(_4 TSRMLS_CC) + 1));
	ZEPHIR_CALL_FUNCTION(&_7, "sprintf", NULL, 1, &_5, &_6);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("replacements"), name, _7 TSRMLS_CC);
	while (1) {
		ZEPHIR_OBS_NVAR(type);
		if (!(zephir_array_isset_long_fetch(&type, matches, 2, 0 TSRMLS_CC))) {
			break;
		}
		zephir_get_strval(_8$$5, type);
		ZEPHIR_SINIT_NVAR(_9$$5);
		ZVAL_LONG(&_9$$5, 1);
		ZEPHIR_INIT_NVAR(type);
		zephir_substr(type, _8$$5, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		_10$$5 = zephir_fetch_nproperty_this(this_ptr, SL("typePatterns"), PH_NOISY_CC);
		if (!(zephir_array_isset_fetch(&pattern, _10$$5, type, 1 TSRMLS_CC))) {
			break;
		}
		ZEPHIR_CONCAT_SVS(return_value, "/(", pattern, ")");
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SSS(return_value, "/(", "\\w+", ")");
	RETURN_MM();

}


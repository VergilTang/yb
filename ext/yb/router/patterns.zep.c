
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/hash.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Yb_Router_Patterns) {

	ZEPHIR_REGISTER_CLASS(Yb\\Router, Patterns, yb, router_patterns, yb_router_patterns_method_entry, 0);

	zend_declare_property_null(yb_router_patterns_ce, SL("types"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_router_patterns_ce, SL("matches"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_router_patterns_ce, SL("patterns"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(yb_router_patterns_ce, SL("DEFAULT_TYPE"), "\\w+" TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Yb_Router_Patterns, __construct) {

	zval *types_param = NULL;
	zval *types = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &types_param);

	zephir_get_arrval(types, types_param);


	zephir_update_property_this(this_ptr, SL("types"), types TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Router_Patterns, getPatterns) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("patterns"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_ARRAY) {
		RETURN_MM_MEMBER(this_ptr, "patterns");
	}
	array_init(return_value);
	RETURN_MM();

}

PHP_METHOD(Yb_Router_Patterns, aliases) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *prefix = NULL;
	zval *aliases_param = NULL, *prefix_param = NULL, *from = NULL, *to = NULL, **_2;
	zval *aliases = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &aliases_param, &prefix_param);

	zephir_get_arrval(aliases, aliases_param);
	if (!prefix_param) {
		ZEPHIR_INIT_VAR(prefix);
		ZVAL_STRING(prefix, "", 1);
	} else {
		zephir_get_strval(prefix, prefix_param);
	}


	zephir_is_iterable(aliases, &_1, &_0, 0, 0, "yb/router/patterns.zep", 32);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(from, _1, _0);
		ZEPHIR_GET_HVALUE(to, _2);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "alias", &_3, 0, from, to, prefix);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Router_Patterns, alias) {

	zval *_1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *from_param = NULL, *to_param = NULL, *prefix_param = NULL, *_0, *_2 = NULL, *_3 = NULL, *_5 = NULL, *_10, *_11 = NULL, *_12, _13, _14, *_15 = NULL, *_16, _6$$3, *_7$$3 = NULL;
	zval *from = NULL, *to = NULL, *prefix = NULL, *_4 = NULL, *_9, *_8$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &from_param, &to_param, &prefix_param);

	zephir_get_strval(from, from_param);
	zephir_get_strval(to, to_param);
	if (!prefix_param) {
		ZEPHIR_INIT_VAR(prefix);
		ZVAL_STRING(prefix, "", 1);
	} else {
		zephir_get_strval(prefix, prefix_param);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("matches"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_1, this_ptr);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "replaceMatches", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "#/\\{(\\w+)(\\:\\w+)?\\}#", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_3, "preg_replace_callback", NULL, 104, _2, _1, from);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_get_strval(_4, _3);
	ZEPHIR_CPY_WRT(from, _4);
	if (zephir_fast_strlen_ev(prefix) > 0) {
		ZEPHIR_SINIT_VAR(_6$$3);
		ZVAL_STRING(&_6$$3, "#", 0);
		ZEPHIR_CALL_FUNCTION(&_7$$3, "preg_quote", NULL, 105, prefix, &_6$$3);
		zephir_check_call_status();
		zephir_get_strval(_8$$3, _7$$3);
		ZEPHIR_CPY_WRT(prefix, _8$$3);
	}
	ZEPHIR_INIT_VAR(_9);
	ZEPHIR_CONCAT_SVVS(_9, "#^", prefix, from, "($|[/\\?])#");
	ZEPHIR_CPY_WRT(from, _9);
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("matches"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_11, "strtr", NULL, 106, to, _10);
	zephir_check_call_status();
	_12 = zephir_fetch_nproperty_this(this_ptr, SL("matches"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_13);
	ZVAL_STRING(&_13, "${%d}", 0);
	ZEPHIR_SINIT_VAR(_14);
	ZVAL_LONG(&_14, (zephir_fast_count_int(_12 TSRMLS_CC) + 1));
	ZEPHIR_CALL_FUNCTION(&_15, "sprintf", NULL, 1, &_13, &_14);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_16);
	ZEPHIR_CONCAT_VVV(_16, prefix, _11, _15);
	zephir_get_strval(to, _16);
	zephir_update_property_array(this_ptr, SL("patterns"), from, to TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Router_Patterns, replaceMatches) {

	zval *t = NULL, *_8$$5 = NULL, *_11$$6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *m_param = NULL, *n = NULL, *k = NULL, *v = NULL, *_0, *_1, *_4, _5, _6, *_7 = NULL, *_2$$4, *_3$$4, _9$$5, *_10$$5;
	zval *m = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &m_param);

	zephir_get_arrval(m, m_param);


	ZEPHIR_OBS_VAR(n);
	if (unlikely(!(zephir_array_isset_long_fetch(&n, m, 1, 0 TSRMLS_CC)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_router_exception_ce, "Invalid matches", "yb/router/patterns.zep", 56);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SVS(_0, "{", n, "}");
	ZEPHIR_CPY_WRT(n, _0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("matches"), PH_NOISY_CC);
	if (unlikely(zephir_array_isset(_1, n))) {
		ZEPHIR_INIT_VAR(_2$$4);
		object_init_ex(_2$$4, yb_router_exception_ce);
		ZEPHIR_INIT_VAR(_3$$4);
		ZEPHIR_CONCAT_SV(_3$$4, "Duplicate match: ", n);
		ZEPHIR_CALL_METHOD(NULL, _2$$4, "__construct", NULL, 2, _3$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2$$4, "yb/router/patterns.zep", 61 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("matches"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_STRING(&_5, "${%d}", 0);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_LONG(&_6, (zephir_fast_count_int(_4 TSRMLS_CC) + 1));
	ZEPHIR_CALL_FUNCTION(&_7, "sprintf", NULL, 1, &_5, &_6);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("matches"), n, _7 TSRMLS_CC);
	ZEPHIR_INIT_VAR(t);
	ZVAL_STRING(t, "\w+", 1);
	ZEPHIR_OBS_VAR(k);
	if (zephir_array_isset_long_fetch(&k, m, 2, 0 TSRMLS_CC)) {
		zephir_get_strval(_8$$5, k);
		ZEPHIR_SINIT_VAR(_9$$5);
		ZVAL_LONG(&_9$$5, 1);
		ZEPHIR_INIT_NVAR(k);
		zephir_substr(k, _8$$5, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		_10$$5 = zephir_fetch_nproperty_this(this_ptr, SL("types"), PH_NOISY_CC);
		if (zephir_array_isset_fetch(&v, _10$$5, k, 1 TSRMLS_CC)) {
			zephir_get_strval(_11$$6, v);
			ZEPHIR_CPY_WRT(t, _11$$6);
		}
	}
	ZEPHIR_CONCAT_SVS(return_value, "/(", t, ")");
	RETURN_MM();

}



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
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/math.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/file.h"
#include "kernel/require.h"


ZEPHIR_INIT_CLASS(Yb_Std) {

	ZEPHIR_REGISTER_CLASS(Yb, Std, yb, std, yb_std_method_entry, 0);

	zend_declare_class_constant_string(yb_std_ce, SL("CHARSET"), "UTF-8" TSRMLS_CC);

	zend_declare_class_constant_string(yb_std_ce, SL("CHAR_LIST"), "0123456789abcdefghijklmnopqrstuvwxyz" TSRMLS_CC);

	zend_declare_class_constant_string(yb_std_ce, SL("IGNORE_ERROR"), "Yb\\Std::ignoreError" TSRMLS_CC);

	zend_declare_class_constant_string(yb_std_ce, SL("THROW_ERROR"), "Yb\\Std::throwError" TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Yb_Std, sizeToByte) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *size_param = NULL, *match = NULL, *_0, *_1 = NULL, *_2, _3, *_4$$3, *_5$$4, *_6$$5, *_7$$6, *_8$$7;
	zval *size = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &size_param);

	zephir_get_strval(size, size_param);


	ZEPHIR_INIT_VAR(match);
	ZVAL_NULL(match);
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_2);
	zephir_fast_strtoupper(_2, size);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "/^([\\d\\.]+)([KMGT])B?$/", 0);
	zephir_preg_match(_0, &_3, _2, match, 0, 0 , 0  TSRMLS_CC);
	if (zephir_is_true(_0)) {
		zephir_array_fetch_long(&_4$$3, match, 2, PH_NOISY | PH_READONLY, "yb/std.zep", 16 TSRMLS_CC);
		do {
			if (ZEPHIR_IS_STRING(_4$$3, "T")) {
				ZEPHIR_OBS_VAR(_5$$4);
				zephir_array_fetch_long(&_5$$4, match, 1, PH_NOISY, "yb/std.zep", 18 TSRMLS_CC);
				RETURN_MM_DOUBLE((1099511627776.0 * zephir_get_doubleval(_5$$4)));
			}
			if (ZEPHIR_IS_STRING(_4$$3, "G")) {
				ZEPHIR_OBS_VAR(_6$$5);
				zephir_array_fetch_long(&_6$$5, match, 1, PH_NOISY, "yb/std.zep", 20 TSRMLS_CC);
				RETURN_MM_DOUBLE((1073741824.0 * zephir_get_doubleval(_6$$5)));
			}
			if (ZEPHIR_IS_STRING(_4$$3, "M")) {
				ZEPHIR_OBS_VAR(_7$$6);
				zephir_array_fetch_long(&_7$$6, match, 1, PH_NOISY, "yb/std.zep", 22 TSRMLS_CC);
				RETURN_MM_DOUBLE((1048576.0 * zephir_get_doubleval(_7$$6)));
			}
			if (ZEPHIR_IS_STRING(_4$$3, "K")) {
				ZEPHIR_OBS_VAR(_8$$7);
				zephir_array_fetch_long(&_8$$7, match, 1, PH_NOISY, "yb/std.zep", 24 TSRMLS_CC);
				RETURN_MM_DOUBLE((1024.0 * zephir_get_doubleval(_8$$7)));
			}
		} while(0);

	}
	ZEPHIR_RETURN_CALL_FUNCTION("floatval", NULL, 46, size);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Std, pascalCase) {

	long _0;
	zend_bool upper, _1$$3, _2$$3, _3$$3;
	char c = 0;
	zval *from_param = NULL;
	zval *from = NULL, *to;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &from_param);

	zephir_get_strval(from, from_param);


	ZEPHIR_INIT_VAR(to);
	ZVAL_EMPTY_STRING(to);
	upper = 1;
	for (_0 = 0; _0 < Z_STRLEN_P(from); _0++) {
		c = ZEPHIR_STRING_OFFSET(from, _0);
		_1$$3 = c >= '0';
		if (_1$$3) {
			_1$$3 = c <= '9';
		}
		if (_1$$3) {
			zephir_concat_self_char(&to, c TSRMLS_CC);
			continue;
		}
		_2$$3 = c >= 'a';
		if (_2$$3) {
			_2$$3 = c <= 'z';
		}
		if (_2$$3) {
			if (upper) {
				upper = 0;
				c -= 32;
			}
			zephir_concat_self_char(&to, c TSRMLS_CC);
			continue;
		}
		_3$$3 = c >= 'A';
		if (_3$$3) {
			_3$$3 = c <= 'Z';
		}
		if (_3$$3) {
			if (upper) {
				upper = 0;
			} else {
				c += 32;
			}
			zephir_concat_self_char(&to, c TSRMLS_CC);
			continue;
		}
		upper = 1;
	}
	RETURN_CTOR(to);

}

PHP_METHOD(Yb_Std, camelCase) {

	long _0;
	zend_bool upper, _1$$3, _2$$3, _3$$3;
	char c = 0;
	zval *from_param = NULL;
	zval *from = NULL, *to;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &from_param);

	zephir_get_strval(from, from_param);


	ZEPHIR_INIT_VAR(to);
	ZVAL_EMPTY_STRING(to);
	upper = 0;
	for (_0 = 0; _0 < Z_STRLEN_P(from); _0++) {
		c = ZEPHIR_STRING_OFFSET(from, _0);
		_1$$3 = c >= '0';
		if (_1$$3) {
			_1$$3 = c <= '9';
		}
		if (_1$$3) {
			zephir_concat_self_char(&to, c TSRMLS_CC);
			continue;
		}
		_2$$3 = c >= 'a';
		if (_2$$3) {
			_2$$3 = c <= 'z';
		}
		if (_2$$3) {
			if (upper) {
				upper = 0;
				c -= 32;
			}
			zephir_concat_self_char(&to, c TSRMLS_CC);
			continue;
		}
		_3$$3 = c >= 'A';
		if (_3$$3) {
			_3$$3 = c <= 'Z';
		}
		if (_3$$3) {
			if (upper) {
				upper = 0;
			} else {
				c += 32;
			}
			zephir_concat_self_char(&to, c TSRMLS_CC);
			continue;
		}
		upper = 1;
	}
	RETURN_CTOR(to);

}

PHP_METHOD(Yb_Std, normalCase) {

	long _0;
	zend_bool notFirst, _1$$3, _2$$3, _3$$3, _4$$3;
	char c = 0;
	zval *from_param = NULL, *sep_param = NULL;
	zval *from = NULL, *sep = NULL, *to;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &from_param, &sep_param);

	zephir_get_strval(from, from_param);
	if (!sep_param) {
		ZEPHIR_INIT_VAR(sep);
		ZVAL_STRING(sep, "-", 1);
	} else {
		zephir_get_strval(sep, sep_param);
	}


	ZEPHIR_INIT_VAR(to);
	ZVAL_EMPTY_STRING(to);
	notFirst = 0;
	for (_0 = 0; _0 < Z_STRLEN_P(from); _0++) {
		c = ZEPHIR_STRING_OFFSET(from, _0);
		_1$$3 = c >= '0';
		if (_1$$3) {
			_1$$3 = c <= '9';
		}
		_2$$3 = _1$$3;
		if (!(_2$$3)) {
			_3$$3 = c >= 'a';
			if (_3$$3) {
				_3$$3 = c <= 'z';
			}
			_2$$3 = _3$$3;
		}
		if (_2$$3) {
			zephir_concat_self_char(&to, c TSRMLS_CC);
			notFirst = 1;
			continue;
		}
		_4$$3 = c >= 'A';
		if (_4$$3) {
			_4$$3 = c <= 'Z';
		}
		if (_4$$3) {
			if (notFirst) {
				zephir_concat_self(&to, sep TSRMLS_CC);
			}
			c += 32;
			zephir_concat_self_char(&to, c TSRMLS_CC);
			notFirst = 1;
			continue;
		}
	}
	RETURN_CTOR(to);

}

PHP_METHOD(Yb_Std, uuid) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *salt_param = NULL, *_0 = NULL, *_1 = NULL, *_2;
	zval *salt = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &salt_param);

	if (!salt_param) {
		ZEPHIR_INIT_VAR(salt);
		ZVAL_STRING(salt, "", 1);
	} else {
		zephir_get_strval(salt, salt_param);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "mt_rand", NULL, 47);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "uniqid", NULL, 48, _0, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VV(_2, _1, salt);
	zephir_md5(return_value, _2);
	RETURN_MM();

}

PHP_METHOD(Yb_Std, randString) {

	zephir_fcall_cache_entry *_9 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *charList = NULL, *result;
	zval *len_param = NULL, *charList_param = NULL, *_0 = NULL, _1, *_2 = NULL, _3$$5 = zval_used_for_init, _4$$5 = zval_used_for_init, _5$$5 = zval_used_for_init, _6$$5 = zval_used_for_init, _7$$5 = zval_used_for_init, *_8$$5 = NULL;
	long len, maxIndex = 0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &len_param, &charList_param);

	len = zephir_get_intval(len_param);
	if (!charList_param) {
		ZEPHIR_INIT_VAR(charList);
		ZVAL_STRING(charList, "", 1);
	} else {
		zephir_get_strval(charList, charList_param);
	}


	ZEPHIR_INIT_VAR(result);
	ZVAL_EMPTY_STRING(result);
	if (unlikely(len < 1)) {
		RETURN_MM_STRING("", 1);
	}
	if (zephir_fast_strlen_ev(charList) < 1) {
		ZEPHIR_INIT_NVAR(charList);
		ZVAL_STRING(charList, "0123456789abcdefghijklmnopqrstuvwxyz", 1);
	}
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "UTF-8", 0);
	ZEPHIR_CALL_FUNCTION(&_2, "mb_strlen", NULL, 24, charList, &_1);
	zephir_check_call_status();
	maxIndex = (zephir_get_intval(_2) - 1);
	while (1) {
		if (!(len)) {
			break;
		}
		len--;
		ZEPHIR_SINIT_NVAR(_3$$5);
		ZVAL_LONG(&_3$$5, 0);
		ZEPHIR_SINIT_NVAR(_4$$5);
		ZVAL_LONG(&_4$$5, maxIndex);
		ZEPHIR_SINIT_NVAR(_5$$5);
		ZVAL_LONG(&_5$$5, zephir_mt_rand(zephir_get_intval(&_3$$5), zephir_get_intval(&_4$$5) TSRMLS_CC));
		ZEPHIR_SINIT_NVAR(_6$$5);
		ZVAL_LONG(&_6$$5, 1);
		ZEPHIR_SINIT_NVAR(_7$$5);
		ZVAL_STRING(&_7$$5, "UTF-8", 0);
		ZEPHIR_CALL_FUNCTION(&_8$$5, "mb_substr", &_9, 27, charList, &_5$$5, &_6$$5, &_7$$5);
		zephir_check_call_status();
		zephir_concat_self(&result, _8$$5 TSRMLS_CC);
	}
	RETURN_CTOR(result);

}

PHP_METHOD(Yb_Std, newInstanceOf) {

	zend_class_entry *_1$$3, *_4$$5, *_7$$6, *_11$$7, *_16$$8, *_22$$9;
	long c = 0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *args = NULL;
	zval *className_param = NULL, *args_param = NULL, *a = NULL, *_28, *_0$$3 = NULL, *_2$$4, *_3$$5 = NULL, *_5$$5, *_6$$6 = NULL, *_8$$6, *_9$$6, *_10$$7 = NULL, *_12$$7, *_13$$7, *_14$$7, *_15$$8 = NULL, *_17$$8, *_18$$8, *_19$$8, *_20$$8, *_21$$9 = NULL, *_23$$9, *_24$$9, *_25$$9, *_26$$9, *_27$$9;
	zval *className = NULL, *_29;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &className_param, &args_param);

	zephir_get_strval(className, className_param);
	if (!args_param) {
		ZEPHIR_INIT_VAR(args);
		array_init(args);
	} else {
		zephir_get_arrval(args, args_param);
	}


	c = zephir_fast_count_int(args TSRMLS_CC);
	if (c < 1) {
		zephir_fetch_safe_class(_0$$3, className);
			_1$$3 = zend_fetch_class(Z_STRVAL_P(_0$$3), Z_STRLEN_P(_0$$3), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(return_value, _1$$3);
		if (zephir_has_constructor(return_value TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		RETURN_MM();
	}
	if (c > 5) {
		ZEPHIR_INIT_VAR(_2$$4);
		object_init_ex(_2$$4, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
		ZEPHIR_CALL_METHOD(NULL, _2$$4, "__construct", NULL, 49, className);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(_2$$4, "newinstanceargs", NULL, 50, args);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&a, "array_values", NULL, 51, args);
	zephir_check_call_status();
	do {
		if (c == 1) {
			zephir_fetch_safe_class(_3$$5, className);
				_4$$5 = zend_fetch_class(Z_STRVAL_P(_3$$5), Z_STRLEN_P(_3$$5), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(return_value, _4$$5);
			if (zephir_has_constructor(return_value TSRMLS_CC)) {
				zephir_array_fetch_long(&_5$$5, a, 0, PH_NOISY | PH_READONLY, "yb/std.zep", 169 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, _5$$5);
				zephir_check_call_status();
			}
			RETURN_MM();
		}
		if (c == 2) {
			zephir_fetch_safe_class(_6$$6, className);
				_7$$6 = zend_fetch_class(Z_STRVAL_P(_6$$6), Z_STRLEN_P(_6$$6), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(return_value, _7$$6);
			if (zephir_has_constructor(return_value TSRMLS_CC)) {
				zephir_array_fetch_long(&_8$$6, a, 0, PH_NOISY | PH_READONLY, "yb/std.zep", 171 TSRMLS_CC);
				zephir_array_fetch_long(&_9$$6, a, 1, PH_NOISY | PH_READONLY, "yb/std.zep", 171 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, _8$$6, _9$$6);
				zephir_check_call_status();
			}
			RETURN_MM();
		}
		if (c == 3) {
			zephir_fetch_safe_class(_10$$7, className);
				_11$$7 = zend_fetch_class(Z_STRVAL_P(_10$$7), Z_STRLEN_P(_10$$7), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(return_value, _11$$7);
			if (zephir_has_constructor(return_value TSRMLS_CC)) {
				zephir_array_fetch_long(&_12$$7, a, 0, PH_NOISY | PH_READONLY, "yb/std.zep", 173 TSRMLS_CC);
				zephir_array_fetch_long(&_13$$7, a, 1, PH_NOISY | PH_READONLY, "yb/std.zep", 173 TSRMLS_CC);
				zephir_array_fetch_long(&_14$$7, a, 2, PH_NOISY | PH_READONLY, "yb/std.zep", 173 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, _12$$7, _13$$7, _14$$7);
				zephir_check_call_status();
			}
			RETURN_MM();
		}
		if (c == 4) {
			zephir_fetch_safe_class(_15$$8, className);
				_16$$8 = zend_fetch_class(Z_STRVAL_P(_15$$8), Z_STRLEN_P(_15$$8), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(return_value, _16$$8);
			if (zephir_has_constructor(return_value TSRMLS_CC)) {
				zephir_array_fetch_long(&_17$$8, a, 0, PH_NOISY | PH_READONLY, "yb/std.zep", 175 TSRMLS_CC);
				zephir_array_fetch_long(&_18$$8, a, 1, PH_NOISY | PH_READONLY, "yb/std.zep", 175 TSRMLS_CC);
				zephir_array_fetch_long(&_19$$8, a, 2, PH_NOISY | PH_READONLY, "yb/std.zep", 175 TSRMLS_CC);
				zephir_array_fetch_long(&_20$$8, a, 3, PH_NOISY | PH_READONLY, "yb/std.zep", 175 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, _17$$8, _18$$8, _19$$8, _20$$8);
				zephir_check_call_status();
			}
			RETURN_MM();
		}
		if (c == 5) {
			zephir_fetch_safe_class(_21$$9, className);
				_22$$9 = zend_fetch_class(Z_STRVAL_P(_21$$9), Z_STRLEN_P(_21$$9), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(return_value, _22$$9);
			if (zephir_has_constructor(return_value TSRMLS_CC)) {
				zephir_array_fetch_long(&_23$$9, a, 0, PH_NOISY | PH_READONLY, "yb/std.zep", 177 TSRMLS_CC);
				zephir_array_fetch_long(&_24$$9, a, 1, PH_NOISY | PH_READONLY, "yb/std.zep", 177 TSRMLS_CC);
				zephir_array_fetch_long(&_25$$9, a, 2, PH_NOISY | PH_READONLY, "yb/std.zep", 177 TSRMLS_CC);
				zephir_array_fetch_long(&_26$$9, a, 3, PH_NOISY | PH_READONLY, "yb/std.zep", 177 TSRMLS_CC);
				zephir_array_fetch_long(&_27$$9, a, 4, PH_NOISY | PH_READONLY, "yb/std.zep", 177 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, _23$$9, _24$$9, _25$$9, _26$$9, _27$$9);
				zephir_check_call_status();
			}
			RETURN_MM();
		}
	} while(0);

	ZEPHIR_INIT_VAR(_28);
	object_init_ex(_28, yb_exception_ce);
	ZEPHIR_INIT_VAR(_29);
	ZEPHIR_CONCAT_SV(_29, "Fail to fetch a new instance of class: ", className);
	ZEPHIR_CALL_METHOD(NULL, _28, "__construct", NULL, 3, _29);
	zephir_check_call_status();
	zephir_throw_exception_debug(_28, "yb/std.zep", 180 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Yb_Std, ignoreError) {

	zval *context = NULL;
	zval *s = NULL, *f = NULL, *l = NULL;
	zval *n_param = NULL, *s_param = NULL, *f_param = NULL, *l_param = NULL, *context_param = NULL;
	long n;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &n_param, &s_param, &f_param, &l_param, &context_param);

	n = zephir_get_intval(n_param);
	zephir_get_strval(s, s_param);
	zephir_get_strval(f, f_param);
	zephir_get_strval(l, l_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	RETURN_MM_NULL();

}

PHP_METHOD(Yb_Std, throwError) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *s = NULL, *f = NULL, *l = NULL, *_1;
	zval *n_param = NULL, *s_param = NULL, *f_param = NULL, *l_param = NULL, *context_param = NULL, *_0, *_2;
	long n;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &n_param, &s_param, &f_param, &l_param, &context_param);

	n = zephir_get_intval(n_param);
	zephir_get_strval(s, s_param);
	zephir_get_strval(f, f_param);
	zephir_get_strval(l, l_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, zephir_get_internal_ce(SS("errorexception") TSRMLS_CC));
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VSVSVS(_1, s, " (", f, ":", l, ")");
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, n);
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 52, _1, _2);
	zephir_check_call_status();
	zephir_throw_exception_debug(_0, "yb/std.zep", 190 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Yb_Std, outputScript) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL;
	zval *path_param = NULL, *data_param = NULL, *_0$$3, *_2, *_3;
	zval *path = NULL, *_1$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &path_param, &data_param);

	zephir_get_strval(path, path_param);
	zephir_get_arrval(data, data_param);


	if (unlikely(!((zephir_file_exists(path TSRMLS_CC) == SUCCESS)))) {
		ZEPHIR_INIT_VAR(_0$$3);
		object_init_ex(_0$$3, yb_exception_ce);
		ZEPHIR_INIT_VAR(_1$$3);
		ZEPHIR_CONCAT_SV(_1$$3, "Cannot find script path: ", path);
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "__construct", NULL, 3, _1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0$$3, "yb/std.zep", 196 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, 4);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_MAKE_REF(data);
	ZEPHIR_CALL_FUNCTION(NULL, "extract", NULL, 53, data, _2, _3);
	zephir_check_temp_parameter(_3);
	ZEPHIR_UNREF(data);
	zephir_check_call_status();
	if (zephir_require_zval(path TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Std, renderScript) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL;
	zval *path_param = NULL, *data_param = NULL, *ex = NULL;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &path_param, &data_param);

	zephir_get_strval(path, path_param);
	zephir_get_arrval(data, data_param);


	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 4);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "ob_implicit_flush", NULL, 5, ZEPHIR_GLOBAL(global_false));
	zephir_check_call_status();

	/* try_start_1: */

		ZEPHIR_CALL_SELF(NULL, "outputscript", NULL, 0, path, data);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", NULL, 6);
		zephir_check_call_status_or_jump(try_end_1);
		RETURN_MM();

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_CPY_WRT(ex, EG(exception));
		if (zephir_instance_of_ev(ex, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 7);
			zephir_check_call_status();
			zephir_throw_exception_debug(ex, "yb/std.zep", 215 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_MM_STRING("", 1);

}


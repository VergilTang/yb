
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
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/time.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Yb_Db_PdoAbstract) {

	ZEPHIR_REGISTER_CLASS_EX(Yb\\Db, PdoAbstract, yb, db_pdoabstract, yb_db_dbabstract_ce, yb_db_pdoabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(yb_db_pdoabstract_ce, SL("pdo"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_db_pdoabstract_ce, SL("lastStatement"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Yb_Db_PdoAbstract, __construct) {

	zval _0, *_1 = NULL, *_2, *_3, *_4 = NULL, *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "pdo", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 12, &_0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_db_exception_ce, "Missing extension: pdo", "yb/db/pdoabstract.zep", 11);
		return;
	}
	ZEPHIR_INIT_VAR(_2);
	object_init_ex(_2, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "PDO", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 13, _3);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_5, "func_get_args", NULL, 14);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, _2, "newinstanceargs", NULL, 15, _5);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("pdo"), _4 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Db_PdoAbstract, getInternalHandler) {

	

	RETURN_MEMBER(this_ptr, "pdo");

}

PHP_METHOD(Yb_Db_PdoAbstract, quote) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL, *_0;
	zval *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	zephir_get_strval(value, value_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("pdo"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "quote", NULL, 0, value);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Db_PdoAbstract, query) {

	HashTable *_3$$3;
	HashPosition _2$$3;
	zend_bool r = 0;
	double t = 0;
	zephir_fcall_cache_entry *_9 = NULL, *_11 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *params = NULL;
	zval *sql_param = NULL, *params_param = NULL, *s = NULL, *k = NULL, *v = NULL, *e = NULL, *_0, *_1, *_12 = NULL, *_13, *_14, **_4$$3, *_5$$5 = NULL, *_6$$5 = NULL, *_7$$5 = NULL, *_8$$5 = NULL, *_10$$6 = NULL, *_15$$7, *_16$$7, *_17$$7;
	zval *sql = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &sql_param, &params_param);

	zephir_get_strval(sql, sql_param);
	if (!params_param) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
	} else {
		zephir_get_arrval(params, params_param);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_microtime(_0, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	t = zephir_get_doubleval(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("pdo"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&s, _1, "prepare", NULL, 0, sql);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("lastStatement"), s TSRMLS_CC);
	if (zephir_fast_count_int(params TSRMLS_CC) > 0) {
		zephir_is_iterable(params, &_3$$3, &_2$$3, 0, 0, "yb/db/pdoabstract.zep", 46);
		for (
		  ; zephir_hash_get_current_data_ex(_3$$3, (void**) &_4$$3, &_2$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3$$3, &_2$$3)
		) {
			ZEPHIR_GET_HMKEY(k, _3$$3, _2$$3);
			ZEPHIR_GET_HVALUE(v, _4$$3);
			if (Z_TYPE_P(v) == IS_STRING) {
				ZEPHIR_INIT_LNVAR(_5$$5);
				ZEPHIR_CONCAT_SV(_5$$5, ":", k);
				ZEPHIR_INIT_LNVAR(_6$$5);
				ZEPHIR_CONCAT_SV(_6$$5, "", v);
				ZEPHIR_INIT_NVAR(_7$$5);
				ZVAL_LONG(_7$$5, 2);
				ZEPHIR_INIT_NVAR(_8$$5);
				ZVAL_LONG(_8$$5, zephir_fast_strlen_ev(v));
				ZEPHIR_CALL_METHOD(NULL, s, "bindparam", &_9, 0, _5$$5, _6$$5, _7$$5, _8$$5);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_LNVAR(_10$$6);
				ZEPHIR_CONCAT_SV(_10$$6, ":", k);
				ZEPHIR_CALL_METHOD(NULL, s, "bindvalue", &_11, 0, _10$$6, v);
				zephir_check_call_status();
			}
		}
	}
	ZEPHIR_CALL_METHOD(&_12, s, "execute", NULL, 0);
	zephir_check_call_status();
	r = zephir_get_boolval(_12);
	ZEPHIR_INIT_VAR(_13);
	zephir_microtime(_13, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	ZEPHIR_INIT_VAR(_14);
	ZVAL_DOUBLE(_14, (double) (zephir_get_doubleval(_13) - t));
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addquery", NULL, 0, sql, params, _14);
	zephir_check_call_status();
	if (unlikely(!r)) {
		ZEPHIR_CALL_METHOD(&e, s, "errorinfo", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_15$$7);
		object_init_ex(_15$$7, yb_db_queryexception_ce);
		zephir_array_fetch_long(&_16$$7, e, 2, PH_NOISY | PH_READONLY, "yb/db/pdoabstract.zep", 53 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_17$$7);
		ZEPHIR_CONCAT_VSV(_17$$7, _16$$7, " [SQL] ", sql);
		ZEPHIR_CALL_METHOD(NULL, _15$$7, "__construct", NULL, 2, _17$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(_15$$7, "yb/db/pdoabstract.zep", 53 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Db_PdoAbstract, queryAll) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *params = NULL;
	zval *sql_param = NULL, *params_param = NULL, *_0, *_1;
	zval *sql = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &sql_param, &params_param);

	zephir_get_strval(sql, sql_param);
	if (!params_param) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
	} else {
		zephir_get_arrval(params, params_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "query", NULL, 0, sql, params);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("lastStatement"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 2);
	ZEPHIR_RETURN_CALL_METHOD(_0, "fetchall", NULL, 0, _1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Db_PdoAbstract, queryRow) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *params = NULL;
	zval *sql_param = NULL, *params_param = NULL, *r = NULL, *_0, *_1;
	zval *sql = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &sql_param, &params_param);

	zephir_get_strval(sql, sql_param);
	if (!params_param) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
	} else {
		zephir_get_arrval(params, params_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "query", NULL, 0, sql, params);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("lastStatement"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 2);
	ZEPHIR_CALL_METHOD(&r, _0, "fetch", NULL, 0, _1);
	zephir_check_call_status();
	if (zephir_is_true(r)) {
		RETURN_CCTOR(r);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Db_PdoAbstract, queryCell) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *params = NULL;
	zval *sql_param = NULL, *params_param = NULL, *_0;
	zval *sql = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &sql_param, &params_param);

	zephir_get_strval(sql, sql_param);
	if (!params_param) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
	} else {
		zephir_get_arrval(params, params_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "query", NULL, 0, sql, params);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("lastStatement"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "fetchcolumn", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Db_PdoAbstract, queryColumns) {

	zend_bool _1$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *params = NULL;
	zval *sql_param = NULL, *params_param = NULL, *d = NULL, *i = NULL, *_0$$3;
	zval *sql = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &sql_param, &params_param);

	zephir_get_strval(sql, sql_param);
	if (!params_param) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
	} else {
		zephir_get_arrval(params, params_param);
	}


	ZEPHIR_INIT_VAR(d);
	array_init(d);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "query", NULL, 0, sql, params);
	zephir_check_call_status();
	while (1) {
		_0$$3 = zephir_fetch_nproperty_this(this_ptr, SL("lastStatement"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&i, _0$$3, "fetchcolumn", NULL, 0);
		zephir_check_call_status();
		_1$$3 = ZEPHIR_IS_FALSE_IDENTICAL(i);
		if (!(_1$$3)) {
			_1$$3 = Z_TYPE_P(i) != IS_STRING;
		}
		if (_1$$3) {
			break;
		}
		zephir_array_append(&d, i, PH_SEPARATE, "yb/db/pdoabstract.zep", 92);
	}
	RETURN_CCTOR(d);

}

PHP_METHOD(Yb_Db_PdoAbstract, tryToBegin) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("pdo"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "begintransaction", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Db_PdoAbstract, tryToCommit) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("pdo"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "commit", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Db_PdoAbstract, tryToRollback) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("pdo"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "rollback", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}


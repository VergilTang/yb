
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
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/time.h"
#include "kernel/hash.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Yb_Db_Oci8) {

	ZEPHIR_REGISTER_CLASS_EX(Yb\\Db, Oci8, yb, db_oci8, yb_db_dbabstract_ce, yb_db_oci8_method_entry, 0);

	zend_declare_property_null(yb_db_oci8_ce, SL("oci"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_db_oci8_ce, SL("lastStatement"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Yb_Db_Oci8, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *dsn_param = NULL, *user_param = NULL, *passwd_param = NULL, *oci = NULL, _0 = zval_used_for_init, *_1 = NULL, *_2$$4;
	zval *dsn = NULL, *user = NULL, *passwd = NULL, *_3$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &dsn_param, &user_param, &passwd_param);

	zephir_get_strval(dsn, dsn_param);
	zephir_get_strval(user, user_param);
	zephir_get_strval(passwd, passwd_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "oci8", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 10, &_0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_db_exception_ce, "Missing extension: oci8", "yb/db/oci8.zep", 13);
		return;
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "utf8", 0);
	ZEPHIR_CALL_FUNCTION(&oci, "oci_connect", NULL, 34, user, passwd, dsn, &_0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(oci))) {
		ZEPHIR_INIT_VAR(_2$$4);
		object_init_ex(_2$$4, yb_db_exception_ce);
		ZEPHIR_INIT_VAR(_3$$4);
		ZEPHIR_CONCAT_SV(_3$$4, "Cannot connect: ", dsn);
		ZEPHIR_CALL_METHOD(NULL, _2$$4, "__construct", NULL, 2, _3$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2$$4, "yb/db/oci8.zep", 18 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_this(this_ptr, SL("oci"), oci TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Db_Oci8, getInternalHandler) {

	

	RETURN_MEMBER(this_ptr, "oci");

}

PHP_METHOD(Yb_Db_Oci8, quote) {

	zval *value_param = NULL, *_0, _1, _2;
	zval *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	zephir_get_strval(value, value_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "'", 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "''", 0);
	zephir_fast_str_replace(&_0, &_1, &_2, value TSRMLS_CC);
	ZEPHIR_CONCAT_SVS(return_value, "'", _0, "'");
	RETURN_MM();

}

PHP_METHOD(Yb_Db_Oci8, query) {

	HashTable *_3$$3;
	HashPosition _2$$3;
	zend_bool r = 0, _12$$7;
	double t = 0;
	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *params = NULL;
	zval *sql_param = NULL, *params_param = NULL, *s = NULL, *k = NULL, *v = NULL, *m = NULL, *e = NULL, *eMessage = NULL, *_0, *_1, *_7, *_8 = NULL, *_9, *_10, **_4$$3, *_5$$4 = NULL, *_11$$7, *_13$$7, *_14$$7;
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
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("oci"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&s, "oci_parse", NULL, 35, _1, sql);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("lastStatement"), s TSRMLS_CC);
	if (zephir_fast_count_int(params TSRMLS_CC) > 0) {
		zephir_is_iterable(params, &_3$$3, &_2$$3, 0, 0, "yb/db/oci8.zep", 49);
		for (
		  ; zephir_hash_get_current_data_ex(_3$$3, (void**) &_4$$3, &_2$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3$$3, &_2$$3)
		) {
			ZEPHIR_GET_HMKEY(k, _3$$3, _2$$3);
			ZEPHIR_GET_HVALUE(v, _4$$3);
			ZEPHIR_INIT_LNVAR(_5$$4);
			ZEPHIR_CONCAT_SV(_5$$4, ":", k);
			ZEPHIR_MAKE_REF(v);
			ZEPHIR_CALL_FUNCTION(NULL, "oci_bind_by_name", &_6, 36, s, _5$$4, v);
			ZEPHIR_UNREF(v);
			zephir_check_call_status();
		}
	}
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("inTransaction"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(m);
	if (zephir_is_true(_7)) {
		ZVAL_LONG(m, 0);
	} else {
		ZVAL_LONG(m, 32);
	}
	ZEPHIR_CALL_FUNCTION(&_8, "oci_execute", NULL, 37, s, m);
	zephir_check_call_status();
	r = zephir_get_boolval(_8);
	ZEPHIR_INIT_VAR(_9);
	zephir_microtime(_9, ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	ZEPHIR_INIT_VAR(_10);
	ZVAL_DOUBLE(_10, (double) (zephir_get_doubleval(_9) - t));
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addquery", NULL, 0, sql, params, _10);
	zephir_check_call_status();
	if (unlikely(!r)) {
		_11$$7 = zephir_fetch_nproperty_this(this_ptr, SL("oci"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&e, "oci_error", NULL, 38, _11$$7);
		zephir_check_call_status();
		_12$$7 = Z_TYPE_P(e) != IS_ARRAY;
		if (!(_12$$7)) {
			ZEPHIR_OBS_VAR(eMessage);
			_12$$7 = !(zephir_array_isset_string_fetch(&eMessage, e, SS("message"), 0 TSRMLS_CC));
		}
		if (_12$$7) {
			ZEPHIR_INIT_NVAR(eMessage);
			ZVAL_STRING(eMessage, "Unknown Error", 1);
		}
		ZEPHIR_INIT_VAR(_13$$7);
		object_init_ex(_13$$7, yb_db_queryexception_ce);
		ZEPHIR_INIT_VAR(_14$$7);
		ZEPHIR_CONCAT_VSV(_14$$7, eMessage, " [SQL] ", sql);
		ZEPHIR_CALL_METHOD(NULL, _13$$7, "__construct", NULL, 2, _14$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(_13$$7, "yb/db/oci8.zep", 65 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Db_Oci8, queryAll) {

	zephir_fcall_cache_entry *_1 = NULL, *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *params = NULL;
	zval *sql_param = NULL, *params_param = NULL, *m = NULL, *d = NULL, *r = NULL, *_0$$3, *_2$$3 = NULL;
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
	ZEPHIR_INIT_VAR(m);
	ZVAL_LONG(m, ((4 + 8) + 1));
	while (1) {
		_0$$3 = zephir_fetch_nproperty_this(this_ptr, SL("lastStatement"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&r, "oci_fetch_array", &_1, 39, _0$$3, m);
		zephir_check_call_status();
		if (!(zephir_is_true(r))) {
			break;
		}
		ZEPHIR_CALL_FUNCTION(&_2$$3, "array_change_key_case", &_3, 40, r);
		zephir_check_call_status();
		zephir_array_append(&d, _2$$3, PH_SEPARATE, "yb/db/oci8.zep", 81);
	}
	RETURN_CCTOR(d);

}

PHP_METHOD(Yb_Db_Oci8, queryRow) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *params = NULL;
	zval *sql_param = NULL, *params_param = NULL, *r = NULL, *_0, _1;
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
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, ((4 + 8) + 1));
	ZEPHIR_CALL_FUNCTION(&r, "oci_fetch_array", NULL, 39, _0, &_1);
	zephir_check_call_status();
	if (zephir_is_true(r)) {
		ZEPHIR_RETURN_CALL_FUNCTION("array_change_key_case", NULL, 40, r);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Db_Oci8, queryCell) {

	zend_bool _2, _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *params = NULL;
	zval *sql_param = NULL, *params_param = NULL, *r = NULL, *i = NULL, *_0, _1;
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
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, ((4 + 8) + 2));
	ZEPHIR_CALL_FUNCTION(&r, "oci_fetch_array", NULL, 39, _0, &_1);
	zephir_check_call_status();
	_2 = zephir_is_true(r);
	if (_2) {
		_2 = Z_TYPE_P(r) == IS_ARRAY;
	}
	_3 = _2;
	if (_3) {
		_3 = zephir_array_isset_long_fetch(&i, r, 0, 1 TSRMLS_CC);
	}
	if (_3) {
		RETURN_CTOR(i);
	}
	RETURN_MM_STRING("", 1);

}

PHP_METHOD(Yb_Db_Oci8, queryColumns) {

	zend_bool _2$$3, _3$$3;
	zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *params = NULL;
	zval *sql_param = NULL, *params_param = NULL, *m = NULL, *d = NULL, *r = NULL, *i = NULL, *_0$$3;
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
	ZEPHIR_INIT_VAR(m);
	ZVAL_LONG(m, ((4 + 8) + 2));
	while (1) {
		_0$$3 = zephir_fetch_nproperty_this(this_ptr, SL("lastStatement"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&r, "oci_fetch_array", &_1, 39, _0$$3, m);
		zephir_check_call_status();
		_2$$3 = !zephir_is_true(r);
		if (!(_2$$3)) {
			_2$$3 = Z_TYPE_P(r) != IS_ARRAY;
		}
		_3$$3 = _2$$3;
		if (!(_3$$3)) {
			_3$$3 = !(zephir_array_isset_long_fetch(&i, r, 0, 1 TSRMLS_CC));
		}
		if (_3$$3) {
			break;
		}
		zephir_array_append(&d, i, PH_SEPARATE, "yb/db/oci8.zep", 125);
	}
	RETURN_CCTOR(d);

}

PHP_METHOD(Yb_Db_Oci8, tryToBegin) {

	

	RETURN_BOOL(1);

}

PHP_METHOD(Yb_Db_Oci8, tryToCommit) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("oci"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("oci_commit", NULL, 41, _0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Db_Oci8, tryToRollback) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("oci"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("oci_rollback", NULL, 42, _0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Db_Oci8, paginateQuery) {

	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	long limit, offset;
	zval *query_param = NULL, *limit_param = NULL, *offset_param = NULL, *_0 = NULL, *_1 = NULL, _3 = zval_used_for_init, _4 = zval_used_for_init, *_5 = NULL, *_8 = NULL, *_10 = NULL, _12;
	zval *query = NULL, *s = NULL, *t1 = NULL, *t2 = NULL, *r3 = NULL, *_2 = NULL, *_7 = NULL, *_9 = NULL, *_11 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &query_param, &limit_param, &offset_param);

	zephir_get_strval(query, query_param);
	limit = zephir_get_intval(limit_param);
	offset = zephir_get_intval(offset_param);


	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "t", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_SELF(&_0, "nextflag", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	zephir_get_strval(_2, _0);
	ZEPHIR_CPY_WRT(t1, _2);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "SELECT %s.* FROM (%s) %s WHERE rownum <= %d", 0);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, limit);
	ZEPHIR_CALL_FUNCTION(&_5, "sprintf", &_6, 1, &_3, t1, query, t1, &_4);
	zephir_check_call_status();
	zephir_get_strval(_7, _5);
	ZEPHIR_CPY_WRT(s, _7);
	if (offset == 0) {
		RETURN_CTOR(s);
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "t", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_SELF(&_8, "nextflag", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	zephir_get_strval(_9, _8);
	ZEPHIR_CPY_WRT(t2, _9);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "r", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_SELF(&_10, "nextflag", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	zephir_get_strval(_11, _10);
	ZEPHIR_CPY_WRT(r3, _11);
	ZEPHIR_SINIT_NVAR(_3);
	ZVAL_STRING(&_3, "SELECT * FROM (SELECT %s.*, rownum %s FROM (%s) %s WHERE rownum <= %d) %s WHERE %s > %d", 0);
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_LONG(&_4, limit);
	ZEPHIR_SINIT_VAR(_12);
	ZVAL_LONG(&_12, offset);
	ZEPHIR_RETURN_CALL_FUNCTION("sprintf", &_6, 1, &_3, t1, r3, query, t1, &_4, t2, r3, &_12);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Db_Oci8, randomOrder) {

	

	RETURN_STRING("dbms_random.value()", 1);

}



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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/hash.h"


ZEPHIR_INIT_CLASS(Yb_Db_DbAbstract) {

	ZEPHIR_REGISTER_CLASS(Yb\\Db, DbAbstract, yb, db_dbabstract, yb_db_dbabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_long(yb_db_dbabstract_ce, SL("nextFlag"), 1, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_bool(yb_db_dbabstract_ce, SL("inTransaction"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_db_dbabstract_ce, SL("savepoints"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_db_dbabstract_ce, SL("queries"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Yb_Db_DbAbstract, nextFlag) {

	long flag = 0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *pre_param = NULL, *_0, *_1, _2, _3;
	zval *pre = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &pre_param);

	if (!pre_param) {
		ZEPHIR_INIT_VAR(pre);
		ZVAL_STRING(pre, "", 1);
	} else {
		zephir_get_strval(pre, pre_param);
	}


	ZEPHIR_OBS_VAR(_0);
	zephir_read_static_property_ce(&_0, yb_db_dbabstract_ce, SL("nextFlag") TSRMLS_CC);
	flag = zephir_get_intval(_0);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(_1, (flag + 1));
	zephir_update_static_property_ce(yb_db_dbabstract_ce, SL("nextFlag"), &_1 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "%s%d", 0);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, flag);
	ZEPHIR_RETURN_CALL_FUNCTION("sprintf", NULL, 1, &_2, pre, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Db_DbAbstract, getInternalHandler) {

}

PHP_METHOD(Yb_Db_DbAbstract, quote) {

}

PHP_METHOD(Yb_Db_DbAbstract, query) {

}

PHP_METHOD(Yb_Db_DbAbstract, queryAll) {

}

PHP_METHOD(Yb_Db_DbAbstract, queryRow) {

}

PHP_METHOD(Yb_Db_DbAbstract, queryCell) {

}

PHP_METHOD(Yb_Db_DbAbstract, queryColumns) {

}

PHP_METHOD(Yb_Db_DbAbstract, inTransaction) {

	

	RETURN_MEMBER(this_ptr, "inTransaction");

}

PHP_METHOD(Yb_Db_DbAbstract, begin) {

	zval *_0, *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("inTransaction"), PH_NOISY_CC);
	if (unlikely(!(!zephir_is_true(_0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_db_transactionexception_ce, "Cannot begin when already in transaction", "yb/db/dbabstract.zep", 41);
		return;
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "trytobegin", NULL, 0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_db_transactionexception_ce, "Cannot begin transaction", "yb/db/dbabstract.zep", 45);
		return;
	}
	if (1) {
		zephir_update_property_this(this_ptr, SL("inTransaction"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("inTransaction"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Db_DbAbstract, commit) {

	zval *_0, *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("inTransaction"), PH_NOISY_CC);
	if (unlikely(!zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_db_transactionexception_ce, "Cannot commit when not in transaction", "yb/db/dbabstract.zep", 54);
		return;
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "trytocommit", NULL, 0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_db_transactionexception_ce, "Cannot commit transaction", "yb/db/dbabstract.zep", 58);
		return;
	}
	if (0) {
		zephir_update_property_this(this_ptr, SL("inTransaction"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("inTransaction"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Db_DbAbstract, rollback) {

	zval *_0, *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("inTransaction"), PH_NOISY_CC);
	if (unlikely(!zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_db_transactionexception_ce, "Cannot rollback when not in transaction", "yb/db/dbabstract.zep", 67);
		return;
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "trytorollback", NULL, 0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_db_transactionexception_ce, "Cannot rollback transaction", "yb/db/dbabstract.zep", 71);
		return;
	}
	if (0) {
		zephir_update_property_this(this_ptr, SL("inTransaction"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("inTransaction"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Db_DbAbstract, savepoint) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *savepoint_param = NULL, *_0, *_1 = NULL, *_5, *_2$$4 = NULL, *_3$$4, *_6$$5;
	zval *savepoint = NULL, *_8, *_4$$4 = NULL, *_7$$5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &savepoint_param);

	if (!savepoint_param) {
		ZEPHIR_INIT_VAR(savepoint);
		ZVAL_STRING(savepoint, "", 1);
	} else {
		zephir_get_strval(savepoint, savepoint_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("inTransaction"), PH_NOISY_CC);
	if (unlikely(!zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_db_transactionexception_ce, "Cannot acquire a savepoint when not in a transaction", "yb/db/dbabstract.zep", 80);
		return;
	}
	if (zephir_fast_strlen_ev(savepoint) < 1) {
		ZEPHIR_INIT_VAR(_3$$4);
		ZVAL_STRING(_3$$4, "s", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_SELF(&_2$$4, "nextflag", NULL, 0, _3$$4);
		zephir_check_temp_parameter(_3$$4);
		zephir_check_call_status();
		zephir_get_strval(_4$$4, _2$$4);
		ZEPHIR_CPY_WRT(savepoint, _4$$4);
	}
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("savepoints"), PH_NOISY_CC);
	if (unlikely(zephir_array_isset(_5, savepoint))) {
		ZEPHIR_INIT_VAR(_6$$5);
		object_init_ex(_6$$5, yb_db_transactionexception_ce);
		ZEPHIR_INIT_VAR(_7$$5);
		ZEPHIR_CONCAT_SV(_7$$5, "Duplicate savepoint: ", savepoint);
		ZEPHIR_CALL_METHOD(NULL, _6$$5, "__construct", NULL, 2, _7$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_6$$5, "yb/db/dbabstract.zep", 88 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_8);
	ZEPHIR_CONCAT_SV(_8, "SAVEPOINT ", savepoint);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "query", NULL, 0, _8);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("savepoints"), savepoint, savepoint TSRMLS_CC);
	RETURN_CTOR(savepoint);

}

PHP_METHOD(Yb_Db_DbAbstract, releaseSavepoint) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *savepoint_param = NULL, *_0, *_1, *_5, *_2$$4;
	zval *savepoint = NULL, *_4, *_3$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &savepoint_param);

	zephir_get_strval(savepoint, savepoint_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("inTransaction"), PH_NOISY_CC);
	if (unlikely(!zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_db_transactionexception_ce, "Cannot release a savepoint when not in a transaction", "yb/db/dbabstract.zep", 100);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("savepoints"), PH_NOISY_CC);
	if (unlikely(!(zephir_array_isset(_1, savepoint)))) {
		ZEPHIR_INIT_VAR(_2$$4);
		object_init_ex(_2$$4, yb_db_transactionexception_ce);
		ZEPHIR_INIT_VAR(_3$$4);
		ZEPHIR_CONCAT_SV(_3$$4, "Cannot find savepoint: ", savepoint);
		ZEPHIR_CALL_METHOD(NULL, _2$$4, "__construct", NULL, 2, _3$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2$$4, "yb/db/dbabstract.zep", 104 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_SV(_4, "RELEASE SAVEPOINT ", savepoint);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "query", NULL, 0, _4);
	zephir_check_call_status();
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("savepoints"), PH_NOISY_CC);
	zephir_array_unset(&_5, savepoint, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Db_DbAbstract, releaseLastSavepoint) {

	zval *_0, *_1, *_2, *_3 = NULL, *_6;
	zval *savepoint = NULL, *_4 = NULL, *_5;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("inTransaction"), PH_NOISY_CC);
	if (unlikely(!zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_db_transactionexception_ce, "Cannot release last savepoint when not in a transaction", "yb/db/dbabstract.zep", 116);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("savepoints"), PH_NOISY_CC);
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_db_transactionexception_ce, "Empty savepoint stack", "yb/db/dbabstract.zep", 120);
		return;
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("savepoints"), PH_NOISY_CC);
	ZEPHIR_MAKE_REF(_2);
	ZEPHIR_CALL_FUNCTION(&_3, "end", NULL, 3, _2);
	ZEPHIR_UNREF(_2);
	zephir_check_call_status();
	zephir_get_strval(_4, _3);
	ZEPHIR_CPY_WRT(savepoint, _4);
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_SV(_5, "RELEASE SAVEPOINT ", savepoint);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "query", NULL, 0, _5);
	zephir_check_call_status();
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("savepoints"), PH_NOISY_CC);
	zephir_array_unset(&_6, savepoint, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Db_DbAbstract, rollbackToSavepoint) {

	zephir_fcall_cache_entry *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *savepoint_param = NULL, *_0, *_1, *_2$$4, *_5$$5, *_6$$5 = NULL;
	zval *savepoint = NULL, *_4, *_3$$4, *_8$$5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &savepoint_param);

	zephir_get_strval(savepoint, savepoint_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("inTransaction"), PH_NOISY_CC);
	if (unlikely(!zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_db_transactionexception_ce, "Cannot rollback to a savepoint when not in a transaction", "yb/db/dbabstract.zep", 132);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("savepoints"), PH_NOISY_CC);
	if (unlikely(!(zephir_array_isset(_1, savepoint)))) {
		ZEPHIR_INIT_VAR(_2$$4);
		object_init_ex(_2$$4, yb_db_transactionexception_ce);
		ZEPHIR_INIT_VAR(_3$$4);
		ZEPHIR_CONCAT_SV(_3$$4, "Cannot find savepoint: ", savepoint);
		ZEPHIR_CALL_METHOD(NULL, _2$$4, "__construct", NULL, 2, _3$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2$$4, "yb/db/dbabstract.zep", 136 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_SV(_4, "ROLLBACK TO SAVEPOINT ", savepoint);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "query", NULL, 0, _4);
	zephir_check_call_status();
	while (1) {
		_5$$5 = zephir_fetch_nproperty_this(this_ptr, SL("savepoints"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_6$$5, "array_pop", &_7, 4, _5$$5);
		zephir_check_call_status();
		zephir_get_strval(_8$$5, _6$$5);
		if (ZEPHIR_IS_IDENTICAL(_8$$5, savepoint)) {
			zephir_update_property_array(this_ptr, SL("savepoints"), savepoint, savepoint TSRMLS_CC);
			break;
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Db_DbAbstract, rollbackToLastSavepoint) {

	zval *_0, *_1, *_2, *_3 = NULL;
	zval *savepoint = NULL, *_4 = NULL, *_5;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("inTransaction"), PH_NOISY_CC);
	if (unlikely(!zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_db_transactionexception_ce, "Cannot rollback to last savepoint when not in a transaction", "yb/db/dbabstract.zep", 154);
		return;
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("savepoints"), PH_NOISY_CC);
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_db_transactionexception_ce, "Empty savepoint stack", "yb/db/dbabstract.zep", 158);
		return;
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("savepoints"), PH_NOISY_CC);
	ZEPHIR_MAKE_REF(_2);
	ZEPHIR_CALL_FUNCTION(&_3, "end", NULL, 3, _2);
	ZEPHIR_UNREF(_2);
	zephir_check_call_status();
	zephir_get_strval(_4, _3);
	ZEPHIR_CPY_WRT(savepoint, _4);
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_SV(_5, "ROLLBACK TO SAVEPOINT ", savepoint);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "query", NULL, 0, _5);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Db_DbAbstract, expression) {

	zval *_1, *_3, *_8;
	zval *f = NULL, *_5 = NULL, *_6 = NULL;
	zval *a = NULL, *_0, *_2 = NULL, *_4 = NULL, *_7 = NULL, *_9 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&a, "func_get_args", NULL, 5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "%", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "?", 1);
	zephir_array_fast_append(_1, _2);
	ZEPHIR_INIT_VAR(_3);
	zephir_create_array(_3, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "%%", 1);
	zephir_array_fast_append(_3, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "%s", 1);
	zephir_array_fast_append(_3, _2);
	ZEPHIR_MAKE_REF(a);
	ZEPHIR_CALL_FUNCTION(&_4, "array_shift", NULL, 6, a);
	ZEPHIR_UNREF(a);
	zephir_check_call_status();
	zephir_get_strval(_5, _4);
	zephir_fast_str_replace(&_0, _1, _3, _5 TSRMLS_CC);
	zephir_get_strval(_6, _0);
	ZEPHIR_CPY_WRT(f, _6);
	if (unlikely(zephir_fast_strlen_ev(f) < 1)) {
		RETURN_MM_STRING("", 1);
	}
	ZEPHIR_INIT_VAR(_8);
	zephir_create_array(_8, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_8, this_ptr);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "quote", 1);
	zephir_array_fast_append(_8, _2);
	ZEPHIR_CALL_FUNCTION(&_9, "array_map", NULL, 7, _8, a);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("vsprintf", NULL, 8, f, _9);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Db_DbAbstract, getQueries) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("queries"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		RETURN_MEMBER(this_ptr, "queries");
	}
	array_init(return_value);
	return;

}

PHP_METHOD(Yb_Db_DbAbstract, insert) {

	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL;
	zval *table_param = NULL, *data_param = NULL, *returningId_param = NULL, *k = NULL, *ks = NULL, *vs = NULL, *_0, **_3, *_5, *_6, *_7, *_4$$3 = NULL;
	zval *table = NULL, *returningId = NULL, *sql = NULL, *_8$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &table_param, &data_param, &returningId_param);

	zephir_get_strval(table, table_param);
	zephir_get_arrval(data, data_param);
	if (!returningId_param) {
		ZEPHIR_INIT_VAR(returningId);
		ZVAL_STRING(returningId, "", 1);
	} else {
		zephir_get_strval(returningId, returningId_param);
	}


	ZEPHIR_INIT_VAR(ks);
	array_init(ks);
	ZEPHIR_INIT_VAR(vs);
	array_init(vs);
	ZEPHIR_INIT_VAR(_0);
	zephir_array_keys(_0, data TSRMLS_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "yb/db/dbabstract.zep", 200);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(k, _3);
		zephir_array_append(&ks, k, PH_SEPARATE, "yb/db/dbabstract.zep", 196);
		ZEPHIR_INIT_LNVAR(_4$$3);
		ZEPHIR_CONCAT_SV(_4$$3, ":", k);
		zephir_array_append(&vs, _4$$3, PH_SEPARATE, "yb/db/dbabstract.zep", 197);
	}
	ZEPHIR_INIT_VAR(_5);
	zephir_fast_join_str(_5, SL(", "), ks TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	zephir_fast_join_str(_6, SL(", "), vs TSRMLS_CC);
	ZEPHIR_INIT_VAR(_7);
	ZEPHIR_CONCAT_SVSVSVS(_7, "INSERT INTO ", table, " (", _5, ") VALUES (", _6, ")");
	zephir_get_strval(sql, _7);
	if (!(!returningId) && Z_STRLEN_P(returningId)) {
		ZEPHIR_INIT_VAR(_8$$4);
		ZEPHIR_CONCAT_SV(_8$$4, " RETURNING ", returningId);
		zephir_concat_self(&sql, _8$$4 TSRMLS_CC);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "querycell", NULL, 0, sql, data);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "query", NULL, 0, sql, data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Db_DbAbstract, delete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *where_param = NULL;
	zval *table = NULL, *where = NULL, *s = NULL, *_0$$3 = NULL, *_1$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &where_param);

	zephir_get_strval(table, table_param);
	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		ZVAL_STRING(where, "", 1);
	} else {
		zephir_get_strval(where, where_param);
	}


	ZEPHIR_INIT_VAR(s);
	ZEPHIR_CONCAT_SV(s, "DELETE FROM ", table);
	if (!(!where) && Z_STRLEN_P(where)) {
		zephir_get_strval(_0$$3, where);
		ZEPHIR_INIT_VAR(_1$$3);
		ZEPHIR_CONCAT_SV(_1$$3, " WHERE ", _0$$3);
		zephir_concat_self(&s, _1$$3 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "query", NULL, 0, s);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Db_DbAbstract, update) {

	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL;
	zval *table_param = NULL, *data_param = NULL, *where_param = NULL, *k = NULL, *v = NULL, *kvs = NULL, *params = NULL, **_2, *_4, *_5, *_3$$3 = NULL;
	zval *table = NULL, *where = NULL, *s = NULL, *_6$$4 = NULL, *_7$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &table_param, &data_param, &where_param);

	zephir_get_strval(table, table_param);
	zephir_get_arrval(data, data_param);
	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		ZVAL_STRING(where, "", 1);
	} else {
		zephir_get_strval(where, where_param);
	}


	ZEPHIR_INIT_VAR(kvs);
	array_init(kvs);
	ZEPHIR_INIT_VAR(params);
	array_init(params);
	zephir_is_iterable(data, &_1, &_0, 0, 0, "yb/db/dbabstract.zep", 232);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		ZEPHIR_INIT_LNVAR(_3$$3);
		ZEPHIR_CONCAT_VSV(_3$$3, k, " = :", k);
		zephir_array_update_zval(&kvs, k, &_3$$3, PH_COPY | PH_SEPARATE);
		zephir_array_update_zval(&params, k, &v, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(_4);
	zephir_fast_join_str(_4, SL(", "), kvs TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_SVSV(_5, "UPDATE ", table, " SET ", _4);
	zephir_get_strval(s, _5);
	if (!(!where) && Z_STRLEN_P(where)) {
		zephir_get_strval(_6$$4, where);
		ZEPHIR_INIT_VAR(_7$$4);
		ZEPHIR_CONCAT_SV(_7$$4, " WHERE ", _6$$4);
		zephir_concat_self(&s, _7$$4 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "query", NULL, 0, s, params);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Db_DbAbstract, upsert) {

	HashTable *_1$$3;
	HashPosition _0$$3;
	zephir_fcall_cache_entry *_5 = NULL, *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL;
	zval *table_param = NULL, *data_param = NULL, *primaryKey, *k = NULL, *v = NULL, *where = NULL, *_14, **_2$$3, *_3$$5 = NULL, *_4$$5 = NULL, *_6$$4 = NULL, *_8$$4 = NULL, *_12$$7 = NULL, *_13$$7, *_10$$8, *_11$$8;
	zval *table = NULL, *_9$$7 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &table_param, &data_param, &primaryKey);

	zephir_get_strval(table, table_param);
	zephir_get_arrval(data, data_param);


	ZEPHIR_INIT_VAR(where);
	array_init(where);
	if (Z_TYPE_P(primaryKey) == IS_ARRAY) {
		zephir_is_iterable(primaryKey, &_1$$3, &_0$$3, 0, 0, "yb/db/dbabstract.zep", 251);
		for (
		  ; zephir_hash_get_current_data_ex(_1$$3, (void**) &_2$$3, &_0$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1$$3, &_0$$3)
		) {
			ZEPHIR_GET_HVALUE(k, _2$$3);
			ZEPHIR_OBS_NVAR(v);
			if (unlikely(!(zephir_array_isset_fetch(&v, data, k, 0 TSRMLS_CC)))) {
				ZEPHIR_INIT_NVAR(_3$$5);
				object_init_ex(_3$$5, yb_db_exception_ce);
				ZEPHIR_INIT_LNVAR(_4$$5);
				ZEPHIR_CONCAT_SV(_4$$5, "Cannot find primary key value in data: ", k);
				ZEPHIR_CALL_METHOD(NULL, _3$$5, "__construct", &_5, 2, _4$$5);
				zephir_check_call_status();
				zephir_throw_exception_debug(_3$$5, "yb/db/dbabstract.zep", 247 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(&_6$$4, this_ptr, "quote", &_7, 0, v);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_8$$4);
			ZEPHIR_CONCAT_VSV(_8$$4, k, " = ", _6$$4);
			zephir_array_update_zval(&where, k, &_8$$4, PH_COPY | PH_SEPARATE);
		}
		if (unlikely(!zephir_is_true(where))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_db_exception_ce, "Cannot upsert with empty where", "yb/db/dbabstract.zep", 252);
			return;
		}
	} else {
		zephir_get_strval(_9$$7, primaryKey);
		ZEPHIR_CPY_WRT(k, _9$$7);
		ZEPHIR_OBS_NVAR(v);
		if (unlikely(!(zephir_array_isset_fetch(&v, data, k, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_VAR(_10$$8);
			object_init_ex(_10$$8, yb_db_exception_ce);
			ZEPHIR_INIT_VAR(_11$$8);
			ZEPHIR_CONCAT_SV(_11$$8, "Cannot find primary key value in data: ", k);
			ZEPHIR_CALL_METHOD(NULL, _10$$8, "__construct", &_5, 2, _11$$8);
			zephir_check_call_status();
			zephir_throw_exception_debug(_10$$8, "yb/db/dbabstract.zep", 257 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(&_12$$7, this_ptr, "quote", &_7, 0, v);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_13$$7);
		ZEPHIR_CONCAT_VSV(_13$$7, k, " = ", _12$$7);
		zephir_array_update_zval(&where, k, &_13$$7, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(_14);
	zephir_fast_join_str(_14, SL(" AND "), where TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "delete", NULL, 0, table, _14);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "insert", NULL, 0, table, data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Db_DbAbstract, parseSelect) {

	zend_bool forUpdate = 0;
	long limit = 0, offset = 0;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *options = NULL;
	zval *table_param = NULL, *options_param = NULL, *orderBy = NULL, *_0 = NULL, *_2 = NULL, *_3 = NULL, *_5 = NULL, *_7 = NULL, *_8 = NULL, *_9 = NULL, *_12$$7 = NULL, *_17$$9 = NULL, *_18$$9, *_19$$9;
	zval *table = NULL, *field = NULL, *where = NULL, *s = NULL, *_4 = NULL, *_6 = NULL, *_10, *_11$$5, *_13$$7 = NULL, *_14$$7, *_15$$8 = NULL, *_16$$8, *_20$$9 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &options_param);

	zephir_get_strval(table, table_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	ZEPHIR_INIT_VAR(s);
	ZVAL_STRING(s, "SELECT ", 1);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "field", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "*", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_0, yb_std_ce, "valueat", &_1, 9, options, _2, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_get_strval(_4, _0);
	ZEPHIR_CPY_WRT(field, _4);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "where", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_5, yb_std_ce, "valueat", &_1, 9, options, _2, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_get_strval(_6, _5);
	ZEPHIR_CPY_WRT(where, _6);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "orderBy", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&orderBy, yb_std_ce, "valueat", &_1, 9, options, _2, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "limit", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_LONG(_3, 0);
	ZEPHIR_CALL_CE_STATIC(&_7, yb_std_ce, "valueat", &_1, 9, options, _2, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	limit = zephir_get_intval(_7);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "offset", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_LONG(_3, 0);
	ZEPHIR_CALL_CE_STATIC(&_8, yb_std_ce, "valueat", &_1, 9, options, _2, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	offset = zephir_get_intval(_8);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "forUpdate", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_BOOL(_3, 0);
	ZEPHIR_CALL_CE_STATIC(&_9, yb_std_ce, "valueat", &_1, 9, options, _2, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	forUpdate = zephir_get_boolval(_9);
	if (!(!field) && Z_STRLEN_P(field)) {
		zephir_concat_self(&s, field TSRMLS_CC);
	} else {
		zephir_concat_self_str(&s, "*", sizeof("*")-1 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_10);
	ZEPHIR_CONCAT_SV(_10, " FROM ", table);
	zephir_concat_self(&s, _10 TSRMLS_CC);
	if (!(!where) && Z_STRLEN_P(where)) {
		ZEPHIR_INIT_VAR(_11$$5);
		ZEPHIR_CONCAT_SV(_11$$5, " WHERE ", where);
		zephir_concat_self(&s, _11$$5 TSRMLS_CC);
	}
	if (zephir_is_true(orderBy)) {
		if (ZEPHIR_IS_TRUE_IDENTICAL(orderBy)) {
			ZEPHIR_CALL_METHOD(&_12$$7, this_ptr, "randomorder", NULL, 0);
			zephir_check_call_status();
			zephir_get_strval(_13$$7, _12$$7);
			ZEPHIR_INIT_VAR(_14$$7);
			ZEPHIR_CONCAT_SV(_14$$7, " ORDER BY ", _13$$7);
			zephir_concat_self(&s, _14$$7 TSRMLS_CC);
			offset = 0;
		} else {
			zephir_get_strval(_15$$8, orderBy);
			ZEPHIR_INIT_VAR(_16$$8);
			ZEPHIR_CONCAT_SV(_16$$8, " ORDER BY ", _15$$8);
			zephir_concat_self(&s, _16$$8 TSRMLS_CC);
		}
	}
	if (limit > 0) {
		ZEPHIR_INIT_VAR(_18$$9);
		ZVAL_LONG(_18$$9, limit);
		ZEPHIR_INIT_VAR(_19$$9);
		ZVAL_LONG(_19$$9, offset);
		ZEPHIR_CALL_METHOD(&_17$$9, this_ptr, "paginatequery", NULL, 0, s, _18$$9, _19$$9);
		zephir_check_call_status();
		zephir_get_strval(_20$$9, _17$$9);
		ZEPHIR_CPY_WRT(s, _20$$9);
	}
	if (forUpdate) {
		zephir_concat_self_str(&s, " FOR UPDATE", sizeof(" FOR UPDATE")-1 TSRMLS_CC);
	}
	RETURN_CTOR(s);

}

PHP_METHOD(Yb_Db_DbAbstract, selectAll) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL;
	zval *table_param = NULL, *options_param = NULL, *_0 = NULL;
	zval *table = NULL, *s = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &options_param);

	zephir_get_strval(table, table_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "parseselect", NULL, 0, table, options);
	zephir_check_call_status();
	zephir_get_strval(_1, _0);
	ZEPHIR_CPY_WRT(s, _1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "queryall", NULL, 0, s);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Db_DbAbstract, selectRow) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL;
	zval *table_param = NULL, *options_param = NULL, *_0 = NULL;
	zval *table = NULL, *s = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &options_param);

	zephir_get_strval(table, table_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "parseselect", NULL, 0, table, options);
	zephir_check_call_status();
	zephir_get_strval(_1, _0);
	ZEPHIR_CPY_WRT(s, _1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "queryrow", NULL, 0, s);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Db_DbAbstract, selectCell) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL;
	zval *table_param = NULL, *options_param = NULL, *_0 = NULL;
	zval *table = NULL, *s = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &options_param);

	zephir_get_strval(table, table_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "parseselect", NULL, 0, table, options);
	zephir_check_call_status();
	zephir_get_strval(_1, _0);
	ZEPHIR_CPY_WRT(s, _1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "querycell", NULL, 0, s);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Db_DbAbstract, selectColumns) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL;
	zval *table_param = NULL, *options_param = NULL, *_0 = NULL;
	zval *table = NULL, *s = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &options_param);

	zephir_get_strval(table, table_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "parseselect", NULL, 0, table, options);
	zephir_check_call_status();
	zephir_get_strval(_1, _0);
	ZEPHIR_CPY_WRT(s, _1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "querycolumns", NULL, 0, s);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Db_DbAbstract, countAndSelect) {

	long c = 0;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *options = NULL;
	zval *table_param = NULL, *options_param = NULL, *_0 = NULL, *_2 = NULL, *_3, *_6 = NULL, *_8 = NULL, *_7$$4 = NULL;
	zval *table = NULL, *where = NULL, *s = NULL, *_4 = NULL, *_5$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &options_param);

	zephir_get_strval(table, table_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "where", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_0, yb_std_ce, "valueat", &_1, 9, options, _2, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_get_strval(_4, _0);
	ZEPHIR_CPY_WRT(where, _4);
	ZEPHIR_INIT_VAR(s);
	ZEPHIR_CONCAT_SV(s, "SELECT COUNT(*) FROM ", table);
	if (!(!where) && Z_STRLEN_P(where)) {
		ZEPHIR_INIT_VAR(_5$$3);
		ZEPHIR_CONCAT_SV(_5$$3, " WHERE ", where);
		zephir_concat_self(&s, _5$$3 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "querycell", NULL, 0, s);
	zephir_check_call_status();
	c = zephir_get_intval(_6);
	if (c < 1) {
		zephir_create_array(return_value, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_7$$4);
		ZVAL_LONG(_7$$4, 0);
		zephir_array_fast_append(return_value, _7$$4);
		ZEPHIR_INIT_NVAR(_7$$4);
		array_init(_7$$4);
		zephir_array_fast_append(return_value, _7$$4);
		RETURN_MM();
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, c);
	zephir_array_fast_append(return_value, _2);
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "selectall", NULL, 0, table, options);
	zephir_check_call_status();
	zephir_array_fast_append(return_value, _8);
	RETURN_MM();

}

PHP_METHOD(Yb_Db_DbAbstract, parseUnionAll) {

	HashTable *_1;
	HashPosition _0;
	zval *s = NULL, *_5 = NULL, *_8 = NULL, *_10$$6 = NULL, *_11$$6, *_12$$7 = NULL, *_13$$7;
	int ZEPHIR_LAST_CALL_STATUS;
	long limit, offset;
	zval *selects_param = NULL, *orderBy = NULL, *limit_param = NULL, *offset_param = NULL, *i = NULL, *a = NULL, **_2, *_4, *_6 = NULL, *_7 = NULL, *_14, *_3$$4 = NULL, *_9$$6 = NULL;
	zval *selects = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &selects_param, &orderBy, &limit_param, &offset_param);

	zephir_get_arrval(selects, selects_param);
	if (!orderBy) {
		orderBy = ZEPHIR_GLOBAL(global_null);
	}
	if (!limit_param) {
		limit = 0;
	} else {
		limit = zephir_get_intval(limit_param);
	}
	if (!offset_param) {
		offset = 0;
	} else {
		offset = zephir_get_intval(offset_param);
	}


	ZEPHIR_INIT_VAR(a);
	array_init(a);
	if (unlikely(zephir_fast_count_int(selects TSRMLS_CC) < 1)) {
		RETURN_MM_STRING("", 1);
	}
	zephir_is_iterable(selects, &_1, &_0, 0, 0, "yb/db/dbabstract.zep", 383);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(i, _2);
		ZEPHIR_INIT_LNVAR(_3$$4);
		ZEPHIR_CONCAT_SVS(_3$$4, "(", i, ")");
		zephir_array_append(&a, _3$$4, PH_SEPARATE, "yb/db/dbabstract.zep", 380);
	}
	ZEPHIR_INIT_VAR(_4);
	zephir_fast_join_str(_4, SL(" UNION ALL "), a TSRMLS_CC);
	zephir_get_strval(_5, _4);
	ZEPHIR_INIT_VAR(_7);
	ZVAL_STRING(_7, "u", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_SELF(&_6, "nextflag", NULL, 0, _7);
	zephir_check_temp_parameter(_7);
	zephir_check_call_status();
	zephir_get_strval(_8, _6);
	ZEPHIR_INIT_VAR(s);
	ZEPHIR_CONCAT_SVSV(s, "SELECT * FROM (", _5, ") AS ", _8);
	if (zephir_is_true(orderBy)) {
		if (ZEPHIR_IS_TRUE_IDENTICAL(orderBy)) {
			ZEPHIR_CALL_METHOD(&_9$$6, this_ptr, "randomorder", NULL, 0);
			zephir_check_call_status();
			zephir_get_strval(_10$$6, _9$$6);
			ZEPHIR_INIT_VAR(_11$$6);
			ZEPHIR_CONCAT_SV(_11$$6, " ORDER BY ", _10$$6);
			zephir_concat_self(&s, _11$$6 TSRMLS_CC);
			offset = 0;
		} else {
			zephir_get_strval(_12$$7, orderBy);
			ZEPHIR_INIT_VAR(_13$$7);
			ZEPHIR_CONCAT_SV(_13$$7, " ORDER BY ", _12$$7);
			zephir_concat_self(&s, _13$$7 TSRMLS_CC);
		}
	}
	if (limit < 1) {
		RETURN_CTOR(s);
	}
	ZEPHIR_INIT_NVAR(_7);
	ZVAL_LONG(_7, limit);
	ZEPHIR_INIT_VAR(_14);
	ZVAL_LONG(_14, offset);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "paginatequery", NULL, 0, s, _7, _14);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Db_DbAbstract, queryUnionAll) {

	zval *s = NULL, *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	long limit, offset;
	zval *selects_param = NULL, *orderBy = NULL, *limit_param = NULL, *offset_param = NULL, *_0 = NULL, *_1, *_2;
	zval *selects = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &selects_param, &orderBy, &limit_param, &offset_param);

	zephir_get_arrval(selects, selects_param);
	if (!orderBy) {
		orderBy = ZEPHIR_GLOBAL(global_null);
	}
	if (!limit_param) {
		limit = 0;
	} else {
		limit = zephir_get_intval(limit_param);
	}
	if (!offset_param) {
		offset = 0;
	} else {
		offset = zephir_get_intval(offset_param);
	}


	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, limit);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, offset);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "parseunionall", NULL, 0, selects, orderBy, _1, _2);
	zephir_check_call_status();
	zephir_get_strval(_3, _0);
	ZEPHIR_CPY_WRT(s, _3);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "queryall", NULL, 0, s);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Db_DbAbstract, countAndQueryUnionAll) {

	HashTable *_2;
	HashPosition _1;
	zval *s = NULL, *_6 = NULL, *_9 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	long limit, offset, c = 0;
	zval *selects_param = NULL, *orderBy = NULL, *limit_param = NULL, *offset_param = NULL, *i = NULL, *a = NULL, **_3, *_5, *_7 = NULL, *_8 = NULL, *_10 = NULL, *_12 = NULL, *_13, *_0$$3 = NULL, *_4$$4 = NULL, *_11$$5 = NULL;
	zval *selects = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &selects_param, &orderBy, &limit_param, &offset_param);

	zephir_get_arrval(selects, selects_param);
	if (!orderBy) {
		orderBy = ZEPHIR_GLOBAL(global_null);
	}
	if (!limit_param) {
		limit = 0;
	} else {
		limit = zephir_get_intval(limit_param);
	}
	if (!offset_param) {
		offset = 0;
	} else {
		offset = zephir_get_intval(offset_param);
	}


	ZEPHIR_INIT_VAR(a);
	array_init(a);
	if (unlikely(zephir_fast_count_int(selects TSRMLS_CC) < 1)) {
		zephir_create_array(return_value, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_0$$3);
		ZVAL_LONG(_0$$3, 0);
		zephir_array_fast_append(return_value, _0$$3);
		ZEPHIR_INIT_NVAR(_0$$3);
		array_init(_0$$3);
		zephir_array_fast_append(return_value, _0$$3);
		RETURN_MM();
	}
	zephir_is_iterable(selects, &_2, &_1, 0, 0, "yb/db/dbabstract.zep", 423);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(i, _3);
		ZEPHIR_INIT_LNVAR(_4$$4);
		ZEPHIR_CONCAT_SVS(_4$$4, "(", i, ")");
		zephir_array_append(&a, _4$$4, PH_SEPARATE, "yb/db/dbabstract.zep", 420);
	}
	ZEPHIR_INIT_VAR(_5);
	zephir_fast_join_str(_5, SL(" UNION ALL "), a TSRMLS_CC);
	zephir_get_strval(_6, _5);
	ZEPHIR_INIT_VAR(_8);
	ZVAL_STRING(_8, "u", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_SELF(&_7, "nextflag", NULL, 0, _8);
	zephir_check_temp_parameter(_8);
	zephir_check_call_status();
	zephir_get_strval(_9, _7);
	ZEPHIR_INIT_VAR(s);
	ZEPHIR_CONCAT_SVSV(s, "SELECT COUNT(*) FROM (", _6, ") AS ", _9);
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "querycell", NULL, 0, s);
	zephir_check_call_status();
	c = zephir_get_intval(_10);
	if (c < 1) {
		zephir_create_array(return_value, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_11$$5);
		ZVAL_LONG(_11$$5, 0);
		zephir_array_fast_append(return_value, _11$$5);
		ZEPHIR_INIT_NVAR(_11$$5);
		array_init(_11$$5);
		zephir_array_fast_append(return_value, _11$$5);
		RETURN_MM();
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_8);
	ZVAL_LONG(_8, c);
	zephir_array_fast_append(return_value, _8);
	ZEPHIR_INIT_NVAR(_8);
	ZVAL_LONG(_8, limit);
	ZEPHIR_INIT_VAR(_13);
	ZVAL_LONG(_13, offset);
	ZEPHIR_CALL_METHOD(&_12, this_ptr, "queryunionall", NULL, 0, selects, orderBy, _8, _13);
	zephir_check_call_status();
	zephir_array_fast_append(return_value, _12);
	RETURN_MM();

}

PHP_METHOD(Yb_Db_DbAbstract, parseAggregation) {

	HashTable *_1;
	HashPosition _0;
	zval *aggregations = NULL;
	zval *table_param = NULL, *aggregations_param = NULL, *where_param = NULL, *k = NULL, *v = NULL, *a = NULL, **_2, *_4, *_5, *_3$$3 = NULL;
	zval *table = NULL, *where = NULL, *s = NULL, *_6$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &table_param, &aggregations_param, &where_param);

	zephir_get_strval(table, table_param);
	zephir_get_arrval(aggregations, aggregations_param);
	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		ZVAL_STRING(where, "", 1);
	} else {
		zephir_get_strval(where, where_param);
	}


	ZEPHIR_INIT_VAR(a);
	array_init(a);
	zephir_is_iterable(aggregations, &_1, &_0, 0, 0, "yb/db/dbabstract.zep", 445);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		ZEPHIR_INIT_LNVAR(_3$$3);
		ZEPHIR_CONCAT_VSV(_3$$3, v, " AS ", k);
		zephir_array_append(&a, _3$$3, PH_SEPARATE, "yb/db/dbabstract.zep", 442);
	}
	ZEPHIR_INIT_VAR(_4);
	zephir_fast_join_str(_4, SL(", "), a TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_SVSV(_5, "SELECT ", _4, " FROM ", table);
	zephir_get_strval(s, _5);
	if (!(!where) && Z_STRLEN_P(where)) {
		ZEPHIR_INIT_VAR(_6$$4);
		ZEPHIR_CONCAT_SV(_6$$4, " WHERE ", where);
		zephir_concat_self(&s, _6$$4 TSRMLS_CC);
	}
	RETURN_CTOR(s);

}

PHP_METHOD(Yb_Db_DbAbstract, queryAggregation) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *aggregations = NULL;
	zval *table_param = NULL, *aggregations_param = NULL, *where_param = NULL, *_0 = NULL;
	zval *table = NULL, *where = NULL, *s = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &table_param, &aggregations_param, &where_param);

	zephir_get_strval(table, table_param);
	zephir_get_arrval(aggregations, aggregations_param);
	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		ZVAL_STRING(where, "", 1);
	} else {
		zephir_get_strval(where, where_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "parseaggregation", NULL, 0, table, aggregations, where);
	zephir_check_call_status();
	zephir_get_strval(_1, _0);
	ZEPHIR_CPY_WRT(s, _1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "queryrow", NULL, 0, s);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Db_DbAbstract, aggregate) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *column_param = NULL, *aggregation_param = NULL, *where_param = NULL;
	zval *table = NULL, *column = NULL, *aggregation = NULL, *where = NULL, *s = NULL, *_0$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &table_param, &column_param, &aggregation_param, &where_param);

	zephir_get_strval(table, table_param);
	zephir_get_strval(column, column_param);
	zephir_get_strval(aggregation, aggregation_param);
	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		ZVAL_STRING(where, "", 1);
	} else {
		zephir_get_strval(where, where_param);
	}


	ZEPHIR_INIT_VAR(s);
	ZEPHIR_CONCAT_SVSVSV(s, "SELECT ", aggregation, "(", column, ") FROM ", table);
	if (!(!where) && Z_STRLEN_P(where)) {
		ZEPHIR_INIT_VAR(_0$$3);
		ZEPHIR_CONCAT_SV(_0$$3, " WHERE ", where);
		zephir_concat_self(&s, _0$$3 TSRMLS_CC);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "querycell", NULL, 0, s);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Db_DbAbstract, count) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *column_param = NULL, *where_param = NULL, *_0 = NULL, *_1;
	zval *table = NULL, *column = NULL, *where = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &table_param, &column_param, &where_param);

	zephir_get_strval(table, table_param);
	if (!column_param) {
		ZEPHIR_INIT_VAR(column);
		ZVAL_STRING(column, "*", 1);
	} else {
		zephir_get_strval(column, column_param);
	}
	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		ZVAL_STRING(where, "", 1);
	} else {
		zephir_get_strval(where, where_param);
	}


	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "COUNT", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "aggregate", NULL, 0, table, column, _1, where);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM_LONG(zephir_get_intval(_0));

}

PHP_METHOD(Yb_Db_DbAbstract, max) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *column_param = NULL, *where_param = NULL, *_0;
	zval *table = NULL, *column = NULL, *where = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &table_param, &column_param, &where_param);

	zephir_get_strval(table, table_param);
	zephir_get_strval(column, column_param);
	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		ZVAL_STRING(where, "", 1);
	} else {
		zephir_get_strval(where, where_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "MAX", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "aggregate", NULL, 0, table, column, _0, where);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Db_DbAbstract, min) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *column_param = NULL, *where_param = NULL, *_0;
	zval *table = NULL, *column = NULL, *where = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &table_param, &column_param, &where_param);

	zephir_get_strval(table, table_param);
	zephir_get_strval(column, column_param);
	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		ZVAL_STRING(where, "", 1);
	} else {
		zephir_get_strval(where, where_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "MIN", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "aggregate", NULL, 0, table, column, _0, where);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Db_DbAbstract, sum) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *column_param = NULL, *where_param = NULL, *_0;
	zval *table = NULL, *column = NULL, *where = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &table_param, &column_param, &where_param);

	zephir_get_strval(table, table_param);
	zephir_get_strval(column, column_param);
	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		ZVAL_STRING(where, "", 1);
	} else {
		zephir_get_strval(where, where_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "SUM", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "aggregate", NULL, 0, table, column, _0, where);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Db_DbAbstract, parseGroupedAggregation) {

	HashTable *_8;
	HashPosition _7;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *aggrs = NULL, *options = NULL;
	zval *table_param = NULL, *groupBy_param = NULL, *aggrs_param = NULL, *options_param = NULL, *orderBy = NULL, *k = NULL, *v = NULL, *a = NULL, *_0 = NULL, *_2 = NULL, *_3 = NULL, *_5 = NULL, **_9, *_11, *_10$$3 = NULL, *_15$$7 = NULL;
	zval *table = NULL, *groupBy = NULL, *where = NULL, *having = NULL, *s = NULL, *_4 = NULL, *_6 = NULL, *_13, *_12$$4, *_14$$5, *_16$$7 = NULL, *_17$$7, *_18$$8 = NULL, *_19$$8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &table_param, &groupBy_param, &aggrs_param, &options_param);

	zephir_get_strval(table, table_param);
	zephir_get_strval(groupBy, groupBy_param);
	zephir_get_arrval(aggrs, aggrs_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	ZEPHIR_INIT_VAR(a);
	array_init(a);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "where", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_0, yb_std_ce, "valueat", &_1, 9, options, _2, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_get_strval(_4, _0);
	ZEPHIR_CPY_WRT(where, _4);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "having", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_5, yb_std_ce, "valueat", &_1, 9, options, _2, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_get_strval(_6, _5);
	ZEPHIR_CPY_WRT(having, _6);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "orderBy", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&orderBy, yb_std_ce, "valueat", &_1, 9, options, _2, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_array_append(&a, groupBy, PH_SEPARATE, "yb/db/dbabstract.zep", 506);
	zephir_is_iterable(aggrs, &_8, &_7, 0, 0, "yb/db/dbabstract.zep", 512);
	for (
	  ; zephir_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
	  ; zephir_hash_move_forward_ex(_8, &_7)
	) {
		ZEPHIR_GET_HMKEY(k, _8, _7);
		ZEPHIR_GET_HVALUE(v, _9);
		ZEPHIR_INIT_LNVAR(_10$$3);
		ZEPHIR_CONCAT_VSVSV(_10$$3, v, "(", groupBy, ") AS ", k);
		zephir_array_append(&a, _10$$3, PH_SEPARATE, "yb/db/dbabstract.zep", 509);
	}
	ZEPHIR_INIT_NVAR(_2);
	zephir_fast_join_str(_2, SL(", "), a TSRMLS_CC);
	ZEPHIR_INIT_VAR(_11);
	ZEPHIR_CONCAT_SVSV(_11, "SELECT ", _2, " FROM ", table);
	zephir_get_strval(s, _11);
	if (!(!where) && Z_STRLEN_P(where)) {
		ZEPHIR_INIT_VAR(_12$$4);
		ZEPHIR_CONCAT_SV(_12$$4, " WHERE ", where);
		zephir_concat_self(&s, _12$$4 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_13);
	ZEPHIR_CONCAT_SV(_13, " GROUP BY ", groupBy);
	zephir_concat_self(&s, _13 TSRMLS_CC);
	if (!(!having) && Z_STRLEN_P(having)) {
		ZEPHIR_INIT_VAR(_14$$5);
		ZEPHIR_CONCAT_SV(_14$$5, " HAVING ", having);
		zephir_concat_self(&s, _14$$5 TSRMLS_CC);
	}
	if (zephir_is_true(orderBy)) {
		if (ZEPHIR_IS_TRUE_IDENTICAL(orderBy)) {
			ZEPHIR_CALL_METHOD(&_15$$7, this_ptr, "randomorder", NULL, 0);
			zephir_check_call_status();
			zephir_get_strval(_16$$7, _15$$7);
			ZEPHIR_INIT_VAR(_17$$7);
			ZEPHIR_CONCAT_SV(_17$$7, " ORDER BY ", _16$$7);
			zephir_concat_self(&s, _17$$7 TSRMLS_CC);
		} else {
			zephir_get_strval(_18$$8, orderBy);
			ZEPHIR_INIT_VAR(_19$$8);
			ZEPHIR_CONCAT_SV(_19$$8, " ORDER BY ", _18$$8);
			zephir_concat_self(&s, _19$$8 TSRMLS_CC);
		}
	}
	RETURN_CTOR(s);

}

PHP_METHOD(Yb_Db_DbAbstract, queryGroupedAggregation) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *aggrs = NULL, *options = NULL;
	zval *table_param = NULL, *groupBy_param = NULL, *aggrs_param = NULL, *options_param = NULL, *_0 = NULL;
	zval *table = NULL, *groupBy = NULL, *s = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &table_param, &groupBy_param, &aggrs_param, &options_param);

	zephir_get_strval(table, table_param);
	zephir_get_strval(groupBy, groupBy_param);
	zephir_get_arrval(aggrs, aggrs_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "parsegroupedaggregation", NULL, 0, table, groupBy, aggrs, options);
	zephir_check_call_status();
	zephir_get_strval(_1, _0);
	ZEPHIR_CPY_WRT(s, _1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "queryall", NULL, 0, s);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Db_DbAbstract, tryToBegin) {

}

PHP_METHOD(Yb_Db_DbAbstract, tryToCommit) {

}

PHP_METHOD(Yb_Db_DbAbstract, tryToRollback) {

}

PHP_METHOD(Yb_Db_DbAbstract, paginateQuery) {

}

PHP_METHOD(Yb_Db_DbAbstract, randomOrder) {

}

PHP_METHOD(Yb_Db_DbAbstract, addQuery) {

	int ZEPHIR_LAST_CALL_STATUS;
	double t;
	zval *p = NULL;
	zval *q_param = NULL, *p_param = NULL, *t_param = NULL, *_0, _1, _2, *_3 = NULL;
	zval *q = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &q_param, &p_param, &t_param);

	zephir_get_strval(q, q_param);
	zephir_get_arrval(p, p_param);
	t = zephir_get_doubleval(t_param);


	ZEPHIR_INIT_VAR(_0);
	zephir_json_encode(_0, &(_0), p, 0  TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "%s # %0.3fms %s", 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_DOUBLE(&_2, (t * 1000.0));
	ZEPHIR_CALL_FUNCTION(&_3, "sprintf", NULL, 1, &_1, q, &_2, _0);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("queries"), _3 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}


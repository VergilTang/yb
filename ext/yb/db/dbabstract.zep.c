
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
		ZEPHIR_MAKE_REF(_5$$5);
		ZEPHIR_CALL_FUNCTION(&_6$$5, "array_pop", &_7, 4, _5$$5);
		ZEPHIR_UNREF(_5$$5);
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
	zval *table_param = NULL, *data_param = NULL, *returningId_param = NULL, *k = NULL, *ks = NULL, *vs = NULL, *_0, **_3, *_5, *_6, *_7, *_8 = NULL, *_4$$3 = NULL;
	zval *table = NULL, *returningId = NULL, *sql = NULL, *_9$$4;

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
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "yb/db/dbabstract.zep", 185);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(k, _3);
		zephir_array_append(&ks, k, PH_SEPARATE, "yb/db/dbabstract.zep", 181);
		ZEPHIR_INIT_LNVAR(_4$$3);
		ZEPHIR_CONCAT_SV(_4$$3, ":", k);
		zephir_array_append(&vs, _4$$3, PH_SEPARATE, "yb/db/dbabstract.zep", 182);
	}
	ZEPHIR_INIT_VAR(_5);
	zephir_fast_join_str(_5, SL(", "), ks TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	zephir_fast_join_str(_6, SL(", "), vs TSRMLS_CC);
	ZEPHIR_INIT_VAR(_7);
	ZEPHIR_CONCAT_SVSVSVS(_7, "INSERT INTO ", table, " (", _5, ") VALUES (", _6, ")");
	zephir_get_strval(sql, _7);
	if (zephir_fast_strlen_ev(returningId) > 0) {
		ZEPHIR_INIT_VAR(_9$$4);
		ZEPHIR_CONCAT_SV(_9$$4, " RETURNING ", returningId);
		zephir_concat_self(&sql, _9$$4 TSRMLS_CC);
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
	zval *where = NULL;
	zval *table_param = NULL, *where_param = NULL, *_0 = NULL, *_2 = NULL;
	zval *table = NULL, *s = NULL, *w = NULL, *_1 = NULL, *_3$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &where_param);

	zephir_get_strval(table, table_param);
	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		array_init(where);
	} else {
		zephir_get_arrval(where, where_param);
	}


	ZEPHIR_INIT_VAR(s);
	ZEPHIR_CONCAT_SV(s, "DELETE FROM ", table);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "parsewhere", NULL, 0, where);
	zephir_check_call_status();
	zephir_get_strval(_1, _0);
	ZEPHIR_CPY_WRT(w, _1);
	if (zephir_fast_strlen_ev(w) > 0) {
		ZEPHIR_INIT_VAR(_3$$3);
		ZEPHIR_CONCAT_SV(_3$$3, " WHERE ", w);
		zephir_concat_self(&s, _3$$3 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "query", NULL, 0, s);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Db_DbAbstract, update) {

	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, *where = NULL;
	zval *table_param = NULL, *data_param = NULL, *where_param = NULL, *k = NULL, *v = NULL, *kvs = NULL, *params = NULL, **_2, *_4, *_5, *_6 = NULL, *_8 = NULL, *_3$$3 = NULL;
	zval *table = NULL, *s = NULL, *w = NULL, *_7 = NULL, *_9$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &table_param, &data_param, &where_param);

	zephir_get_strval(table, table_param);
	zephir_get_arrval(data, data_param);
	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		array_init(where);
	} else {
		zephir_get_arrval(where, where_param);
	}


	ZEPHIR_INIT_VAR(kvs);
	array_init(kvs);
	ZEPHIR_INIT_VAR(params);
	array_init(params);
	zephir_is_iterable(data, &_1, &_0, 0, 0, "yb/db/dbabstract.zep", 218);
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
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "parsewhere", NULL, 0, where);
	zephir_check_call_status();
	zephir_get_strval(_7, _6);
	ZEPHIR_CPY_WRT(w, _7);
	if (zephir_fast_strlen_ev(w) > 0) {
		ZEPHIR_INIT_VAR(_9$$4);
		ZEPHIR_CONCAT_SV(_9$$4, " WHERE ", w);
		zephir_concat_self(&s, _9$$4 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "query", NULL, 0, s, params);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Db_DbAbstract, upsert) {

	HashTable *_1$$3;
	HashPosition _0$$3;
	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL;
	zval *table_param = NULL, *data_param = NULL, *primaryKey, *k = NULL, *v = NULL, *where = NULL, **_2$$3, *_3$$5 = NULL, *_4$$5 = NULL, *_7$$8, *_8$$8;
	zval *table = NULL, *_6$$7 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &table_param, &data_param, &primaryKey);

	zephir_get_strval(table, table_param);
	zephir_get_arrval(data, data_param);


	ZEPHIR_INIT_VAR(where);
	array_init(where);
	if (Z_TYPE_P(primaryKey) == IS_ARRAY) {
		zephir_is_iterable(primaryKey, &_1$$3, &_0$$3, 0, 0, "yb/db/dbabstract.zep", 238);
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
				zephir_throw_exception_debug(_3$$5, "yb/db/dbabstract.zep", 234 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_zval(&where, k, &v, PH_COPY | PH_SEPARATE);
		}
		if (unlikely(!zephir_is_true(where))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_db_exception_ce, "Cannot upsert with empty where", "yb/db/dbabstract.zep", 239);
			return;
		}
	} else {
		zephir_get_strval(_6$$7, primaryKey);
		ZEPHIR_CPY_WRT(k, _6$$7);
		ZEPHIR_OBS_NVAR(v);
		if (unlikely(!(zephir_array_isset_fetch(&v, data, k, 0 TSRMLS_CC)))) {
			ZEPHIR_INIT_VAR(_7$$8);
			object_init_ex(_7$$8, yb_db_exception_ce);
			ZEPHIR_INIT_VAR(_8$$8);
			ZEPHIR_CONCAT_SV(_8$$8, "Cannot find primary key value in data: ", k);
			ZEPHIR_CALL_METHOD(NULL, _7$$8, "__construct", &_5, 2, _8$$8);
			zephir_check_call_status();
			zephir_throw_exception_debug(_7$$8, "yb/db/dbabstract.zep", 244 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_zval(&where, k, &v, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "delete", NULL, 0, table, where);
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
	zval *options = NULL, *_6 = NULL;
	zval *table_param = NULL, *options_param = NULL, *where = NULL, *orderBy = NULL, *_0 = NULL, *_2 = NULL, *_3 = NULL, *_5 = NULL, *_7 = NULL, *_8 = NULL, *_9 = NULL, *_10 = NULL, *_13 = NULL, *_15$$7 = NULL, *_20$$9 = NULL, *_21$$9, *_22$$9;
	zval *table = NULL, *field = NULL, *w = NULL, *s = NULL, *_4 = NULL, *_11, *_12 = NULL, *_14$$5, *_16$$7 = NULL, *_17$$7, *_18$$8 = NULL, *_19$$8, *_23$$9 = NULL;

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
	ZEPHIR_CALL_CE_STATIC(&_0, yb_std_ce, "valueat", &_1, 5, options, _2, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_get_strval(_4, _0);
	ZEPHIR_CPY_WRT(field, _4);
	ZEPHIR_INIT_NVAR(_2);
	array_init(_2);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "where", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_5, yb_std_ce, "valueat", &_1, 5, options, _3, _2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_get_arrval(_6, _5);
	ZEPHIR_CPY_WRT(where, _6);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "orderBy", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_7);
	ZVAL_STRING(_7, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&orderBy, yb_std_ce, "valueat", &_1, 5, options, _3, _7);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_7);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "limit", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_7);
	ZVAL_LONG(_7, 0);
	ZEPHIR_CALL_CE_STATIC(&_8, yb_std_ce, "valueat", &_1, 5, options, _3, _7);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	limit = zephir_get_intval(_8);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "offset", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_7);
	ZVAL_LONG(_7, 0);
	ZEPHIR_CALL_CE_STATIC(&_9, yb_std_ce, "valueat", &_1, 5, options, _3, _7);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	offset = zephir_get_intval(_9);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "forUpdate", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_7);
	ZVAL_BOOL(_7, 0);
	ZEPHIR_CALL_CE_STATIC(&_10, yb_std_ce, "valueat", &_1, 5, options, _3, _7);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	forUpdate = zephir_get_boolval(_10);
	if (!(!field) && Z_STRLEN_P(field)) {
		zephir_concat_self(&s, field TSRMLS_CC);
	} else {
		zephir_concat_self_str(&s, "*", sizeof("*")-1 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_11);
	ZEPHIR_CONCAT_SV(_11, " FROM ", table);
	zephir_concat_self(&s, _11 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "parsewhere", NULL, 0, where);
	zephir_check_call_status();
	zephir_get_strval(_12, _10);
	ZEPHIR_CPY_WRT(w, _12);
	if (zephir_fast_strlen_ev(w) > 0) {
		ZEPHIR_INIT_VAR(_14$$5);
		ZEPHIR_CONCAT_SV(_14$$5, " WHERE ", w);
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
			offset = 0;
		} else {
			zephir_get_strval(_18$$8, orderBy);
			ZEPHIR_INIT_VAR(_19$$8);
			ZEPHIR_CONCAT_SV(_19$$8, " ORDER BY ", _18$$8);
			zephir_concat_self(&s, _19$$8 TSRMLS_CC);
		}
	}
	if (limit > 0) {
		ZEPHIR_INIT_VAR(_21$$9);
		ZVAL_LONG(_21$$9, limit);
		ZEPHIR_INIT_VAR(_22$$9);
		ZVAL_LONG(_22$$9, offset);
		ZEPHIR_CALL_METHOD(&_20$$9, this_ptr, "paginatequery", NULL, 0, s, _21$$9, _22$$9);
		zephir_check_call_status();
		zephir_get_strval(_23$$9, _20$$9);
		ZEPHIR_CPY_WRT(s, _23$$9);
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
	zval *options = NULL, *_4 = NULL;
	zval *table_param = NULL, *options_param = NULL, *where = NULL, *_0 = NULL, *_2, *_3 = NULL, *_5 = NULL, *_7 = NULL, *_9 = NULL, *_11 = NULL, *_10$$4 = NULL;
	zval *table = NULL, *s = NULL, *w = NULL, *_6 = NULL, *_8$$3;

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
	array_init(_2);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "where", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_0, yb_std_ce, "valueat", &_1, 5, options, _3, _2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_get_arrval(_4, _0);
	ZEPHIR_CPY_WRT(where, _4);
	ZEPHIR_INIT_VAR(s);
	ZEPHIR_CONCAT_SV(s, "SELECT COUNT(*) FROM ", table);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "parsewhere", NULL, 0, where);
	zephir_check_call_status();
	zephir_get_strval(_6, _5);
	ZEPHIR_CPY_WRT(w, _6);
	if (zephir_fast_strlen_ev(w) > 0) {
		ZEPHIR_INIT_VAR(_8$$3);
		ZEPHIR_CONCAT_SV(_8$$3, " WHERE ", w);
		zephir_concat_self(&s, _8$$3 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "querycell", NULL, 0, s);
	zephir_check_call_status();
	c = zephir_get_intval(_9);
	if (c < 1) {
		zephir_create_array(return_value, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_10$$4);
		ZVAL_LONG(_10$$4, 0);
		zephir_array_fast_append(return_value, _10$$4);
		ZEPHIR_INIT_NVAR(_10$$4);
		array_init(_10$$4);
		zephir_array_fast_append(return_value, _10$$4);
		RETURN_MM();
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_LONG(_3, c);
	zephir_array_fast_append(return_value, _3);
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "selectall", NULL, 0, table, options);
	zephir_check_call_status();
	zephir_array_fast_append(return_value, _11);
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
	zephir_is_iterable(selects, &_1, &_0, 0, 0, "yb/db/dbabstract.zep", 372);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(i, _2);
		ZEPHIR_INIT_LNVAR(_3$$4);
		ZEPHIR_CONCAT_SVS(_3$$4, "(", i, ")");
		zephir_array_append(&a, _3$$4, PH_SEPARATE, "yb/db/dbabstract.zep", 369);
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
	zephir_is_iterable(selects, &_2, &_1, 0, 0, "yb/db/dbabstract.zep", 412);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(i, _3);
		ZEPHIR_INIT_LNVAR(_4$$4);
		ZEPHIR_CONCAT_SVS(_4$$4, "(", i, ")");
		zephir_array_append(&a, _4$$4, PH_SEPARATE, "yb/db/dbabstract.zep", 409);
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
	int ZEPHIR_LAST_CALL_STATUS;
	zval *aggregations = NULL, *where = NULL;
	zval *table_param = NULL, *aggregations_param = NULL, *where_param = NULL, *k = NULL, *v = NULL, *a = NULL, **_2, *_4, *_5, *_6 = NULL, *_8 = NULL, *_3$$3 = NULL;
	zval *table = NULL, *s = NULL, *w = NULL, *_7 = NULL, *_9$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &table_param, &aggregations_param, &where_param);

	zephir_get_strval(table, table_param);
	zephir_get_arrval(aggregations, aggregations_param);
	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		array_init(where);
	} else {
		zephir_get_arrval(where, where_param);
	}


	ZEPHIR_INIT_VAR(a);
	array_init(a);
	zephir_is_iterable(aggregations, &_1, &_0, 0, 0, "yb/db/dbabstract.zep", 434);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		ZEPHIR_INIT_LNVAR(_3$$3);
		ZEPHIR_CONCAT_VSV(_3$$3, v, " AS ", k);
		zephir_array_append(&a, _3$$3, PH_SEPARATE, "yb/db/dbabstract.zep", 431);
	}
	ZEPHIR_INIT_VAR(_4);
	zephir_fast_join_str(_4, SL(", "), a TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_SVSV(_5, "SELECT ", _4, " FROM ", table);
	zephir_get_strval(s, _5);
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "parsewhere", NULL, 0, where);
	zephir_check_call_status();
	zephir_get_strval(_7, _6);
	ZEPHIR_CPY_WRT(w, _7);
	if (zephir_fast_strlen_ev(w) > 0) {
		ZEPHIR_INIT_VAR(_9$$4);
		ZEPHIR_CONCAT_SV(_9$$4, " WHERE ", w);
		zephir_concat_self(&s, _9$$4 TSRMLS_CC);
	}
	RETURN_CTOR(s);

}

PHP_METHOD(Yb_Db_DbAbstract, queryAggregation) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *aggregations = NULL, *where = NULL;
	zval *table_param = NULL, *aggregations_param = NULL, *where_param = NULL, *_0 = NULL;
	zval *table = NULL, *s = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &table_param, &aggregations_param, &where_param);

	zephir_get_strval(table, table_param);
	zephir_get_arrval(aggregations, aggregations_param);
	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		array_init(where);
	} else {
		zephir_get_arrval(where, where_param);
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
	zval *where = NULL;
	zval *table_param = NULL, *column_param = NULL, *aggregation_param = NULL, *where_param = NULL, *_0 = NULL, *_2 = NULL;
	zval *table = NULL, *column = NULL, *aggregation = NULL, *s = NULL, *w = NULL, *_1 = NULL, *_3$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &table_param, &column_param, &aggregation_param, &where_param);

	zephir_get_strval(table, table_param);
	zephir_get_strval(column, column_param);
	zephir_get_strval(aggregation, aggregation_param);
	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		array_init(where);
	} else {
		zephir_get_arrval(where, where_param);
	}


	ZEPHIR_INIT_VAR(s);
	ZEPHIR_CONCAT_SVSVSV(s, "SELECT ", aggregation, "(", column, ") FROM ", table);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "parsewhere", NULL, 0, where);
	zephir_check_call_status();
	zephir_get_strval(_1, _0);
	ZEPHIR_CPY_WRT(w, _1);
	if (zephir_fast_strlen_ev(w) > 0) {
		ZEPHIR_INIT_VAR(_3$$3);
		ZEPHIR_CONCAT_SV(_3$$3, " WHERE ", w);
		zephir_concat_self(&s, _3$$3 TSRMLS_CC);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "querycell", NULL, 0, s);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Db_DbAbstract, count) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *where = NULL;
	zval *table_param = NULL, *column_param = NULL, *where_param = NULL, *_0 = NULL, *_1;
	zval *table = NULL, *column = NULL;

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
		array_init(where);
	} else {
		zephir_get_arrval(where, where_param);
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
	zval *where = NULL;
	zval *table_param = NULL, *column_param = NULL, *where_param = NULL, *_0;
	zval *table = NULL, *column = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &table_param, &column_param, &where_param);

	zephir_get_strval(table, table_param);
	zephir_get_strval(column, column_param);
	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		array_init(where);
	} else {
		zephir_get_arrval(where, where_param);
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
	zval *where = NULL;
	zval *table_param = NULL, *column_param = NULL, *where_param = NULL, *_0;
	zval *table = NULL, *column = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &table_param, &column_param, &where_param);

	zephir_get_strval(table, table_param);
	zephir_get_strval(column, column_param);
	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		array_init(where);
	} else {
		zephir_get_arrval(where, where_param);
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
	zval *where = NULL;
	zval *table_param = NULL, *column_param = NULL, *where_param = NULL, *_0;
	zval *table = NULL, *column = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &table_param, &column_param, &where_param);

	zephir_get_strval(table, table_param);
	zephir_get_strval(column, column_param);
	if (!where_param) {
		ZEPHIR_INIT_VAR(where);
		array_init(where);
	} else {
		zephir_get_arrval(where, where_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "SUM", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "aggregate", NULL, 0, table, column, _0, where);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Db_DbAbstract, parseGroupedAggregation) {

	HashTable *_10;
	HashPosition _9;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_15 = NULL;
	zval *aggrs = NULL, *options = NULL, *_4 = NULL, *_7 = NULL;
	zval *table_param = NULL, *groupBy_param = NULL, *aggrs_param = NULL, *options_param = NULL, *where = NULL, *having = NULL, *orderBy = NULL, *k = NULL, *v = NULL, *a = NULL, *_0 = NULL, *_2, *_3 = NULL, *_5 = NULL, *_6 = NULL, *_8, **_11, *_13, *_14 = NULL, *_17 = NULL, *_20 = NULL, *_22 = NULL, *_12$$3 = NULL, *_24$$7 = NULL;
	zval *table = NULL, *groupBy = NULL, *s = NULL, *w = NULL, *_16 = NULL, *_19, *_21 = NULL, *_18$$4, *_23$$5, *_25$$7 = NULL, *_26$$7, *_27$$8 = NULL, *_28$$8;

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
	array_init(_2);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "where", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_0, yb_std_ce, "valueat", &_1, 5, options, _3, _2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_get_arrval(_4, _0);
	ZEPHIR_CPY_WRT(where, _4);
	ZEPHIR_INIT_NVAR(_3);
	array_init(_3);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_STRING(_6, "having", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_5, yb_std_ce, "valueat", &_1, 5, options, _6, _3);
	zephir_check_temp_parameter(_6);
	zephir_check_call_status();
	zephir_get_arrval(_7, _5);
	ZEPHIR_CPY_WRT(having, _7);
	ZEPHIR_INIT_NVAR(_6);
	ZVAL_STRING(_6, "orderBy", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_8);
	ZVAL_STRING(_8, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&orderBy, yb_std_ce, "valueat", &_1, 5, options, _6, _8);
	zephir_check_temp_parameter(_6);
	zephir_check_temp_parameter(_8);
	zephir_check_call_status();
	zephir_array_append(&a, groupBy, PH_SEPARATE, "yb/db/dbabstract.zep", 497);
	zephir_is_iterable(aggrs, &_10, &_9, 0, 0, "yb/db/dbabstract.zep", 503);
	for (
	  ; zephir_hash_get_current_data_ex(_10, (void**) &_11, &_9) == SUCCESS
	  ; zephir_hash_move_forward_ex(_10, &_9)
	) {
		ZEPHIR_GET_HMKEY(k, _10, _9);
		ZEPHIR_GET_HVALUE(v, _11);
		ZEPHIR_INIT_LNVAR(_12$$3);
		ZEPHIR_CONCAT_VSVSV(_12$$3, v, "(", groupBy, ") AS ", k);
		zephir_array_append(&a, _12$$3, PH_SEPARATE, "yb/db/dbabstract.zep", 500);
	}
	ZEPHIR_INIT_NVAR(_6);
	zephir_fast_join_str(_6, SL(", "), a TSRMLS_CC);
	ZEPHIR_INIT_VAR(_13);
	ZEPHIR_CONCAT_SVSV(_13, "SELECT ", _6, " FROM ", table);
	zephir_get_strval(s, _13);
	ZEPHIR_CALL_METHOD(&_14, this_ptr, "parsewhere", &_15, 0, where);
	zephir_check_call_status();
	zephir_get_strval(_16, _14);
	ZEPHIR_CPY_WRT(w, _16);
	if (zephir_fast_strlen_ev(w) > 0) {
		ZEPHIR_INIT_VAR(_18$$4);
		ZEPHIR_CONCAT_SV(_18$$4, " WHERE ", w);
		zephir_concat_self(&s, _18$$4 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_19);
	ZEPHIR_CONCAT_SV(_19, " GROUP BY ", groupBy);
	zephir_concat_self(&s, _19 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_20, this_ptr, "parsewhere", &_15, 0, having);
	zephir_check_call_status();
	zephir_get_strval(_21, _20);
	ZEPHIR_CPY_WRT(w, _21);
	if (zephir_fast_strlen_ev(w) > 0) {
		ZEPHIR_INIT_VAR(_23$$5);
		ZEPHIR_CONCAT_SV(_23$$5, " HAVING ", w);
		zephir_concat_self(&s, _23$$5 TSRMLS_CC);
	}
	if (zephir_is_true(orderBy)) {
		if (ZEPHIR_IS_TRUE_IDENTICAL(orderBy)) {
			ZEPHIR_CALL_METHOD(&_24$$7, this_ptr, "randomorder", NULL, 0);
			zephir_check_call_status();
			zephir_get_strval(_25$$7, _24$$7);
			ZEPHIR_INIT_VAR(_26$$7);
			ZEPHIR_CONCAT_SV(_26$$7, " ORDER BY ", _25$$7);
			zephir_concat_self(&s, _26$$7 TSRMLS_CC);
		} else {
			zephir_get_strval(_27$$8, orderBy);
			ZEPHIR_INIT_VAR(_28$$8);
			ZEPHIR_CONCAT_SV(_28$$8, " ORDER BY ", _27$$8);
			zephir_concat_self(&s, _28$$8 TSRMLS_CC);
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

PHP_METHOD(Yb_Db_DbAbstract, parseWhere) {

	zend_bool _23$$15, _24$$15, _32$$20, _48$$28, _63$$31, _68$$33, _72$$35;
	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL, *_10 = NULL, *_39 = NULL, *_42 = NULL, *_61 = NULL, *_66 = NULL, *_78 = NULL;
	zval *sep = NULL, *k1 = NULL, *k2 = NULL, *tmp = NULL, *_5$$3 = NULL, *_7$$3 = NULL, *_8$$5 = NULL, *_12$$8 = NULL, *_45$$26 = NULL, *_54$$28 = NULL, *_55$$28 = NULL, *_77$$37 = NULL;
	zval *where_param = NULL, *sep_param = NULL, *k = NULL, *v = NULL, *ks = NULL, *ws = NULL, **_2, *_3$$3 = NULL, *_6$$3 = NULL, *_9$$6 = NULL, *_11$$6 = NULL, *_13$$9 = NULL, *_14$$9 = NULL, *_15$$10 = NULL, *_16$$10 = NULL, *_17$$11 = NULL, *_18$$11 = NULL, *_19$$12 = NULL, *_20$$12 = NULL, *_21$$13 = NULL, *_22$$13 = NULL, *_25$$15 = NULL, *_26$$15, *_27$$15 = NULL, *_28$$15, *_29$$15 = NULL, *_30$$18 = NULL, *_31$$18 = NULL, _33$$20 = zval_used_for_init, *_34$$20 = NULL, *_35$$22 = NULL, *_37$$22 = NULL, *_38$$22 = NULL, *_40$$22 = NULL, *_41$$23 = NULL, _43$$25 = zval_used_for_init, *_44$$25 = NULL, *_46$$25 = NULL, *_47$$27 = NULL, *_49$$28 = NULL, *_51$$28 = NULL, *_53$$28 = NULL, *_56$$28 = NULL, *_58$$30 = NULL, *_59$$30 = NULL, *_60$$30 = NULL, *_62$$30 = NULL, *_64$$31 = NULL, *_65$$31 = NULL, *_67$$31 = NULL, *_69$$33 = NULL, *_70$$33 = NULL, *_71$$33 = NULL, *_73$$35 = NULL, *_74$$35 = NULL, *_75$$35 = NULL, *_76$$37 = NULL;
	zval *where = NULL, *_36$$22 = NULL, *_50$$28 = NULL, *_52$$28 = NULL, *_57$$30 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &where_param, &sep_param);

	zephir_get_arrval(where, where_param);
	if (!sep_param) {
		ZEPHIR_INIT_VAR(sep);
		ZVAL_STRING(sep, " AND ", 1);
	} else {
		zephir_get_strval(sep, sep_param);
	}


	ZEPHIR_INIT_VAR(ws);
	array_init(ws);
	zephir_is_iterable(where, &_1, &_0, 0, 0, "yb/db/dbabstract.zep", 646);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		ZEPHIR_INIT_NVAR(ks);
		zephir_fast_explode_str(ks, SL("$"), k, LONG_MAX TSRMLS_CC);
		ZEPHIR_MAKE_REF(ks);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "array_shift", &_4, 6, ks);
		ZEPHIR_UNREF(ks);
		zephir_check_call_status();
		zephir_get_strval(_5$$3, _3$$3);
		ZEPHIR_CPY_WRT(k1, _5$$3);
		ZEPHIR_MAKE_REF(ks);
		ZEPHIR_CALL_FUNCTION(&_6$$3, "array_shift", &_4, 6, ks);
		ZEPHIR_UNREF(ks);
		zephir_check_call_status();
		zephir_get_strval(_7$$3, _6$$3);
		ZEPHIR_CPY_WRT(k2, _7$$3);
		ZEPHIR_INIT_NVAR(tmp);
		ZVAL_EMPTY_STRING(tmp);
		do {
			if (ZEPHIR_IS_STRING(k2, "")) {
				if (Z_TYPE_P(v) == IS_NULL) {
					ZEPHIR_INIT_LNVAR(_8$$5);
					ZEPHIR_CONCAT_VS(_8$$5, k1, " IS NULL");
					zephir_array_append(&ws, _8$$5, PH_SEPARATE, "yb/db/dbabstract.zep", 550);
				} else {
					ZEPHIR_CALL_METHOD(&_9$$6, this_ptr, "quote", &_10, 0, v);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_11$$6);
					ZEPHIR_CONCAT_VSV(_11$$6, k1, " = ", _9$$6);
					zephir_array_append(&ws, _11$$6, PH_SEPARATE, "yb/db/dbabstract.zep", 552);
				}
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "neq")) {
				if (Z_TYPE_P(v) == IS_NULL) {
					ZEPHIR_INIT_LNVAR(_12$$8);
					ZEPHIR_CONCAT_VS(_12$$8, k1, "IS NOT NULL");
					zephir_array_append(&ws, _12$$8, PH_SEPARATE, "yb/db/dbabstract.zep", 557);
				} else {
					ZEPHIR_CALL_METHOD(&_13$$9, this_ptr, "quote", &_10, 0, v);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_14$$9);
					ZEPHIR_CONCAT_VSV(_14$$9, k1, " <> ", _13$$9);
					zephir_array_append(&ws, _14$$9, PH_SEPARATE, "yb/db/dbabstract.zep", 559);
				}
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "lt")) {
				ZEPHIR_CALL_METHOD(&_15$$10, this_ptr, "quote", &_10, 0, v);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_16$$10);
				ZEPHIR_CONCAT_VSV(_16$$10, k1, " < ", _15$$10);
				zephir_array_append(&ws, _16$$10, PH_SEPARATE, "yb/db/dbabstract.zep", 563);
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "lte")) {
				ZEPHIR_CALL_METHOD(&_17$$11, this_ptr, "quote", &_10, 0, v);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_18$$11);
				ZEPHIR_CONCAT_VSV(_18$$11, k1, " <= ", _17$$11);
				zephir_array_append(&ws, _18$$11, PH_SEPARATE, "yb/db/dbabstract.zep", 566);
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "gt")) {
				ZEPHIR_CALL_METHOD(&_19$$12, this_ptr, "quote", &_10, 0, v);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_20$$12);
				ZEPHIR_CONCAT_VSV(_20$$12, k1, " > ", _19$$12);
				zephir_array_append(&ws, _20$$12, PH_SEPARATE, "yb/db/dbabstract.zep", 569);
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "gte")) {
				ZEPHIR_CALL_METHOD(&_21$$13, this_ptr, "quote", &_10, 0, v);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_22$$13);
				ZEPHIR_CONCAT_VSV(_22$$13, k1, " >= ", _21$$13);
				zephir_array_append(&ws, _22$$13, PH_SEPARATE, "yb/db/dbabstract.zep", 572);
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "notBetween")) {
				ZEPHIR_INIT_NVAR(tmp);
				ZVAL_STRING(tmp, " NOT", 1);
			}
			if (ZEPHIR_IS_STRING(k2, "between")) {
				_23$$15 = Z_TYPE_P(v) != IS_ARRAY;
				if (!(_23$$15)) {
					_23$$15 = !(zephir_array_isset_long(v, 0));
				}
				_24$$15 = _23$$15;
				if (!(_24$$15)) {
					_24$$15 = !(zephir_array_isset_long(v, 1));
				}
				if (unlikely(_24$$15)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_db_exception_ce, "Invalid between", "yb/db/dbabstract.zep", 578);
					return;
				}
				zephir_array_fetch_long(&_26$$15, v, 0, PH_NOISY | PH_READONLY, "yb/db/dbabstract.zep", 580 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_25$$15, this_ptr, "quote", &_10, 0, _26$$15);
				zephir_check_call_status();
				zephir_array_fetch_long(&_28$$15, v, 1, PH_NOISY | PH_READONLY, "yb/db/dbabstract.zep", 580 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_27$$15, this_ptr, "quote", &_10, 0, _28$$15);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_29$$15);
				ZEPHIR_CONCAT_VVSVSV(_29$$15, k1, tmp, " BETWEEN ", _25$$15, " AND ", _27$$15);
				zephir_array_append(&ws, _29$$15, PH_SEPARATE, "yb/db/dbabstract.zep", 580);
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "notLike")) {
				ZEPHIR_INIT_NVAR(tmp);
				ZVAL_STRING(tmp, " NOT", 1);
			}
			if (ZEPHIR_IS_STRING(k2, "like")) {
				ZEPHIR_CALL_METHOD(&_30$$18, this_ptr, "quote", &_10, 0, v);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_31$$18);
				ZEPHIR_CONCAT_VVSV(_31$$18, k1, tmp, " LIKE ", _30$$18);
				zephir_array_append(&ws, _31$$18, PH_SEPARATE, "yb/db/dbabstract.zep", 585);
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "notIn")) {
				ZEPHIR_INIT_NVAR(tmp);
				ZVAL_STRING(tmp, " NOT", 1);
			}
			if (ZEPHIR_IS_STRING(k2, "in")) {
				_32$$20 = Z_TYPE_P(v) != IS_ARRAY;
				if (!(_32$$20)) {
					_32$$20 = zephir_fast_count_int(v TSRMLS_CC) < 1;
				}
				if (unlikely(_32$$20)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_db_exception_ce, "Invalid in", "yb/db/dbabstract.zep", 591);
					return;
				}
				ZEPHIR_SINIT_NVAR(_33$$20);
				ZVAL_STRING(&_33$$20, ",", 0);
				ZEPHIR_INIT_NVAR(_34$$20);
				zephir_fast_strpos(_34$$20, k1, &_33$$20, 0 );
				if (ZEPHIR_IS_FALSE_IDENTICAL(_34$$20)) {
					ZEPHIR_INIT_NVAR(_35$$22);
					ZEPHIR_INIT_NVAR(_36$$22);
					zephir_create_array(_36$$22, 2, 0 TSRMLS_CC);
					zephir_array_fast_append(_36$$22, this_ptr);
					ZEPHIR_INIT_NVAR(_37$$22);
					ZVAL_STRING(_37$$22, "quote", 1);
					zephir_array_fast_append(_36$$22, _37$$22);
					ZEPHIR_CALL_FUNCTION(&_38$$22, "array_map", &_39, 7, _36$$22, v);
					zephir_check_call_status();
					zephir_fast_join_str(_35$$22, SL(", "), _38$$22 TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_40$$22);
					ZEPHIR_CONCAT_VVSVS(_40$$22, k1, tmp, " IN (", _35$$22, ")");
					zephir_array_append(&ws, _40$$22, PH_SEPARATE, "yb/db/dbabstract.zep", 594);
				} else {
					ZEPHIR_CALL_METHOD(&_41$$23, this_ptr, "parsewheremultiplein", &_42, 0, k1, v, tmp);
					zephir_check_call_status();
					zephir_array_append(&ws, _41$$23, PH_SEPARATE, "yb/db/dbabstract.zep", 596);
				}
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "notInSelect")) {
				ZEPHIR_INIT_NVAR(tmp);
				ZVAL_STRING(tmp, " NOT", 1);
			}
			if (ZEPHIR_IS_STRING(k2, "inSelect")) {
				ZEPHIR_SINIT_NVAR(_43$$25);
				ZVAL_STRING(&_43$$25, ",", 0);
				ZEPHIR_INIT_NVAR(_44$$25);
				zephir_fast_strpos(_44$$25, k1, &_43$$25, 0 );
				if (!ZEPHIR_IS_FALSE_IDENTICAL(_44$$25)) {
					ZEPHIR_INIT_LNVAR(_45$$26);
					ZEPHIR_CONCAT_SVS(_45$$26, "(", k1, ")");
					ZEPHIR_CPY_WRT(k1, _45$$26);
				}
				ZEPHIR_INIT_LNVAR(_46$$25);
				ZEPHIR_CONCAT_VVSVS(_46$$25, k1, tmp, " IN (", v, ")");
				zephir_array_append(&ws, _46$$25, PH_SEPARATE, "yb/db/dbabstract.zep", 605);
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "raw")) {
				ZEPHIR_INIT_LNVAR(_47$$27);
				ZEPHIR_CONCAT_SVS(_47$$27, "(", v, ")");
				zephir_array_append(&ws, _47$$27, PH_SEPARATE, "yb/db/dbabstract.zep", 609);
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "expression")) {
				_48$$28 = Z_TYPE_P(v) != IS_ARRAY;
				if (!(_48$$28)) {
					_48$$28 = zephir_fast_count_int(v TSRMLS_CC) < 1;
				}
				if (unlikely(_48$$28)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_db_exception_ce, "Invalid expression", "yb/db/dbabstract.zep", 613);
					return;
				}
				ZEPHIR_INIT_NVAR(_49$$28);
				ZEPHIR_INIT_NVAR(_50$$28);
				zephir_create_array(_50$$28, 2, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_51$$28);
				ZVAL_STRING(_51$$28, "%", 1);
				zephir_array_fast_append(_50$$28, _51$$28);
				ZEPHIR_INIT_NVAR(_51$$28);
				ZVAL_STRING(_51$$28, "?", 1);
				zephir_array_fast_append(_50$$28, _51$$28);
				ZEPHIR_INIT_NVAR(_52$$28);
				zephir_create_array(_52$$28, 2, 0 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_51$$28);
				ZVAL_STRING(_51$$28, "%%", 1);
				zephir_array_fast_append(_52$$28, _51$$28);
				ZEPHIR_INIT_NVAR(_51$$28);
				ZVAL_STRING(_51$$28, "%s", 1);
				zephir_array_fast_append(_52$$28, _51$$28);
				ZEPHIR_MAKE_REF(v);
				ZEPHIR_CALL_FUNCTION(&_53$$28, "array_shift", &_4, 6, v);
				ZEPHIR_UNREF(v);
				zephir_check_call_status();
				zephir_get_strval(_54$$28, _53$$28);
				zephir_fast_str_replace(&_49$$28, _50$$28, _52$$28, _54$$28 TSRMLS_CC);
				zephir_get_strval(_55$$28, _49$$28);
				ZEPHIR_CPY_WRT(tmp, _55$$28);
				if (unlikely(zephir_fast_strlen_ev(tmp) > 0)) {
					ZEPHIR_INIT_NVAR(_57$$30);
					zephir_create_array(_57$$30, 2, 0 TSRMLS_CC);
					zephir_array_fast_append(_57$$30, this_ptr);
					ZEPHIR_INIT_NVAR(_58$$30);
					ZVAL_STRING(_58$$30, "quote", 1);
					zephir_array_fast_append(_57$$30, _58$$30);
					ZEPHIR_CALL_FUNCTION(&_59$$30, "array_map", &_39, 7, _57$$30, v);
					zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(&_60$$30, "vsprintf", &_61, 8, tmp, _59$$30);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_62$$30);
					ZEPHIR_CONCAT_SVS(_62$$30, "(", _60$$30, ")");
					zephir_array_append(&ws, _62$$30, PH_SEPARATE, "yb/db/dbabstract.zep", 618);
				}
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "and")) {
				_63$$31 = Z_TYPE_P(v) != IS_ARRAY;
				if (!(_63$$31)) {
					_63$$31 = zephir_fast_count_int(v TSRMLS_CC) < 1;
				}
				if (unlikely(_63$$31)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_db_exception_ce, "Invalid and", "yb/db/dbabstract.zep", 624);
					return;
				}
				ZEPHIR_INIT_NVAR(_65$$31);
				ZVAL_STRING(_65$$31, " AND ", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_64$$31, this_ptr, "parsewhere", &_66, 9, v, _65$$31);
				zephir_check_temp_parameter(_65$$31);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_67$$31);
				ZEPHIR_CONCAT_SVS(_67$$31, "(", _64$$31, ")");
				zephir_array_append(&ws, _67$$31, PH_SEPARATE, "yb/db/dbabstract.zep", 626);
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "or")) {
				_68$$33 = Z_TYPE_P(v) != IS_ARRAY;
				if (!(_68$$33)) {
					_68$$33 = zephir_fast_count_int(v TSRMLS_CC) < 1;
				}
				if (unlikely(_68$$33)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_db_exception_ce, "Invalid or", "yb/db/dbabstract.zep", 630);
					return;
				}
				ZEPHIR_INIT_NVAR(_70$$33);
				ZVAL_STRING(_70$$33, " OR ", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_69$$33, this_ptr, "parsewhere", &_66, 9, v, _70$$33);
				zephir_check_temp_parameter(_70$$33);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_71$$33);
				ZEPHIR_CONCAT_SVS(_71$$33, "(", _69$$33, ")");
				zephir_array_append(&ws, _71$$33, PH_SEPARATE, "yb/db/dbabstract.zep", 632);
				break;
			}
			if (ZEPHIR_IS_STRING(k2, "xor")) {
				_72$$35 = Z_TYPE_P(v) != IS_ARRAY;
				if (!(_72$$35)) {
					_72$$35 = zephir_fast_count_int(v TSRMLS_CC) < 1;
				}
				if (unlikely(_72$$35)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_db_exception_ce, "Invalid xor", "yb/db/dbabstract.zep", 636);
					return;
				}
				ZEPHIR_INIT_NVAR(_74$$35);
				ZVAL_STRING(_74$$35, " XOR ", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(&_73$$35, this_ptr, "parsewhere", &_66, 9, v, _74$$35);
				zephir_check_temp_parameter(_74$$35);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_75$$35);
				ZEPHIR_CONCAT_SVS(_75$$35, "(", _73$$35, ")");
				zephir_array_append(&ws, _75$$35, PH_SEPARATE, "yb/db/dbabstract.zep", 638);
				break;
			}
			ZEPHIR_INIT_NVAR(_76$$37);
			object_init_ex(_76$$37, yb_db_exception_ce);
			ZEPHIR_INIT_LNVAR(_77$$37);
			ZEPHIR_CONCAT_SV(_77$$37, "Invalid k2: ", k2);
			ZEPHIR_CALL_METHOD(NULL, _76$$37, "__construct", &_78, 2, _77$$37);
			zephir_check_call_status();
			zephir_throw_exception_debug(_76$$37, "yb/db/dbabstract.zep", 642 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		} while(0);

	}
	zephir_fast_join(return_value, sep, ws TSRMLS_CC);
	RETURN_MM();

}

PHP_METHOD(Yb_Db_DbAbstract, parseWhereMultipleIn) {

	zend_bool _8$$4;
	HashTable *_6;
	HashPosition _5;
	long c = 0;
	zephir_fcall_cache_entry *_13 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *values = NULL;
	zval *columns_param = NULL, *values_param = NULL, *isNot_param = NULL, *k = NULL, *v = NULL, *vs = NULL, *quoter = NULL, _0, *_1 = NULL, *_4 = NULL, **_7, *_2$$3, *_11$$4 = NULL, *_12$$4 = NULL, *_14$$4 = NULL, *_9$$5 = NULL, *_10$$5 = NULL;
	zval *columns = NULL, *isNot = NULL, *_3$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &columns_param, &values_param, &isNot_param);

	zephir_get_strval(columns, columns_param);
	zephir_get_arrval(values, values_param);
	if (!isNot_param) {
		ZEPHIR_INIT_VAR(isNot);
		ZVAL_STRING(isNot, "", 1);
	} else {
		zephir_get_strval(isNot, isNot_param);
	}


	ZEPHIR_INIT_VAR(vs);
	array_init(vs);
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, ",", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "substr_count", NULL, 10, columns, &_0);
	zephir_check_call_status();
	c = (1 + zephir_get_intval(_1));
	if (unlikely(c < 2)) {
		ZEPHIR_INIT_VAR(_2$$3);
		object_init_ex(_2$$3, yb_db_exception_ce);
		ZEPHIR_INIT_VAR(_3$$3);
		ZEPHIR_CONCAT_SV(_3$$3, "Invalid multiple in columns: ", columns);
		ZEPHIR_CALL_METHOD(NULL, _2$$3, "__construct", NULL, 2, _3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2$$3, "yb/db/dbabstract.zep", 656 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(quoter);
	zephir_create_array(quoter, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(quoter, this_ptr);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "quote", 1);
	zephir_array_fast_append(quoter, _4);
	zephir_is_iterable(values, &_6, &_5, 0, 0, "yb/db/dbabstract.zep", 668);
	for (
	  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
	  ; zephir_hash_move_forward_ex(_6, &_5)
	) {
		ZEPHIR_GET_HMKEY(k, _6, _5);
		ZEPHIR_GET_HVALUE(v, _7);
		_8$$4 = Z_TYPE_P(v) != IS_ARRAY;
		if (!(_8$$4)) {
			_8$$4 = zephir_fast_count_int(v TSRMLS_CC) != 2;
		}
		if (unlikely(_8$$4)) {
			ZEPHIR_INIT_NVAR(_9$$5);
			object_init_ex(_9$$5, yb_db_exception_ce);
			ZEPHIR_INIT_LNVAR(_10$$5);
			ZEPHIR_CONCAT_SV(_10$$5, "Invalid multiple in value at: ", k);
			ZEPHIR_CALL_METHOD(NULL, _9$$5, "__construct", NULL, 2, _10$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(_9$$5, "yb/db/dbabstract.zep", 663 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(_11$$4);
		ZEPHIR_CALL_FUNCTION(&_12$$4, "array_map", &_13, 7, quoter, v);
		zephir_check_call_status();
		zephir_fast_join_str(_11$$4, SL(", "), _12$$4 TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_14$$4);
		ZEPHIR_CONCAT_SVS(_14$$4, "(", _11$$4, ")");
		zephir_array_append(&vs, _14$$4, PH_SEPARATE, "yb/db/dbabstract.zep", 665);
	}
	ZEPHIR_INIT_NVAR(_4);
	zephir_fast_join_str(_4, SL(", "), vs TSRMLS_CC);
	ZEPHIR_CONCAT_SVSVSVS(return_value, "(", columns, ")", isNot, " in (", _4, ")");
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
	zephir_fcall_cache_entry *_4 = NULL;
	double t;
	zval *p = NULL;
	zval *q_param = NULL, *p_param = NULL, *t_param = NULL, *_0$$3, _1$$3, _2$$3, *_3$$3 = NULL, _5$$4, _6$$4, *_7$$4 = NULL;
	zval *q = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &q_param, &p_param, &t_param);

	zephir_get_strval(q, q_param);
	zephir_get_arrval(p, p_param);
	t = zephir_get_doubleval(t_param);


	if (zephir_fast_count_int(p TSRMLS_CC) > 0) {
		ZEPHIR_INIT_VAR(_0$$3);
		zephir_json_encode(_0$$3, &(_0$$3), p, 0  TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_1$$3);
		ZVAL_STRING(&_1$$3, "%s # %0.3fms %s", 0);
		ZEPHIR_SINIT_VAR(_2$$3);
		ZVAL_DOUBLE(&_2$$3, (t * 1000.0));
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", &_4, 1, &_1$$3, q, &_2$$3, _0$$3);
		zephir_check_call_status();
		zephir_update_property_array_append(this_ptr, SL("queries"), _3$$3 TSRMLS_CC);
	} else {
		ZEPHIR_SINIT_VAR(_5$$4);
		ZVAL_STRING(&_5$$4, "%s # %0.3fms", 0);
		ZEPHIR_SINIT_VAR(_6$$4);
		ZVAL_DOUBLE(&_6$$4, (t * 1000.0));
		ZEPHIR_CALL_FUNCTION(&_7$$4, "sprintf", &_4, 1, &_5$$4, q, &_6$$4);
		zephir_check_call_status();
		zephir_update_property_array_append(this_ptr, SL("queries"), _7$$4 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}


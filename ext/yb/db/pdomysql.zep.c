
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
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Yb_Db_PdoMysql) {

	ZEPHIR_REGISTER_CLASS_EX(Yb\\Db, PdoMysql, yb, db_pdomysql, yb_db_pdoabstract_ce, yb_db_pdomysql_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Yb_Db_PdoMysql, insert) {

	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL;
	zval *table_param = NULL, *data_param = NULL, *returningId_param = NULL, *k = NULL, *v = NULL, *ks = NULL, *vs = NULL, *_0, **_3, *_5, *_6, *_7, *_8 = NULL, *_9, *_4$$3 = NULL;
	zval *table = NULL, *returningId = NULL, *s = NULL;

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
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "yb/db/pdomysql.zep", 15);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(k, _3);
		zephir_array_append(&ks, k, PH_SEPARATE, "yb/db/pdomysql.zep", 11);
		ZEPHIR_INIT_LNVAR(_4$$3);
		ZEPHIR_CONCAT_SV(_4$$3, ":", k);
		zephir_array_append(&vs, _4$$3, PH_SEPARATE, "yb/db/pdomysql.zep", 12);
	}
	ZEPHIR_INIT_VAR(_5);
	zephir_fast_join_str(_5, SL(", "), ks TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	zephir_fast_join_str(_6, SL(", "), vs TSRMLS_CC);
	ZEPHIR_INIT_VAR(_7);
	ZEPHIR_CONCAT_SVSVSVS(_7, "INSERT INTO ", table, " (", _5, ") VALUES (", _6, ")");
	zephir_get_strval(s, _7);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "query", NULL, 0, s, data);
	zephir_check_call_status();
	if (zephir_fast_strlen_ev(returningId) < 1) {
		RETURN_MM_NULL();
	}
	ZEPHIR_OBS_VAR(v);
	if (zephir_array_isset_fetch(&v, data, returningId, 0 TSRMLS_CC)) {
		RETURN_CCTOR(v);
	}
	ZEPHIR_INIT_VAR(_9);
	ZVAL_STRING(_9, "SELECT LAST_INSERT_ID()", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "querycell", NULL, 0, _9);
	zephir_check_temp_parameter(_9);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Db_PdoMysql, countAndSelect) {

	zval *s = NULL, *_1 = NULL, *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, *d = NULL, *_0 = NULL, *_2 = NULL, *_3, *_4 = NULL, *_6 = NULL;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	zephir_get_arrval(options, options_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "parseselect", NULL, 0, options);
	zephir_check_call_status();
	zephir_get_strval(_1, _0);
	ZEPHIR_CPY_WRT(s, _1);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "/^SELECT /i", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "SELECT SQL_CALC_FOUND_ROWS ", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_4, "preg_replace", NULL, 38, _2, _3, s);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_get_strval(_5, _4);
	ZEPHIR_CPY_WRT(s, _5);
	ZEPHIR_CALL_METHOD(&d, this_ptr, "queryall", NULL, 0, s);
	zephir_check_call_status();
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "SELECT FOUND_ROWS()", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "querycell", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_array_fast_append(return_value, _6);
	zephir_array_fast_append(return_value, d);
	RETURN_MM();

}

PHP_METHOD(Yb_Db_PdoMysql, paginateQuery) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	long limit, offset;
	zval *query_param = NULL, *limit_param = NULL, *offset_param = NULL, _0$$3, _1$$3, _3, _4, _5;
	zval *query = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &query_param, &limit_param, &offset_param);

	zephir_get_strval(query, query_param);
	limit = zephir_get_intval(limit_param);
	offset = zephir_get_intval(offset_param);


	if (offset == 0) {
		ZEPHIR_SINIT_VAR(_0$$3);
		ZVAL_STRING(&_0$$3, "%s LIMIT %d", 0);
		ZEPHIR_SINIT_VAR(_1$$3);
		ZVAL_LONG(&_1$$3, limit);
		ZEPHIR_RETURN_CALL_FUNCTION("sprintf", &_2, 1, &_0$$3, query, &_1$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "%s LIMIT %d, %d", 0);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, offset);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_LONG(&_5, limit);
	ZEPHIR_RETURN_CALL_FUNCTION("sprintf", &_2, 1, &_3, query, &_4, &_5);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Db_PdoMysql, randomOrder) {

	

	RETURN_STRING("RAND()", 1);

}


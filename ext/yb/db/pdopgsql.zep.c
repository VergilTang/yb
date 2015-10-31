
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


ZEPHIR_INIT_CLASS(Yb_Db_PdoPgsql) {

	ZEPHIR_REGISTER_CLASS_EX(Yb\\Db, PdoPgsql, yb, db_pdopgsql, yb_db_pdoabstract_ce, yb_db_pdopgsql_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Yb_Db_PdoPgsql, paginateQuery) {

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
	ZVAL_STRING(&_3, "%s LIMIT %d OFFSET %d", 0);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, limit);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_LONG(&_5, offset);
	ZEPHIR_RETURN_CALL_FUNCTION("sprintf", &_2, 1, &_3, query, &_4, &_5);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Db_PdoPgsql, randomOrder) {

	

	RETURN_STRING("RANDOM()", 1);

}


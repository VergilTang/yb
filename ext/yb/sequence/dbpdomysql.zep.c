
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
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/hash.h"


ZEPHIR_INIT_CLASS(Yb_Sequence_DbPdoMysql) {

	ZEPHIR_REGISTER_CLASS(Yb\\Sequence, DbPdoMysql, yb, sequence_dbpdomysql, yb_sequence_dbpdomysql_method_entry, 0);

	zend_declare_property_null(yb_sequence_dbpdomysql_ce, SL("mysql"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_sequence_dbpdomysql_ce, SL("table"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(yb_sequence_dbpdomysql_ce, SL("DEFAULT_TABLE"), "sequence" TSRMLS_CC);

	zend_class_implements(yb_sequence_dbpdomysql_ce TSRMLS_CC, 1, yb_sequence_sequenceinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Yb_Sequence_DbPdoMysql, tableCreationQuery) {

	zval *table_param = NULL;
	zval *table = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &table_param);

	zephir_get_strval(table, table_param);


	ZEPHIR_CONCAT_SVS(return_value, "create table ", table, " (\n                name varchar(100) not null,\n                sequence int not null auto_increment,\n                primary key (name),\n                key (name, sequence)\n            ) engine=myisam;");
	RETURN_MM();

}

PHP_METHOD(Yb_Sequence_DbPdoMysql, __construct) {

	zval *table = NULL;
	zval *mysql, *table_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &mysql, &table_param);

	if (!table_param) {
		ZEPHIR_INIT_VAR(table);
		ZVAL_STRING(table, "sequence", 1);
	} else {
		zephir_get_strval(table, table_param);
	}


	zephir_update_property_this(this_ptr, SL("mysql"), mysql TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("table"), table TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Sequence_DbPdoMysql, getNextSequence) {

	zval *_3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *_0, *_1 = NULL, *_2, *_4, *_5;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("mysql"), PH_NOISY_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("table"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	zephir_create_array(_3, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_3, SL("name"), &name, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "sequence", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_BOOL(_5, 1);
	ZEPHIR_CALL_METHOD(&_1, _0, "insert", NULL, 0, _2, _3, _4, _5);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	RETURN_MM_LONG(zephir_get_intval(_1));

}

PHP_METHOD(Yb_Sequence_DbPdoMysql, restoreSequences) {

	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *sequences_param = NULL, *name = NULL, *sequence = NULL, **_2, *_3$$3, *_5$$3 = NULL;
	zval *sequences = NULL, *_4$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sequences_param);

	zephir_get_arrval(sequences, sequences_param);


	zephir_is_iterable(sequences, &_1, &_0, 0, 0, "yb/sequence/dbpdomysql.zep", 40);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(name, _1, _0);
		ZEPHIR_GET_HVALUE(sequence, _2);
		_3$$3 = zephir_fetch_nproperty_this(this_ptr, SL("mysql"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_4$$3);
		zephir_create_array(_4$$3, 2, 0 TSRMLS_CC);
		zephir_array_update_string(&_4$$3, SL("name"), &name, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_4$$3, SL("sequence"), &sequence, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_5$$3);
		ZVAL_STRING(_5$$3, "name", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _3$$3, "replace", NULL, 0, _4$$3, _5$$3);
		zephir_check_temp_parameter(_5$$3);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}


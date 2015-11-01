
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
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/hash.h"


ZEPHIR_INIT_CLASS(Yb_Sequence_MongoCollection) {

	ZEPHIR_REGISTER_CLASS(Yb\\Sequence, MongoCollection, yb, sequence_mongocollection, yb_sequence_mongocollection_method_entry, 0);

	zend_declare_property_null(yb_sequence_mongocollection_ce, SL("mongoCollection"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(yb_sequence_mongocollection_ce TSRMLS_CC, 1, yb_sequence_sequenceinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Yb_Sequence_MongoCollection, __construct) {

	zval *mongoCollection;

	zephir_fetch_params(0, 1, 0, &mongoCollection);



	zephir_update_property_this(this_ptr, SL("mongoCollection"), mongoCollection TSRMLS_CC);

}

PHP_METHOD(Yb_Sequence_MongoCollection, getNextSequence) {

	zend_bool _5;
	zval *_1, *_2, *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *r = NULL, *s = NULL, *_0, *_4, *_6$$3;
	zval *name = NULL, *_7$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("mongoCollection"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_1, SL("_id"), &name, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	zephir_create_array(_3, 1, 0 TSRMLS_CC);
	add_assoc_long_ex(_3, SS("sequence"), 1);
	zephir_array_update_string(&_2, SL("$inc"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_3);
	zephir_create_array(_3, 2, 0 TSRMLS_CC);
	zephir_array_update_string(&_3, SL("upsert"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_3, SL("new"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_NULL(_4);
	ZEPHIR_CALL_METHOD(&r, _0, "findandmodify", NULL, 0, _1, _2, _4, _3);
	zephir_check_call_status();
	_5 = Z_TYPE_P(r) != IS_ARRAY;
	if (!(_5)) {
		ZEPHIR_OBS_VAR(s);
		_5 = !(zephir_array_isset_string_fetch(&s, r, SS("sequence"), 0 TSRMLS_CC));
	}
	if (unlikely(_5)) {
		ZEPHIR_INIT_VAR(_6$$3);
		object_init_ex(_6$$3, yb_sequence_exception_ce);
		ZEPHIR_INIT_VAR(_7$$3);
		ZEPHIR_CONCAT_SV(_7$$3, "Cannot get next sequence of: ", name);
		ZEPHIR_CALL_METHOD(NULL, _6$$3, "__construct", NULL, 2, _7$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_6$$3, "yb/sequence/mongocollection.zep", 28 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_LONG(zephir_get_intval(s));

}

PHP_METHOD(Yb_Sequence_MongoCollection, restoreSequences) {

	zval *_5$$3 = NULL;
	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *sequences_param = NULL, *name = NULL, *sequence = NULL, *options = NULL, **_2, *_3$$3;
	zval *sequences = NULL, *_4$$3 = NULL, *_6$$3 = NULL, *_7$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sequences_param);

	zephir_get_arrval(sequences, sequences_param);


	ZEPHIR_INIT_VAR(options);
	zephir_create_array(options, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&options, SL("upsert"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_is_iterable(sequences, &_1, &_0, 0, 0, "yb/sequence/mongocollection.zep", 51);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(name, _1, _0);
		ZEPHIR_GET_HVALUE(sequence, _2);
		_3$$3 = zephir_fetch_nproperty_this(this_ptr, SL("mongoCollection"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_4$$3);
		zephir_create_array(_4$$3, 1, 0 TSRMLS_CC);
		zephir_get_strval(_5$$3, name);
		zephir_array_update_string(&_4$$3, SL("_id"), &_5$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_6$$3);
		zephir_create_array(_6$$3, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_7$$3);
		zephir_create_array(_7$$3, 1, 0 TSRMLS_CC);
		add_assoc_long_ex(_7$$3, SS("sequence"), zephir_get_intval(sequence));
		zephir_array_update_string(&_6$$3, SL("$set"), &_7$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, _3$$3, "insert", NULL, 0, _4$$3, _6$$3, options);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}


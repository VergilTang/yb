
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
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/hash.h"


ZEPHIR_INIT_CLASS(Yb_Sequence_Redis) {

	ZEPHIR_REGISTER_CLASS(Yb\\Sequence, Redis, yb, sequence_redis, yb_sequence_redis_method_entry, 0);

	zend_declare_property_null(yb_sequence_redis_ce, SL("redis"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_sequence_redis_ce, SL("prefix"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(yb_sequence_redis_ce, SL("DEFAULT_PREFIX"), "sequence:" TSRMLS_CC);

	zend_class_implements(yb_sequence_redis_ce TSRMLS_CC, 1, yb_sequence_sequenceinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Yb_Sequence_Redis, __construct) {

	zval *prefix = NULL;
	zval *redis, *prefix_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &redis, &prefix_param);

	if (!prefix_param) {
		ZEPHIR_INIT_VAR(prefix);
		ZVAL_STRING(prefix, "sequence:", 1);
	} else {
		zephir_get_strval(prefix, prefix_param);
	}


	zephir_update_property_this(this_ptr, SL("redis"), redis TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("prefix"), prefix TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Sequence_Redis, getNextSequence) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *s = NULL, *_0, *_1, *_2, *_3, *_4$$3;
	zval *name = NULL, *_5$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VV(_2, _1, name);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 1);
	ZEPHIR_CALL_METHOD(&s, _0, "incr", NULL, 0, _2, _3);
	zephir_check_call_status();
	if (unlikely(ZEPHIR_IS_FALSE_IDENTICAL(s))) {
		ZEPHIR_INIT_VAR(_4$$3);
		object_init_ex(_4$$3, yb_sequence_exception_ce);
		ZEPHIR_INIT_VAR(_5$$3);
		ZEPHIR_CONCAT_SV(_5$$3, "Cannot get next sequence of: ", name);
		ZEPHIR_CALL_METHOD(NULL, _4$$3, "__construct", NULL, 2, _5$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_4$$3, "yb/sequence/redis.zep", 22 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_LONG(zephir_get_intval(s));

}

PHP_METHOD(Yb_Sequence_Redis, restoreSequences) {

	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *sequences_param = NULL, *name = NULL, *sequence = NULL, **_2, *_3$$3, *_4$$3, *_5$$3 = NULL;
	zval *sequences = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sequences_param);

	zephir_get_arrval(sequences, sequences_param);


	zephir_is_iterable(sequences, &_1, &_0, 0, 0, "yb/sequence/redis.zep", 35);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(name, _1, _0);
		ZEPHIR_GET_HVALUE(sequence, _2);
		_3$$3 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
		_4$$3 = zephir_fetch_nproperty_this(this_ptr, SL("prefix"), PH_NOISY_CC);
		ZEPHIR_INIT_LNVAR(_5$$3);
		ZEPHIR_CONCAT_VV(_5$$3, _4$$3, name);
		ZEPHIR_CALL_METHOD(NULL, _3$$3, "set", NULL, 0, _5$$3, sequence);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}


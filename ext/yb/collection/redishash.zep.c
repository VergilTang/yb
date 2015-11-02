
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Yb_Collection_RedisHash) {

	ZEPHIR_REGISTER_CLASS(Yb\\Collection, RedisHash, yb, collection_redishash, yb_collection_redishash_method_entry, 0);

	zend_declare_property_null(yb_collection_redishash_ce, SL("redis"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_collection_redishash_ce, SL("hashName"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(yb_collection_redishash_ce TSRMLS_CC, 1, yb_collection_collectioninterface_ce);
	return SUCCESS;

}

PHP_METHOD(Yb_Collection_RedisHash, __construct) {

	zval *hashName = NULL;
	zval *redis, *hashName_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &redis, &hashName_param);

	zephir_get_strval(hashName, hashName_param);


	zephir_update_property_this(this_ptr, SL("redis"), redis TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("hashName"), hashName TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Collection_RedisHash, set) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, *_0, *_1;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("hashName"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "hset", NULL, 0, _1, key, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Collection_RedisHash, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value = NULL, *_0, *_1;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("hashName"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&value, _0, "hget", NULL, 0, _1, key);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(value)) {
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(value);

}

PHP_METHOD(Yb_Collection_RedisHash, delete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *_0, *_1;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("hashName"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "hdel", NULL, 0, _1, key);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Collection_RedisHash, setMany) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyValues_param = NULL, *_0, *_1;
	zval *keyValues = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyValues_param);

	zephir_get_arrval(keyValues, keyValues_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("hashName"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "hmset", NULL, 0, _1, keyValues);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Collection_RedisHash, getMany) {

	zend_bool _5$$5;
	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keys_param = NULL, *a = NULL, *k = NULL, *v = NULL, *r = NULL, *_0, *_1, **_4;
	zval *keys = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keys_param);

	zephir_get_arrval(keys, keys_param);


	ZEPHIR_INIT_VAR(r);
	array_init(r);
	if (unlikely(zephir_fast_count_int(keys TSRMLS_CC) < 1)) {
		RETURN_CCTOR(r);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("hashName"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&a, _0, "hmget", NULL, 0, _1, keys);
	zephir_check_call_status();
	if (unlikely(Z_TYPE_P(a) != IS_ARRAY)) {
		RETURN_CCTOR(r);
	}
	zephir_is_iterable(keys, &_3, &_2, 0, 0, "yb/collection/redishash.zep", 60);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(k, _4);
		_5$$5 = zephir_array_isset_fetch(&v, a, k, 1 TSRMLS_CC);
		if (_5$$5) {
			_5$$5 = !ZEPHIR_IS_FALSE_IDENTICAL(v);
		}
		if (_5$$5) {
			zephir_array_update_zval(&r, k, &v, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(r);

}

PHP_METHOD(Yb_Collection_RedisHash, deleteMany) {

	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keys_param = NULL, *k = NULL, **_2, *_3$$3, *_4$$3;
	zval *keys = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keys_param);

	zephir_get_arrval(keys, keys_param);


	zephir_is_iterable(keys, &_1, &_0, 0, 0, "yb/collection/redishash.zep", 70);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(k, _2);
		_3$$3 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
		_4$$3 = zephir_fetch_nproperty_this(this_ptr, SL("hashName"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _3$$3, "hdel", NULL, 0, _4$$3, k);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Collection_RedisHash, setAll) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyValues_param = NULL, *_0, *_1 = NULL, *_2 = NULL, *_3, *_4 = NULL, *_5;
	zval *keyValues = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyValues_param);

	zephir_get_arrval(keyValues, keyValues_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "multi", NULL, 0);
	zephir_check_call_status();
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("hashName"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, _1, "delete", NULL, 0, _3);
	zephir_check_call_status();
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("hashName"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_4, _2, "hmset", NULL, 0, _5, keyValues);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _4, "exec", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Collection_RedisHash, getAll) {

	zval *a = NULL, *_0, *_1;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("hashName"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&a, _0, "hgetall", NULL, 0, _1);
	zephir_check_call_status();
	if (Z_TYPE_P(a) != IS_ARRAY) {
		array_init(return_value);
		RETURN_MM();
	}
	RETURN_CCTOR(a);

}

PHP_METHOD(Yb_Collection_RedisHash, deleteAll) {

	zval *_0, *_1;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("hashName"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "delete", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}


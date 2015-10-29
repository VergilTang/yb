
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/hash.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Yb_Collection_RedisHashSerialized) {

	ZEPHIR_REGISTER_CLASS_EX(Yb\\Collection, RedisHashSerialized, yb, collection_redishashserialized, yb_collection_redishash_ce, yb_collection_redishashserialized_method_entry, 0);

	zend_declare_property_null(yb_collection_redishashserialized_ce, SL("serializer"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Yb_Collection_RedisHashSerialized, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *hashName = NULL;
	zval *redis, *hashName_param = NULL, *serializer;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &redis, &hashName_param, &serializer);

	zephir_get_strval(hashName, hashName_param);


	ZEPHIR_CALL_PARENT(NULL, yb_collection_redishashserialized_ce, this_ptr, "__construct", &_0, 12, redis, hashName);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("serializer"), serializer TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Collection_RedisHashSerialized, set) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *key_param = NULL, *value, *_1, *_2 = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(key, key_param);


	_1 = zephir_fetch_nproperty_this(this_ptr, SL("serializer"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, _1, "serialize", NULL, 0, value);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, yb_collection_redishashserialized_ce, this_ptr, "set", &_0, 13, key, _2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Collection_RedisHashSerialized, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *key_param = NULL, *value = NULL, *_1;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	ZEPHIR_CALL_PARENT(&value, yb_collection_redishashserialized_ce, this_ptr, "get", &_0, 14, key);
	zephir_check_call_status();
	if (Z_TYPE_P(value) == IS_NULL) {
		RETURN_MM_NULL();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("serializer"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_1, "unserialize", NULL, 0, value);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Collection_RedisHashSerialized, setMany) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyValues_param = NULL, *k = NULL, *v = NULL, *data = NULL, **_2, *_3$$3, *_4$$3 = NULL;
	zval *keyValues = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyValues_param);

	zephir_get_arrval(keyValues, keyValues_param);


	ZEPHIR_INIT_VAR(data);
	array_init(data);
	zephir_is_iterable(keyValues, &_1, &_0, 0, 0, "yb/collection/redishashserialized.zep", 40);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		_3$$3 = zephir_fetch_nproperty_this(this_ptr, SL("serializer"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_4$$3, _3$$3, "serialize", NULL, 0, v);
		zephir_check_call_status();
		zephir_array_update_zval(&data, k, &_4$$3, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_PARENT(NULL, yb_collection_redishashserialized_ce, this_ptr, "setmany", &_5, 15, data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Collection_RedisHashSerialized, getMany) {

	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *keys_param = NULL, *a = NULL, *k = NULL, *v = NULL, *data = NULL, **_3, *_4$$3, *_5$$3 = NULL;
	zval *keys = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keys_param);

	zephir_get_arrval(keys, keys_param);


	ZEPHIR_INIT_VAR(data);
	array_init(data);
	ZEPHIR_CALL_PARENT(&a, yb_collection_redishashserialized_ce, this_ptr, "getmany", &_0, 16, keys);
	zephir_check_call_status();
	zephir_is_iterable(a, &_2, &_1, 0, 0, "yb/collection/redishashserialized.zep", 52);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(k, _2, _1);
		ZEPHIR_GET_HVALUE(v, _3);
		_4$$3 = zephir_fetch_nproperty_this(this_ptr, SL("serializer"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_5$$3, _4$$3, "unserialize", NULL, 0, v);
		zephir_check_call_status();
		zephir_array_update_zval(&data, k, &_5$$3, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(data);

}

PHP_METHOD(Yb_Collection_RedisHashSerialized, setAll) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyValues_param = NULL, *k = NULL, *v = NULL, *data = NULL, **_2, *_3$$3, *_4$$3 = NULL;
	zval *keyValues = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyValues_param);

	zephir_get_arrval(keyValues, keyValues_param);


	ZEPHIR_INIT_VAR(data);
	array_init(data);
	zephir_is_iterable(keyValues, &_1, &_0, 0, 0, "yb/collection/redishashserialized.zep", 63);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		_3$$3 = zephir_fetch_nproperty_this(this_ptr, SL("serializer"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_4$$3, _3$$3, "serialize", NULL, 0, v);
		zephir_check_call_status();
		zephir_array_update_zval(&data, k, &_4$$3, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_PARENT(NULL, yb_collection_redishashserialized_ce, this_ptr, "setall", &_5, 17, data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Collection_RedisHashSerialized, getAll) {

	HashTable *_2;
	HashPosition _1;
	zval *a = NULL, *k = NULL, *v = NULL, *data = NULL, **_3, *_4$$3, *_5$$3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(data);
	array_init(data);
	ZEPHIR_CALL_PARENT(&a, yb_collection_redishashserialized_ce, this_ptr, "getall", &_0, 18);
	zephir_check_call_status();
	zephir_is_iterable(a, &_2, &_1, 0, 0, "yb/collection/redishashserialized.zep", 75);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(k, _2, _1);
		ZEPHIR_GET_HVALUE(v, _3);
		_4$$3 = zephir_fetch_nproperty_this(this_ptr, SL("serializer"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_5$$3, _4$$3, "unserialize", NULL, 0, v);
		zephir_check_call_status();
		zephir_array_update_zval(&data, k, &_5$$3, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(data);

}


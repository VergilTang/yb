
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
#include "kernel/operators.h"
#include "kernel/hash.h"


ZEPHIR_INIT_CLASS(Yb_Collection_MongoCollection) {

	ZEPHIR_REGISTER_CLASS(Yb\\Collection, MongoCollection, yb, collection_mongocollection, yb_collection_mongocollection_method_entry, 0);

	zend_declare_property_null(yb_collection_mongocollection_ce, SL("mongoCollection"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(yb_collection_mongocollection_ce TSRMLS_CC, 1, yb_collection_collectioninterface_ce);
	return SUCCESS;

}

PHP_METHOD(Yb_Collection_MongoCollection, __construct) {

	zval *mongoCollection;

	zephir_fetch_params(0, 1, 0, &mongoCollection);



	zephir_update_property_this(this_ptr, SL("mongoCollection"), mongoCollection TSRMLS_CC);

}

PHP_METHOD(Yb_Collection_MongoCollection, set) {

	zval *_1, *_2, *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("mongoCollection"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_1, SL("_id"), &key, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	zephir_create_array(_3, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_3, SL("value"), &value, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_2, SL("$set"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_3);
	zephir_create_array(_3, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_3, SL("upsert"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, _0, "update", NULL, 0, _1, _2, _3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Collection_MongoCollection, get) {

	zend_bool _2;
	zval *_1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *row = NULL, *value = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("mongoCollection"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_1, SL("_id"), &key, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&row, _0, "findone", NULL, 0, _1);
	zephir_check_call_status();
	_2 = Z_TYPE_P(row) == IS_ARRAY;
	if (_2) {
		_2 = zephir_array_isset_string_fetch(&value, row, SS("value"), 1 TSRMLS_CC);
	}
	if (_2) {
		RETURN_CTOR(value);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Collection_MongoCollection, delete) {

	zval *_1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("mongoCollection"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_1, SL("_id"), &key, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, _0, "remove", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Collection_MongoCollection, setMany) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyValues_param = NULL, *k = NULL, *v = NULL, **_2;
	zval *keyValues = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyValues_param);

	zephir_get_arrval(keyValues, keyValues_param);


	zephir_is_iterable(keyValues, &_1, &_0, 0, 0, "yb/collection/mongocollection.zep", 52);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_3, 0, k, v);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Collection_MongoCollection, getMany) {

	HashTable *_5;
	HashPosition _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keys_param = NULL, *rows = NULL, *row = NULL, *a = NULL, *k = NULL, *v = NULL, *_0, *_3 = NULL, **_6;
	zval *keys = NULL, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keys_param);

	zephir_get_arrval(keys, keys_param);


	ZEPHIR_INIT_VAR(a);
	array_init(a);
	if (unlikely(zephir_fast_count_int(keys TSRMLS_CC) < 1)) {
		RETURN_CCTOR(a);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("mongoCollection"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_2, SL("$in"), &keys, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("_id"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&rows, _0, "find", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_3, "iterator_to_array", NULL, 29, rows);
	zephir_check_call_status();
	zephir_is_iterable(_3, &_5, &_4, 0, 0, "yb/collection/mongocollection.zep", 76);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(row, _6);
		if (zephir_array_isset_string_fetch(&k, row, SS("_id"), 1 TSRMLS_CC)) {
			if (zephir_array_isset_string_fetch(&v, row, SS("value"), 1 TSRMLS_CC)) {
				zephir_array_update_zval(&a, k, &v, PH_COPY | PH_SEPARATE);
			}
		}
	}
	RETURN_CCTOR(a);

}

PHP_METHOD(Yb_Collection_MongoCollection, deleteMany) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keys_param = NULL, *_0;
	zval *keys = NULL, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keys_param);

	zephir_get_arrval(keys, keys_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("mongoCollection"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 1, 0 TSRMLS_CC);
	zephir_array_update_string(&_2, SL("$in"), &keys, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("_id"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, _0, "remove", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Collection_MongoCollection, setAll) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyValues_param = NULL;
	zval *keyValues = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyValues_param);

	zephir_get_arrval(keyValues, keyValues_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "deleteall", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setmany", NULL, 0, keyValues);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Collection_MongoCollection, getAll) {

	HashTable *_3;
	HashPosition _2;
	zval *rows = NULL, *row = NULL, *a = NULL, *k = NULL, *v = NULL, *_0, *_1 = NULL, **_4;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(a);
	array_init(a);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("mongoCollection"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&rows, _0, "find", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "iterator_to_array", NULL, 29, rows);
	zephir_check_call_status();
	zephir_is_iterable(_1, &_3, &_2, 0, 0, "yb/collection/mongocollection.zep", 108);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(row, _4);
		if (zephir_array_isset_string_fetch(&k, row, SS("_id"), 1 TSRMLS_CC)) {
			if (zephir_array_isset_string_fetch(&v, row, SS("value"), 1 TSRMLS_CC)) {
				zephir_array_update_zval(&a, k, &v, PH_COPY | PH_SEPARATE);
			}
		}
	}
	RETURN_CCTOR(a);

}

PHP_METHOD(Yb_Collection_MongoCollection, deleteAll) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("mongoCollection"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "drop", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}


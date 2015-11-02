
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
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Yb_Collection_Proxy) {

	ZEPHIR_REGISTER_CLASS(Yb\\Collection, Proxy, yb, collection_proxy, yb_collection_proxy_method_entry, 0);

	zend_declare_property_null(yb_collection_proxy_ce, SL("frontend"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_collection_proxy_ce, SL("backend"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_null(yb_collection_proxy_ce, SL("NON_EXISTENT_VALUE") TSRMLS_CC);

	zend_class_implements(yb_collection_proxy_ce TSRMLS_CC, 1, yb_collection_collectioninterface_ce);
	return SUCCESS;

}

PHP_METHOD(Yb_Collection_Proxy, __construct) {

	zval *frontend, *backend;

	zephir_fetch_params(0, 2, 0, &frontend, &backend);



	zephir_update_property_this(this_ptr, SL("frontend"), frontend TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("backend"), backend TSRMLS_CC);

}

PHP_METHOD(Yb_Collection_Proxy, set) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, *_0, *_1;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("frontend"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "delete", NULL, 0, key);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _1, "set", NULL, 0, key, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Collection_Proxy, get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value = NULL, *_0, *_1, *_3, *_4, *_2$$5;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("frontend"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&value, _0, "get", NULL, 0, key);
	zephir_check_call_status();
	if (Z_TYPE_P(value) != IS_NULL) {
		if (Z_TYPE_P(value) != IS_NULL) {
			RETURN_CCTOR(value);
		}
		RETURN_MM_NULL();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&value, _1, "get", NULL, 0, key);
	zephir_check_call_status();
	if (Z_TYPE_P(value) != IS_NULL) {
		_2$$5 = zephir_fetch_nproperty_this(this_ptr, SL("frontend"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _2$$5, "set", NULL, 0, key, value);
		zephir_check_call_status();
		RETURN_CCTOR(value);
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("frontend"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_NULL(_4);
	ZEPHIR_CALL_METHOD(NULL, _3, "set", NULL, 0, key, _4);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Collection_Proxy, delete) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *_0, *_1, *_2;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(key, key_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("frontend"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_NULL(_1);
	ZEPHIR_CALL_METHOD(NULL, _0, "set", NULL, 0, key, _1);
	zephir_check_call_status();
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _2, "delete", NULL, 0, key);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Collection_Proxy, setMany) {

	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyValues_param = NULL, *k = NULL, *_0 = NULL, **_3, *_5, *_4$$3;
	zval *keyValues = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyValues_param);

	zephir_get_arrval(keyValues, keyValues_param);


	ZEPHIR_INIT_VAR(_0);
	zephir_is_iterable(keyValues, &_2, &_1, 0, 0, "yb/collection/proxy.zep", 57);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(k, _2, _1);
		ZEPHIR_GET_HVALUE(_0, _3);
		_4$$3 = zephir_fetch_nproperty_this(this_ptr, SL("frontend"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _4$$3, "delete", NULL, 0, k);
		zephir_check_call_status();
	}
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _5, "setmany", NULL, 0, keyValues);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Collection_Proxy, getMany) {

	HashTable *_2, *_6$$7;
	HashPosition _1, _5$$7;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keys_param = NULL, *k = NULL, *v = NULL, *a = NULL, *r = NULL, *x = NULL, *_0, **_3, *_4$$7, **_7$$7, *_8$$9, *_9$$10, *_10$$10 = NULL;
	zval *keys = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keys_param);

	zephir_get_arrval(keys, keys_param);


	ZEPHIR_INIT_VAR(r);
	array_init(r);
	ZEPHIR_INIT_VAR(x);
	array_init(x);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("frontend"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&a, _0, "getmany", NULL, 0, keys);
	zephir_check_call_status();
	zephir_is_iterable(keys, &_2, &_1, 0, 0, "yb/collection/proxy.zep", 76);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(k, _3);
		ZEPHIR_OBS_NVAR(v);
		if (zephir_array_isset_fetch(&v, a, k, 0 TSRMLS_CC)) {
			if (Z_TYPE_P(v) != IS_NULL) {
				zephir_array_update_zval(&r, k, &v, PH_COPY | PH_SEPARATE);
			}
		} else {
			zephir_array_append(&x, k, PH_SEPARATE, "yb/collection/proxy.zep", 71);
			zephir_array_update_zval(&r, k, &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
		}
	}
	if (zephir_is_true(x)) {
		_4$$7 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&a, _4$$7, "getmany", NULL, 0, x);
		zephir_check_call_status();
		zephir_is_iterable(x, &_6$$7, &_5$$7, 0, 0, "yb/collection/proxy.zep", 87);
		for (
		  ; zephir_hash_get_current_data_ex(_6$$7, (void**) &_7$$7, &_5$$7) == SUCCESS
		  ; zephir_hash_move_forward_ex(_6$$7, &_5$$7)
		) {
			ZEPHIR_GET_HVALUE(k, _7$$7);
			ZEPHIR_OBS_NVAR(v);
			if (zephir_array_isset_fetch(&v, a, k, 0 TSRMLS_CC)) {
				zephir_array_update_zval(&r, k, &v, PH_COPY | PH_SEPARATE);
				_8$$9 = zephir_fetch_nproperty_this(this_ptr, SL("frontend"), PH_NOISY_CC);
				ZEPHIR_CALL_METHOD(NULL, _8$$9, "set", NULL, 0, k, v);
				zephir_check_call_status();
			} else {
				zephir_array_unset(&r, k, PH_SEPARATE);
				_9$$10 = zephir_fetch_nproperty_this(this_ptr, SL("frontend"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(_10$$10);
				ZVAL_NULL(_10$$10);
				ZEPHIR_CALL_METHOD(NULL, _9$$10, "set", NULL, 0, k, _10$$10);
				zephir_check_call_status();
			}
		}
	}
	RETURN_CCTOR(r);

}

PHP_METHOD(Yb_Collection_Proxy, deleteMany) {

	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keys_param = NULL, *k = NULL, **_2, *_5, *_3$$3, *_4$$3 = NULL;
	zval *keys = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keys_param);

	zephir_get_arrval(keys, keys_param);


	zephir_is_iterable(keys, &_1, &_0, 0, 0, "yb/collection/proxy.zep", 100);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(k, _2);
		_3$$3 = zephir_fetch_nproperty_this(this_ptr, SL("frontend"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_4$$3);
		ZVAL_NULL(_4$$3);
		ZEPHIR_CALL_METHOD(NULL, _3$$3, "set", NULL, 0, k, _4$$3);
		zephir_check_call_status();
	}
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _5, "deletemany", NULL, 0, keys);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Collection_Proxy, setAll) {

	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *keyValues_param = NULL, *k = NULL, *_0 = NULL, **_3, *_5, *_4$$3;
	zval *keyValues = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keyValues_param);

	zephir_get_arrval(keyValues, keyValues_param);


	ZEPHIR_INIT_VAR(_0);
	zephir_is_iterable(keyValues, &_2, &_1, 0, 0, "yb/collection/proxy.zep", 111);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(k, _2, _1);
		ZEPHIR_GET_HVALUE(_0, _3);
		_4$$3 = zephir_fetch_nproperty_this(this_ptr, SL("frontend"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _4$$3, "delete", NULL, 0, k);
		zephir_check_call_status();
	}
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _5, "setall", NULL, 0, keyValues);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Collection_Proxy, getAll) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getall", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Collection_Proxy, deleteAll) {

	zval *_0, *_1;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("frontend"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "deleteall", NULL, 0);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _1, "deleteall", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}


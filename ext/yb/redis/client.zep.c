
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
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "utils.h"


ZEPHIR_INIT_CLASS(Yb_Redis_Client) {

	ZEPHIR_REGISTER_CLASS(Yb\\Redis, Client, yb, redis_client, yb_redis_client_method_entry, 0);

	zend_declare_property_null(yb_redis_client_ce, SL("slotsCacher"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_redis_client_ce, SL("timeout"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_redis_client_ce, SL("slots"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_redis_client_ce, SL("connections"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(yb_redis_client_ce, SL("DEFAULT_HOST"), "127.0.0.1" TSRMLS_CC);

	zend_declare_class_constant_long(yb_redis_client_ce, SL("DEFAULT_PORT"), 6379 TSRMLS_CC);

	zend_class_implements(yb_redis_client_ce TSRMLS_CC, 1, yb_redis_redisclientinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Yb_Redis_Client, __construct) {

	zval *host = NULL, *_6$$4 = NULL, *_8$$5 = NULL, *_12$$5 = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	long timeout, port = 0;
	zval *slotsCacher, *address = NULL, *timeout_param = NULL, *_0, *_1 = NULL, *_2$$4 = NULL, *_4$$4 = NULL, *_5$$4 = NULL, *_7$$4 = NULL, *_9$$5 = NULL, *_10$$5 = NULL, *_11$$5 = NULL, *_13$$5 = NULL, *_14$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &slotsCacher, &address, &timeout_param);

	if (!address) {
		ZEPHIR_INIT_VAR(address);
		ZVAL_STRING(address, "", 1);
	} else {
		ZEPHIR_SEPARATE_PARAM(address);
	}
	if (!timeout_param) {
		timeout = 5;
	} else {
		timeout = zephir_get_intval(timeout_param);
	}


	zephir_update_property_this(this_ptr, SL("slotsCacher"), slotsCacher TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, timeout);
	zephir_update_property_this(this_ptr, SL("timeout"), _0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_1, slotsCacher, "fetchslots", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("slots"), _1 TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("slots"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		if (Z_TYPE_P(address) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(_4$$4);
			ZVAL_STRING(_4$$4, "host", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_VAR(_5$$4);
			ZVAL_STRING(_5$$4, "127.0.0.1", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_CE_STATIC(&_2$$4, yb_std_ce, "valueat", &_3, 9, address, _4$$4, _5$$4);
			zephir_check_temp_parameter(_4$$4);
			zephir_check_temp_parameter(_5$$4);
			zephir_check_call_status();
			zephir_get_strval(_6$$4, _2$$4);
			ZEPHIR_CPY_WRT(host, _6$$4);
			ZEPHIR_INIT_NVAR(_4$$4);
			ZVAL_STRING(_4$$4, "port", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_5$$4);
			ZVAL_LONG(_5$$4, 6379);
			ZEPHIR_CALL_CE_STATIC(&_7$$4, yb_std_ce, "valueat", &_3, 9, address, _4$$4, _5$$4);
			zephir_check_temp_parameter(_4$$4);
			zephir_check_call_status();
			port = zephir_get_intval(_7$$4);
		} else {
			zephir_get_strval(_8$$5, address);
			ZEPHIR_INIT_NVAR(address);
			zephir_fast_explode_str(address, SL(":"), _8$$5, 2  TSRMLS_CC);
			ZEPHIR_INIT_VAR(_10$$5);
			ZVAL_LONG(_10$$5, 0);
			ZEPHIR_INIT_VAR(_11$$5);
			ZVAL_STRING(_11$$5, "127.0.0.1", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_CE_STATIC(&_9$$5, yb_std_ce, "valueat", &_3, 9, address, _10$$5, _11$$5);
			zephir_check_temp_parameter(_11$$5);
			zephir_check_call_status();
			zephir_get_strval(_12$$5, _9$$5);
			ZEPHIR_CPY_WRT(host, _12$$5);
			ZEPHIR_INIT_NVAR(_10$$5);
			ZVAL_LONG(_10$$5, 1);
			ZEPHIR_INIT_NVAR(_11$$5);
			ZVAL_LONG(_11$$5, 6379);
			ZEPHIR_CALL_CE_STATIC(&_13$$5, yb_std_ce, "valueat", &_3, 9, address, _10$$5, _11$$5);
			zephir_check_call_status();
			port = zephir_get_intval(_13$$5);
		}
		ZEPHIR_INIT_VAR(_14$$3);
		ZVAL_LONG(_14$$3, port);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "refleshslots", NULL, 0, host, _14$$3);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Redis_Client, runCommandByKey) {

	zend_bool _2;
	int ZEPHIR_LAST_CALL_STATUS, slot = 0;
	zval *cmd = NULL;
	zval *key_param = NULL, *cmd_param = NULL, *result = NULL, *_0 = NULL, *_1 = NULL, *_3;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &cmd_param);

	zephir_get_strval(key, key_param);
	zephir_get_arrval(cmd, cmd_param);


	slot = yb_redis_cluster_hash_slot( key);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, slot);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getconnectionbyslot", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&result, _0, "runcommand", NULL, 0, cmd);
	zephir_check_call_status();
	_2 = Z_TYPE_P(result) != IS_OBJECT;
	if (!(_2)) {
		_2 = !((zephir_instance_of_ev(result, yb_redis_error_ce TSRMLS_CC)));
	}
	if (_2) {
		RETURN_CCTOR(result);
	}
	if (zephir_instance_of_ev(result, yb_redis_errormoved_ce TSRMLS_CC)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "onmoved", NULL, 0, result, cmd);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (zephir_instance_of_ev(result, yb_redis_errorask_ce TSRMLS_CC)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "onask", NULL, 0, result, cmd);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(_1);
	object_init_ex(_1, yb_redis_exception_ce);
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property(&_3, result, SL("error"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 2, _3);
	zephir_check_call_status();
	zephir_throw_exception_debug(_1, "yb/redis/client.zep", 58 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Yb_Redis_Client, runCommandsByKey) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *cmds = NULL;
	zval *key_param = NULL, *cmds_param = NULL, *resultProcessor = NULL, *_0;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &key_param, &cmds_param, &resultProcessor);

	zephir_get_strval(key, key_param);
	zephir_get_arrval(cmds, cmds_param);
	if (!resultProcessor) {
		resultProcessor = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_BOOL(_0, 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "runcommandsbykeyinternally", NULL, 0, key, cmds, resultProcessor, _0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Redis_Client, runCommandsByKeyInternally) {

	HashTable *_3;
	HashPosition _2;
	zephir_fcall_cache_entry *_6 = NULL, *_9 = NULL, *_12 = NULL, *_14 = NULL, *_17 = NULL;
	int ZEPHIR_LAST_CALL_STATUS, slot = 0;
	zend_bool twice, hasResultProcessor, found, _5$$5;
	zval *cmds = NULL;
	zval *key_param = NULL, *cmds_param = NULL, *resultProcessor, *twice_param = NULL, *results = NULL, *index = NULL, *result = NULL, *_0 = NULL, *_1, **_4, *_18$$5 = NULL, *_19$$5 = NULL, *_7$$10 = NULL, *_8$$10 = NULL, *_10$$8 = NULL, *_11$$8 = NULL, *_13$$8 = NULL, *_15$$11 = NULL, *_16$$11;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &key_param, &cmds_param, &resultProcessor, &twice_param);

	zephir_get_strval(key, key_param);
	zephir_get_arrval(cmds, cmds_param);
	twice = zephir_get_boolval(twice_param);


	hasResultProcessor = 0;
	found = 0;
	if (zephir_is_true(resultProcessor)) {
		if (unlikely(!(zephir_is_callable(resultProcessor TSRMLS_CC)))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_redis_exception_ce, "Invalid result processor", "yb/redis/client.zep", 74);
			return;
		}
		hasResultProcessor = 1;
	}
	slot = yb_redis_cluster_hash_slot( key);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, slot);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getconnectionbyslot", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&results, _0, "runcommands", NULL, 0, cmds);
	zephir_check_call_status();
	zephir_is_iterable(results, &_3, &_2, 0, 0, "yb/redis/client.zep", 114);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(index, _3, _2);
		ZEPHIR_GET_HVALUE(result, _4);
		_5$$5 = Z_TYPE_P(result) != IS_OBJECT;
		if (!(_5$$5)) {
			_5$$5 = !((zephir_instance_of_ev(result, yb_redis_error_ce TSRMLS_CC)));
		}
		if (_5$$5) {
			if (hasResultProcessor) {
				ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", &_6, 44, resultProcessor, result, index);
				zephir_check_call_status();
			}
			found = 1;
			continue;
		}
		if (zephir_instance_of_ev(result, yb_redis_errormoved_ce TSRMLS_CC)) {
			if (unlikely(found)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_redis_exception_ce, "Commands are not in one slot", "yb/redis/client.zep", 93);
				return;
			}
			if (unlikely(twice)) {
				ZEPHIR_INIT_NVAR(_7$$10);
				object_init_ex(_7$$10, yb_redis_exception_ce);
				ZEPHIR_OBS_NVAR(_8$$10);
				zephir_read_property(&_8$$10, result, SL("error"), PH_NOISY_CC);
				ZEPHIR_CALL_METHOD(NULL, _7$$10, "__construct", &_9, 2, _8$$10);
				zephir_check_call_status();
				zephir_throw_exception_debug(_7$$10, "yb/redis/client.zep", 96 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(_10$$8);
			zephir_read_property(&_10$$8, result, SL("host"), PH_NOISY_CC);
			ZEPHIR_OBS_NVAR(_11$$8);
			zephir_read_property(&_11$$8, result, SL("port"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "refleshslots", &_12, 0, _10$$8, _11$$8);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_13$$8);
			ZVAL_BOOL(_13$$8, 1);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "runcommandsbykeyinternally", &_14, 94, key, cmds, resultProcessor, _13$$8);
			zephir_check_call_status();
			RETURN_MM_NULL();
		}
		if (zephir_instance_of_ev(result, yb_redis_errorask_ce TSRMLS_CC)) {
			zephir_array_fetch(&_16$$11, cmds, index, PH_NOISY | PH_READONLY, "yb/redis/client.zep", 104 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_15$$11, this_ptr, "onask", &_17, 0, result, _16$$11);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(result, _15$$11);
			if (hasResultProcessor) {
				ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", &_6, 44, resultProcessor, result, index);
				zephir_check_call_status();
			}
			found = 1;
			continue;
		}
		ZEPHIR_INIT_NVAR(_18$$5);
		object_init_ex(_18$$5, yb_redis_exception_ce);
		ZEPHIR_OBS_NVAR(_19$$5);
		zephir_read_property(&_19$$5, result, SL("error"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _18$$5, "__construct", &_9, 2, _19$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_18$$5, "yb/redis/client.zep", 112 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Redis_Client, getConnectionBySlot) {

	zend_bool _6$$4;
	HashTable *_3$$3;
	HashPosition _2$$3;
	zephir_fcall_cache_entry *_12 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *slot_param = NULL, *s = NULL, *_0, *_13, _14, _15, *_16 = NULL, *_1$$3, **_4$$3, *_5$$4, *_7$$4, *_8$$5, *_9$$5, *_10$$5, *_11$$5;
	long slot;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &slot_param);

	slot = zephir_get_intval(slot_param);


	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("slots"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_ARRAY) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("slots"), PH_NOISY_CC);
		zephir_is_iterable(_1$$3, &_3$$3, &_2$$3, 0, 0, "yb/redis/client.zep", 126);
		for (
		  ; zephir_hash_get_current_data_ex(_3$$3, (void**) &_4$$3, &_2$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3$$3, &_2$$3)
		) {
			ZEPHIR_GET_HVALUE(s, _4$$3);
			zephir_array_fetch_long(&_5$$4, s, 0, PH_NOISY | PH_READONLY, "yb/redis/client.zep", 122 TSRMLS_CC);
			_6$$4 = ZEPHIR_LE_LONG(_5$$4, slot);
			if (_6$$4) {
				zephir_array_fetch_long(&_7$$4, s, 1, PH_NOISY | PH_READONLY, "yb/redis/client.zep", 122 TSRMLS_CC);
				_6$$4 = ZEPHIR_GE_LONG(_7$$4, slot);
			}
			if (_6$$4) {
				zephir_array_fetch_long(&_8$$5, s, 2, PH_NOISY | PH_READONLY, "yb/redis/client.zep", 123 TSRMLS_CC);
				zephir_array_fetch_long(&_9$$5, _8$$5, 0, PH_NOISY | PH_READONLY, "yb/redis/client.zep", 123 TSRMLS_CC);
				zephir_array_fetch_long(&_10$$5, s, 2, PH_NOISY | PH_READONLY, "yb/redis/client.zep", 123 TSRMLS_CC);
				zephir_array_fetch_long(&_11$$5, _10$$5, 1, PH_NOISY | PH_READONLY, "yb/redis/client.zep", 123 TSRMLS_CC);
				ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getconnection", &_12, 0, _9$$5, _11$$5);
				zephir_check_call_status();
				RETURN_MM();
			}
		}
	}
	ZEPHIR_INIT_VAR(_13);
	object_init_ex(_13, yb_redis_exception_ce);
	ZEPHIR_SINIT_VAR(_14);
	ZVAL_STRING(&_14, "Cannot find connection for slot: %d", 0);
	ZEPHIR_SINIT_VAR(_15);
	ZVAL_LONG(&_15, slot);
	ZEPHIR_CALL_FUNCTION(&_16, "sprintf", NULL, 1, &_14, &_15);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _13, "__construct", NULL, 2, _16);
	zephir_check_call_status();
	zephir_throw_exception_debug(_13, "yb/redis/client.zep", 128 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(Yb_Redis_Client, getConnection) {

	int ZEPHIR_LAST_CALL_STATUS;
	long port;
	zval *host_param = NULL, *port_param = NULL, *connection = NULL, _0, _1, *_2 = NULL, *_4, *_5;
	zval *host = NULL, *address = NULL, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &host_param, &port_param);

	zephir_get_strval(host, host_param);
	port = zephir_get_intval(port_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "%s:%d", 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, port);
	ZEPHIR_CALL_FUNCTION(&_2, "sprintf", NULL, 1, &_0, host, &_1);
	zephir_check_call_status();
	zephir_get_strval(_3, _2);
	ZEPHIR_CPY_WRT(address, _3);
	ZEPHIR_OBS_VAR(connection);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("connections"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&connection, _4, address, 0 TSRMLS_CC)) {
		RETURN_CCTOR(connection);
	}
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, port);
	ZEPHIR_CALL_METHOD(&connection, this_ptr, "newconnection", NULL, 0, host, _5);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("connections"), address, connection TSRMLS_CC);
	RETURN_CCTOR(connection);

}

PHP_METHOD(Yb_Redis_Client, newConnection) {

	int ZEPHIR_LAST_CALL_STATUS;
	long port;
	zval *host_param = NULL, *port_param = NULL, *_0, *_1;
	zval *host = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &host_param, &port_param);

	zephir_get_strval(host, host_param);
	port = zephir_get_intval(port_param);


	object_init_ex(return_value, yb_redis_connection_ce);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("timeout"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, port);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 95, host, _1, _0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Redis_Client, refleshSlots) {

	zval *_2;
	int ZEPHIR_LAST_CALL_STATUS;
	long port;
	zval *host_param = NULL, *port_param = NULL, *slots = NULL, *_0 = NULL, *_1 = NULL, *_3;
	zval *host = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &host_param, &port_param);

	zephir_get_strval(host, host_param);
	port = zephir_get_intval(port_param);


	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, port);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getconnection", NULL, 0, host, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "CLUSTER", 1);
	zephir_array_fast_append(_2, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "SLOTS", 1);
	zephir_array_fast_append(_2, _1);
	ZEPHIR_CALL_METHOD(&slots, _0, "runcommand", NULL, 0, _2);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("slots"), slots TSRMLS_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("slotsCacher"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _3, "storeslots", NULL, 0, slots);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Redis_Client, onMoved) {

	zend_bool _5;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *cmd = NULL;
	zval *error, *cmd_param = NULL, *result = NULL, *_0, *_1, *_2 = NULL, *_3, *_4, *_6$$3, *_7$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &error, &cmd_param);

	zephir_get_arrval(cmd, cmd_param);


	ZEPHIR_OBS_VAR(_0);
	zephir_read_property(&_0, error, SL("host"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property(&_1, error, SL("port"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "refleshslots", NULL, 0, _0, _1);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property(&_3, error, SL("host"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_4);
	zephir_read_property(&_4, error, SL("port"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getconnection", NULL, 0, _3, _4);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&result, _2, "runcommand", NULL, 0, cmd);
	zephir_check_call_status();
	_5 = Z_TYPE_P(result) == IS_OBJECT;
	if (_5) {
		_5 = (zephir_instance_of_ev(result, yb_redis_error_ce TSRMLS_CC));
	}
	if (unlikely(_5)) {
		ZEPHIR_INIT_VAR(_6$$3);
		object_init_ex(_6$$3, yb_redis_exception_ce);
		ZEPHIR_OBS_VAR(_7$$3);
		zephir_read_property(&_7$$3, result, SL("error"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _6$$3, "__construct", NULL, 2, _7$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_6$$3, "yb/redis/client.zep", 169 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(result);

}

PHP_METHOD(Yb_Redis_Client, onAsk) {

	zend_bool _6;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *cmd = NULL, *_3, *_4;
	zval *error, *cmd_param = NULL, *results = NULL, *result = NULL, *_0 = NULL, *_1, *_2, *_5, *_7$$4, *_8$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &error, &cmd_param);

	zephir_get_arrval(cmd, cmd_param);


	ZEPHIR_OBS_VAR(_1);
	zephir_read_property(&_1, error, SL("host"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property(&_2, error, SL("port"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getconnection", NULL, 0, _1, _2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	zephir_create_array(_3, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	zephir_create_array(_4, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_STRING(_5, "ASKING", 1);
	zephir_array_fast_append(_4, _5);
	zephir_array_fast_append(_3, _4);
	zephir_array_fast_append(_3, cmd);
	ZEPHIR_CALL_METHOD(&results, _0, "runcommands", NULL, 0, _3);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(result);
	if (unlikely(!(zephir_array_isset_long_fetch(&result, results, 1, 0 TSRMLS_CC)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_redis_exception_ce, "Invalid result when asking", "yb/redis/client.zep", 187);
		return;
	}
	_6 = Z_TYPE_P(result) == IS_OBJECT;
	if (_6) {
		_6 = (zephir_instance_of_ev(result, yb_redis_error_ce TSRMLS_CC));
	}
	if (unlikely(_6)) {
		ZEPHIR_INIT_VAR(_7$$4);
		object_init_ex(_7$$4, yb_redis_exception_ce);
		ZEPHIR_OBS_VAR(_8$$4);
		zephir_read_property(&_8$$4, result, SL("error"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _7$$4, "__construct", NULL, 2, _8$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_7$$4, "yb/redis/client.zep", 191 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(result);

}


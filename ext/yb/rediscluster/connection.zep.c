
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
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/file.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Yb_RedisCluster_Connection) {

	ZEPHIR_REGISTER_CLASS(Yb\\RedisCluster, Connection, yb, rediscluster_connection, yb_rediscluster_connection_method_entry, 0);

	zend_declare_property_null(yb_rediscluster_connection_ce, SL("handler"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(yb_rediscluster_connection_ce, SL("DEFAULT_HOST"), "127.0.0.1" TSRMLS_CC);

	zend_declare_class_constant_long(yb_rediscluster_connection_ce, SL("DEFAULT_PORT"), 6379 TSRMLS_CC);

	zend_declare_class_constant_long(yb_rediscluster_connection_ce, SL("DEFAULT_TIMEOUT"), 5 TSRMLS_CC);

	zend_declare_class_constant_bool(yb_rediscluster_connection_ce, SL("DEFAULT_PERSISTENT"), 0 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Yb_RedisCluster_Connection, __construct) {

	zend_bool persistent = 0;
	long port = 0, timeout = 0;
	zval *host = NULL, *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *options_param = NULL, *handler = NULL, *errStr = NULL, *_0 = NULL, *_2 = NULL, *_3 = NULL, *_5 = NULL, *_6 = NULL, *_7 = NULL, _16, *_8$$3, *_9$$3, *_10$$3, *_11$$4, *_12$$4, *_13$$4, *_14$$5, *_15$$5;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	ZEPHIR_INIT_VAR(errStr);
	ZVAL_NULL(errStr);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "host", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "127.0.0.1", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_0, yb_std_ce, "valueat", &_1, 9, options, _2, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_get_strval(_4, _0);
	ZEPHIR_CPY_WRT(host, _4);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "port", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_LONG(_3, 6379);
	ZEPHIR_CALL_CE_STATIC(&_5, yb_std_ce, "valueat", &_1, 9, options, _2, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	port = zephir_get_intval(_5);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "timeout", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_LONG(_3, 5);
	ZEPHIR_CALL_CE_STATIC(&_6, yb_std_ce, "valueat", &_1, 9, options, _2, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	timeout = zephir_get_intval(_6);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "persistent", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_BOOL(_3, 0);
	ZEPHIR_CALL_CE_STATIC(&_7, yb_std_ce, "valueat", &_1, 9, options, _2, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	persistent = zephir_get_boolval(_7);
	if (persistent) {
		ZEPHIR_INIT_VAR(_8$$3);
		ZVAL_LONG(_8$$3, port);
		ZEPHIR_INIT_VAR(_9$$3);
		ZVAL_NULL(_9$$3);
		ZEPHIR_INIT_VAR(_10$$3);
		ZVAL_LONG(_10$$3, timeout);
		ZEPHIR_MAKE_REF(_9$$3);
		ZEPHIR_CALL_FUNCTION(&handler, "pfsockopen", NULL, 98, host, _8$$3, _9$$3, errStr, _10$$3);
		ZEPHIR_UNREF(_9$$3);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(_11$$4);
		ZVAL_LONG(_11$$4, port);
		ZEPHIR_INIT_VAR(_12$$4);
		ZVAL_NULL(_12$$4);
		ZEPHIR_INIT_VAR(_13$$4);
		ZVAL_LONG(_13$$4, timeout);
		ZEPHIR_MAKE_REF(_12$$4);
		ZEPHIR_CALL_FUNCTION(&handler, "fsockopen", NULL, 82, host, _11$$4, _12$$4, errStr, _13$$4);
		ZEPHIR_UNREF(_12$$4);
		zephir_check_call_status();
	}
	if (unlikely(!zephir_is_true(handler))) {
		ZEPHIR_INIT_VAR(_14$$5);
		object_init_ex(_14$$5, yb_rediscluster_socketexception_ce);
		ZEPHIR_INIT_VAR(_15$$5);
		ZEPHIR_CONCAT_SV(_15$$5, "Cannot open socket: ", errStr);
		ZEPHIR_CALL_METHOD(NULL, _14$$5, "__construct", NULL, 2, _15$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_14$$5, "yb/rediscluster/connection.zep", 33 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_SINIT_VAR(_16);
	ZVAL_LONG(&_16, 1);
	ZEPHIR_CALL_FUNCTION(&_7, "stream_set_blocking", NULL, 85, handler, &_16);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_7))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_rediscluster_socketexception_ce, "Cannot set blocking socket", "yb/rediscluster/connection.zep", 37);
		return;
	}
	zephir_update_property_this(this_ptr, SL("handler"), handler TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_RedisCluster_Connection, getInternalHandler) {

	

	RETURN_MEMBER(this_ptr, "handler");

}

PHP_METHOD(Yb_RedisCluster_Connection, __call) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *args = NULL;
	zval *method_param = NULL, *args_param = NULL, *cmd = NULL;
	zval *method = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &args_param);

	zephir_get_strval(method, method_param);
	zephir_get_arrval(args, args_param);


	ZEPHIR_CPY_WRT(cmd, args);
	ZEPHIR_MAKE_REF(cmd);
	ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", NULL, 99, cmd, method);
	ZEPHIR_UNREF(cmd);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "runcommand", NULL, 0, cmd);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_RedisCluster_Connection, runCommand) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *cmd_param = NULL;
	zval *cmd = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cmd_param);

	zephir_get_arrval(cmd, cmd_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, cmd);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "read", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_RedisCluster_Connection, runCommands) {

	HashTable *_1, *_6;
	HashPosition _0, _5;
	zephir_fcall_cache_entry *_3 = NULL, *_9 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *cmds_param = NULL, *index = NULL, *cmd = NULL, *results = NULL, **_2, *_4 = NULL, **_7, *_8$$4 = NULL;
	zval *cmds = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cmds_param);

	zephir_get_arrval(cmds, cmds_param);


	ZEPHIR_INIT_VAR(results);
	array_init(results);
	zephir_is_iterable(cmds, &_1, &_0, 0, 0, "yb/rediscluster/connection.zep", 72);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(cmd, _2);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", &_3, 0, cmd);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_4);
	zephir_is_iterable(cmds, &_6, &_5, 0, 0, "yb/rediscluster/connection.zep", 76);
	for (
	  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
	  ; zephir_hash_move_forward_ex(_6, &_5)
	) {
		ZEPHIR_GET_HMKEY(index, _6, _5);
		ZEPHIR_GET_HVALUE(_4, _7);
		ZEPHIR_CALL_METHOD(&_8$$4, this_ptr, "read", &_9, 0);
		zephir_check_call_status();
		zephir_array_update_zval(&results, index, &_8$$4, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(results);

}

PHP_METHOD(Yb_RedisCluster_Connection, __destruct) {

	zval *_0, *_1$$3;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("handler"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("handler"), PH_NOISY_CC);
		zephir_fclose(_1$$3 TSRMLS_CC);
	}

}

PHP_METHOD(Yb_RedisCluster_Connection, write) {

	HashTable *_6$$3;
	HashPosition _5$$3;
	zval *_9 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_8 = NULL;
	zval *data, *d = NULL, *s = NULL, _10, _11, *_12, *_13, _0$$3, _1$$3, *_3$$3, *_4$$3, **_7$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	if (Z_TYPE_P(data) == IS_ARRAY) {
		ZEPHIR_SINIT_VAR(_0$$3);
		ZVAL_STRING(&_0$$3, "*%d\r\n", 0);
		ZEPHIR_SINIT_VAR(_1$$3);
		ZVAL_LONG(&_1$$3, zephir_fast_count_int(data TSRMLS_CC));
		ZEPHIR_CALL_FUNCTION(&s, "sprintf", &_2, 1, &_0$$3, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_3$$3);
		_4$$3 = zephir_fetch_nproperty_this(this_ptr, SL("handler"), PH_NOISY_CC);
		zephir_fwrite(_3$$3, _4$$3, s TSRMLS_CC);
		if (unlikely(ZEPHIR_IS_FALSE_IDENTICAL(_3$$3))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_rediscluster_socketexception_ce, "Cannot write to socket", "yb/rediscluster/connection.zep", 94);
			return;
		}
		zephir_is_iterable(data, &_6$$3, &_5$$3, 0, 0, "yb/rediscluster/connection.zep", 101);
		for (
		  ; zephir_hash_get_current_data_ex(_6$$3, (void**) &_7$$3, &_5$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_6$$3, &_5$$3)
		) {
			ZEPHIR_GET_HVALUE(d, _7$$3);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", &_8, 100, d);
			zephir_check_call_status();
		}
		RETURN_MM_NULL();
	}
	zephir_get_strval(_9, data);
	ZEPHIR_CPY_WRT(d, _9);
	ZEPHIR_SINIT_VAR(_10);
	ZVAL_STRING(&_10, "$%d\r\n%s\r\n", 0);
	ZEPHIR_SINIT_VAR(_11);
	ZVAL_LONG(&_11, zephir_fast_strlen_ev(d));
	ZEPHIR_CALL_FUNCTION(&s, "sprintf", &_2, 1, &_10, &_11, d);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_12);
	_13 = zephir_fetch_nproperty_this(this_ptr, SL("handler"), PH_NOISY_CC);
	zephir_fwrite(_12, _13, s TSRMLS_CC);
	if (unlikely(ZEPHIR_IS_FALSE_IDENTICAL(_12))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_rediscluster_socketexception_ce, "Cannot write to socket", "yb/rediscluster/connection.zep", 108);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_RedisCluster_Connection, read) {

	zval *a = NULL, *_0 = NULL, _3, _4, *_5, *_7$$5, *_8$$7 = NULL, *_9$$7, _11$$7, _12$$7, *_13$$11 = NULL, *_15$$13, *_16$$13, *_17$$13;
	long l = 0;
	char c = 0;
	zval *line = NULL, *_2 = NULL, *_6 = NULL, *_10$$7 = NULL;
	zephir_fcall_cache_entry *_1 = NULL, *_14 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "readline", &_1, 0);
	zephir_check_call_status();
	zephir_get_strval(_2, _0);
	ZEPHIR_CPY_WRT(line, _2);
	c = ZEPHIR_STRING_OFFSET(line, 0);
	c = c;
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, 1);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, -2);
	ZEPHIR_INIT_VAR(_5);
	zephir_substr(_5, line, 1 , -2 , 0);
	zephir_get_strval(_6, _5);
	ZEPHIR_CPY_WRT(line, _6);
	do {
		if (c == '+') {
			RETURN_CTOR(line);
		}
		if (c == '-') {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newerror", NULL, 0, line);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (c == ':') {
			ZEPHIR_INIT_VAR(_7$$5);
			ZEPHIR_GET_CONSTANT(_7$$5, "PHP_INT_MAX");
			if (ZEPHIR_GT(line, _7$$5)) {
				RETURN_CTOR(line);
			}
			RETURN_MM_LONG(zephir_get_intval(line));
		}
		if (c == '$') {
			l = zephir_get_intval(line);
			if (l < 0) {
				RETURN_MM_NULL();
			}
			ZEPHIR_INIT_VAR(_9$$7);
			ZVAL_LONG(_9$$7, (l + 2));
			ZEPHIR_CALL_METHOD(&_8$$7, this_ptr, "readline", &_1, 0, _9$$7);
			zephir_check_call_status();
			zephir_get_strval(_10$$7, _8$$7);
			ZEPHIR_CPY_WRT(line, _10$$7);
			ZEPHIR_SINIT_VAR(_11$$7);
			ZVAL_LONG(&_11$$7, 0);
			ZEPHIR_SINIT_VAR(_12$$7);
			ZVAL_LONG(&_12$$7, -2);
			zephir_substr(return_value, line, 0 , -2 , 0);
			RETURN_MM();
		}
		if (c == '*') {
			l = zephir_get_intval(line);
			if (l < 0) {
				RETURN_MM_NULL();
			}
			ZEPHIR_INIT_VAR(a);
			array_init(a);
			while (1) {
				if (l <= 0) {
					break;
				}
				l--;
				ZEPHIR_CALL_METHOD(&_13$$11, this_ptr, "read", &_14, 101);
				zephir_check_call_status();
				zephir_array_append(&a, _13$$11, PH_SEPARATE, "yb/rediscluster/connection.zep", 156);
			}
			RETURN_CCTOR(a);
		}
		ZEPHIR_INIT_VAR(_15$$13);
		object_init_ex(_15$$13, yb_rediscluster_exception_ce);
		ZEPHIR_INIT_VAR(_16$$13);
		zephir_json_encode(_16$$13, &(_16$$13), line, 0  TSRMLS_CC);
		ZEPHIR_INIT_VAR(_17$$13);
		ZEPHIR_CONCAT_SV(_17$$13, "Invalid line type: ", _16$$13);
		ZEPHIR_CALL_METHOD(NULL, _15$$13, "__construct", NULL, 2, _17$$13);
		zephir_check_call_status();
		zephir_throw_exception_debug(_15$$13, "yb/rediscluster/connection.zep", 161 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_RedisCluster_Connection, readLine) {

	zend_bool _5;
	unsigned char _4, _6;
	zval *s = NULL, *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *len_param = NULL, *line = NULL, *_0$$3, _1$$3, *_2$$4, *_7$$6, *_8$$6, *_9$$6;
	long len;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &len_param);

	if (!len_param) {
		len = 0;
	} else {
		len = zephir_get_intval(len_param);
	}


	if (len > 0) {
		_0$$3 = zephir_fetch_nproperty_this(this_ptr, SL("handler"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_1$$3);
		ZVAL_LONG(&_1$$3, len);
		ZEPHIR_CALL_FUNCTION(&line, "stream_get_contents", NULL, 102, _0$$3, &_1$$3);
		zephir_check_call_status();
	} else {
		_2$$4 = zephir_fetch_nproperty_this(this_ptr, SL("handler"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&line, "fgets", NULL, 103, _2$$4);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_FALSE_IDENTICAL(line)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_rediscluster_socketexception_ce, "Cannot read from socket", "yb/rediscluster/connection.zep", 177);
		return;
	}
	zephir_get_strval(_3, line);
	ZEPHIR_CPY_WRT(s, _3);
	len = zephir_fast_strlen_ev(s);
	_4 = ZEPHIR_STRING_OFFSET(s, (len - 2));
	_5 = _4 != '\r';
	if (!(_5)) {
		_6 = ZEPHIR_STRING_OFFSET(s, (len - 1));
		_5 = _6 != '\n';
	}
	if (unlikely(_5)) {
		ZEPHIR_INIT_VAR(_7$$6);
		object_init_ex(_7$$6, yb_rediscluster_exception_ce);
		ZEPHIR_INIT_VAR(_8$$6);
		zephir_json_encode(_8$$6, &(_8$$6), line, 0  TSRMLS_CC);
		ZEPHIR_INIT_VAR(_9$$6);
		ZEPHIR_CONCAT_SV(_9$$6, "Invalid line end: ", _8$$6);
		ZEPHIR_CALL_METHOD(NULL, _7$$6, "__construct", NULL, 2, _9$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(_7$$6, "yb/rediscluster/connection.zep", 184 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CTOR(s);

}

PHP_METHOD(Yb_RedisCluster_Connection, newError) {

	unsigned char _2$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *error_param = NULL, *m = NULL, *e = NULL, *_0, _1, *_3$$4, *_4$$4, *_5$$4, *_6$$5, *_7$$5, *_8$$5;
	zval *error = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &error_param);

	zephir_get_strval(error, error_param);


	ZEPHIR_INIT_VAR(m);
	ZVAL_NULL(m);
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "#^(MOVED|ASK) (\\d+) ([\\d\\.]+):(\\d+)$#", 0);
	zephir_preg_match(_0, &_1, error, m, 0, 0 , 0  TSRMLS_CC);
	if (zephir_is_true(_0)) {
		_2$$3 = ZEPHIR_STRING_OFFSET(error, 0);
		do {
			if (_2$$3 == 'M') {
				ZEPHIR_INIT_VAR(e);
				object_init_ex(e, yb_rediscluster_errormoved_ce);
				if (zephir_has_constructor(e TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(NULL, e, "__construct", NULL, 0);
					zephir_check_call_status();
				}
				zephir_update_property_zval(e, SL("error"), error TSRMLS_CC);
				zephir_array_fetch_long(&_3$$4, m, 2, PH_NOISY | PH_READONLY, "yb/rediscluster/connection.zep", 199 TSRMLS_CC);
				zephir_update_property_zval(e, SL("slot"), _3$$4 TSRMLS_CC);
				zephir_array_fetch_long(&_4$$4, m, 3, PH_NOISY | PH_READONLY, "yb/rediscluster/connection.zep", 200 TSRMLS_CC);
				zephir_update_property_zval(e, SL("host"), _4$$4 TSRMLS_CC);
				zephir_array_fetch_long(&_5$$4, m, 4, PH_NOISY | PH_READONLY, "yb/rediscluster/connection.zep", 201 TSRMLS_CC);
				zephir_update_property_zval(e, SL("port"), _5$$4 TSRMLS_CC);
				RETURN_CCTOR(e);
			}
			if (_2$$3 == 'A') {
				ZEPHIR_INIT_NVAR(e);
				object_init_ex(e, yb_rediscluster_errorask_ce);
				if (zephir_has_constructor(e TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(NULL, e, "__construct", NULL, 0);
					zephir_check_call_status();
				}
				zephir_update_property_zval(e, SL("error"), error TSRMLS_CC);
				zephir_array_fetch_long(&_6$$5, m, 2, PH_NOISY | PH_READONLY, "yb/rediscluster/connection.zep", 207 TSRMLS_CC);
				zephir_update_property_zval(e, SL("slot"), _6$$5 TSRMLS_CC);
				zephir_array_fetch_long(&_7$$5, m, 3, PH_NOISY | PH_READONLY, "yb/rediscluster/connection.zep", 208 TSRMLS_CC);
				zephir_update_property_zval(e, SL("host"), _7$$5 TSRMLS_CC);
				zephir_array_fetch_long(&_8$$5, m, 4, PH_NOISY | PH_READONLY, "yb/rediscluster/connection.zep", 209 TSRMLS_CC);
				zephir_update_property_zval(e, SL("port"), _8$$5 TSRMLS_CC);
				RETURN_CCTOR(e);
			}
		} while(0);

	}
	ZEPHIR_INIT_NVAR(e);
	object_init_ex(e, yb_rediscluster_error_ce);
	if (zephir_has_constructor(e TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, e, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(e, SL("error"), error TSRMLS_CC);
	RETURN_CCTOR(e);

}


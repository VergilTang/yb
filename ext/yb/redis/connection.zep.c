
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
#include "kernel/object.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Yb_Redis_Connection) {

	ZEPHIR_REGISTER_CLASS(Yb\\Redis, Connection, yb, redis_connection, yb_redis_connection_method_entry, 0);

	zend_declare_property_null(yb_redis_connection_ce, SL("socket"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(yb_redis_connection_ce, SL("DEFAULT_HOST"), "127.0.0.1" TSRMLS_CC);

	zend_declare_class_constant_long(yb_redis_connection_ce, SL("DEFAULT_PORT"), 6379 TSRMLS_CC);

	zend_declare_class_constant_long(yb_redis_connection_ce, SL("DEFAULT_CONNECT_TIMEOUT"), 5 TSRMLS_CC);

	zend_declare_class_constant_double(yb_redis_connection_ce, SL("DEFAULT_TIMEOUT"), 2.0 TSRMLS_CC);

	zend_declare_class_constant_bool(yb_redis_connection_ce, SL("DEFAULT_PERSISTENT"), 0 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Yb_Redis_Connection, __construct) {

	double timeout = 0;
	zend_bool persistent = 0;
	long port = 0, connectTimeout = 0;
	zval *host = NULL, *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *options_param = NULL, *socket = NULL, *_0 = NULL, *_2 = NULL, *_3 = NULL, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_8, *_9$$3;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "host", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "127.0.0.1", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_0, yb_std_ce, "valueat", &_1, 5, options, _2, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_get_strval(_4, _0);
	ZEPHIR_CPY_WRT(host, _4);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "port", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_LONG(_3, 6379);
	ZEPHIR_CALL_CE_STATIC(&_5, yb_std_ce, "valueat", &_1, 5, options, _2, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	port = zephir_get_intval(_5);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "connectTimeout", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_LONG(_3, 5);
	ZEPHIR_CALL_CE_STATIC(&_6, yb_std_ce, "valueat", &_1, 5, options, _2, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	connectTimeout = zephir_get_intval(_6);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "persistent", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_BOOL(_3, 0);
	ZEPHIR_CALL_CE_STATIC(&_7, yb_std_ce, "valueat", &_1, 5, options, _2, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	persistent = zephir_get_boolval(_7);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "timeout", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_DOUBLE(_3, 2.0);
	ZEPHIR_CALL_CE_STATIC(&_7, yb_std_ce, "valueat", &_1, 5, options, _2, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	timeout = zephir_get_doubleval(_7);
	ZEPHIR_INIT_VAR(socket);
	object_init_ex(socket, yb_socket_tcpclient_ce);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, port);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_LONG(_3, connectTimeout);
	ZEPHIR_INIT_VAR(_8);
	if (persistent) {
		ZVAL_BOOL(_8, 1);
	} else {
		ZVAL_BOOL(_8, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, socket, "__construct", NULL, 94, host, _2, _3, _8);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_BOOL(_2, 1);
	ZEPHIR_CALL_METHOD(NULL, socket, "settcpnodelay", NULL, 95, _2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_BOOL(_2, 1);
	ZEPHIR_CALL_METHOD(NULL, socket, "setblocking", NULL, 96, _2);
	zephir_check_call_status();
	if (timeout > 0) {
		ZEPHIR_INIT_VAR(_9$$3);
		ZVAL_DOUBLE(_9$$3, timeout);
		ZEPHIR_CALL_METHOD(NULL, socket, "settimeout", NULL, 97, _9$$3);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("socket"), socket TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Redis_Connection, getSocket) {

	

	RETURN_MEMBER(this_ptr, "socket");

}

PHP_METHOD(Yb_Redis_Connection, __call) {

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
	ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", NULL, 105, cmd, method);
	ZEPHIR_UNREF(cmd);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "runcommand", NULL, 0, cmd);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Redis_Connection, runCommand) {

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

PHP_METHOD(Yb_Redis_Connection, runCommands) {

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
	zephir_is_iterable(cmds, &_1, &_0, 0, 0, "yb/redis/connection.zep", 69);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(cmd, _2);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", &_3, 0, cmd);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_4);
	zephir_is_iterable(cmds, &_6, &_5, 0, 0, "yb/redis/connection.zep", 73);
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

PHP_METHOD(Yb_Redis_Connection, write) {

	zval *_0$$3 = NULL;
	HashTable *_11;
	HashPosition _10;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_5 = NULL, *_13 = NULL;
	zval *data, *d = NULL, *_6, _7, _8, *_9 = NULL, **_12, *_1$$3, _2$$3, _3$$3, *_4$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	if (Z_TYPE_P(data) != IS_ARRAY) {
		zephir_get_strval(_0$$3, data);
		ZEPHIR_CPY_WRT(d, _0$$3);
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("socket"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_2$$3);
		ZVAL_STRING(&_2$$3, "$%d\r\n%s\r\n", 0);
		ZEPHIR_SINIT_VAR(_3$$3);
		ZVAL_LONG(&_3$$3, zephir_fast_strlen_ev(d));
		ZEPHIR_CALL_FUNCTION(&_4$$3, "sprintf", &_5, 1, &_2$$3, &_3$$3, d);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "write", NULL, 0, _4$$3);
		zephir_check_call_status();
		RETURN_MM_NULL();
	}
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("socket"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_STRING(&_7, "*%d\r\n", 0);
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_LONG(&_8, zephir_fast_count_int(data TSRMLS_CC));
	ZEPHIR_CALL_FUNCTION(&_9, "sprintf", &_5, 1, &_7, &_8);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _6, "write", NULL, 0, _9);
	zephir_check_call_status();
	zephir_is_iterable(data, &_11, &_10, 0, 0, "yb/redis/connection.zep", 92);
	for (
	  ; zephir_hash_get_current_data_ex(_11, (void**) &_12, &_10) == SUCCESS
	  ; zephir_hash_move_forward_ex(_11, &_10)
	) {
		ZEPHIR_GET_HVALUE(d, _12);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", &_13, 106, d);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Redis_Connection, read) {

	unsigned char _4, _6, _20$$8, _22$$8;
	zend_bool _3, _5, _19$$8, _21$$8;
	zval *a = NULL, *_0, *_1 = NULL, _10, _11, *_12, *_7$$3, *_8$$3, *_9$$3, *_14$$6, *_15$$8, *_16$$8 = NULL, *_17$$8, _26$$8, _27$$8, *_23$$10, *_24$$10, *_25$$10, *_28$$13 = NULL, *_30$$15, *_31$$15, *_32$$15;
	long l = 0;
	char c = 0;
	zval *line = NULL, *_2 = NULL, *_13 = NULL, *_18$$8 = NULL;
	zephir_fcall_cache_entry *_29 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("socket"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "readline", NULL, 0);
	zephir_check_call_status();
	zephir_get_strval(_2, _1);
	ZEPHIR_CPY_WRT(line, _2);
	l = zephir_fast_strlen_ev(line);
	_3 = l < 2;
	if (!(_3)) {
		_4 = ZEPHIR_STRING_OFFSET(line, (l - 2));
		_3 = _4 != '\r';
	}
	_5 = _3;
	if (!(_5)) {
		_6 = ZEPHIR_STRING_OFFSET(line, (l - 1));
		_5 = _6 != '\n';
	}
	if (unlikely(_5)) {
		ZEPHIR_INIT_VAR(_7$$3);
		object_init_ex(_7$$3, yb_redis_exception_ce);
		ZEPHIR_INIT_VAR(_8$$3);
		zephir_json_encode(_8$$3, &(_8$$3), line, 0  TSRMLS_CC);
		ZEPHIR_INIT_VAR(_9$$3);
		ZEPHIR_CONCAT_SV(_9$$3, "Invalid line end: ", _8$$3);
		ZEPHIR_CALL_METHOD(NULL, _7$$3, "__construct", NULL, 2, _9$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_7$$3, "yb/redis/connection.zep", 104 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	c = ZEPHIR_STRING_OFFSET(line, 0);
	c = c;
	ZEPHIR_SINIT_VAR(_10);
	ZVAL_LONG(&_10, 1);
	ZEPHIR_SINIT_VAR(_11);
	ZVAL_LONG(&_11, -2);
	ZEPHIR_INIT_VAR(_12);
	zephir_substr(_12, line, 1 , -2 , 0);
	zephir_get_strval(_13, _12);
	ZEPHIR_CPY_WRT(line, _13);
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
			ZEPHIR_INIT_VAR(_14$$6);
			ZEPHIR_GET_CONSTANT(_14$$6, "PHP_INT_MAX");
			if (ZEPHIR_GT(line, _14$$6)) {
				RETURN_CTOR(line);
			}
			RETURN_MM_LONG(zephir_get_intval(line));
		}
		if (c == '$') {
			l = zephir_get_intval(line);
			if (l < 0) {
				RETURN_MM_NULL();
			}
			_15$$8 = zephir_fetch_nproperty_this(this_ptr, SL("socket"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_17$$8);
			ZVAL_LONG(_17$$8, (l + 2));
			ZEPHIR_CALL_METHOD(&_16$$8, _15$$8, "readlength", NULL, 0, _17$$8);
			zephir_check_call_status();
			zephir_get_strval(_18$$8, _16$$8);
			ZEPHIR_CPY_WRT(line, _18$$8);
			l = zephir_fast_strlen_ev(line);
			_19$$8 = l < 2;
			if (!(_19$$8)) {
				_20$$8 = ZEPHIR_STRING_OFFSET(line, (l - 2));
				_19$$8 = _20$$8 != '\r';
			}
			_21$$8 = _19$$8;
			if (!(_21$$8)) {
				_22$$8 = ZEPHIR_STRING_OFFSET(line, (l - 1));
				_21$$8 = _22$$8 != '\n';
			}
			if (unlikely(_21$$8)) {
				ZEPHIR_INIT_VAR(_23$$10);
				object_init_ex(_23$$10, yb_redis_exception_ce);
				ZEPHIR_INIT_VAR(_24$$10);
				zephir_json_encode(_24$$10, &(_24$$10), line, 0  TSRMLS_CC);
				ZEPHIR_INIT_VAR(_25$$10);
				ZEPHIR_CONCAT_SV(_25$$10, "Invalid line end: ", _24$$10);
				ZEPHIR_CALL_METHOD(NULL, _23$$10, "__construct", NULL, 2, _25$$10);
				zephir_check_call_status();
				zephir_throw_exception_debug(_23$$10, "yb/redis/connection.zep", 130 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_SINIT_VAR(_26$$8);
			ZVAL_LONG(&_26$$8, 0);
			ZEPHIR_SINIT_VAR(_27$$8);
			ZVAL_LONG(&_27$$8, -2);
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
				ZEPHIR_CALL_METHOD(&_28$$13, this_ptr, "read", &_29, 107);
				zephir_check_call_status();
				zephir_array_append(&a, _28$$13, PH_SEPARATE, "yb/redis/connection.zep", 145);
			}
			RETURN_CCTOR(a);
		}
		ZEPHIR_INIT_VAR(_30$$15);
		object_init_ex(_30$$15, yb_redis_exception_ce);
		ZEPHIR_INIT_VAR(_31$$15);
		zephir_json_encode(_31$$15, &(_31$$15), line, 0  TSRMLS_CC);
		ZEPHIR_INIT_VAR(_32$$15);
		ZEPHIR_CONCAT_SV(_32$$15, "Invalid line type: ", _31$$15);
		ZEPHIR_CALL_METHOD(NULL, _30$$15, "__construct", NULL, 2, _32$$15);
		zephir_check_call_status();
		zephir_throw_exception_debug(_30$$15, "yb/redis/connection.zep", 150 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Redis_Connection, newError) {

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
				object_init_ex(e, yb_redis_errormoved_ce);
				if (zephir_has_constructor(e TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(NULL, e, "__construct", NULL, 0);
					zephir_check_call_status();
				}
				zephir_update_property_zval(e, SL("error"), error TSRMLS_CC);
				zephir_array_fetch_long(&_3$$4, m, 2, PH_NOISY | PH_READONLY, "yb/redis/connection.zep", 163 TSRMLS_CC);
				zephir_update_property_zval(e, SL("slot"), _3$$4 TSRMLS_CC);
				zephir_array_fetch_long(&_4$$4, m, 3, PH_NOISY | PH_READONLY, "yb/redis/connection.zep", 164 TSRMLS_CC);
				zephir_update_property_zval(e, SL("host"), _4$$4 TSRMLS_CC);
				zephir_array_fetch_long(&_5$$4, m, 4, PH_NOISY | PH_READONLY, "yb/redis/connection.zep", 165 TSRMLS_CC);
				zephir_update_property_zval(e, SL("port"), _5$$4 TSRMLS_CC);
				RETURN_CCTOR(e);
			}
			if (_2$$3 == 'A') {
				ZEPHIR_INIT_NVAR(e);
				object_init_ex(e, yb_redis_errorask_ce);
				if (zephir_has_constructor(e TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(NULL, e, "__construct", NULL, 0);
					zephir_check_call_status();
				}
				zephir_update_property_zval(e, SL("error"), error TSRMLS_CC);
				zephir_array_fetch_long(&_6$$5, m, 2, PH_NOISY | PH_READONLY, "yb/redis/connection.zep", 171 TSRMLS_CC);
				zephir_update_property_zval(e, SL("slot"), _6$$5 TSRMLS_CC);
				zephir_array_fetch_long(&_7$$5, m, 3, PH_NOISY | PH_READONLY, "yb/redis/connection.zep", 172 TSRMLS_CC);
				zephir_update_property_zval(e, SL("host"), _7$$5 TSRMLS_CC);
				zephir_array_fetch_long(&_8$$5, m, 4, PH_NOISY | PH_READONLY, "yb/redis/connection.zep", 173 TSRMLS_CC);
				zephir_update_property_zval(e, SL("port"), _8$$5 TSRMLS_CC);
				RETURN_CCTOR(e);
			}
		} while(0);

	}
	ZEPHIR_INIT_NVAR(e);
	object_init_ex(e, yb_redis_error_ce);
	if (zephir_has_constructor(e TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, e, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(e, SL("error"), error TSRMLS_CC);
	RETURN_CCTOR(e);

}


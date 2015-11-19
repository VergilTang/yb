
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
#include "kernel/file.h"


ZEPHIR_INIT_CLASS(Yb_Socket_TcpClient) {

	ZEPHIR_REGISTER_CLASS(Yb\\Socket, TcpClient, yb, socket_tcpclient, yb_socket_tcpclient_method_entry, 0);

	zend_declare_property_null(yb_socket_tcpclient_ce, SL("handler"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Yb_Socket_TcpClient, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool persistent;
	long port, timeout, flags = 0;
	zval *host_param = NULL, *port_param = NULL, *timeout_param = NULL, *persistent_param = NULL, *handler = NULL, *errNo = NULL, *errStr = NULL, _0, _1, *_2 = NULL, *_4, *_5, *_6$$4, *_7$$4;
	zval *host = NULL, *address = NULL, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &host_param, &port_param, &timeout_param, &persistent_param);

	zephir_get_strval(host, host_param);
	port = zephir_get_intval(port_param);
	if (!timeout_param) {
		timeout = 5;
	} else {
		timeout = zephir_get_intval(timeout_param);
	}
	if (!persistent_param) {
		persistent = 0;
	} else {
		persistent = zephir_get_boolval(persistent_param);
	}


	ZEPHIR_INIT_VAR(errNo);
	ZVAL_NULL(errNo);
	ZEPHIR_INIT_VAR(errStr);
	ZVAL_NULL(errStr);
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "tcp://%s:%d", 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, port);
	ZEPHIR_CALL_FUNCTION(&_2, "sprintf", NULL, 1, &_0, host, &_1);
	zephir_check_call_status();
	zephir_get_strval(_3, _2);
	ZEPHIR_CPY_WRT(address, _3);
	flags = 4;
	if (persistent) {
		flags = (flags | 1);
	}
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, timeout);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, flags);
	ZEPHIR_MAKE_REF(errNo);
	ZEPHIR_CALL_FUNCTION(&handler, "stream_socket_client", NULL, 106, address, errNo, errStr, _4, _5);
	ZEPHIR_UNREF(errNo);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(handler))) {
		ZEPHIR_INIT_VAR(_6$$4);
		object_init_ex(_6$$4, yb_socket_exception_ce);
		ZEPHIR_INIT_VAR(_7$$4);
		ZEPHIR_CONCAT_SVSVSV(_7$$4, "Cannot connect to ", address, " [", errNo, "]", errStr);
		ZEPHIR_CALL_METHOD(NULL, _6$$4, "__construct", NULL, 2, _7$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_6$$4, "yb/socket/tcpclient.zep", 21 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_this(this_ptr, SL("handler"), handler TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Socket_TcpClient, __destruct) {

	zval *_0, *_1$$3;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("handler"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("handler"), PH_NOISY_CC);
		zephir_fclose(_1$$3 TSRMLS_CC);
	}

}

PHP_METHOD(Yb_Socket_TcpClient, getInternalHandler) {

	

	RETURN_MEMBER(this_ptr, "handler");

}

PHP_METHOD(Yb_Socket_TcpClient, setTcpNodelay) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *on_param = NULL, *socket = NULL, *_0, *_1 = NULL, _2, _3, *_4 = NULL;
	zend_bool on;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &on_param);

	on = zephir_get_boolval(on_param);


	if (unlikely(!((zephir_function_exists_ex(SS("socket_import_stream") TSRMLS_CC) == SUCCESS)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_socket_exception_ce, "Not supported: socket_import_stream", "yb/socket/tcpclient.zep", 44);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("handler"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&socket, "socket_import_stream", NULL, 107, _0);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(socket))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_socket_exception_ce, "Failed: socket_import_stream", "yb/socket/tcpclient.zep", 49);
		return;
	}
	ZEPHIR_INIT_VAR(_1);
	if (on) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, 1);
	} else {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, 0);
	}
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 6);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, 1);
	ZEPHIR_CALL_FUNCTION(&_4, "socket_set_option", NULL, 108, socket, &_2, &_3, _1);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_4))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_socket_exception_ce, "Cannot set SOL_TCP TCP_NODELAY", "yb/socket/tcpclient.zep", 53);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Socket_TcpClient, setBlocking) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *on_param = NULL, *_0, *_1 = NULL, *_2 = NULL;
	zend_bool on;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &on_param);

	on = zephir_get_boolval(on_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("handler"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	if (on) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, 1);
	} else {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, 0);
	}
	ZEPHIR_CALL_FUNCTION(&_2, "stream_set_blocking", NULL, 109, _0, _1);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_2))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_socket_exception_ce, "Cannot set blocking", "yb/socket/tcpclient.zep", 60);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Socket_TcpClient, setIoTimeout) {

	long ioTimeoutSeconds = 0, ioTimeoutMicroSeconds = 0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *ioTimeout_param = NULL, *_0, _1, _2, *_3 = NULL;
	double ioTimeout;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &ioTimeout_param);

	ioTimeout = zephir_get_doubleval(ioTimeout_param);


	if (unlikely(ioTimeout < 0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_socket_exception_ce, "Cannot set io timeout to negative value", "yb/socket/tcpclient.zep", 69);
		return;
	}
	ioTimeoutSeconds = (long) (ioTimeout);
	ioTimeoutMicroSeconds = (long) ((((ioTimeout -  (double) ioTimeoutSeconds)) * 1000000.0));
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("handler"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, ioTimeoutSeconds);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, ioTimeoutMicroSeconds);
	ZEPHIR_CALL_FUNCTION(&_3, "stream_set_timeout", NULL, 110, _0, &_1, &_2);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_3))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_socket_exception_ce, "Failed: stream_set_timeout", "yb/socket/tcpclient.zep", 76);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Socket_TcpClient, enableCrypto) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *cryptoType, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cryptoType);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("handler"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "stream_socket_enable_crypto", NULL, 111, _0, ZEPHIR_GLOBAL(global_true), cryptoType);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_socket_exception_ce, "Failed: stream_socket_enable_crypto", "yb/socket/tcpclient.zep", 83);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Socket_TcpClient, write) {

	zval *data_param = NULL, *_0, *_1;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_strval(data, data_param);


	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("handler"), PH_NOISY_CC);
	zephir_fwrite(_0, _1, data TSRMLS_CC);
	if (unlikely(ZEPHIR_IS_FALSE_IDENTICAL(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_socket_exception_ce, "Cannot write", "yb/socket/tcpclient.zep", 90);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Socket_TcpClient, readLine) {

	zval *line = NULL, *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("handler"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&line, "fgets", NULL, 112, _0);
	zephir_check_call_status();
	if (unlikely(ZEPHIR_IS_FALSE_IDENTICAL(line))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_socket_exception_ce, "Cannot read line", "yb/socket/tcpclient.zep", 100);
		return;
	}
	RETURN_CCTOR(line);

}

PHP_METHOD(Yb_Socket_TcpClient, readAll) {

	zval *line = NULL, *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("handler"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&line, "stream_get_contents", NULL, 113, _0);
	zephir_check_call_status();
	if (unlikely(ZEPHIR_IS_FALSE_IDENTICAL(line))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_socket_exception_ce, "Cannot read all", "yb/socket/tcpclient.zep", 112);
		return;
	}
	RETURN_CCTOR(line);

}

PHP_METHOD(Yb_Socket_TcpClient, readLength) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *len_param = NULL, *line = NULL, *_4, _5, *_0$$3, _1$$3, *_2$$3 = NULL, *_3$$3;
	long len;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &len_param);

	len = zephir_get_intval(len_param);


	if (unlikely(len < 1)) {
		ZEPHIR_INIT_VAR(_0$$3);
		object_init_ex(_0$$3, yb_socket_exception_ce);
		ZEPHIR_SINIT_VAR(_1$$3);
		ZVAL_LONG(&_1$$3, len);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "strval", NULL, 114, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_3$$3);
		ZEPHIR_CONCAT_SV(_3$$3, "Invalid read length: ", _2$$3);
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "__construct", NULL, 2, _3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0$$3, "yb/socket/tcpclient.zep", 123 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("handler"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_LONG(&_5, len);
	ZEPHIR_CALL_FUNCTION(&line, "stream_get_contents", NULL, 113, _4, &_5);
	zephir_check_call_status();
	if (unlikely(ZEPHIR_IS_FALSE_IDENTICAL(line))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_socket_exception_ce, "Cannot read length", "yb/socket/tcpclient.zep", 128);
		return;
	}
	RETURN_CCTOR(line);

}

PHP_METHOD(Yb_Socket_TcpClient, readMaxLength) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *len_param = NULL, *line = NULL, *_4, _5, *_0$$3, _1$$3, *_2$$3 = NULL, *_3$$3;
	long len;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &len_param);

	len = zephir_get_intval(len_param);


	if (unlikely(len < 1)) {
		ZEPHIR_INIT_VAR(_0$$3);
		object_init_ex(_0$$3, yb_socket_exception_ce);
		ZEPHIR_SINIT_VAR(_1$$3);
		ZVAL_LONG(&_1$$3, len);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "strval", NULL, 114, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_3$$3);
		ZEPHIR_CONCAT_SV(_3$$3, "Invalid read max length: ", _2$$3);
		ZEPHIR_CALL_METHOD(NULL, _0$$3, "__construct", NULL, 2, _3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0$$3, "yb/socket/tcpclient.zep", 139 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("handler"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_LONG(&_5, len);
	ZEPHIR_CALL_FUNCTION(&line, "fread", NULL, 115, _4, &_5);
	zephir_check_call_status();
	if (unlikely(ZEPHIR_IS_FALSE_IDENTICAL(line))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_socket_exception_ce, "Cannot read max length", "yb/socket/tcpclient.zep", 144);
		return;
	}
	RETURN_CCTOR(line);

}


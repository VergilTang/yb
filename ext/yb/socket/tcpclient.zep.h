
extern zend_class_entry *yb_socket_tcpclient_ce;

ZEPHIR_INIT_CLASS(Yb_Socket_TcpClient);

PHP_METHOD(Yb_Socket_TcpClient, __construct);
PHP_METHOD(Yb_Socket_TcpClient, __destruct);
PHP_METHOD(Yb_Socket_TcpClient, getInternalHandler);
PHP_METHOD(Yb_Socket_TcpClient, setTcpNodelay);
PHP_METHOD(Yb_Socket_TcpClient, setBlocking);
PHP_METHOD(Yb_Socket_TcpClient, setIoTimeout);
PHP_METHOD(Yb_Socket_TcpClient, enableCrypto);
PHP_METHOD(Yb_Socket_TcpClient, readLine);
PHP_METHOD(Yb_Socket_TcpClient, readAll);
PHP_METHOD(Yb_Socket_TcpClient, readLength);
PHP_METHOD(Yb_Socket_TcpClient, write);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_socket_tcpclient___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, host)
	ZEND_ARG_INFO(0, port)
	ZEND_ARG_INFO(0, timeout)
	ZEND_ARG_INFO(0, persistent)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_socket_tcpclient_settcpnodelay, 0, 0, 1)
	ZEND_ARG_INFO(0, on)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_socket_tcpclient_setblocking, 0, 0, 1)
	ZEND_ARG_INFO(0, on)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_socket_tcpclient_setiotimeout, 0, 0, 1)
	ZEND_ARG_INFO(0, ioTimeout)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_socket_tcpclient_enablecrypto, 0, 0, 1)
	ZEND_ARG_INFO(0, cryptoType)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_socket_tcpclient_readlength, 0, 0, 1)
	ZEND_ARG_INFO(0, len)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_socket_tcpclient_write, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_socket_tcpclient_method_entry) {
	PHP_ME(Yb_Socket_TcpClient, __construct, arginfo_yb_socket_tcpclient___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_Socket_TcpClient, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(Yb_Socket_TcpClient, getInternalHandler, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Socket_TcpClient, setTcpNodelay, arginfo_yb_socket_tcpclient_settcpnodelay, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Socket_TcpClient, setBlocking, arginfo_yb_socket_tcpclient_setblocking, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Socket_TcpClient, setIoTimeout, arginfo_yb_socket_tcpclient_setiotimeout, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Socket_TcpClient, enableCrypto, arginfo_yb_socket_tcpclient_enablecrypto, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Socket_TcpClient, readLine, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Socket_TcpClient, readAll, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Socket_TcpClient, readLength, arginfo_yb_socket_tcpclient_readlength, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Socket_TcpClient, write, arginfo_yb_socket_tcpclient_write, ZEND_ACC_PUBLIC)
	PHP_FE_END
};


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
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Yb_Redis_Client) {

	ZEPHIR_REGISTER_CLASS(Yb\\Redis, Client, yb, redis_client, yb_redis_client_method_entry, 0);

	zend_declare_property_null(yb_redis_client_ce, SL("connections"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Yb_Redis_Client, hashSlot) {

	int r = 0;
	zval *s_param = NULL;
	zval *s = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &s_param);

	zephir_get_strval(s, s_param);


	r = yb_redis_cluster_hash_slot( s);
	RETURN_MM_LONG(r);

}

PHP_METHOD(Yb_Redis_Client, __construct) {

	zval *connection;

	zephir_fetch_params(0, 1, 0, &connection);




}


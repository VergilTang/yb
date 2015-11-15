
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


ZEPHIR_INIT_CLASS(Yb_RedisCluster_ErrorAsk) {

	ZEPHIR_REGISTER_CLASS_EX(Yb\\RedisCluster, ErrorAsk, yb, rediscluster_errorask, yb_rediscluster_error_ce, NULL, 0);

	zend_declare_property_null(yb_rediscluster_errorask_ce, SL("slot"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(yb_rediscluster_errorask_ce, SL("host"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(yb_rediscluster_errorask_ce, SL("port"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}


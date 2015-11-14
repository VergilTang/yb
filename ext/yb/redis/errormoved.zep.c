
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


ZEPHIR_INIT_CLASS(Yb_Redis_ErrorMoved) {

	ZEPHIR_REGISTER_CLASS_EX(Yb\\Redis, ErrorMoved, yb, redis_errormoved, yb_redis_error_ce, NULL, 0);

	zend_declare_property_null(yb_redis_errormoved_ce, SL("slot"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(yb_redis_errormoved_ce, SL("host"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(yb_redis_errormoved_ce, SL("port"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}


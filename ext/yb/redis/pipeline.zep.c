
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


ZEPHIR_INIT_CLASS(Yb_Redis_Pipeline) {

	ZEPHIR_REGISTER_CLASS(Yb\\Redis, Pipeline, yb, redis_pipeline, yb_redis_pipeline_method_entry, 0);

	zend_declare_property_null(yb_redis_pipeline_ce, SL("client"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_redis_pipeline_ce, SL("cmds"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Yb_Redis_Pipeline, __construct) {

	zval *client;

	zephir_fetch_params(0, 1, 0, &client);



	zephir_update_property_this(this_ptr, SL("client"), client TSRMLS_CC);

}

PHP_METHOD(Yb_Redis_Pipeline, __call) {

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
	ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", NULL, 92, cmd, method);
	ZEPHIR_UNREF(cmd);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("cmds"), cmd TSRMLS_CC);
	RETURN_THIS();

}


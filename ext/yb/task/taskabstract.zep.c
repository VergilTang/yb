
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
#include "kernel/string.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Yb_Task_TaskAbstract) {

	ZEPHIR_REGISTER_CLASS(Yb\\Task, TaskAbstract, yb, task_taskabstract, yb_task_taskabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(yb_task_taskabstract_ce, SL("data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(yb_task_taskabstract_ce TSRMLS_CC, 1, yb_task_taskinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Yb_Task_TaskAbstract, serialize) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	zephir_json_encode(return_value, &(return_value), _0, 0  TSRMLS_CC);
	return;

}

PHP_METHOD(Yb_Task_TaskAbstract, unserialize) {

	zval *data_param = NULL, *_0;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_strval(data, data_param);


	ZEPHIR_INIT_VAR(_0);
	zephir_json_decode(_0, &(_0), data, zephir_get_intval(ZEPHIR_GLOBAL(global_true))  TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("data"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}


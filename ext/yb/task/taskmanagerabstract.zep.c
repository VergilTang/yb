
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
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Yb_Task_TaskManagerAbstract) {

	ZEPHIR_REGISTER_CLASS(Yb\\Task, TaskManagerAbstract, yb, task_taskmanagerabstract, yb_task_taskmanagerabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(yb_task_taskmanagerabstract_ce, SL("taskExecutor"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(yb_task_taskmanagerabstract_ce, SL("sleep"), -1, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Yb_Task_TaskManagerAbstract, produce) {

}

PHP_METHOD(Yb_Task_TaskManagerAbstract, consume) {

}

PHP_METHOD(Yb_Task_TaskManagerAbstract, setTaskExecutor) {

	zval *taskExecutor;

	zephir_fetch_params(0, 1, 0, &taskExecutor);



	zephir_update_property_this(this_ptr, SL("taskExecutor"), taskExecutor TSRMLS_CC);

}

PHP_METHOD(Yb_Task_TaskManagerAbstract, setSleep) {

	zval *sleep_param = NULL, *_0;
	long sleep;

	zephir_fetch_params(0, 1, 0, &sleep_param);

	sleep = zephir_get_intval(sleep_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, sleep);
	zephir_update_property_this(this_ptr, SL("sleep"), _0 TSRMLS_CC);

}

PHP_METHOD(Yb_Task_TaskManagerAbstract, getSleep) {

	

	RETURN_MEMBER(this_ptr, "sleep");

}

PHP_METHOD(Yb_Task_TaskManagerAbstract, runTask) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *task_param = NULL, *re = NULL, *ex = NULL, *_0, *_1$$4, *_2$$4, *_3$$5;
	zval *task = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &task_param);

	zephir_get_arrval(task, task_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("taskExecutor"), PH_NOISY_CC);
	if (unlikely(!zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_task_exception_ce, "Missing task executor", "yb/task/taskmanagerabstract.zep", 31);
		return;
	}

	/* try_start_1: */

		_1$$4 = zephir_fetch_nproperty_this(this_ptr, SL("taskExecutor"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&re, _1$$4, "executetask", NULL, 0, task);
		zephir_check_call_status_or_jump(try_end_1);
		_2$$4 = zephir_fetch_nproperty_this(this_ptr, SL("taskExecutor"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _2$$4, "ontaskreturn", NULL, 0, task, re);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_CPY_WRT(ex, EG(exception));
		if (zephir_instance_of_ev(ex, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			_3$$5 = zephir_fetch_nproperty_this(this_ptr, SL("taskExecutor"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, _3$$5, "ontaskexception", NULL, 0, task, ex);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Task_TaskManagerAbstract, __invoke) {

	zval *task = NULL, *_2$$3, *_3$$3;
	zephir_fcall_cache_entry *_0 = NULL, *_1 = NULL, *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	while (1) {
		ZEPHIR_CALL_METHOD(&task, this_ptr, "consume", &_0, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(task) != IS_NULL) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "runtask", &_1, 0, task);
			zephir_check_call_status();
			continue;
		}
		_2$$3 = zephir_fetch_nproperty_this(this_ptr, SL("sleep"), PH_NOISY_CC);
		if (ZEPHIR_LT_LONG(_2$$3, 0)) {
			RETURN_MM_NULL();
		}
		_3$$3 = zephir_fetch_nproperty_this(this_ptr, SL("sleep"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "sleep", &_4, 21, _3$$3);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Task_TaskManagerAbstract, serializeTask) {

	zval *task_param = NULL;
	zval *task = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &task_param);

	zephir_get_arrval(task, task_param);


	zephir_json_encode(return_value, &(return_value), task, 0  TSRMLS_CC);
	RETURN_MM();

}

PHP_METHOD(Yb_Task_TaskManagerAbstract, unserializeTask) {

	zval *task_param = NULL;
	zval *task = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &task_param);

	zephir_get_strval(task, task_param);


	zephir_json_decode(return_value, &(return_value), task, zephir_get_intval(ZEPHIR_GLOBAL(global_true))  TSRMLS_CC);
	RETURN_MM();

}


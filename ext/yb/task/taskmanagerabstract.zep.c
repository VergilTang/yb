
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
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Yb_Task_TaskManagerAbstract) {

	ZEPHIR_REGISTER_CLASS(Yb\\Task, TaskManagerAbstract, yb, task_taskmanagerabstract, yb_task_taskmanagerabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_long(yb_task_taskmanagerabstract_ce, SL("sleep"), -1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_task_taskmanagerabstract_ce, SL("taskFactory"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(yb_task_taskmanagerabstract_ce TSRMLS_CC, 1, yb_task_taskmanagerinterface_ce);
	return SUCCESS;

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

PHP_METHOD(Yb_Task_TaskManagerAbstract, setTaskFactory) {

	zval *taskFactory;

	zephir_fetch_params(0, 1, 0, &taskFactory);



	zephir_update_property_this(this_ptr, SL("taskFactory"), taskFactory TSRMLS_CC);

}

PHP_METHOD(Yb_Task_TaskManagerAbstract, getTaskFactory) {

	

	RETURN_MEMBER(this_ptr, "taskFactory");

}

PHP_METHOD(Yb_Task_TaskManagerAbstract, hasTask) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("taskFactory"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "__isset", NULL, 0, name);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Task_TaskManagerAbstract, getTask) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *_0;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("taskFactory"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "__get", NULL, 0, name);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Task_TaskManagerAbstract, runTask) {

	zend_bool _8;
	zval *name = NULL, *_4 = NULL, *_7$$3, *_10$$4;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *taskData_param = NULL, *task = NULL, *input = NULL, *re = NULL, *ex = NULL, *_0 = NULL, *_2, *_3, *_5 = NULL, *_6$$3, *_9$$4, *_11$$5, *_12$$5;
	zval *taskData = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &taskData_param);

	zephir_get_arrval(taskData, taskData_param);


	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "name", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "defaultTask", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_0, yb_std_ce, "valueat", &_1, 5, taskData, _2, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	zephir_get_strval(_4, _0);
	ZEPHIR_CPY_WRT(name, _4);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "hastask", NULL, 0, name);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_5))) {
		ZEPHIR_INIT_VAR(_6$$3);
		object_init_ex(_6$$3, yb_task_exception_ce);
		ZEPHIR_INIT_VAR(_7$$3);
		ZEPHIR_CONCAT_SV(_7$$3, "Cannot find task: ", name);
		ZEPHIR_CALL_METHOD(NULL, _6$$3, "__construct", NULL, 2, _7$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_6$$3, "yb/task/taskmanagerabstract.zep", 48 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&task, this_ptr, "gettask", NULL, 0, name);
	zephir_check_call_status();
	_8 = Z_TYPE_P(task) != IS_OBJECT;
	if (!(_8)) {
		_8 = !((zephir_instance_of_ev(task, yb_task_taskinterface_ce TSRMLS_CC)));
	}
	if (unlikely(_8)) {
		ZEPHIR_INIT_VAR(_9$$4);
		object_init_ex(_9$$4, yb_task_exception_ce);
		ZEPHIR_INIT_VAR(_10$$4);
		ZEPHIR_CONCAT_SV(_10$$4, "Invalid task: ", name);
		ZEPHIR_CALL_METHOD(NULL, _9$$4, "__construct", NULL, 2, _10$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_9$$4, "yb/task/taskmanagerabstract.zep", 53 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}

	/* try_start_1: */

		ZEPHIR_INIT_VAR(_11$$5);
		array_init(_11$$5);
		ZEPHIR_INIT_VAR(_12$$5);
		ZVAL_STRING(_12$$5, "input", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_CE_STATIC(&input, yb_std_ce, "valueat", &_1, 5, taskData, _12$$5, _11$$5);
		zephir_check_temp_parameter(_12$$5);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&re, task, "__invoke", NULL, 0, input);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(NULL, task, "onreturn", NULL, 0, this_ptr, re);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_CPY_WRT(ex, EG(exception));
		if (zephir_instance_of_ev(ex, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CALL_METHOD(NULL, task, "onexception", NULL, 0, this_ptr, ex);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Task_TaskManagerAbstract, __invoke) {

	zval *taskData = NULL, *_2$$3, *_3$$3;
	zephir_fcall_cache_entry *_0 = NULL, *_1 = NULL, *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	while (1) {
		ZEPHIR_CALL_METHOD(&taskData, this_ptr, "consume", &_0, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(taskData) != IS_NULL) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "runtask", &_1, 0, taskData);
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

PHP_METHOD(Yb_Task_TaskManagerAbstract, serializeTaskData) {

	zval *taskData_param = NULL;
	zval *taskData = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &taskData_param);

	zephir_get_arrval(taskData, taskData_param);


	zephir_json_encode(return_value, &(return_value), taskData, 0  TSRMLS_CC);
	RETURN_MM();

}

PHP_METHOD(Yb_Task_TaskManagerAbstract, unserializeTaskData) {

	zval *taskData_param = NULL;
	zval *taskData = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &taskData_param);

	zephir_get_strval(taskData, taskData_param);


	zephir_json_decode(return_value, &(return_value), taskData, zephir_get_intval(ZEPHIR_GLOBAL(global_true))  TSRMLS_CC);
	RETURN_MM();

}


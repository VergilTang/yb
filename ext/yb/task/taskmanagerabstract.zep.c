
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
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Yb_Task_TaskManagerAbstract) {

	ZEPHIR_REGISTER_CLASS(Yb\\Task, TaskManagerAbstract, yb, task_taskmanagerabstract, yb_task_taskmanagerabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_class_implements(yb_task_taskmanagerabstract_ce TSRMLS_CC, 1, yb_task_taskmanagerinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Yb_Task_TaskManagerAbstract, onReturn) {

	zval *task, *r;

	zephir_fetch_params(0, 2, 0, &task, &r);



	RETURN_NULL();

}

PHP_METHOD(Yb_Task_TaskManagerAbstract, onException) {

	zval *task, *e;

	zephir_fetch_params(0, 2, 0, &task, &e);



	zephir_throw_exception_debug(e, "yb/task/taskmanagerabstract.zep", 12 TSRMLS_CC);
	return;

}


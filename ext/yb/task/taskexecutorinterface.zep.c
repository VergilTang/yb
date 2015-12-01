
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Yb_Task_TaskExecutorInterface) {

	ZEPHIR_REGISTER_INTERFACE(Yb\\Task, TaskExecutorInterface, yb, task_taskexecutorinterface, yb_task_taskexecutorinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Yb_Task_TaskExecutorInterface, executeTask);

ZEPHIR_DOC_METHOD(Yb_Task_TaskExecutorInterface, onTaskReturn);

ZEPHIR_DOC_METHOD(Yb_Task_TaskExecutorInterface, onTaskException);


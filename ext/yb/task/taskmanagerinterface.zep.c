
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Yb_Task_TaskManagerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Yb\\Task, TaskManagerInterface, yb, task_taskmanagerinterface, yb_task_taskmanagerinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Yb_Task_TaskManagerInterface, produce);

ZEPHIR_DOC_METHOD(Yb_Task_TaskManagerInterface, consume);

ZEPHIR_DOC_METHOD(Yb_Task_TaskManagerInterface, hasTask);

ZEPHIR_DOC_METHOD(Yb_Task_TaskManagerInterface, getTask);

ZEPHIR_DOC_METHOD(Yb_Task_TaskManagerInterface, runTask);

ZEPHIR_DOC_METHOD(Yb_Task_TaskManagerInterface, __invoke);

ZEPHIR_DOC_METHOD(Yb_Task_TaskManagerInterface, serializeTaskData);

ZEPHIR_DOC_METHOD(Yb_Task_TaskManagerInterface, unserializeTaskData);


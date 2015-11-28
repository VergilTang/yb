
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Yb_Task_TaskInterface) {

	ZEPHIR_REGISTER_INTERFACE(Yb\\Task, TaskInterface, yb, task_taskinterface, yb_task_taskinterface_method_entry);

	zend_class_implements(yb_task_taskinterface_ce TSRMLS_CC, 1, zend_ce_serializable);
	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Yb_Task_TaskInterface, __invoke);


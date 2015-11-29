
extern zend_class_entry *yb_task_taskinterface_ce;

ZEPHIR_INIT_CLASS(Yb_Task_TaskInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_task_taskinterface___invoke, 0, 0, 1)
	ZEND_ARG_INFO(0, input)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_task_taskinterface_onreturn, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, taskManager, Yb\\Task\\TaskManagerInterface, 0)
	ZEND_ARG_INFO(0, re)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_task_taskinterface_onexception, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, taskManager, Yb\\Task\\TaskManagerInterface, 0)
	ZEND_ARG_OBJ_INFO(0, ex, Exception, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_task_taskinterface_method_entry) {
	PHP_ABSTRACT_ME(Yb_Task_TaskInterface, __invoke, arginfo_yb_task_taskinterface___invoke)
	PHP_ABSTRACT_ME(Yb_Task_TaskInterface, onReturn, arginfo_yb_task_taskinterface_onreturn)
	PHP_ABSTRACT_ME(Yb_Task_TaskInterface, onException, arginfo_yb_task_taskinterface_onexception)
	PHP_FE_END
};

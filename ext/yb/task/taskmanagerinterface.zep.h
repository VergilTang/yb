
extern zend_class_entry *yb_task_taskmanagerinterface_ce;

ZEPHIR_INIT_CLASS(Yb_Task_TaskManagerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_task_taskmanagerinterface_produce, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, task, Yb\\Task\\TaskInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_task_taskmanagerinterface_onreturn, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, task, Yb\\Task\\TaskInterface, 0)
	ZEND_ARG_INFO(0, r)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_task_taskmanagerinterface_onexception, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, task, Yb\\Task\\TaskInterface, 0)
	ZEND_ARG_OBJ_INFO(0, e, Exception, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_task_taskmanagerinterface_method_entry) {
	PHP_ABSTRACT_ME(Yb_Task_TaskManagerInterface, produce, arginfo_yb_task_taskmanagerinterface_produce)
	PHP_ABSTRACT_ME(Yb_Task_TaskManagerInterface, consume, NULL)
	PHP_ABSTRACT_ME(Yb_Task_TaskManagerInterface, onReturn, arginfo_yb_task_taskmanagerinterface_onreturn)
	PHP_ABSTRACT_ME(Yb_Task_TaskManagerInterface, onException, arginfo_yb_task_taskmanagerinterface_onexception)
	PHP_FE_END
};

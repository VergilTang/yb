
extern zend_class_entry *yb_task_taskmanagerinterface_ce;

ZEPHIR_INIT_CLASS(Yb_Task_TaskManagerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_task_taskmanagerinterface_produce, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, taskData, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_task_taskmanagerinterface_hastask, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_task_taskmanagerinterface_gettask, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_task_taskmanagerinterface_runtask, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, taskData, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_task_taskmanagerinterface_serializetaskdata, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, taskData, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_task_taskmanagerinterface_unserializetaskdata, 0, 0, 1)
	ZEND_ARG_INFO(0, taskData)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_task_taskmanagerinterface_method_entry) {
	PHP_ABSTRACT_ME(Yb_Task_TaskManagerInterface, produce, arginfo_yb_task_taskmanagerinterface_produce)
	PHP_ABSTRACT_ME(Yb_Task_TaskManagerInterface, consume, NULL)
	PHP_ABSTRACT_ME(Yb_Task_TaskManagerInterface, hasTask, arginfo_yb_task_taskmanagerinterface_hastask)
	PHP_ABSTRACT_ME(Yb_Task_TaskManagerInterface, getTask, arginfo_yb_task_taskmanagerinterface_gettask)
	PHP_ABSTRACT_ME(Yb_Task_TaskManagerInterface, runTask, arginfo_yb_task_taskmanagerinterface_runtask)
	PHP_ABSTRACT_ME(Yb_Task_TaskManagerInterface, __invoke, NULL)
	PHP_ABSTRACT_ME(Yb_Task_TaskManagerInterface, serializeTaskData, arginfo_yb_task_taskmanagerinterface_serializetaskdata)
	PHP_ABSTRACT_ME(Yb_Task_TaskManagerInterface, unserializeTaskData, arginfo_yb_task_taskmanagerinterface_unserializetaskdata)
	PHP_FE_END
};

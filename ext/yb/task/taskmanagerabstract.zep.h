
extern zend_class_entry *yb_task_taskmanagerabstract_ce;

ZEPHIR_INIT_CLASS(Yb_Task_TaskManagerAbstract);

PHP_METHOD(Yb_Task_TaskManagerAbstract, produce);
PHP_METHOD(Yb_Task_TaskManagerAbstract, consume);
PHP_METHOD(Yb_Task_TaskManagerAbstract, setTaskExecutor);
PHP_METHOD(Yb_Task_TaskManagerAbstract, setSleep);
PHP_METHOD(Yb_Task_TaskManagerAbstract, getSleep);
PHP_METHOD(Yb_Task_TaskManagerAbstract, runTask);
PHP_METHOD(Yb_Task_TaskManagerAbstract, __invoke);
PHP_METHOD(Yb_Task_TaskManagerAbstract, serializeTask);
PHP_METHOD(Yb_Task_TaskManagerAbstract, unserializeTask);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_task_taskmanagerabstract_produce, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, task, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_task_taskmanagerabstract_settaskexecutor, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, taskExecutor, Yb\\Task\\TaskExecutorInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_task_taskmanagerabstract_setsleep, 0, 0, 1)
	ZEND_ARG_INFO(0, sleep)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_task_taskmanagerabstract_runtask, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, task, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_task_taskmanagerabstract_serializetask, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, task, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_task_taskmanagerabstract_unserializetask, 0, 0, 1)
	ZEND_ARG_INFO(0, task)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_task_taskmanagerabstract_method_entry) {
	PHP_ME(Yb_Task_TaskManagerAbstract, produce, arginfo_yb_task_taskmanagerabstract_produce, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Task_TaskManagerAbstract, consume, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Task_TaskManagerAbstract, setTaskExecutor, arginfo_yb_task_taskmanagerabstract_settaskexecutor, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Task_TaskManagerAbstract, setSleep, arginfo_yb_task_taskmanagerabstract_setsleep, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Task_TaskManagerAbstract, getSleep, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Task_TaskManagerAbstract, runTask, arginfo_yb_task_taskmanagerabstract_runtask, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Task_TaskManagerAbstract, __invoke, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Task_TaskManagerAbstract, serializeTask, arginfo_yb_task_taskmanagerabstract_serializetask, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Task_TaskManagerAbstract, unserializeTask, arginfo_yb_task_taskmanagerabstract_unserializetask, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

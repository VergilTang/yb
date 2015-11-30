
extern zend_class_entry *yb_task_taskmanagerabstract_ce;

ZEPHIR_INIT_CLASS(Yb_Task_TaskManagerAbstract);

PHP_METHOD(Yb_Task_TaskManagerAbstract, setSleep);
PHP_METHOD(Yb_Task_TaskManagerAbstract, getSleep);
PHP_METHOD(Yb_Task_TaskManagerAbstract, setTaskFactory);
PHP_METHOD(Yb_Task_TaskManagerAbstract, getTaskFactory);
PHP_METHOD(Yb_Task_TaskManagerAbstract, hasTask);
PHP_METHOD(Yb_Task_TaskManagerAbstract, getTask);
PHP_METHOD(Yb_Task_TaskManagerAbstract, runTask);
PHP_METHOD(Yb_Task_TaskManagerAbstract, __invoke);
PHP_METHOD(Yb_Task_TaskManagerAbstract, serializeTaskData);
PHP_METHOD(Yb_Task_TaskManagerAbstract, unserializeTaskData);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_task_taskmanagerabstract_setsleep, 0, 0, 1)
	ZEND_ARG_INFO(0, sleep)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_task_taskmanagerabstract_settaskfactory, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, taskFactory, Yb\\Factory\\FactoryInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_task_taskmanagerabstract_hastask, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_task_taskmanagerabstract_gettask, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_task_taskmanagerabstract_runtask, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, taskData, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_task_taskmanagerabstract_serializetaskdata, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, taskData, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_task_taskmanagerabstract_unserializetaskdata, 0, 0, 1)
	ZEND_ARG_INFO(0, taskData)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_task_taskmanagerabstract_method_entry) {
	PHP_ME(Yb_Task_TaskManagerAbstract, setSleep, arginfo_yb_task_taskmanagerabstract_setsleep, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Task_TaskManagerAbstract, getSleep, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Task_TaskManagerAbstract, setTaskFactory, arginfo_yb_task_taskmanagerabstract_settaskfactory, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Task_TaskManagerAbstract, getTaskFactory, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Task_TaskManagerAbstract, hasTask, arginfo_yb_task_taskmanagerabstract_hastask, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Task_TaskManagerAbstract, getTask, arginfo_yb_task_taskmanagerabstract_gettask, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Task_TaskManagerAbstract, runTask, arginfo_yb_task_taskmanagerabstract_runtask, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Task_TaskManagerAbstract, __invoke, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Task_TaskManagerAbstract, serializeTaskData, arginfo_yb_task_taskmanagerabstract_serializetaskdata, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Task_TaskManagerAbstract, unserializeTaskData, arginfo_yb_task_taskmanagerabstract_unserializetaskdata, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

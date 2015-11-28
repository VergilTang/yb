
extern zend_class_entry *yb_task_taskmanagerabstract_ce;

ZEPHIR_INIT_CLASS(Yb_Task_TaskManagerAbstract);

PHP_METHOD(Yb_Task_TaskManagerAbstract, onReturn);
PHP_METHOD(Yb_Task_TaskManagerAbstract, onException);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_task_taskmanagerabstract_onreturn, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, task, Yb\\Task\\TaskInterface, 0)
	ZEND_ARG_INFO(0, r)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_task_taskmanagerabstract_onexception, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, task, Yb\\Task\\TaskInterface, 0)
	ZEND_ARG_OBJ_INFO(0, e, Exception, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_task_taskmanagerabstract_method_entry) {
	PHP_ME(Yb_Task_TaskManagerAbstract, onReturn, arginfo_yb_task_taskmanagerabstract_onreturn, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Task_TaskManagerAbstract, onException, arginfo_yb_task_taskmanagerabstract_onexception, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

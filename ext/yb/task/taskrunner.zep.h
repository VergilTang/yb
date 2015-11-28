
extern zend_class_entry *yb_task_taskrunner_ce;

ZEPHIR_INIT_CLASS(Yb_Task_TaskRunner);

PHP_METHOD(Yb_Task_TaskRunner, __construct);
PHP_METHOD(Yb_Task_TaskRunner, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_task_taskrunner___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, taskManager, Yb\\Task\\TaskManagerInterface, 0)
	ZEND_ARG_INFO(0, sleep)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_task_taskrunner_method_entry) {
	PHP_ME(Yb_Task_TaskRunner, __construct, arginfo_yb_task_taskrunner___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_Task_TaskRunner, __invoke, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

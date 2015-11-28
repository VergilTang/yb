
extern zend_class_entry *yb_task_taskabstract_ce;

ZEPHIR_INIT_CLASS(Yb_Task_TaskAbstract);

PHP_METHOD(Yb_Task_TaskAbstract, serialize);
PHP_METHOD(Yb_Task_TaskAbstract, unserialize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_task_taskabstract_unserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_task_taskabstract_method_entry) {
	PHP_ME(Yb_Task_TaskAbstract, serialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Task_TaskAbstract, unserialize, arginfo_yb_task_taskabstract_unserialize, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

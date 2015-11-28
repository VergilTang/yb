
extern zend_class_entry *yb_task_taskinterface_ce;

ZEPHIR_INIT_CLASS(Yb_Task_TaskInterface);

ZEPHIR_INIT_FUNCS(yb_task_taskinterface_method_entry) {
	PHP_ABSTRACT_ME(Yb_Task_TaskInterface, __invoke, NULL)
	PHP_FE_END
};

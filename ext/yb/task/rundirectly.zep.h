
extern zend_class_entry *yb_task_rundirectly_ce;

ZEPHIR_INIT_CLASS(Yb_Task_RunDirectly);

PHP_METHOD(Yb_Task_RunDirectly, produce);
PHP_METHOD(Yb_Task_RunDirectly, consume);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_task_rundirectly_produce, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, taskData, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_task_rundirectly_method_entry) {
	PHP_ME(Yb_Task_RunDirectly, produce, arginfo_yb_task_rundirectly_produce, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Task_RunDirectly, consume, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

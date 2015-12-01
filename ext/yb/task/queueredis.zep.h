
extern zend_class_entry *yb_task_queueredis_ce;

ZEPHIR_INIT_CLASS(Yb_Task_QueueRedis);

PHP_METHOD(Yb_Task_QueueRedis, __construct);
PHP_METHOD(Yb_Task_QueueRedis, produce);
PHP_METHOD(Yb_Task_QueueRedis, consume);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_task_queueredis___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, redis)
	ZEND_ARG_INFO(0, queueKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_task_queueredis_produce, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, task, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_task_queueredis_method_entry) {
	PHP_ME(Yb_Task_QueueRedis, __construct, arginfo_yb_task_queueredis___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_Task_QueueRedis, produce, arginfo_yb_task_queueredis_produce, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Task_QueueRedis, consume, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};


#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Yb_Task_QueueRedis) {

	ZEPHIR_REGISTER_CLASS_EX(Yb\\Task, QueueRedis, yb, task_queueredis, yb_task_taskmanagerabstract_ce, yb_task_queueredis_method_entry, 0);

	zend_declare_property_null(yb_task_queueredis_ce, SL("redis"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_task_queueredis_ce, SL("queueKey"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Yb_Task_QueueRedis, __construct) {

	zval *queueKey = NULL;
	zval *redis, *queueKey_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &redis, &queueKey_param);

	zephir_get_strval(queueKey, queueKey_param);


	zephir_update_property_this(this_ptr, SL("redis"), redis TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("queueKey"), queueKey TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Task_QueueRedis, produce) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *task, *_0, *_1 = NULL, *_2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &task);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("queueKey"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_3, "serialize", NULL, 29, task);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, _0, "lpush", NULL, 0, _2, _3);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_task_exception_ce, "Fail when redis lpush", "yb/task/queueredis.zep", 17);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Task_QueueRedis, consume) {

	zend_bool _3;
	zval *task = NULL, *_0, *_1, *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("queueKey"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&task, _0, "rpop", NULL, 0, _1);
	zephir_check_call_status();
	if (!(zephir_is_true(task))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_FUNCTION(&_2, "unserialize", NULL, 30, task);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(task, _2);
	_3 = Z_TYPE_P(task) != IS_OBJECT;
	if (!(_3)) {
		_3 = !((zephir_instance_of_ev(task, yb_task_taskinterface_ce TSRMLS_CC)));
	}
	if (unlikely(_3)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_task_exception_ce, "Invalid task from redis", "yb/task/queueredis.zep", 32);
		return;
	}
	RETURN_CCTOR(task);

}


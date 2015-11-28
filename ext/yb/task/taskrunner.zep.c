
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Yb_Task_TaskRunner) {

	ZEPHIR_REGISTER_CLASS(Yb\\Task, TaskRunner, yb, task_taskrunner, yb_task_taskrunner_method_entry, 0);

	zend_declare_property_null(yb_task_taskrunner_ce, SL("taskManager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_task_taskrunner_ce, SL("sleep"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Yb_Task_TaskRunner, __construct) {

	long sleep;
	zval *taskManager, *sleep_param = NULL, *_0;

	zephir_fetch_params(0, 1, 1, &taskManager, &sleep_param);

	if (!sleep_param) {
		sleep = 0;
	} else {
		sleep = zephir_get_intval(sleep_param);
	}


	zephir_update_property_this(this_ptr, SL("taskManager"), taskManager TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, sleep);
	zephir_update_property_this(this_ptr, SL("sleep"), _0 TSRMLS_CC);

}

PHP_METHOD(Yb_Task_TaskRunner, __invoke) {

	zval *task = NULL, *r = NULL, *e = NULL, *_0$$3, *_3$$3, *_4$$3, *_1$$5, *_2$$6;
	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	while (1) {
		_0$$3 = zephir_fetch_nproperty_this(this_ptr, SL("taskManager"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&task, _0$$3, "consume", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(task) != IS_NULL) {

			/* try_start_1: */

				ZEPHIR_CALL_METHOD(&r, task, "__invoke", NULL, 0);
				zephir_check_call_status_or_jump(try_end_1);
				_1$$5 = zephir_fetch_nproperty_this(this_ptr, SL("taskManager"), PH_NOISY_CC);
				ZEPHIR_CALL_METHOD(NULL, _1$$5, "onreturn", NULL, 0, task, r);
				zephir_check_call_status_or_jump(try_end_1);

			try_end_1:

			if (EG(exception)) {
				ZEPHIR_CPY_WRT(e, EG(exception));
				if (zephir_instance_of_ev(e, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
					zend_clear_exception(TSRMLS_C);
					_2$$6 = zephir_fetch_nproperty_this(this_ptr, SL("taskManager"), PH_NOISY_CC);
					ZEPHIR_CALL_METHOD(NULL, _2$$6, "onexception", NULL, 0, task, e);
					zephir_check_call_status();
				}
			}
		}
		_3$$3 = zephir_fetch_nproperty_this(this_ptr, SL("sleep"), PH_NOISY_CC);
		if (ZEPHIR_LT_LONG(_3$$3, 0)) {
			RETURN_MM_NULL();
		}
		_4$$3 = zephir_fetch_nproperty_this(this_ptr, SL("sleep"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "sleep", &_5, 119, _4$$3);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}


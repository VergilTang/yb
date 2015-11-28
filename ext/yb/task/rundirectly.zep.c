
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Yb_Task_RunDirectly) {

	ZEPHIR_REGISTER_CLASS_EX(Yb\\Task, RunDirectly, yb, task_rundirectly, yb_task_taskmanagerabstract_ce, yb_task_rundirectly_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Yb_Task_RunDirectly, produce) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *task, *r = NULL, *e = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &task);




	/* try_start_1: */

		ZEPHIR_CALL_METHOD(&r, task, "__invoke", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "onreturn", NULL, 0, task, r);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_CPY_WRT(e, EG(exception));
		if (zephir_instance_of_ev(e, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "onexception", NULL, 0, task, e);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Task_RunDirectly, consume) {

	

	RETURN_NULL();

}


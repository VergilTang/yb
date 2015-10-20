
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Yb_Factory_Generated) {

	ZEPHIR_REGISTER_CLASS_EX(Yb\\Factory, Generated, yb, factory_generated, yb_factory_classname_ce, yb_factory_generated_method_entry, 0);

	zend_declare_property_null(yb_factory_generated_ce, SL("classNameGenerator"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Yb_Factory_Generated, __construct) {

	zephir_nts_static zend_class_entry *_1$$3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *classNameGenerator, *_0$$3, *_2$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &classNameGenerator);



	if (unlikely(!(zephir_is_callable(classNameGenerator TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(_0$$3);
		if (!_1$$3) {
			_1$$3 = zend_fetch_class(SL("Yb\\Factory\\Exception"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		}
		object_init_ex(_0$$3, _1$$3);
		if (zephir_has_constructor(_0$$3 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(_2$$3);
			ZVAL_STRING(_2$$3, "Class name generator is not callable", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _0$$3, "__construct", NULL, 0, _2$$3);
			zephir_check_temp_parameter(_2$$3);
			zephir_check_call_status();
		}
		zephir_throw_exception_debug(_0$$3, "yb/factory/generated.zep", 10 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_this(this_ptr, SL("classNameGenerator"), classNameGenerator TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Factory_Generated, getClassName) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *_0, *_1 = NULL;
	zval *name = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("classNameGenerator"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "call_user_func", NULL, 10, _0, name);
	zephir_check_call_status();
	zephir_get_strval(_2, _1);
	RETURN_CTOR(_2);

}


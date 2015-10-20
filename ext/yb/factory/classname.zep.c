
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Yb_Factory_ClassName) {

	ZEPHIR_REGISTER_CLASS(Yb\\Factory, ClassName, yb, factory_classname, yb_factory_classname_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_class_implements(yb_factory_classname_ce TSRMLS_CC, 1, yb_factory_factoryinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Yb_Factory_ClassName, has) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *_0 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getclassname", NULL, 0, name);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_class_exists(_0, 1 TSRMLS_CC));

}

PHP_METHOD(Yb_Factory_ClassName, get) {

	zephir_nts_static zend_class_entry *_3$$3 = NULL;
	zend_class_entry *_6;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *_0 = NULL, *_5 = NULL, *_2$$3;
	zval *name = NULL, *className = NULL, *_1 = NULL, *_4$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getclassname", NULL, 0, name);
	zephir_check_call_status();
	zephir_get_strval(_1, _0);
	ZEPHIR_CPY_WRT(className, _1);
	if (unlikely(!(zephir_class_exists(className, 1 TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(_2$$3);
		if (!_3$$3) {
			_3$$3 = zend_fetch_class(SL("Yb\\Factory\\Exception"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		}
		object_init_ex(_2$$3, _3$$3);
		if (zephir_has_constructor(_2$$3 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(_4$$3);
			ZEPHIR_CONCAT_SV(_4$$3, "Invalid product: ", name);
			ZEPHIR_CALL_METHOD(NULL, _2$$3, "__construct", NULL, 0, _4$$3);
			zephir_check_call_status();
		}
		zephir_throw_exception_debug(_2$$3, "yb/factory/classname.zep", 16 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_fetch_safe_class(_5, className);
		_6 = zend_fetch_class(Z_STRVAL_P(_5), Z_STRLEN_P(_5), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(return_value, _6);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM();

}

PHP_METHOD(Yb_Factory_ClassName, getClassName) {

}


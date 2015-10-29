
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


ZEPHIR_INIT_CLASS(Yb_Application_RouterAbstract) {

	ZEPHIR_REGISTER_CLASS(Yb\\Application, RouterAbstract, yb, application_routerabstract, yb_application_routerabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(yb_application_routerabstract_ce, SL("controller"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_application_routerabstract_ce, SL("action"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_application_routerabstract_ce, SL("params"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(yb_application_routerabstract_ce, SL("DEFAULT_CONTROLLER"), "index" TSRMLS_CC);

	zend_declare_class_constant_string(yb_application_routerabstract_ce, SL("DEFAULT_ACTION"), "index" TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Yb_Application_RouterAbstract, getController) {

	

	RETURN_MEMBER(this_ptr, "controller");

}

PHP_METHOD(Yb_Application_RouterAbstract, getAction) {

	

	RETURN_MEMBER(this_ptr, "action");

}

PHP_METHOD(Yb_Application_RouterAbstract, getParams) {

	

	RETURN_MEMBER(this_ptr, "params");

}


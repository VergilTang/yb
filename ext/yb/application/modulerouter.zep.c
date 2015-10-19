
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
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Yb_Application_ModuleRouter) {

	ZEPHIR_REGISTER_CLASS(Yb\\Application, ModuleRouter, yb, application_modulerouter, yb_application_modulerouter_method_entry, 0);

	zend_declare_property_null(yb_application_modulerouter_ce, SL("modules"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(yb_application_modulerouter_ce TSRMLS_CC, 1, yb_application_applicationfilterinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Yb_Application_ModuleRouter, __construct) {

	zval *modules_param = NULL;
	zval *modules = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &modules_param);

	zephir_get_arrval(modules, modules_param);


	zephir_update_property_this(this_ptr, SL("modules"), modules TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Application_ModuleRouter, filterApplication) {

	zend_bool _7, _2$$5, _4$$5;
	zval *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *core, *_SERVER, *module = NULL, *moduleObject = NULL, *httpHost = NULL, *_0, *_10, *_1$$3, *_3$$5, *_5$$5, *_8$$7, *_9$$7;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &core);



	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_GET_CONSTANT(_0, "PHP_SAPI");
	if (ZEPHIR_IS_STRING(_0, "cli")) {
		ZEPHIR_OBS_VAR(module);
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("modules"), PH_NOISY_CC);
		if (unlikely(!(zephir_array_isset_string_fetch(&module, _1$$3, SS("cli"), 0 TSRMLS_CC)))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_application_exception_ce, "Cannot run application in cli mode", "yb/application/modulerouter.zep", 18);
			return;
		}
	} else {
		ZEPHIR_OBS_VAR(httpHost);
		_2$$5 = !(zephir_array_isset_string_fetch(&httpHost, _SERVER, SS("HTTP_HOST"), 0 TSRMLS_CC));
		if (_2$$5) {
			ZEPHIR_OBS_NVAR(module);
			_3$$5 = zephir_fetch_nproperty_this(this_ptr, SL("modules"), PH_NOISY_CC);
			_2$$5 = !(zephir_array_isset_fetch(&module, _3$$5, httpHost, 0 TSRMLS_CC));
		}
		_4$$5 = _2$$5;
		if (_4$$5) {
			ZEPHIR_OBS_NVAR(module);
			_5$$5 = zephir_fetch_nproperty_this(this_ptr, SL("modules"), PH_NOISY_CC);
			_4$$5 = !(zephir_array_isset_string_fetch(&module, _5$$5, SS("default"), 0 TSRMLS_CC));
		}
		if (unlikely(_4$$5)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_application_exception_ce, "Cannot match module to http host and no default module", "yb/application/modulerouter.zep", 23);
			return;
		}
	}
	zephir_get_strval(_6, module);
	ZEPHIR_CALL_METHOD(&moduleObject, core, "__get", NULL, 0, _6);
	zephir_check_call_status();
	_7 = Z_TYPE_P(moduleObject) != IS_OBJECT;
	if (!(_7)) {
		_7 = !((zephir_instance_of_ev(moduleObject, yb_application_applicationfilterinterface_ce TSRMLS_CC)));
	}
	if (_7) {
		ZEPHIR_INIT_VAR(_8$$7);
		object_init_ex(_8$$7, yb_application_exception_ce);
		ZEPHIR_INIT_VAR(_9$$7);
		ZEPHIR_CONCAT_SV(_9$$7, "Invalid module: ", module);
		ZEPHIR_CALL_METHOD(NULL, _8$$7, "__construct", NULL, 3, _9$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(_8$$7, "yb/application/modulerouter.zep", 29 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_10);
	ZVAL_STRING(_10, "module", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, core, "__set", NULL, 0, _10, moduleObject);
	zephir_check_temp_parameter(_10);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, moduleObject, "filterapplication", NULL, 0, core);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}


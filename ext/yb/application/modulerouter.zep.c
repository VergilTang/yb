
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

	zend_bool _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *core, *_SERVER, *m = NULL, *mo = NULL, *httpHost = NULL, *_0, *_7, *_1$$3, *_2$$5, *_3$$7, *_5$$9, *_6$$9;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &core);



	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_GET_CONSTANT(_0, "PHP_SAPI");
	if (ZEPHIR_IS_STRING(_0, "cli")) {
		ZEPHIR_OBS_VAR(m);
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("modules"), PH_NOISY_CC);
		if (unlikely(!(zephir_array_isset_string_fetch(&m, _1$$3, SS("cli"), 0 TSRMLS_CC)))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_application_exception_ce, "Cannot run application in cli mode", "yb/application/modulerouter.zep", 18);
			return;
		}
	} else {
		ZEPHIR_OBS_VAR(httpHost);
		if (unlikely(!(zephir_array_isset_string_fetch(&httpHost, _SERVER, SS("HTTP_HOST"), 0 TSRMLS_CC)))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_application_exception_ce, "Cannot find http host", "yb/application/modulerouter.zep", 22);
			return;
		}
		ZEPHIR_OBS_NVAR(m);
		_2$$5 = zephir_fetch_nproperty_this(this_ptr, SL("modules"), PH_NOISY_CC);
		if (!(zephir_array_isset_fetch(&m, _2$$5, httpHost, 0 TSRMLS_CC))) {
			ZEPHIR_OBS_NVAR(m);
			_3$$7 = zephir_fetch_nproperty_this(this_ptr, SL("modules"), PH_NOISY_CC);
			if (!(zephir_array_isset_string_fetch(&m, _3$$7, SS("default"), 0 TSRMLS_CC))) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_application_exception_ce, "Cannot match module to http host and no default module", "yb/application/modulerouter.zep", 27);
				return;
			}
		}
	}
	ZEPHIR_CALL_METHOD(&mo, core, "__get", NULL, 0, m);
	zephir_check_call_status();
	_4 = Z_TYPE_P(mo) != IS_OBJECT;
	if (!(_4)) {
		_4 = !((zephir_instance_of_ev(mo, yb_application_applicationfilterinterface_ce TSRMLS_CC)));
	}
	if (_4) {
		ZEPHIR_INIT_VAR(_5$$9);
		object_init_ex(_5$$9, yb_application_exception_ce);
		ZEPHIR_INIT_VAR(_6$$9);
		ZEPHIR_CONCAT_SV(_6$$9, "Invalid module: ", m);
		ZEPHIR_CALL_METHOD(NULL, _5$$9, "__construct", NULL, 3, _6$$9);
		zephir_check_call_status();
		zephir_throw_exception_debug(_5$$9, "yb/application/modulerouter.zep", 34 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_7);
	ZVAL_STRING(_7, "module", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, core, "__set", NULL, 0, _7, mo);
	zephir_check_temp_parameter(_7);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, mo, "filterapplication", NULL, 0, core);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}


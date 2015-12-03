
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/file.h"
#include "kernel/require.h"


ZEPHIR_INIT_CLASS(Yb_Application) {

	ZEPHIR_REGISTER_CLASS_EX(Yb, Application, yb, application, yb_di_ce, yb_application_method_entry, 0);

	zend_declare_property_null(yb_application_ce, SL("configs"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Yb_Application, __construct) {

	zval *configs_param = NULL;
	zval *configs = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &configs_param);

	if (!configs_param) {
		ZEPHIR_INIT_VAR(configs);
		array_init(configs);
	} else {
		zephir_get_arrval(configs, configs_param);
	}


	zephir_update_property_this(this_ptr, SL("configs"), configs TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Application, config) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *name_param = NULL, *defaultValue = NULL, *_1;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &defaultValue);

	zephir_get_strval(name, name_param);
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}


	_1 = zephir_fetch_nproperty_this(this_ptr, SL("configs"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_CE_STATIC(yb_std_ce, "valueof", &_0, 27, _1, name, defaultValue);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Application, mergeConfigs) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *configs_param = NULL, *_0, *_1 = NULL;
	zval *configs = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &configs_param);

	zephir_get_arrval(configs, configs_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("configs"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "array_replace_recursive", NULL, 28, _0, configs);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("configs"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Application, mergeConfigsInPathIfValid) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *configs = NULL, *_0 = NULL;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(path, path_param);


	if (!((zephir_file_exists(path TSRMLS_CC) == SUCCESS))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_0);
	if (zephir_require_zval_ret(&_0, path TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CPY_WRT(configs, _0);
	if (Z_TYPE_P(configs) != IS_ARRAY) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "mergeconfigs", NULL, 0, configs);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}


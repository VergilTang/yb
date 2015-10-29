
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
#include "kernel/hash.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/require.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Yb_Loader_NamespaceDirectory) {

	ZEPHIR_REGISTER_CLASS_EX(Yb\\Loader, NamespaceDirectory, yb, loader_namespacedirectory, yb_loader_loaderabstract_ce, yb_loader_namespacedirectory_method_entry, 0);

	zend_declare_property_null(yb_loader_namespacedirectory_ce, SL("namespaceDirectories"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_loader_namespacedirectory_ce, SL("lowerCase"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Yb_Loader_NamespaceDirectory, __construct) {

	HashTable *_1;
	HashPosition _0;
	zend_bool lowerCase;
	zval *namespaceDirectories_param = NULL, *lowerCase_param = NULL, *n = NULL, *d = NULL, **_2, *_3$$3 = NULL;
	zval *namespaceDirectories = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &namespaceDirectories_param, &lowerCase_param);

	if (!namespaceDirectories_param) {
		ZEPHIR_INIT_VAR(namespaceDirectories);
		array_init(namespaceDirectories);
	} else {
		zephir_get_arrval(namespaceDirectories, namespaceDirectories_param);
	}
	if (!lowerCase_param) {
		lowerCase = 0;
	} else {
		lowerCase = zephir_get_boolval(lowerCase_param);
	}


	zephir_is_iterable(namespaceDirectories, &_1, &_0, 0, 0, "yb/loader/namespacedirectory.zep", 16);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(n, _1, _0);
		ZEPHIR_GET_HVALUE(d, _2);
		ZEPHIR_INIT_NVAR(_3$$3);
		zephir_fast_strtolower(_3$$3, n);
		zephir_update_property_array(this_ptr, SL("namespaceDirectories"), _3$$3, d TSRMLS_CC);
	}
	if (lowerCase) {
		zephir_update_property_this(this_ptr, SL("lowerCase"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("lowerCase"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Loader_NamespaceDirectory, __invoke) {

	zend_bool found, _3$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *className_param = NULL, *match = NULL, *pos = NULL, *dir = NULL, *_0 = NULL, _6, *_8, *_10, _11, _12, *_13, _1$$3 = zval_used_for_init, *_4$$3 = NULL, *_5$$3, *_9$$7, *_14$$9;
	zval *className = NULL, *path = NULL, *_7 = NULL, *_15$$9;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &className_param);

	zephir_get_strval(className, className_param);


	found = 0;
	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strtolower(_0, className);
	ZEPHIR_CPY_WRT(match, _0);
	while (1) {
		ZEPHIR_SINIT_NVAR(_1$$3);
		ZVAL_STRING(&_1$$3, "\\", 0);
		ZEPHIR_CALL_FUNCTION(&pos, "strrpos", &_2, 51, match, &_1$$3);
		zephir_check_call_status();
		_3$$3 = ZEPHIR_IS_FALSE_IDENTICAL(pos);
		if (!(_3$$3)) {
			_3$$3 = ZEPHIR_LT_LONG(pos, 1);
		}
		if (_3$$3) {
			break;
		}
		ZEPHIR_SINIT_NVAR(_1$$3);
		ZVAL_LONG(&_1$$3, 0);
		ZEPHIR_INIT_NVAR(_4$$3);
		zephir_substr(_4$$3, match, 0 , zephir_get_intval(pos), 0);
		ZEPHIR_CPY_WRT(match, _4$$3);
		ZEPHIR_OBS_NVAR(dir);
		_5$$3 = zephir_fetch_nproperty_this(this_ptr, SL("namespaceDirectories"), PH_NOISY_CC);
		if (zephir_array_isset_fetch(&dir, _5$$3, match, 0 TSRMLS_CC)) {
			found = 1;
			break;
		}
	}
	if (!(found)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_LONG(&_6, (zephir_get_numberval(pos) + 1));
	ZEPHIR_INIT_NVAR(_0);
	zephir_substr(_0, className, zephir_get_intval(&_6), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	zephir_get_strval(_7, _0);
	ZEPHIR_CPY_WRT(path, _7);
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("lowerCase"), PH_NOISY_CC);
	if (zephir_is_true(_8)) {
		ZEPHIR_INIT_VAR(_9$$7);
		zephir_fast_strtolower(_9$$7, path);
		zephir_get_strval(path, _9$$7);
	}
	ZEPHIR_INIT_VAR(_10);
	ZEPHIR_SINIT_VAR(_11);
	ZVAL_STRING(&_11, "\\", 0);
	ZEPHIR_SINIT_VAR(_12);
	ZVAL_STRING(&_12, "/", 0);
	zephir_fast_str_replace(&_10, &_11, &_12, path TSRMLS_CC);
	ZEPHIR_INIT_VAR(_13);
	ZEPHIR_CONCAT_VSVS(_13, dir, "/", _10, ".php");
	zephir_get_strval(path, _13);
	if (!((zephir_file_exists(path TSRMLS_CC) == SUCCESS))) {
		RETURN_MM_BOOL(0);
	}
	if (zephir_require_zval(path TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	if (unlikely(!(zephir_class_exists(className, zephir_is_true(ZEPHIR_GLOBAL(global_false))  TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(_14$$9);
		object_init_ex(_14$$9, yb_loader_exception_ce);
		ZEPHIR_INIT_VAR(_15$$9);
		ZEPHIR_CONCAT_SVSV(_15$$9, "Cannot find class: ", className, ", in path: ", path);
		ZEPHIR_CALL_METHOD(NULL, _14$$9, "__construct", NULL, 1, _15$$9);
		zephir_check_call_status();
		zephir_throw_exception_debug(_14$$9, "yb/loader/namespacedirectory.zep", 55 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(Yb_Loader_NamespaceDirectory, set) {

	zval *ns_param = NULL, *dir_param = NULL, *_0 = NULL, *_1;
	zval *ns = NULL, *dir = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &ns_param, &dir_param);

	zephir_get_strval(ns, ns_param);
	zephir_get_strval(dir, dir_param);


	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strtolower(_1, ns);
	zephir_update_property_array(this_ptr, SL("namespaceDirectories"), _1, dir TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}


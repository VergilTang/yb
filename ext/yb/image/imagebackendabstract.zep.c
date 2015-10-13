
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/hash.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Yb_Image_ImageBackendAbstract) {

	ZEPHIR_REGISTER_CLASS(Yb\\Image, ImageBackendAbstract, yb, image_imagebackendabstract, yb_image_imagebackendabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(yb_image_imagebackendabstract_ce, SL("defaults"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(yb_image_imagebackendabstract_ce, SL("DEFAULT_FONT"), "" TSRMLS_CC);

	zend_declare_class_constant_long(yb_image_imagebackendabstract_ce, SL("DEFAULT_FONT_SIZE"), 24 TSRMLS_CC);

	zend_declare_class_constant_string(yb_image_imagebackendabstract_ce, SL("DEFAULT_COLOR"), "#000000" TSRMLS_CC);

	zend_declare_class_constant_long(yb_image_imagebackendabstract_ce, SL("DEFAULT_RED"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(yb_image_imagebackendabstract_ce, SL("DEFAULT_GREEN"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(yb_image_imagebackendabstract_ce, SL("DEFAULT_BLUE"), 0 TSRMLS_CC);

	zend_declare_class_constant_double(yb_image_imagebackendabstract_ce, SL("DEFAULT_OPACITY"), 0.5 TSRMLS_CC);

	zend_declare_class_constant_long(yb_image_imagebackendabstract_ce, SL("DEFAULT_PADDING"), 5 TSRMLS_CC);

	zend_declare_class_constant_double(yb_image_imagebackendabstract_ce, SL("DEFAULT_R_PADDING"), 0.2 TSRMLS_CC);

	zend_declare_class_constant_double(yb_image_imagebackendabstract_ce, SL("DEFAULT_R_OVERLAP"), 0.2 TSRMLS_CC);

	zend_declare_class_constant_long(yb_image_imagebackendabstract_ce, SL("LEFT_TOP"), 7 TSRMLS_CC);

	zend_declare_class_constant_long(yb_image_imagebackendabstract_ce, SL("TOP"), 8 TSRMLS_CC);

	zend_declare_class_constant_long(yb_image_imagebackendabstract_ce, SL("RIGHT_TOP"), 9 TSRMLS_CC);

	zend_declare_class_constant_long(yb_image_imagebackendabstract_ce, SL("LEFT"), 4 TSRMLS_CC);

	zend_declare_class_constant_long(yb_image_imagebackendabstract_ce, SL("CENTER"), 5 TSRMLS_CC);

	zend_declare_class_constant_long(yb_image_imagebackendabstract_ce, SL("RIGHT"), 6 TSRMLS_CC);

	zend_declare_class_constant_long(yb_image_imagebackendabstract_ce, SL("LEFT_BOTTOM"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(yb_image_imagebackendabstract_ce, SL("BOTTOM"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(yb_image_imagebackendabstract_ce, SL("RIGHT_BOTTOM"), 3 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Yb_Image_ImageBackendAbstract, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *defaults_param = NULL;
	zval *defaults = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &defaults_param);

	zephir_get_arrval(defaults, defaults_param);


	if (zephir_fast_count_int(defaults TSRMLS_CC) > 0) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdefaults", NULL, 0, defaults);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Image_ImageBackendAbstract, setDefaults) {

	HashTable *_1;
	HashPosition _0;
	zval *defaults_param = NULL, *k = NULL, *v = NULL, **_2;
	zval *defaults = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &defaults_param);

	zephir_get_arrval(defaults, defaults_param);


	zephir_is_iterable(defaults, &_1, &_0, 0, 0, "yb/image/imagebackendabstract.zep", 42);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(k, _1, _0);
		ZEPHIR_GET_HVALUE(v, _2);
		zephir_update_property_array(this_ptr, SL("defaults"), k, v TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Image_ImageBackendAbstract, setDefault) {

	zval *name_param = NULL, *value;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	zephir_get_strval(name, name_param);


	zephir_update_property_array(this_ptr, SL("defaults"), name, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Image_ImageBackendAbstract, text) {

}

PHP_METHOD(Yb_Image_ImageBackendAbstract, captcha) {

}

PHP_METHOD(Yb_Image_ImageBackendAbstract, fromImage) {

}

PHP_METHOD(Yb_Image_ImageBackendAbstract, fromSize) {

}

PHP_METHOD(Yb_Image_ImageBackendAbstract, fromPath) {

}

PHP_METHOD(Yb_Image_ImageBackendAbstract, fromString) {

}

PHP_METHOD(Yb_Image_ImageBackendAbstract, resize) {

}

PHP_METHOD(Yb_Image_ImageBackendAbstract, crop) {

}

PHP_METHOD(Yb_Image_ImageBackendAbstract, thumbnail) {

}

PHP_METHOD(Yb_Image_ImageBackendAbstract, draw) {

}

PHP_METHOD(Yb_Image_ImageBackendAbstract, save) {

}

PHP_METHOD(Yb_Image_ImageBackendAbstract, destroy) {

}

PHP_METHOD(Yb_Image_ImageBackendAbstract, validTextOptions) {

	zend_bool _13$$9, _26$$11;
	double d = 0;
	long l = 0;
	zval *s = NULL, *_10$$5 = NULL, *_12$$9 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_18 = NULL;
	zval *options_param = NULL, *valid = NULL, *merged = NULL, *v = NULL, *m = NULL, *_0, *_2, *_3, *_4, *_5, *_6, *_7, *_8, *_9, *_1$$3, *_11$$8, *_14$$9, _15$$9, *_16$$10, *_17$$10 = NULL, *_19$$10, *_20$$10, *_21$$10 = NULL, *_22$$10, *_23$$10, *_24$$10 = NULL, *_25$$10, *_27$$12, *_28$$14;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	zephir_get_arrval(options, options_param);


	ZEPHIR_INIT_VAR(valid);
	array_init(valid);
	ZEPHIR_INIT_VAR(m);
	ZVAL_NULL(m);
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("defaults"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_ARRAY) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("defaults"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(merged);
		zephir_fast_array_merge(merged, &(_1$$3), &(options) TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(merged, options);
	}
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "", 1);
	zephir_array_update_string(&valid, SL("font"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 24);
	zephir_array_update_string(&valid, SL("fontSize"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "#000000", 1);
	zephir_array_update_string(&valid, SL("color"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, 0);
	zephir_array_update_string(&valid, SL("red"), &_5, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_LONG(_6, 0);
	zephir_array_update_string(&valid, SL("green"), &_6, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_7);
	ZVAL_LONG(_7, 0);
	zephir_array_update_string(&valid, SL("blue"), &_7, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_8);
	ZVAL_DOUBLE(_8, 0.5);
	zephir_array_update_string(&valid, SL("opacity"), &_8, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_9);
	ZVAL_LONG(_9, 5);
	zephir_array_update_string(&valid, SL("padding"), &_9, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(v);
	if (zephir_array_isset_string_fetch(&v, merged, SS("font"), 0 TSRMLS_CC)) {
		zephir_get_strval(_10$$5, v);
		ZEPHIR_CPY_WRT(s, _10$$5);
		if (!(!s) && Z_STRLEN_P(s)) {
			zephir_array_update_string(&valid, SL("font"), &s, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_OBS_NVAR(v);
	if (zephir_array_isset_string_fetch(&v, merged, SS("fontSize"), 0 TSRMLS_CC)) {
		l = zephir_get_intval(v);
		if (l > 7) {
			ZEPHIR_INIT_VAR(_11$$8);
			ZVAL_LONG(_11$$8, l);
			zephir_array_update_string(&valid, SL("fontSize"), &_11$$8, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_OBS_NVAR(v);
	if (zephir_array_isset_string_fetch(&v, merged, SS("color"), 0 TSRMLS_CC)) {
		zephir_get_strval(_12$$9, v);
		ZEPHIR_CPY_WRT(s, _12$$9);
		_13$$9 = zephir_is_true(s);
		if (_13$$9) {
			ZEPHIR_INIT_VAR(_14$$9);
			ZEPHIR_SINIT_VAR(_15$$9);
			ZVAL_STRING(&_15$$9, "/^#([0-9a-fA-F]{2})([0-9a-fA-F]{2})([0-9a-fA-F]{2})/", 0);
			zephir_preg_match(_14$$9, &_15$$9, s, m, 0, 0 , 0  TSRMLS_CC);
			_13$$9 = zephir_is_true(_14$$9);
		}
		if (_13$$9) {
			zephir_array_update_string(&valid, SL("color"), &s, PH_COPY | PH_SEPARATE);
			zephir_array_fetch_long(&_16$$10, m, 1, PH_NOISY | PH_READONLY, "yb/image/imagebackendabstract.zep", 102 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_17$$10, "hexdec", &_18, 1, _16$$10);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_19$$10);
			ZVAL_LONG(_19$$10, zephir_get_intval(_17$$10));
			zephir_array_update_string(&valid, SL("red"), &_19$$10, PH_COPY | PH_SEPARATE);
			zephir_array_fetch_long(&_20$$10, m, 2, PH_NOISY | PH_READONLY, "yb/image/imagebackendabstract.zep", 103 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_21$$10, "hexdec", &_18, 1, _20$$10);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_22$$10);
			ZVAL_LONG(_22$$10, zephir_get_intval(_21$$10));
			zephir_array_update_string(&valid, SL("green"), &_22$$10, PH_COPY | PH_SEPARATE);
			zephir_array_fetch_long(&_23$$10, m, 3, PH_NOISY | PH_READONLY, "yb/image/imagebackendabstract.zep", 104 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_24$$10, "hexdec", &_18, 1, _23$$10);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_25$$10);
			ZVAL_LONG(_25$$10, zephir_get_intval(_24$$10));
			zephir_array_update_string(&valid, SL("blue"), &_25$$10, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_OBS_NVAR(v);
	if (zephir_array_isset_string_fetch(&v, merged, SS("opacity"), 0 TSRMLS_CC)) {
		d = zephir_get_doubleval(v);
		_26$$11 = d >= 0;
		if (_26$$11) {
			_26$$11 = d <= 1;
		}
		if (_26$$11) {
			ZEPHIR_INIT_VAR(_27$$12);
			ZVAL_DOUBLE(_27$$12, d);
			zephir_array_update_string(&valid, SL("opacity"), &_27$$12, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_OBS_NVAR(v);
	if (zephir_array_isset_string_fetch(&v, merged, SS("padding"), 0 TSRMLS_CC)) {
		l = zephir_get_intval(v);
		if (l >= 0) {
			ZEPHIR_INIT_VAR(_28$$14);
			ZVAL_LONG(_28$$14, l);
			zephir_array_update_string(&valid, SL("padding"), &_28$$14, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(valid);

}

PHP_METHOD(Yb_Image_ImageBackendAbstract, validCaptchaOptions) {

	zend_bool _6$$7, _8$$9;
	double d = 0;
	zval *s = NULL, *_5$$5 = NULL;
	zval *options_param = NULL, *valid = NULL, *merged = NULL, *v = NULL, *_0, *_2, *_3, *_4, *_1$$3, *_7$$8, *_9$$10;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	zephir_get_arrval(options, options_param);


	ZEPHIR_INIT_VAR(valid);
	array_init(valid);
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("defaults"), PH_NOISY_CC);
	if (Z_TYPE_P(_0) == IS_ARRAY) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("defaults"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(merged);
		zephir_fast_array_merge(merged, &(_1$$3), &(options) TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(merged, options);
	}
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "", 1);
	zephir_array_update_string(&valid, SL("font"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_DOUBLE(_3, 0.2);
	zephir_array_update_string(&valid, SL("rPadding"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_DOUBLE(_4, 0.2);
	zephir_array_update_string(&valid, SL("rOverlap"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(v);
	if (zephir_array_isset_string_fetch(&v, merged, SS("font"), 0 TSRMLS_CC)) {
		zephir_get_strval(_5$$5, v);
		ZEPHIR_CPY_WRT(s, _5$$5);
		if (!(!s) && Z_STRLEN_P(s)) {
			zephir_array_update_string(&valid, SL("font"), &s, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_OBS_NVAR(v);
	if (zephir_array_isset_string_fetch(&v, merged, SS("rPadding"), 0 TSRMLS_CC)) {
		d = zephir_get_doubleval(v);
		_6$$7 = d > 0;
		if (_6$$7) {
			_6$$7 = d < 1;
		}
		if (_6$$7) {
			ZEPHIR_INIT_VAR(_7$$8);
			ZVAL_DOUBLE(_7$$8, d);
			zephir_array_update_string(&valid, SL("rPadding"), &_7$$8, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_OBS_NVAR(v);
	if (zephir_array_isset_string_fetch(&v, merged, SS("rOverlap"), 0 TSRMLS_CC)) {
		d = zephir_get_doubleval(v);
		_8$$9 = d > 0;
		if (_8$$9) {
			_8$$9 = d < 1;
		}
		if (_8$$9) {
			ZEPHIR_INIT_VAR(_9$$10);
			ZVAL_DOUBLE(_9$$10, d);
			zephir_array_update_string(&valid, SL("rOverlap"), &_9$$10, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(valid);

}


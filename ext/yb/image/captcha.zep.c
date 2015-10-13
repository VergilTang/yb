
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Yb_Image_Captcha) {

	ZEPHIR_REGISTER_CLASS_EX(Yb\\Image, Captcha, yb, image_captcha, yb_image_image_ce, yb_image_captcha_method_entry, 0);

	zend_declare_property_string(yb_image_captcha_ce, SL("text"), "", ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_string(yb_image_captcha_ce, SL("font"), "simhei.ttf", ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_double(yb_image_captcha_ce, SL("rPadding"), 0.2, ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_double(yb_image_captcha_ce, SL("rOverlap"), 0.2, ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Yb_Image_Captcha, setOptions) {

	zend_bool _1$$5, _3$$7;
	double d = 0;
	zval *s = NULL, *_0$$3 = NULL;
	zval *options_param = NULL, *opt = NULL, *_2$$6, *_4$$8;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	zephir_get_arrval(options, options_param);


	ZEPHIR_OBS_VAR(opt);
	if (zephir_array_isset_string_fetch(&opt, options, SS("font"), 0 TSRMLS_CC)) {
		zephir_get_strval(_0$$3, opt);
		ZEPHIR_CPY_WRT(s, _0$$3);
		if (!(!s) && Z_STRLEN_P(s)) {
			zephir_update_property_this(this_ptr, SL("font"), s TSRMLS_CC);
		}
	}
	ZEPHIR_OBS_NVAR(opt);
	if (zephir_array_isset_string_fetch(&opt, options, SS("rPadding"), 0 TSRMLS_CC)) {
		d = zephir_get_doubleval(opt);
		_1$$5 = d > 0;
		if (_1$$5) {
			_1$$5 = d < 1;
		}
		if (_1$$5) {
			ZEPHIR_INIT_ZVAL_NREF(_2$$6);
			ZVAL_DOUBLE(_2$$6, d);
			zephir_update_property_this(this_ptr, SL("rPadding"), _2$$6 TSRMLS_CC);
		}
	}
	ZEPHIR_OBS_NVAR(opt);
	if (zephir_array_isset_string_fetch(&opt, options, SS("rOverlap"), 0 TSRMLS_CC)) {
		d = zephir_get_doubleval(opt);
		_3$$7 = d > 0;
		if (_3$$7) {
			_3$$7 = d < 1;
		}
		if (_3$$7) {
			ZEPHIR_INIT_ZVAL_NREF(_4$$8);
			ZVAL_DOUBLE(_4$$8, d);
			zephir_update_property_this(this_ptr, SL("rOverlap"), _4$$8 TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}


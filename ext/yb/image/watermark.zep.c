
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
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Yb_Image_Watermark) {

	ZEPHIR_REGISTER_CLASS_EX(Yb\\Image, Watermark, yb, image_watermark, yb_image_imageabstract_ce, yb_image_watermark_method_entry, 0);

	zend_declare_property_string(yb_image_watermark_ce, SL("text"), "", ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_string(yb_image_watermark_ce, SL("font"), "simhei.ttf", ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_long(yb_image_watermark_ce, SL("fontSize"), 24, ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_string(yb_image_watermark_ce, SL("color"), "#000000", ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_long(yb_image_watermark_ce, SL("colorRed"), 0, ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_long(yb_image_watermark_ce, SL("colorGreen"), 0, ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_long(yb_image_watermark_ce, SL("colorBlue"), 0, ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_double(yb_image_watermark_ce, SL("opacity"), 0.5, ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_long(yb_image_watermark_ce, SL("padding"), 5, ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Yb_Image_Watermark, setOptions) {

	zend_bool _3$$7, _16$$9;
	double d = 0;
	long l = 0;
	zval *s = NULL, *_0$$3 = NULL, *_2$$7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_10 = NULL;
	zval *options_param = NULL, *opt = NULL, *m = NULL, *_1$$6, *_4$$7, _5$$7, *_6$$8 = NULL, *_7$$8, *_8$$8, *_9$$8 = NULL, *_11$$8, *_12$$8, *_13$$8 = NULL, *_14$$8, *_15$$8 = NULL, *_17$$10, *_18$$12;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	zephir_get_arrval(options, options_param);


	ZEPHIR_INIT_VAR(m);
	ZVAL_NULL(m);
	ZEPHIR_OBS_VAR(opt);
	if (zephir_array_isset_string_fetch(&opt, options, SS("font"), 0 TSRMLS_CC)) {
		zephir_get_strval(_0$$3, opt);
		ZEPHIR_CPY_WRT(s, _0$$3);
		if (!(!s) && Z_STRLEN_P(s)) {
			zephir_update_property_this(this_ptr, SL("font"), s TSRMLS_CC);
		}
	}
	ZEPHIR_OBS_NVAR(opt);
	if (zephir_array_isset_string_fetch(&opt, options, SS("fontSize"), 0 TSRMLS_CC)) {
		l = zephir_get_intval(opt);
		if (l > 7) {
			ZEPHIR_INIT_ZVAL_NREF(_1$$6);
			ZVAL_LONG(_1$$6, l);
			zephir_update_property_this(this_ptr, SL("fontSize"), _1$$6 TSRMLS_CC);
		}
	}
	ZEPHIR_OBS_NVAR(opt);
	if (zephir_array_isset_string_fetch(&opt, options, SS("color"), 0 TSRMLS_CC)) {
		zephir_get_strval(_2$$7, opt);
		ZEPHIR_CPY_WRT(s, _2$$7);
		_3$$7 = zephir_is_true(s);
		if (_3$$7) {
			ZEPHIR_INIT_VAR(_4$$7);
			ZEPHIR_SINIT_VAR(_5$$7);
			ZVAL_STRING(&_5$$7, "/^#([0-9a-fA-F]{2})([0-9a-fA-F]{2})([0-9a-fA-F]{2})/", 0);
			zephir_preg_match(_4$$7, &_5$$7, s, m, 0, 0 , 0  TSRMLS_CC);
			_3$$7 = zephir_is_true(_4$$7);
		}
		if (_3$$7) {
			ZEPHIR_INIT_VAR(_7$$8);
			zephir_fast_strtoupper(_7$$8, s);
			zephir_update_property_this(this_ptr, SL("color"), _7$$8 TSRMLS_CC);
			zephir_array_fetch_long(&_8$$8, m, 1, PH_NOISY | PH_READONLY, "yb/image/watermark.zep", 41 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_9$$8, "hexdec", &_10, 38, _8$$8);
			zephir_check_call_status();
			ZEPHIR_INIT_ZVAL_NREF(_11$$8);
			ZVAL_LONG(_11$$8, zephir_get_intval(_9$$8));
			zephir_update_property_this(this_ptr, SL("colorRed"), _11$$8 TSRMLS_CC);
			zephir_array_fetch_long(&_12$$8, m, 2, PH_NOISY | PH_READONLY, "yb/image/watermark.zep", 42 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_13$$8, "hexdec", &_10, 38, _12$$8);
			zephir_check_call_status();
			ZEPHIR_INIT_ZVAL_NREF(_11$$8);
			ZVAL_LONG(_11$$8, zephir_get_intval(_13$$8));
			zephir_update_property_this(this_ptr, SL("colorGreen"), _11$$8 TSRMLS_CC);
			zephir_array_fetch_long(&_14$$8, m, 3, PH_NOISY | PH_READONLY, "yb/image/watermark.zep", 43 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_15$$8, "hexdec", &_10, 38, _14$$8);
			zephir_check_call_status();
			ZEPHIR_INIT_ZVAL_NREF(_11$$8);
			ZVAL_LONG(_11$$8, zephir_get_intval(_15$$8));
			zephir_update_property_this(this_ptr, SL("colorBlue"), _11$$8 TSRMLS_CC);
		}
	}
	ZEPHIR_OBS_NVAR(opt);
	if (zephir_array_isset_string_fetch(&opt, options, SS("opacity"), 0 TSRMLS_CC)) {
		d = zephir_get_doubleval(opt);
		_16$$9 = d >= 0;
		if (_16$$9) {
			_16$$9 = d <= 1;
		}
		if (_16$$9) {
			ZEPHIR_INIT_ZVAL_NREF(_17$$10);
			ZVAL_DOUBLE(_17$$10, d);
			zephir_update_property_this(this_ptr, SL("opacity"), _17$$10 TSRMLS_CC);
		}
	}
	ZEPHIR_OBS_NVAR(opt);
	if (zephir_array_isset_string_fetch(&opt, options, SS("padding"), 0 TSRMLS_CC)) {
		l = zephir_get_intval(opt);
		if (l >= 0) {
			ZEPHIR_INIT_ZVAL_NREF(_18$$12);
			ZVAL_LONG(_18$$12, l);
			zephir_update_property_this(this_ptr, SL("padding"), _18$$12 TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}


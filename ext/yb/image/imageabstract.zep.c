
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
#include "kernel/memory.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Yb_Image_ImageAbstract) {

	ZEPHIR_REGISTER_CLASS(Yb\\Image, ImageAbstract, yb, image_imageabstract, yb_image_imageabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(yb_image_imageabstract_ce, SL("width"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(yb_image_imageabstract_ce, SL("height"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(yb_image_imageabstract_ce, SL("backend"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(yb_image_imageabstract_ce, SL("DEFAULT_FONT"), "simhei.ttf" TSRMLS_CC);

	zend_declare_class_constant_long(yb_image_imageabstract_ce, SL("LEFT_TOP"), 7 TSRMLS_CC);

	zend_declare_class_constant_long(yb_image_imageabstract_ce, SL("TOP"), 8 TSRMLS_CC);

	zend_declare_class_constant_long(yb_image_imageabstract_ce, SL("RIGHT_TOP"), 9 TSRMLS_CC);

	zend_declare_class_constant_long(yb_image_imageabstract_ce, SL("LEFT"), 4 TSRMLS_CC);

	zend_declare_class_constant_long(yb_image_imageabstract_ce, SL("CENTER"), 5 TSRMLS_CC);

	zend_declare_class_constant_long(yb_image_imageabstract_ce, SL("RIGHT"), 6 TSRMLS_CC);

	zend_declare_class_constant_long(yb_image_imageabstract_ce, SL("LEFT_BOTTOM"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(yb_image_imageabstract_ce, SL("BOTTOM"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(yb_image_imageabstract_ce, SL("RIGHT_BOTTOM"), 3 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Yb_Image_ImageAbstract, __construct) {

	zval *backend;

	zephir_fetch_params(0, 1, 0, &backend);



	zephir_update_property_this(this_ptr, SL("backend"), backend TSRMLS_CC);

}

PHP_METHOD(Yb_Image_ImageAbstract, __destruct) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "destroy", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}



extern zend_class_entry *yb_image_imageabstract_ce;

ZEPHIR_INIT_CLASS(Yb_Image_ImageAbstract);

PHP_METHOD(Yb_Image_ImageAbstract, __construct);
PHP_METHOD(Yb_Image_ImageAbstract, __destruct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imageabstract___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, backend, Yb\\Image\\ImageBackendAbstract, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_image_imageabstract_method_entry) {
	PHP_ME(Yb_Image_ImageAbstract, __construct, arginfo_yb_image_imageabstract___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_Image_ImageAbstract, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_FE_END
};

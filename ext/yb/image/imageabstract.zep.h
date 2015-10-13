
extern zend_class_entry *yb_image_imageabstract_ce;

ZEPHIR_INIT_CLASS(Yb_Image_ImageAbstract);

PHP_METHOD(Yb_Image_ImageAbstract, __construct);
PHP_METHOD(Yb_Image_ImageAbstract, __set);
PHP_METHOD(Yb_Image_ImageAbstract, __get);
PHP_METHOD(Yb_Image_ImageAbstract, __destruct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imageabstract___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, backend, Yb\\Image\\ImageBackendAbstract, 0)
	ZEND_ARG_ARRAY_INFO(0, properties, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imageabstract___set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imageabstract___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_image_imageabstract_method_entry) {
	PHP_ME(Yb_Image_ImageAbstract, __construct, arginfo_yb_image_imageabstract___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_Image_ImageAbstract, __set, arginfo_yb_image_imageabstract___set, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_ImageAbstract, __get, arginfo_yb_image_imageabstract___get, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_ImageAbstract, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_FE_END
};

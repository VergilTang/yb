
extern zend_class_entry *yb_image_watermark_ce;

ZEPHIR_INIT_CLASS(Yb_Image_Watermark);

PHP_METHOD(Yb_Image_Watermark, setOptions);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_watermark_setoptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_image_watermark_method_entry) {
	PHP_ME(Yb_Image_Watermark, setOptions, arginfo_yb_image_watermark_setoptions, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

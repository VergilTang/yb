
extern zend_class_entry *yb_image_text_ce;

ZEPHIR_INIT_CLASS(Yb_Image_Text);

PHP_METHOD(Yb_Image_Text, setOptions);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_text_setoptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_image_text_method_entry) {
	PHP_ME(Yb_Image_Text, setOptions, arginfo_yb_image_text_setoptions, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

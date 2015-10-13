
extern zend_class_entry *yb_image_imagick_ce;

ZEPHIR_INIT_CLASS(Yb_Image_Imagick);

PHP_METHOD(Yb_Image_Imagick, __construct);
PHP_METHOD(Yb_Image_Imagick, watermark);
PHP_METHOD(Yb_Image_Imagick, fromImage);
PHP_METHOD(Yb_Image_Imagick, fromSize);
PHP_METHOD(Yb_Image_Imagick, fromPath);
PHP_METHOD(Yb_Image_Imagick, fromString);
PHP_METHOD(Yb_Image_Imagick, captcha);
PHP_METHOD(Yb_Image_Imagick, resize);
PHP_METHOD(Yb_Image_Imagick, crop);
PHP_METHOD(Yb_Image_Imagick, thumbnail);
PHP_METHOD(Yb_Image_Imagick, draw);
PHP_METHOD(Yb_Image_Imagick, save);
PHP_METHOD(Yb_Image_Imagick, destroy);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imagick_watermark, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imagick_fromimage, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, im, Yb\\Image\\Image, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imagick_fromsize, 0, 0, 1)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, extension)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imagick_frompath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, extension)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imagick_fromstring, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, extension)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imagick_captcha, 0, 0, 3)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imagick_resize, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, im, Yb\\Image\\Image, 0)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imagick_crop, 0, 0, 5)
	ZEND_ARG_OBJ_INFO(0, im, Yb\\Image\\Image, 0)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
	ZEND_ARG_INFO(0, w)
	ZEND_ARG_INFO(0, h)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imagick_thumbnail, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, im, Yb\\Image\\Image, 0)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, cropped)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imagick_draw, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, destIm, Yb\\Image\\Image, 0)
	ZEND_ARG_OBJ_INFO(0, srcIm, Yb\\Image\\ImageAbstract, 0)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imagick_save, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, im, Yb\\Image\\Image, 0)
	ZEND_ARG_INFO(0, destPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imagick_destroy, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, im, Yb\\Image\\ImageAbstract, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_image_imagick_method_entry) {
	PHP_ME(Yb_Image_Imagick, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_Image_Imagick, watermark, arginfo_yb_image_imagick_watermark, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_Imagick, fromImage, arginfo_yb_image_imagick_fromimage, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_Imagick, fromSize, arginfo_yb_image_imagick_fromsize, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_Imagick, fromPath, arginfo_yb_image_imagick_frompath, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_Imagick, fromString, arginfo_yb_image_imagick_fromstring, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_Imagick, captcha, arginfo_yb_image_imagick_captcha, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_Imagick, resize, arginfo_yb_image_imagick_resize, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_Imagick, crop, arginfo_yb_image_imagick_crop, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_Imagick, thumbnail, arginfo_yb_image_imagick_thumbnail, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_Imagick, draw, arginfo_yb_image_imagick_draw, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_Imagick, save, arginfo_yb_image_imagick_save, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_Imagick, destroy, arginfo_yb_image_imagick_destroy, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

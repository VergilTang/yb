
extern zend_class_entry *yb_image_imagebackendabstract_ce;

ZEPHIR_INIT_CLASS(Yb_Image_ImageBackendAbstract);

PHP_METHOD(Yb_Image_ImageBackendAbstract, setDefaultOptions);
PHP_METHOD(Yb_Image_ImageBackendAbstract, getDefaultOptions);
PHP_METHOD(Yb_Image_ImageBackendAbstract, watermark);
PHP_METHOD(Yb_Image_ImageBackendAbstract, fromImage);
PHP_METHOD(Yb_Image_ImageBackendAbstract, fromSize);
PHP_METHOD(Yb_Image_ImageBackendAbstract, fromPath);
PHP_METHOD(Yb_Image_ImageBackendAbstract, fromString);
PHP_METHOD(Yb_Image_ImageBackendAbstract, captcha);
PHP_METHOD(Yb_Image_ImageBackendAbstract, resize);
PHP_METHOD(Yb_Image_ImageBackendAbstract, crop);
PHP_METHOD(Yb_Image_ImageBackendAbstract, thumbnail);
PHP_METHOD(Yb_Image_ImageBackendAbstract, draw);
PHP_METHOD(Yb_Image_ImageBackendAbstract, save);
PHP_METHOD(Yb_Image_ImageBackendAbstract, destroy);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imagebackendabstract_setdefaultoptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imagebackendabstract_watermark, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imagebackendabstract_fromimage, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, im, Yb\\Image\\Image, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imagebackendabstract_fromsize, 0, 0, 1)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, extension)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imagebackendabstract_frompath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, extension)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imagebackendabstract_fromstring, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, extension)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imagebackendabstract_captcha, 0, 0, 3)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imagebackendabstract_resize, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, im, Yb\\Image\\Image, 0)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imagebackendabstract_crop, 0, 0, 5)
	ZEND_ARG_OBJ_INFO(0, im, Yb\\Image\\Image, 0)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
	ZEND_ARG_INFO(0, w)
	ZEND_ARG_INFO(0, h)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imagebackendabstract_thumbnail, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, im, Yb\\Image\\Image, 0)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, cropped)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imagebackendabstract_draw, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, destIm, Yb\\Image\\Image, 0)
	ZEND_ARG_OBJ_INFO(0, srcIm, Yb\\Image\\ImageAbstract, 0)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imagebackendabstract_save, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, im, Yb\\Image\\Image, 0)
	ZEND_ARG_INFO(0, destPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imagebackendabstract_destroy, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, im, Yb\\Image\\ImageAbstract, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_image_imagebackendabstract_method_entry) {
	PHP_ME(Yb_Image_ImageBackendAbstract, setDefaultOptions, arginfo_yb_image_imagebackendabstract_setdefaultoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_ImageBackendAbstract, getDefaultOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_ImageBackendAbstract, watermark, arginfo_yb_image_imagebackendabstract_watermark, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_ImageBackendAbstract, fromImage, arginfo_yb_image_imagebackendabstract_fromimage, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_ImageBackendAbstract, fromSize, arginfo_yb_image_imagebackendabstract_fromsize, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_ImageBackendAbstract, fromPath, arginfo_yb_image_imagebackendabstract_frompath, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_ImageBackendAbstract, fromString, arginfo_yb_image_imagebackendabstract_fromstring, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_ImageBackendAbstract, captcha, arginfo_yb_image_imagebackendabstract_captcha, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_ImageBackendAbstract, resize, arginfo_yb_image_imagebackendabstract_resize, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_ImageBackendAbstract, crop, arginfo_yb_image_imagebackendabstract_crop, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_ImageBackendAbstract, thumbnail, arginfo_yb_image_imagebackendabstract_thumbnail, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_ImageBackendAbstract, draw, arginfo_yb_image_imagebackendabstract_draw, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_ImageBackendAbstract, save, arginfo_yb_image_imagebackendabstract_save, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_ImageBackendAbstract, destroy, arginfo_yb_image_imagebackendabstract_destroy, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
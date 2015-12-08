
extern zend_class_entry *yb_image_imagebackendabstract_ce;

ZEPHIR_INIT_CLASS(Yb_Image_ImageBackendAbstract);

PHP_METHOD(Yb_Image_ImageBackendAbstract, __construct);
PHP_METHOD(Yb_Image_ImageBackendAbstract, setDefaultOptions);
PHP_METHOD(Yb_Image_ImageBackendAbstract, getDefaultOptions);
PHP_METHOD(Yb_Image_ImageBackendAbstract, text);
PHP_METHOD(Yb_Image_ImageBackendAbstract, fromImage);
PHP_METHOD(Yb_Image_ImageBackendAbstract, fromSize);
PHP_METHOD(Yb_Image_ImageBackendAbstract, fromPath);
PHP_METHOD(Yb_Image_ImageBackendAbstract, fromString);
PHP_METHOD(Yb_Image_ImageBackendAbstract, captcha);
PHP_METHOD(Yb_Image_ImageBackendAbstract, largest);
PHP_METHOD(Yb_Image_ImageBackendAbstract, resize);
PHP_METHOD(Yb_Image_ImageBackendAbstract, crop);
PHP_METHOD(Yb_Image_ImageBackendAbstract, thumbnail);
PHP_METHOD(Yb_Image_ImageBackendAbstract, draw);
PHP_METHOD(Yb_Image_ImageBackendAbstract, save);
PHP_METHOD(Yb_Image_ImageBackendAbstract, destroy);
PHP_METHOD(Yb_Image_ImageBackendAbstract, newText);
PHP_METHOD(Yb_Image_ImageBackendAbstract, newImage);
PHP_METHOD(Yb_Image_ImageBackendAbstract, newCaptcha);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imagebackendabstract___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, defaultOptions, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imagebackendabstract_setdefaultoptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imagebackendabstract_text, 0, 0, 1)
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imagebackendabstract_largest, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, im, Yb\\Image\\Image, 0)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
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
	PHP_ME(Yb_Image_ImageBackendAbstract, __construct, arginfo_yb_image_imagebackendabstract___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_Image_ImageBackendAbstract, setDefaultOptions, arginfo_yb_image_imagebackendabstract_setdefaultoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_ImageBackendAbstract, getDefaultOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_ImageBackendAbstract, text, arginfo_yb_image_imagebackendabstract_text, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_ImageBackendAbstract, fromImage, arginfo_yb_image_imagebackendabstract_fromimage, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_ImageBackendAbstract, fromSize, arginfo_yb_image_imagebackendabstract_fromsize, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_ImageBackendAbstract, fromPath, arginfo_yb_image_imagebackendabstract_frompath, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_ImageBackendAbstract, fromString, arginfo_yb_image_imagebackendabstract_fromstring, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_ImageBackendAbstract, captcha, arginfo_yb_image_imagebackendabstract_captcha, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_ImageBackendAbstract, largest, arginfo_yb_image_imagebackendabstract_largest, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_ImageBackendAbstract, resize, arginfo_yb_image_imagebackendabstract_resize, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_ImageBackendAbstract, crop, arginfo_yb_image_imagebackendabstract_crop, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_ImageBackendAbstract, thumbnail, arginfo_yb_image_imagebackendabstract_thumbnail, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_ImageBackendAbstract, draw, arginfo_yb_image_imagebackendabstract_draw, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_ImageBackendAbstract, save, arginfo_yb_image_imagebackendabstract_save, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_ImageBackendAbstract, destroy, arginfo_yb_image_imagebackendabstract_destroy, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_ImageBackendAbstract, newText, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_ImageBackendAbstract, newImage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Image_ImageBackendAbstract, newCaptcha, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

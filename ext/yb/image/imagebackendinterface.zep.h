
extern zend_class_entry *yb_image_imagebackendinterface_ce;

ZEPHIR_INIT_CLASS(Yb_Image_ImageBackendInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imagebackendinterface_watermark, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imagebackendinterface_fromimage, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, im, Yb\\Image\\Image, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imagebackendinterface_fromsize, 0, 0, 1)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, extension)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imagebackendinterface_frompath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, extension)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imagebackendinterface_fromstring, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, extension)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imagebackendinterface_captcha, 0, 0, 3)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imagebackendinterface_resize, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, im, Yb\\Image\\Image, 0)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imagebackendinterface_crop, 0, 0, 5)
	ZEND_ARG_OBJ_INFO(0, im, Yb\\Image\\Image, 0)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
	ZEND_ARG_INFO(0, w)
	ZEND_ARG_INFO(0, h)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imagebackendinterface_thumbnail, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, im, Yb\\Image\\Image, 0)
	ZEND_ARG_INFO(0, width)
	ZEND_ARG_INFO(0, height)
	ZEND_ARG_INFO(0, cropped)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imagebackendinterface_draw, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, destIm, Yb\\Image\\Image, 0)
	ZEND_ARG_OBJ_INFO(0, srcIm, Yb\\Image\\ImageAbstract, 0)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imagebackendinterface_save, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, im, Yb\\Image\\Image, 0)
	ZEND_ARG_INFO(0, destPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_image_imagebackendinterface_destroy, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, im, Yb\\Image\\ImageAbstract, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_image_imagebackendinterface_method_entry) {
	PHP_ABSTRACT_ME(Yb_Image_ImageBackendInterface, watermark, arginfo_yb_image_imagebackendinterface_watermark)
	PHP_ABSTRACT_ME(Yb_Image_ImageBackendInterface, fromImage, arginfo_yb_image_imagebackendinterface_fromimage)
	PHP_ABSTRACT_ME(Yb_Image_ImageBackendInterface, fromSize, arginfo_yb_image_imagebackendinterface_fromsize)
	PHP_ABSTRACT_ME(Yb_Image_ImageBackendInterface, fromPath, arginfo_yb_image_imagebackendinterface_frompath)
	PHP_ABSTRACT_ME(Yb_Image_ImageBackendInterface, fromString, arginfo_yb_image_imagebackendinterface_fromstring)
	PHP_ABSTRACT_ME(Yb_Image_ImageBackendInterface, captcha, arginfo_yb_image_imagebackendinterface_captcha)
	PHP_ABSTRACT_ME(Yb_Image_ImageBackendInterface, resize, arginfo_yb_image_imagebackendinterface_resize)
	PHP_ABSTRACT_ME(Yb_Image_ImageBackendInterface, crop, arginfo_yb_image_imagebackendinterface_crop)
	PHP_ABSTRACT_ME(Yb_Image_ImageBackendInterface, thumbnail, arginfo_yb_image_imagebackendinterface_thumbnail)
	PHP_ABSTRACT_ME(Yb_Image_ImageBackendInterface, draw, arginfo_yb_image_imagebackendinterface_draw)
	PHP_ABSTRACT_ME(Yb_Image_ImageBackendInterface, save, arginfo_yb_image_imagebackendinterface_save)
	PHP_ABSTRACT_ME(Yb_Image_ImageBackendInterface, destroy, arginfo_yb_image_imagebackendinterface_destroy)
	PHP_FE_END
};
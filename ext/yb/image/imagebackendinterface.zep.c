
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Yb_Image_ImageBackendInterface) {

	ZEPHIR_REGISTER_INTERFACE(Yb\\Image, ImageBackendInterface, yb, image_imagebackendinterface, yb_image_imagebackendinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Yb_Image_ImageBackendInterface, watermark);

ZEPHIR_DOC_METHOD(Yb_Image_ImageBackendInterface, fromImage);

ZEPHIR_DOC_METHOD(Yb_Image_ImageBackendInterface, fromSize);

ZEPHIR_DOC_METHOD(Yb_Image_ImageBackendInterface, fromPath);

ZEPHIR_DOC_METHOD(Yb_Image_ImageBackendInterface, fromString);

ZEPHIR_DOC_METHOD(Yb_Image_ImageBackendInterface, captcha);

ZEPHIR_DOC_METHOD(Yb_Image_ImageBackendInterface, resize);

ZEPHIR_DOC_METHOD(Yb_Image_ImageBackendInterface, crop);

ZEPHIR_DOC_METHOD(Yb_Image_ImageBackendInterface, thumbnail);

ZEPHIR_DOC_METHOD(Yb_Image_ImageBackendInterface, draw);

ZEPHIR_DOC_METHOD(Yb_Image_ImageBackendInterface, save);

ZEPHIR_DOC_METHOD(Yb_Image_ImageBackendInterface, destroy);


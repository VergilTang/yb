
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Yb_Upload_UriGeneratorInterface) {

	ZEPHIR_REGISTER_INTERFACE(Yb\\Upload, UriGeneratorInterface, yb, upload_urigeneratorinterface, yb_upload_urigeneratorinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Yb_Upload_UriGeneratorInterface, generateUri);


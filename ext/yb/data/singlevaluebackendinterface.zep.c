
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Yb_Data_SingleValueBackendInterface) {

	ZEPHIR_REGISTER_INTERFACE(Yb\\Data, SingleValueBackendInterface, yb, data_singlevaluebackendinterface, yb_data_singlevaluebackendinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Yb_Data_SingleValueBackendInterface, setSingleValue);

ZEPHIR_DOC_METHOD(Yb_Data_SingleValueBackendInterface, getSingleValue);

ZEPHIR_DOC_METHOD(Yb_Data_SingleValueBackendInterface, deleteSingleValue);


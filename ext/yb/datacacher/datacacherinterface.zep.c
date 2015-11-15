
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Yb_DataCacher_DataCacherInterface) {

	ZEPHIR_REGISTER_INTERFACE(Yb\\DataCacher, DataCacherInterface, yb, datacacher_datacacherinterface, yb_datacacher_datacacherinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Yb_DataCacher_DataCacherInterface, storeData);

ZEPHIR_DOC_METHOD(Yb_DataCacher_DataCacherInterface, fetchData);

ZEPHIR_DOC_METHOD(Yb_DataCacher_DataCacherInterface, forgetData);



#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Yb_Data_GroupedBackendInterface) {

	ZEPHIR_REGISTER_INTERFACE(Yb\\Data, GroupedBackendInterface, yb, data_groupedbackendinterface, yb_data_groupedbackendinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Yb_Data_GroupedBackendInterface, setGrouped);

ZEPHIR_DOC_METHOD(Yb_Data_GroupedBackendInterface, getGrouped);

ZEPHIR_DOC_METHOD(Yb_Data_GroupedBackendInterface, deleteGrouped);

ZEPHIR_DOC_METHOD(Yb_Data_GroupedBackendInterface, setManyGrouped);

ZEPHIR_DOC_METHOD(Yb_Data_GroupedBackendInterface, getManyGrouped);

ZEPHIR_DOC_METHOD(Yb_Data_GroupedBackendInterface, deleteManyGrouped);

ZEPHIR_DOC_METHOD(Yb_Data_GroupedBackendInterface, setAllGrouped);

ZEPHIR_DOC_METHOD(Yb_Data_GroupedBackendInterface, getAllGrouped);

ZEPHIR_DOC_METHOD(Yb_Data_GroupedBackendInterface, deleteAllGrouped);



#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Yb_Collection_CollectionInterface) {

	ZEPHIR_REGISTER_INTERFACE(Yb\\Collection, CollectionInterface, yb, collection_collectioninterface, yb_collection_collectioninterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Yb_Collection_CollectionInterface, set);

ZEPHIR_DOC_METHOD(Yb_Collection_CollectionInterface, get);

ZEPHIR_DOC_METHOD(Yb_Collection_CollectionInterface, delete);

ZEPHIR_DOC_METHOD(Yb_Collection_CollectionInterface, setMany);

ZEPHIR_DOC_METHOD(Yb_Collection_CollectionInterface, getMany);

ZEPHIR_DOC_METHOD(Yb_Collection_CollectionInterface, deleteMany);

ZEPHIR_DOC_METHOD(Yb_Collection_CollectionInterface, setAll);

ZEPHIR_DOC_METHOD(Yb_Collection_CollectionInterface, getAll);

ZEPHIR_DOC_METHOD(Yb_Collection_CollectionInterface, deleteAll);


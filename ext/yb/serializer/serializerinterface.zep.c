
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Yb_Serializer_SerializerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Yb\\Serializer, SerializerInterface, yb, serializer_serializerinterface, yb_serializer_serializerinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Yb_Serializer_SerializerInterface, serialize);

ZEPHIR_DOC_METHOD(Yb_Serializer_SerializerInterface, unserialize);


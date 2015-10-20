
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Yb_Factory_FactoryInterface) {

	ZEPHIR_REGISTER_INTERFACE(Yb\\Factory, FactoryInterface, yb, factory_factoryinterface, yb_factory_factoryinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Yb_Factory_FactoryInterface, has);

ZEPHIR_DOC_METHOD(Yb_Factory_FactoryInterface, get);


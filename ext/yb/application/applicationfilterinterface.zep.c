
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Yb_Application_ApplicationFilterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Yb\\Application, ApplicationFilterInterface, yb, application_applicationfilterinterface, yb_application_applicationfilterinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Yb_Application_ApplicationFilterInterface, filterApplication);


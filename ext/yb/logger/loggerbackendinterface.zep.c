
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Yb_Logger_LoggerBackendInterface) {

	ZEPHIR_REGISTER_INTERFACE(Yb\\Logger, LoggerBackendInterface, yb, logger_loggerbackendinterface, yb_logger_loggerbackendinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Yb_Logger_LoggerBackendInterface, log);


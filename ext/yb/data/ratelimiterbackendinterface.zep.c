
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Yb_Data_RateLimiterBackendInterface) {

	ZEPHIR_REGISTER_INTERFACE(Yb\\Data, RateLimiterBackendInterface, yb, data_ratelimiterbackendinterface, yb_data_ratelimiterbackendinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Yb_Data_RateLimiterBackendInterface, passRateLimiter);


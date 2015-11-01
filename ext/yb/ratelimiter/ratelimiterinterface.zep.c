
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Yb_RateLimiter_RateLimiterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Yb\\RateLimiter, RateLimiterInterface, yb, ratelimiter_ratelimiterinterface, yb_ratelimiter_ratelimiterinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Yb_RateLimiter_RateLimiterInterface, passRateLimiter);


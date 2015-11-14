
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Yb_Redis_RedisClientInterface) {

	ZEPHIR_REGISTER_INTERFACE(Yb\\Redis, RedisClientInterface, yb, redis_redisclientinterface, NULL);

	return SUCCESS;

}


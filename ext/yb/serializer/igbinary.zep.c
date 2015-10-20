
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Yb_Serializer_Igbinary) {

	ZEPHIR_REGISTER_CLASS(Yb\\Serializer, Igbinary, yb, serializer_igbinary, yb_serializer_igbinary_method_entry, 0);

	zend_class_implements(yb_serializer_igbinary_ce TSRMLS_CC, 1, yb_serializer_serializerinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Yb_Serializer_Igbinary, __construct) {

	

	if (unlikely(!((zephir_function_exists_ex(SS("igbinary_serialize") TSRMLS_CC) == SUCCESS)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(yb_serializer_exception_ce, "Missing extension: igbinary", "yb/serializer/igbinary.zep", 8);
		return;
	}

}

PHP_METHOD(Yb_Serializer_Igbinary, serialize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_RETURN_CALL_FUNCTION("igbinary_serialize", NULL, 44, data);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Yb_Serializer_Igbinary, unserialize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	ZEPHIR_RETURN_CALL_FUNCTION("igbinary_unserialize", NULL, 45, str);
	zephir_check_call_status();
	RETURN_MM();

}


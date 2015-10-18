
extern zend_class_entry *yb_serializer_json_ce;

ZEPHIR_INIT_CLASS(Yb_Serializer_Json);

PHP_METHOD(Yb_Serializer_Json, __construct);
PHP_METHOD(Yb_Serializer_Json, serialize);
PHP_METHOD(Yb_Serializer_Json, unserialize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_serializer_json___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, serializeFlag)
	ZEND_ARG_INFO(0, unserializeToArray)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_serializer_json_serialize, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_serializer_json_unserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_serializer_json_method_entry) {
	PHP_ME(Yb_Serializer_Json, __construct, arginfo_yb_serializer_json___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_Serializer_Json, serialize, arginfo_yb_serializer_json_serialize, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Serializer_Json, unserialize, arginfo_yb_serializer_json_unserialize, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

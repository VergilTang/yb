
extern zend_class_entry *yb_serializer_igbinary_ce;

ZEPHIR_INIT_CLASS(Yb_Serializer_Igbinary);

PHP_METHOD(Yb_Serializer_Igbinary, __construct);
PHP_METHOD(Yb_Serializer_Igbinary, serialize);
PHP_METHOD(Yb_Serializer_Igbinary, unserialize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_serializer_igbinary_serialize, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_serializer_igbinary_unserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_serializer_igbinary_method_entry) {
	PHP_ME(Yb_Serializer_Igbinary, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_Serializer_Igbinary, serialize, arginfo_yb_serializer_igbinary_serialize, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Serializer_Igbinary, unserialize, arginfo_yb_serializer_igbinary_unserialize, ZEND_ACC_PUBLIC)
	PHP_FE_END
};


extern zend_class_entry *yb_std_ce;

ZEPHIR_INIT_CLASS(Yb_Std);

PHP_METHOD(Yb_Std, sizeToByte);
PHP_METHOD(Yb_Std, pascalCase);
PHP_METHOD(Yb_Std, camelCase);
PHP_METHOD(Yb_Std, normalCase);
PHP_METHOD(Yb_Std, uuid);
PHP_METHOD(Yb_Std, randString);
PHP_METHOD(Yb_Std, newInstanceOf);
PHP_METHOD(Yb_Std, ignoreError);
PHP_METHOD(Yb_Std, throwError);
PHP_METHOD(Yb_Std, outputScript);
PHP_METHOD(Yb_Std, renderScript);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_std_sizetobyte, 0, 0, 1)
	ZEND_ARG_INFO(0, size)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_std_pascalcase, 0, 0, 1)
	ZEND_ARG_INFO(0, from)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_std_camelcase, 0, 0, 1)
	ZEND_ARG_INFO(0, from)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_std_normalcase, 0, 0, 1)
	ZEND_ARG_INFO(0, from)
	ZEND_ARG_INFO(0, sep)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_std_uuid, 0, 0, 0)
	ZEND_ARG_INFO(0, salt)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_std_randstring, 0, 0, 1)
	ZEND_ARG_INFO(0, len)
	ZEND_ARG_INFO(0, charList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_std_newinstanceof, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
	ZEND_ARG_ARRAY_INFO(0, args, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_std_ignoreerror, 0, 0, 4)
	ZEND_ARG_INFO(0, n)
	ZEND_ARG_INFO(0, s)
	ZEND_ARG_INFO(0, f)
	ZEND_ARG_INFO(0, l)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_std_throwerror, 0, 0, 4)
	ZEND_ARG_INFO(0, n)
	ZEND_ARG_INFO(0, s)
	ZEND_ARG_INFO(0, f)
	ZEND_ARG_INFO(0, l)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_std_outputscript, 0, 0, 2)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_std_renderscript, 0, 0, 2)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_std_method_entry) {
	PHP_ME(Yb_Std, sizeToByte, arginfo_yb_std_sizetobyte, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yb_Std, pascalCase, arginfo_yb_std_pascalcase, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yb_Std, camelCase, arginfo_yb_std_camelcase, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yb_Std, normalCase, arginfo_yb_std_normalcase, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yb_Std, uuid, arginfo_yb_std_uuid, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yb_Std, randString, arginfo_yb_std_randstring, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yb_Std, newInstanceOf, arginfo_yb_std_newinstanceof, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yb_Std, ignoreError, arginfo_yb_std_ignoreerror, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yb_Std, throwError, arginfo_yb_std_throwerror, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yb_Std, outputScript, arginfo_yb_std_outputscript, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yb_Std, renderScript, arginfo_yb_std_renderscript, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

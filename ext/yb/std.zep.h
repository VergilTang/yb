
extern zend_class_entry *yb_std_ce;

ZEPHIR_INIT_CLASS(Yb_Std);

PHP_METHOD(Yb_Std, sizeToBytes);
PHP_METHOD(Yb_Std, bytesToSize);
PHP_METHOD(Yb_Std, pascalCase);
PHP_METHOD(Yb_Std, camelCase);
PHP_METHOD(Yb_Std, normalCase);
PHP_METHOD(Yb_Std, uuid);
PHP_METHOD(Yb_Std, randString);
PHP_METHOD(Yb_Std, tr);
PHP_METHOD(Yb_Std, valueAt);
PHP_METHOD(Yb_Std, valueOf);
PHP_METHOD(Yb_Std, indexedData);
PHP_METHOD(Yb_Std, indexedValues);
PHP_METHOD(Yb_Std, groupedData);
PHP_METHOD(Yb_Std, groupedValues);
PHP_METHOD(Yb_Std, groupIndexedData);
PHP_METHOD(Yb_Std, groupIndexedValues);
PHP_METHOD(Yb_Std, uniqueValues);
PHP_METHOD(Yb_Std, newInstanceOf);
PHP_METHOD(Yb_Std, ignoreError);
PHP_METHOD(Yb_Std, throwError);
PHP_METHOD(Yb_Std, outputScript);
PHP_METHOD(Yb_Std, renderScript);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_std_sizetobytes, 0, 0, 1)
	ZEND_ARG_INFO(0, size)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_std_bytestosize, 0, 0, 1)
	ZEND_ARG_INFO(0, bytes)
	ZEND_ARG_INFO(0, decimal)
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_std_tr, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_std_valueat, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, arr, 0)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_std_valueof, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, arr, 0)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_std_indexeddata, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, indexKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_std_indexedvalues, 0, 0, 3)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, indexKey)
	ZEND_ARG_INFO(0, valueKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_std_groupeddata, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, groupKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_std_groupedvalues, 0, 0, 3)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, groupKey)
	ZEND_ARG_INFO(0, valueKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_std_groupindexeddata, 0, 0, 3)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, groupKey)
	ZEND_ARG_INFO(0, indexKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_std_groupindexedvalues, 0, 0, 4)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, groupKey)
	ZEND_ARG_INFO(0, indexKey)
	ZEND_ARG_INFO(0, valueKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_std_uniquevalues, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, uniqueKey)
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
	PHP_ME(Yb_Std, sizeToBytes, arginfo_yb_std_sizetobytes, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yb_Std, bytesToSize, arginfo_yb_std_bytestosize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yb_Std, pascalCase, arginfo_yb_std_pascalcase, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yb_Std, camelCase, arginfo_yb_std_camelcase, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yb_Std, normalCase, arginfo_yb_std_normalcase, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yb_Std, uuid, arginfo_yb_std_uuid, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yb_Std, randString, arginfo_yb_std_randstring, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yb_Std, tr, arginfo_yb_std_tr, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yb_Std, valueAt, arginfo_yb_std_valueat, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yb_Std, valueOf, arginfo_yb_std_valueof, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yb_Std, indexedData, arginfo_yb_std_indexeddata, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yb_Std, indexedValues, arginfo_yb_std_indexedvalues, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yb_Std, groupedData, arginfo_yb_std_groupeddata, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yb_Std, groupedValues, arginfo_yb_std_groupedvalues, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yb_Std, groupIndexedData, arginfo_yb_std_groupindexeddata, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yb_Std, groupIndexedValues, arginfo_yb_std_groupindexedvalues, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yb_Std, uniqueValues, arginfo_yb_std_uniquevalues, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yb_Std, newInstanceOf, arginfo_yb_std_newinstanceof, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yb_Std, ignoreError, arginfo_yb_std_ignoreerror, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yb_Std, throwError, arginfo_yb_std_throwerror, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yb_Std, outputScript, arginfo_yb_std_outputscript, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yb_Std, renderScript, arginfo_yb_std_renderscript, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

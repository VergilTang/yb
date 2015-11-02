
extern zend_class_entry *yb_db_oci8_ce;

ZEPHIR_INIT_CLASS(Yb_Db_Oci8);

PHP_METHOD(Yb_Db_Oci8, __construct);
PHP_METHOD(Yb_Db_Oci8, getInternalHandler);
PHP_METHOD(Yb_Db_Oci8, quote);
PHP_METHOD(Yb_Db_Oci8, query);
PHP_METHOD(Yb_Db_Oci8, queryAll);
PHP_METHOD(Yb_Db_Oci8, queryAllCallback);
PHP_METHOD(Yb_Db_Oci8, queryRow);
PHP_METHOD(Yb_Db_Oci8, queryCell);
PHP_METHOD(Yb_Db_Oci8, queryColumns);
PHP_METHOD(Yb_Db_Oci8, tryToBegin);
PHP_METHOD(Yb_Db_Oci8, tryToCommit);
PHP_METHOD(Yb_Db_Oci8, tryToRollback);
PHP_METHOD(Yb_Db_Oci8, paginateQuery);
PHP_METHOD(Yb_Db_Oci8, randomOrder);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_oci8___construct, 0, 0, 3)
	ZEND_ARG_INFO(0, dsn)
	ZEND_ARG_INFO(0, user)
	ZEND_ARG_INFO(0, passwd)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_oci8_quote, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_oci8_query, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_oci8_queryall, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_oci8_queryallcallback, 0, 0, 2)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_oci8_queryrow, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_oci8_querycell, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_oci8_querycolumns, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_oci8_paginatequery, 0, 0, 3)
	ZEND_ARG_INFO(0, query)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_db_oci8_method_entry) {
	PHP_ME(Yb_Db_Oci8, __construct, arginfo_yb_db_oci8___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_Db_Oci8, getInternalHandler, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Oci8, quote, arginfo_yb_db_oci8_quote, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Oci8, query, arginfo_yb_db_oci8_query, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Oci8, queryAll, arginfo_yb_db_oci8_queryall, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Oci8, queryAllCallback, arginfo_yb_db_oci8_queryallcallback, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Oci8, queryRow, arginfo_yb_db_oci8_queryrow, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Oci8, queryCell, arginfo_yb_db_oci8_querycell, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Oci8, queryColumns, arginfo_yb_db_oci8_querycolumns, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Oci8, tryToBegin, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Yb_Db_Oci8, tryToCommit, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Yb_Db_Oci8, tryToRollback, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Yb_Db_Oci8, paginateQuery, arginfo_yb_db_oci8_paginatequery, ZEND_ACC_PROTECTED)
	PHP_ME(Yb_Db_Oci8, randomOrder, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

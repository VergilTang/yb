
extern zend_class_entry *yb_db_pdomysql_ce;

ZEPHIR_INIT_CLASS(Yb_Db_PdoMysql);

PHP_METHOD(Yb_Db_PdoMysql, insert);
PHP_METHOD(Yb_Db_PdoMysql, upsert);
PHP_METHOD(Yb_Db_PdoMysql, countAndSelect);
PHP_METHOD(Yb_Db_PdoMysql, paginateQuery);
PHP_METHOD(Yb_Db_PdoMysql, randomOrder);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_pdomysql_insert, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, returningId)
	ZEND_ARG_INFO(0, upsert)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_pdomysql_upsert, 0, 0, 3)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, primaryKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_pdomysql_countandselect, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_pdomysql_paginatequery, 0, 0, 3)
	ZEND_ARG_INFO(0, query)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_db_pdomysql_method_entry) {
	PHP_ME(Yb_Db_PdoMysql, insert, arginfo_yb_db_pdomysql_insert, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_PdoMysql, upsert, arginfo_yb_db_pdomysql_upsert, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_PdoMysql, countAndSelect, arginfo_yb_db_pdomysql_countandselect, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_PdoMysql, paginateQuery, arginfo_yb_db_pdomysql_paginatequery, ZEND_ACC_PROTECTED)
	PHP_ME(Yb_Db_PdoMysql, randomOrder, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

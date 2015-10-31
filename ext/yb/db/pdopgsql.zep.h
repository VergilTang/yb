
extern zend_class_entry *yb_db_pdopgsql_ce;

ZEPHIR_INIT_CLASS(Yb_Db_PdoPgsql);

PHP_METHOD(Yb_Db_PdoPgsql, paginateQuery);
PHP_METHOD(Yb_Db_PdoPgsql, randomOrder);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_pdopgsql_paginatequery, 0, 0, 3)
	ZEND_ARG_INFO(0, query)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_db_pdopgsql_method_entry) {
	PHP_ME(Yb_Db_PdoPgsql, paginateQuery, arginfo_yb_db_pdopgsql_paginatequery, ZEND_ACC_PROTECTED)
	PHP_ME(Yb_Db_PdoPgsql, randomOrder, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

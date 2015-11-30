
extern zend_class_entry *yb_db_dbabstract_ce;

ZEPHIR_INIT_CLASS(Yb_Db_DbAbstract);

PHP_METHOD(Yb_Db_DbAbstract, nextFlag);
PHP_METHOD(Yb_Db_DbAbstract, getInternalHandler);
PHP_METHOD(Yb_Db_DbAbstract, quote);
PHP_METHOD(Yb_Db_DbAbstract, query);
PHP_METHOD(Yb_Db_DbAbstract, queryAll);
PHP_METHOD(Yb_Db_DbAbstract, queryRow);
PHP_METHOD(Yb_Db_DbAbstract, queryCell);
PHP_METHOD(Yb_Db_DbAbstract, queryColumns);
PHP_METHOD(Yb_Db_DbAbstract, inTransaction);
PHP_METHOD(Yb_Db_DbAbstract, begin);
PHP_METHOD(Yb_Db_DbAbstract, commit);
PHP_METHOD(Yb_Db_DbAbstract, rollback);
PHP_METHOD(Yb_Db_DbAbstract, savepoint);
PHP_METHOD(Yb_Db_DbAbstract, releaseSavepoint);
PHP_METHOD(Yb_Db_DbAbstract, releaseLastSavepoint);
PHP_METHOD(Yb_Db_DbAbstract, rollbackToSavepoint);
PHP_METHOD(Yb_Db_DbAbstract, rollbackToLastSavepoint);
PHP_METHOD(Yb_Db_DbAbstract, getQueries);
PHP_METHOD(Yb_Db_DbAbstract, insert);
PHP_METHOD(Yb_Db_DbAbstract, delete);
PHP_METHOD(Yb_Db_DbAbstract, update);
PHP_METHOD(Yb_Db_DbAbstract, upsert);
PHP_METHOD(Yb_Db_DbAbstract, parseSelect);
PHP_METHOD(Yb_Db_DbAbstract, selectAll);
PHP_METHOD(Yb_Db_DbAbstract, selectRow);
PHP_METHOD(Yb_Db_DbAbstract, selectCell);
PHP_METHOD(Yb_Db_DbAbstract, selectColumns);
PHP_METHOD(Yb_Db_DbAbstract, countAndSelect);
PHP_METHOD(Yb_Db_DbAbstract, parseUnionAll);
PHP_METHOD(Yb_Db_DbAbstract, queryUnionAll);
PHP_METHOD(Yb_Db_DbAbstract, countAndQueryUnionAll);
PHP_METHOD(Yb_Db_DbAbstract, parseAggregation);
PHP_METHOD(Yb_Db_DbAbstract, queryAggregation);
PHP_METHOD(Yb_Db_DbAbstract, aggregate);
PHP_METHOD(Yb_Db_DbAbstract, count);
PHP_METHOD(Yb_Db_DbAbstract, max);
PHP_METHOD(Yb_Db_DbAbstract, min);
PHP_METHOD(Yb_Db_DbAbstract, sum);
PHP_METHOD(Yb_Db_DbAbstract, parseGroupedAggregation);
PHP_METHOD(Yb_Db_DbAbstract, queryGroupedAggregation);
PHP_METHOD(Yb_Db_DbAbstract, parseWhere);
PHP_METHOD(Yb_Db_DbAbstract, tryToBegin);
PHP_METHOD(Yb_Db_DbAbstract, tryToCommit);
PHP_METHOD(Yb_Db_DbAbstract, tryToRollback);
PHP_METHOD(Yb_Db_DbAbstract, paginateQuery);
PHP_METHOD(Yb_Db_DbAbstract, randomOrder);
PHP_METHOD(Yb_Db_DbAbstract, addQuery);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_dbabstract_nextflag, 0, 0, 0)
	ZEND_ARG_INFO(0, pre)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_dbabstract_quote, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_dbabstract_query, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_dbabstract_queryall, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_dbabstract_queryrow, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_dbabstract_querycell, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_dbabstract_querycolumns, 0, 0, 1)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_dbabstract_savepoint, 0, 0, 0)
	ZEND_ARG_INFO(0, savepoint)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_dbabstract_releasesavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, savepoint)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_dbabstract_rollbacktosavepoint, 0, 0, 1)
	ZEND_ARG_INFO(0, savepoint)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_dbabstract_insert, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, returningId)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_dbabstract_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_ARRAY_INFO(0, where, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_dbabstract_update, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_ARRAY_INFO(0, where, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_dbabstract_upsert, 0, 0, 3)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_INFO(0, primaryKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_dbabstract_parseselect, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_dbabstract_selectall, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_dbabstract_selectrow, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_dbabstract_selectcell, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_dbabstract_selectcolumns, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_dbabstract_countandselect, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_dbabstract_parseunionall, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, selects, 0)
	ZEND_ARG_INFO(0, orderBy)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_dbabstract_queryunionall, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, selects, 0)
	ZEND_ARG_INFO(0, orderBy)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_dbabstract_countandqueryunionall, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, selects, 0)
	ZEND_ARG_INFO(0, orderBy)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_dbabstract_parseaggregation, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_ARRAY_INFO(0, aggregations, 0)
	ZEND_ARG_ARRAY_INFO(0, where, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_dbabstract_queryaggregation, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_ARRAY_INFO(0, aggregations, 0)
	ZEND_ARG_ARRAY_INFO(0, where, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_dbabstract_aggregate, 0, 0, 3)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, column)
	ZEND_ARG_INFO(0, aggregation)
	ZEND_ARG_ARRAY_INFO(0, where, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_dbabstract_count, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, column)
	ZEND_ARG_ARRAY_INFO(0, where, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_dbabstract_max, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, column)
	ZEND_ARG_ARRAY_INFO(0, where, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_dbabstract_min, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, column)
	ZEND_ARG_ARRAY_INFO(0, where, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_dbabstract_sum, 0, 0, 2)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, column)
	ZEND_ARG_ARRAY_INFO(0, where, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_dbabstract_parsegroupedaggregation, 0, 0, 3)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, groupBy)
	ZEND_ARG_ARRAY_INFO(0, aggrs, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_dbabstract_querygroupedaggregation, 0, 0, 3)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, groupBy)
	ZEND_ARG_ARRAY_INFO(0, aggrs, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_dbabstract_parsewhere, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, where, 0)
	ZEND_ARG_INFO(0, sep)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_dbabstract_paginatequery, 0, 0, 3)
	ZEND_ARG_INFO(0, query)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_dbabstract_addquery, 0, 0, 3)
	ZEND_ARG_INFO(0, q)
	ZEND_ARG_ARRAY_INFO(0, p, 0)
	ZEND_ARG_INFO(0, t)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_db_dbabstract_method_entry) {
	PHP_ME(Yb_Db_DbAbstract, nextFlag, arginfo_yb_db_dbabstract_nextflag, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Yb_Db_DbAbstract, getInternalHandler, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_DbAbstract, quote, arginfo_yb_db_dbabstract_quote, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_DbAbstract, query, arginfo_yb_db_dbabstract_query, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_DbAbstract, queryAll, arginfo_yb_db_dbabstract_queryall, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_DbAbstract, queryRow, arginfo_yb_db_dbabstract_queryrow, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_DbAbstract, queryCell, arginfo_yb_db_dbabstract_querycell, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_DbAbstract, queryColumns, arginfo_yb_db_dbabstract_querycolumns, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_DbAbstract, inTransaction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_DbAbstract, begin, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_DbAbstract, commit, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_DbAbstract, rollback, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_DbAbstract, savepoint, arginfo_yb_db_dbabstract_savepoint, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_DbAbstract, releaseSavepoint, arginfo_yb_db_dbabstract_releasesavepoint, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_DbAbstract, releaseLastSavepoint, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_DbAbstract, rollbackToSavepoint, arginfo_yb_db_dbabstract_rollbacktosavepoint, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_DbAbstract, rollbackToLastSavepoint, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_DbAbstract, getQueries, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_DbAbstract, insert, arginfo_yb_db_dbabstract_insert, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_DbAbstract, delete, arginfo_yb_db_dbabstract_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_DbAbstract, update, arginfo_yb_db_dbabstract_update, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_DbAbstract, upsert, arginfo_yb_db_dbabstract_upsert, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_DbAbstract, parseSelect, arginfo_yb_db_dbabstract_parseselect, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_DbAbstract, selectAll, arginfo_yb_db_dbabstract_selectall, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_DbAbstract, selectRow, arginfo_yb_db_dbabstract_selectrow, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_DbAbstract, selectCell, arginfo_yb_db_dbabstract_selectcell, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_DbAbstract, selectColumns, arginfo_yb_db_dbabstract_selectcolumns, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_DbAbstract, countAndSelect, arginfo_yb_db_dbabstract_countandselect, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_DbAbstract, parseUnionAll, arginfo_yb_db_dbabstract_parseunionall, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_DbAbstract, queryUnionAll, arginfo_yb_db_dbabstract_queryunionall, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_DbAbstract, countAndQueryUnionAll, arginfo_yb_db_dbabstract_countandqueryunionall, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_DbAbstract, parseAggregation, arginfo_yb_db_dbabstract_parseaggregation, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_DbAbstract, queryAggregation, arginfo_yb_db_dbabstract_queryaggregation, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_DbAbstract, aggregate, arginfo_yb_db_dbabstract_aggregate, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_DbAbstract, count, arginfo_yb_db_dbabstract_count, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_DbAbstract, max, arginfo_yb_db_dbabstract_max, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_DbAbstract, min, arginfo_yb_db_dbabstract_min, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_DbAbstract, sum, arginfo_yb_db_dbabstract_sum, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_DbAbstract, parseGroupedAggregation, arginfo_yb_db_dbabstract_parsegroupedaggregation, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_DbAbstract, queryGroupedAggregation, arginfo_yb_db_dbabstract_querygroupedaggregation, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_DbAbstract, parseWhere, arginfo_yb_db_dbabstract_parsewhere, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_DbAbstract, tryToBegin, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Yb_Db_DbAbstract, tryToCommit, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Yb_Db_DbAbstract, tryToRollback, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Yb_Db_DbAbstract, paginateQuery, arginfo_yb_db_dbabstract_paginatequery, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Yb_Db_DbAbstract, randomOrder, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Yb_Db_DbAbstract, addQuery, arginfo_yb_db_dbabstract_addquery, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

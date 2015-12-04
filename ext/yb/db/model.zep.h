
extern zend_class_entry *yb_db_model_ce;

ZEPHIR_INIT_CLASS(Yb_Db_Model);

PHP_METHOD(Yb_Db_Model, __construct);
PHP_METHOD(Yb_Db_Model, setDb);
PHP_METHOD(Yb_Db_Model, getDb);
PHP_METHOD(Yb_Db_Model, insert);
PHP_METHOD(Yb_Db_Model, update);
PHP_METHOD(Yb_Db_Model, delete);
PHP_METHOD(Yb_Db_Model, newEntity);
PHP_METHOD(Yb_Db_Model, create);
PHP_METHOD(Yb_Db_Model, first);
PHP_METHOD(Yb_Db_Model, id);
PHP_METHOD(Yb_Db_Model, newCollection);
PHP_METHOD(Yb_Db_Model, all);
PHP_METHOD(Yb_Db_Model, ids);
PHP_METHOD(Yb_Db_Model, chunkByDynamicWhere);
PHP_METHOD(Yb_Db_Model, chunkByFixedWhere);
PHP_METHOD(Yb_Db_Model, aggregation);
PHP_METHOD(Yb_Db_Model, countAll);
PHP_METHOD(Yb_Db_Model, count);
PHP_METHOD(Yb_Db_Model, max);
PHP_METHOD(Yb_Db_Model, min);
PHP_METHOD(Yb_Db_Model, sum);
PHP_METHOD(Yb_Db_Model, onStore);
PHP_METHOD(Yb_Db_Model, onFetch);
PHP_METHOD(Yb_Db_Model, pickPrimaryKeyValue);
PHP_METHOD(Yb_Db_Model, packPrimaryKeyValue);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_model___construct, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, db, Yb\\Db\\DbAbstract, 0)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, primaryKey)
	ZEND_ARG_INFO(0, autoIncrement)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_model_setdb, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, db, Yb\\Db\\DbAbstract, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_model_insert, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, row, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_model_update, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, updates, 0)
	ZEND_ARG_ARRAY_INFO(0, where, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_model_delete, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, where, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_model_newentity, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, row, 1)
	ZEND_ARG_INFO(0, isNew)
	ZEND_ARG_OBJ_INFO(0, collection, Yb\\Db\\Collection, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_model_create, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, row, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_model_first, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, where, 1)
	ZEND_ARG_INFO(0, orderBy)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_model_id, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_model_newcollection, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_model_all, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, where, 1)
	ZEND_ARG_INFO(0, orderBy)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_model_ids, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, ids, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_model_chunkbydynamicwhere, 0, 0, 1)
	ZEND_ARG_INFO(0, delegate)
	ZEND_ARG_ARRAY_INFO(0, where, 1)
	ZEND_ARG_INFO(0, orderBy)
	ZEND_ARG_INFO(0, limit)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_model_chunkbyfixedwhere, 0, 0, 1)
	ZEND_ARG_INFO(0, delegate)
	ZEND_ARG_ARRAY_INFO(0, where, 1)
	ZEND_ARG_INFO(0, orderBy)
	ZEND_ARG_INFO(0, limit)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_model_aggregation, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, aggregations, 0)
	ZEND_ARG_ARRAY_INFO(0, where, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_model_countall, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, where, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_model_count, 0, 0, 0)
	ZEND_ARG_INFO(0, column)
	ZEND_ARG_ARRAY_INFO(0, where, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_model_max, 0, 0, 1)
	ZEND_ARG_INFO(0, column)
	ZEND_ARG_ARRAY_INFO(0, where, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_model_min, 0, 0, 1)
	ZEND_ARG_INFO(0, column)
	ZEND_ARG_ARRAY_INFO(0, where, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_model_sum, 0, 0, 1)
	ZEND_ARG_INFO(0, column)
	ZEND_ARG_ARRAY_INFO(0, where, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_model_onstore, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, row, 0)
	ZEND_ARG_INFO(0, isUpdate)
	ZEND_ARG_ARRAY_INFO(0, where, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_model_onfetch, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, row, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_model_pickprimarykeyvalue, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, row, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_db_model_packprimarykeyvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_db_model_method_entry) {
	PHP_ME(Yb_Db_Model, __construct, arginfo_yb_db_model___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_Db_Model, setDb, arginfo_yb_db_model_setdb, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Model, getDb, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Model, insert, arginfo_yb_db_model_insert, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Model, update, arginfo_yb_db_model_update, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Model, delete, arginfo_yb_db_model_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Model, newEntity, arginfo_yb_db_model_newentity, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Model, create, arginfo_yb_db_model_create, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Model, first, arginfo_yb_db_model_first, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Model, id, arginfo_yb_db_model_id, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Model, newCollection, arginfo_yb_db_model_newcollection, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Model, all, arginfo_yb_db_model_all, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Model, ids, arginfo_yb_db_model_ids, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Model, chunkByDynamicWhere, arginfo_yb_db_model_chunkbydynamicwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Model, chunkByFixedWhere, arginfo_yb_db_model_chunkbyfixedwhere, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Model, aggregation, arginfo_yb_db_model_aggregation, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Model, countAll, arginfo_yb_db_model_countall, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Model, count, arginfo_yb_db_model_count, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Model, max, arginfo_yb_db_model_max, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Model, min, arginfo_yb_db_model_min, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Model, sum, arginfo_yb_db_model_sum, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Model, onStore, arginfo_yb_db_model_onstore, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Model, onFetch, arginfo_yb_db_model_onfetch, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Model, pickPrimaryKeyValue, arginfo_yb_db_model_pickprimarykeyvalue, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Db_Model, packPrimaryKeyValue, arginfo_yb_db_model_packprimarykeyvalue, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

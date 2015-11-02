
extern zend_class_entry *yb_sequence_dbpdomysql_ce;

ZEPHIR_INIT_CLASS(Yb_Sequence_DbPdoMysql);

PHP_METHOD(Yb_Sequence_DbPdoMysql, __construct);
PHP_METHOD(Yb_Sequence_DbPdoMysql, getNextSequence);
PHP_METHOD(Yb_Sequence_DbPdoMysql, restoreSequences);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_sequence_dbpdomysql___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, mysql, Yb\\Db\\PdoMysql, 0)
	ZEND_ARG_INFO(0, table)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_sequence_dbpdomysql_getnextsequence, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_sequence_dbpdomysql_restoresequences, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, sequences, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_sequence_dbpdomysql_method_entry) {
	PHP_ME(Yb_Sequence_DbPdoMysql, __construct, arginfo_yb_sequence_dbpdomysql___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_Sequence_DbPdoMysql, getNextSequence, arginfo_yb_sequence_dbpdomysql_getnextsequence, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Sequence_DbPdoMysql, restoreSequences, arginfo_yb_sequence_dbpdomysql_restoresequences, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

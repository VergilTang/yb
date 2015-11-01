
extern zend_class_entry *yb_sequence_redishash_ce;

ZEPHIR_INIT_CLASS(Yb_Sequence_RedisHash);

PHP_METHOD(Yb_Sequence_RedisHash, __construct);
PHP_METHOD(Yb_Sequence_RedisHash, getNextSequence);
PHP_METHOD(Yb_Sequence_RedisHash, restoreSequences);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_sequence_redishash___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, redis)
	ZEND_ARG_INFO(0, hashName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_sequence_redishash_getnextsequence, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_sequence_redishash_restoresequences, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, sequences, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_sequence_redishash_method_entry) {
	PHP_ME(Yb_Sequence_RedisHash, __construct, arginfo_yb_sequence_redishash___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_Sequence_RedisHash, getNextSequence, arginfo_yb_sequence_redishash_getnextsequence, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Sequence_RedisHash, restoreSequences, arginfo_yb_sequence_redishash_restoresequences, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

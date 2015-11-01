
extern zend_class_entry *yb_sequence_sequenceinterface_ce;

ZEPHIR_INIT_CLASS(Yb_Sequence_SequenceInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_sequence_sequenceinterface_getnextsequence, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_sequence_sequenceinterface_restoresequences, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, sequences, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_sequence_sequenceinterface_method_entry) {
	PHP_ABSTRACT_ME(Yb_Sequence_SequenceInterface, getNextSequence, arginfo_yb_sequence_sequenceinterface_getnextsequence)
	PHP_ABSTRACT_ME(Yb_Sequence_SequenceInterface, restoreSequences, arginfo_yb_sequence_sequenceinterface_restoresequences)
	PHP_FE_END
};

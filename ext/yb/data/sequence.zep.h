
extern zend_class_entry *yb_data_sequence_ce;

ZEPHIR_INIT_CLASS(Yb_Data_Sequence);

PHP_METHOD(Yb_Data_Sequence, next);
PHP_METHOD(Yb_Data_Sequence, restore);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_data_sequence_next, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_data_sequence_restore, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, sequences, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_data_sequence_method_entry) {
	PHP_ME(Yb_Data_Sequence, next, arginfo_yb_data_sequence_next, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Data_Sequence, restore, arginfo_yb_data_sequence_restore, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

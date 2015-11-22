
extern zend_class_entry *yb_data_singlevaluebackendinterface_ce;

ZEPHIR_INIT_CLASS(Yb_Data_SingleValueBackendInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_data_singlevaluebackendinterface_setsinglevalue, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_data_singlevaluebackendinterface_getsinglevalue, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_data_singlevaluebackendinterface_deletesinglevalue, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_data_singlevaluebackendinterface_method_entry) {
	PHP_ABSTRACT_ME(Yb_Data_SingleValueBackendInterface, setSingleValue, arginfo_yb_data_singlevaluebackendinterface_setsinglevalue)
	PHP_ABSTRACT_ME(Yb_Data_SingleValueBackendInterface, getSingleValue, arginfo_yb_data_singlevaluebackendinterface_getsinglevalue)
	PHP_ABSTRACT_ME(Yb_Data_SingleValueBackendInterface, deleteSingleValue, arginfo_yb_data_singlevaluebackendinterface_deletesinglevalue)
	PHP_FE_END
};


extern zend_class_entry *yb_datacacher_datacacherinterface_ce;

ZEPHIR_INIT_CLASS(Yb_DataCacher_DataCacherInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_datacacher_datacacherinterface_storedata, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_datacacher_datacacherinterface_method_entry) {
	PHP_ABSTRACT_ME(Yb_DataCacher_DataCacherInterface, storeData, arginfo_yb_datacacher_datacacherinterface_storedata)
	PHP_ABSTRACT_ME(Yb_DataCacher_DataCacherInterface, fetchData, NULL)
	PHP_ABSTRACT_ME(Yb_DataCacher_DataCacherInterface, forgetData, NULL)
	PHP_FE_END
};

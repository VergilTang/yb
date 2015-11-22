
extern zend_class_entry *yb_data_groupedbackendinterface_ce;

ZEPHIR_INIT_CLASS(Yb_Data_GroupedBackendInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_data_groupedbackendinterface_setgrouped, 0, 0, 3)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_data_groupedbackendinterface_getgrouped, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_data_groupedbackendinterface_deletegrouped, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_data_groupedbackendinterface_setmanygrouped, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_ARRAY_INFO(0, keyValues, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_data_groupedbackendinterface_getmanygrouped, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_data_groupedbackendinterface_deletemanygrouped, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_data_groupedbackendinterface_setallgrouped, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_ARRAY_INFO(0, keyValues, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_data_groupedbackendinterface_getallgrouped, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_data_groupedbackendinterface_deleteallgrouped, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_data_groupedbackendinterface_method_entry) {
	PHP_ABSTRACT_ME(Yb_Data_GroupedBackendInterface, setGrouped, arginfo_yb_data_groupedbackendinterface_setgrouped)
	PHP_ABSTRACT_ME(Yb_Data_GroupedBackendInterface, getGrouped, arginfo_yb_data_groupedbackendinterface_getgrouped)
	PHP_ABSTRACT_ME(Yb_Data_GroupedBackendInterface, deleteGrouped, arginfo_yb_data_groupedbackendinterface_deletegrouped)
	PHP_ABSTRACT_ME(Yb_Data_GroupedBackendInterface, setManyGrouped, arginfo_yb_data_groupedbackendinterface_setmanygrouped)
	PHP_ABSTRACT_ME(Yb_Data_GroupedBackendInterface, getManyGrouped, arginfo_yb_data_groupedbackendinterface_getmanygrouped)
	PHP_ABSTRACT_ME(Yb_Data_GroupedBackendInterface, deleteManyGrouped, arginfo_yb_data_groupedbackendinterface_deletemanygrouped)
	PHP_ABSTRACT_ME(Yb_Data_GroupedBackendInterface, setAllGrouped, arginfo_yb_data_groupedbackendinterface_setallgrouped)
	PHP_ABSTRACT_ME(Yb_Data_GroupedBackendInterface, getAllGrouped, arginfo_yb_data_groupedbackendinterface_getallgrouped)
	PHP_ABSTRACT_ME(Yb_Data_GroupedBackendInterface, deleteAllGrouped, arginfo_yb_data_groupedbackendinterface_deleteallgrouped)
	PHP_FE_END
};

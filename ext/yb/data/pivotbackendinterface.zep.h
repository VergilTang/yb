
extern zend_class_entry *yb_data_pivotbackendinterface_ce;

ZEPHIR_INIT_CLASS(Yb_Data_PivotBackendInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_data_pivotbackendinterface_addpivot, 0, 0, 4)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, subj)
	ZEND_ARG_INFO(0, obj)
	ZEND_ARG_INFO(0, score)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_data_pivotbackendinterface_removepivot, 0, 0, 3)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, subj)
	ZEND_ARG_INFO(0, obj)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_data_pivotbackendinterface_haspivot, 0, 0, 3)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, subj)
	ZEND_ARG_INFO(0, obj)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_data_pivotbackendinterface_addobjectspivot, 0, 0, 3)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, subj)
	ZEND_ARG_ARRAY_INFO(0, objScores, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_data_pivotbackendinterface_removeobjectspivot, 0, 0, 3)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, subj)
	ZEND_ARG_ARRAY_INFO(0, objs, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_data_pivotbackendinterface_hasobjectspivot, 0, 0, 3)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, subj)
	ZEND_ARG_ARRAY_INFO(0, objs, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_data_pivotbackendinterface_getobjectspivot, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, subj)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_data_pivotbackendinterface_countobjectspivot, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, subj)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_data_pivotbackendinterface_countandgetobjectspivot, 0, 0, 5)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, subj)
	ZEND_ARG_INFO(0, asc)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, skip)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_data_pivotbackendinterface_addsubjectspivot, 0, 0, 3)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_ARRAY_INFO(0, subjScores, 0)
	ZEND_ARG_INFO(0, obj)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_data_pivotbackendinterface_removesubjectspivot, 0, 0, 3)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_ARRAY_INFO(0, subjs, 0)
	ZEND_ARG_INFO(0, obj)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_data_pivotbackendinterface_hassubjectspivot, 0, 0, 3)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_ARRAY_INFO(0, subjs, 0)
	ZEND_ARG_INFO(0, obj)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_data_pivotbackendinterface_getsubjectspivot, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, obj)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_data_pivotbackendinterface_countsubjectspivot, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, obj)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_data_pivotbackendinterface_countandgetsubjectspivot, 0, 0, 5)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, obj)
	ZEND_ARG_INFO(0, asc)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, skip)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_data_pivotbackendinterface_method_entry) {
	PHP_ABSTRACT_ME(Yb_Data_PivotBackendInterface, addPivot, arginfo_yb_data_pivotbackendinterface_addpivot)
	PHP_ABSTRACT_ME(Yb_Data_PivotBackendInterface, removePivot, arginfo_yb_data_pivotbackendinterface_removepivot)
	PHP_ABSTRACT_ME(Yb_Data_PivotBackendInterface, hasPivot, arginfo_yb_data_pivotbackendinterface_haspivot)
	PHP_ABSTRACT_ME(Yb_Data_PivotBackendInterface, addObjectsPivot, arginfo_yb_data_pivotbackendinterface_addobjectspivot)
	PHP_ABSTRACT_ME(Yb_Data_PivotBackendInterface, removeObjectsPivot, arginfo_yb_data_pivotbackendinterface_removeobjectspivot)
	PHP_ABSTRACT_ME(Yb_Data_PivotBackendInterface, hasObjectsPivot, arginfo_yb_data_pivotbackendinterface_hasobjectspivot)
	PHP_ABSTRACT_ME(Yb_Data_PivotBackendInterface, getObjectsPivot, arginfo_yb_data_pivotbackendinterface_getobjectspivot)
	PHP_ABSTRACT_ME(Yb_Data_PivotBackendInterface, countObjectsPivot, arginfo_yb_data_pivotbackendinterface_countobjectspivot)
	PHP_ABSTRACT_ME(Yb_Data_PivotBackendInterface, countAndGetObjectsPivot, arginfo_yb_data_pivotbackendinterface_countandgetobjectspivot)
	PHP_ABSTRACT_ME(Yb_Data_PivotBackendInterface, addSubjectsPivot, arginfo_yb_data_pivotbackendinterface_addsubjectspivot)
	PHP_ABSTRACT_ME(Yb_Data_PivotBackendInterface, removeSubjectsPivot, arginfo_yb_data_pivotbackendinterface_removesubjectspivot)
	PHP_ABSTRACT_ME(Yb_Data_PivotBackendInterface, hasSubjectsPivot, arginfo_yb_data_pivotbackendinterface_hassubjectspivot)
	PHP_ABSTRACT_ME(Yb_Data_PivotBackendInterface, getSubjectsPivot, arginfo_yb_data_pivotbackendinterface_getsubjectspivot)
	PHP_ABSTRACT_ME(Yb_Data_PivotBackendInterface, countSubjectsPivot, arginfo_yb_data_pivotbackendinterface_countsubjectspivot)
	PHP_ABSTRACT_ME(Yb_Data_PivotBackendInterface, countAndGetSubjectsPivot, arginfo_yb_data_pivotbackendinterface_countandgetsubjectspivot)
	PHP_FE_END
};

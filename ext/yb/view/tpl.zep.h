
extern zend_class_entry *yb_view_tpl_ce;

ZEPHIR_INIT_CLASS(Yb_View_Tpl);

PHP_METHOD(Yb_View_Tpl, run);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_view_tpl_run, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_view_tpl_method_entry) {
	PHP_ME(Yb_View_Tpl, run, arginfo_yb_view_tpl_run, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

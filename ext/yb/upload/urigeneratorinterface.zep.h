
extern zend_class_entry *yb_upload_urigeneratorinterface_ce;

ZEPHIR_INIT_CLASS(Yb_Upload_UriGeneratorInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_upload_urigeneratorinterface_generateuri, 0, 0, 3)
	ZEND_ARG_INFO(0, source)
	ZEND_ARG_INFO(0, prefix)
	ZEND_ARG_INFO(0, extension)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_upload_urigeneratorinterface_method_entry) {
	PHP_ABSTRACT_ME(Yb_Upload_UriGeneratorInterface, generateUri, arginfo_yb_upload_urigeneratorinterface_generateuri)
	PHP_FE_END
};

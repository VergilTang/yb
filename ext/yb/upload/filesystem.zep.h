
extern zend_class_entry *yb_upload_filesystem_ce;

ZEPHIR_INIT_CLASS(Yb_Upload_FileSystem);

PHP_METHOD(Yb_Upload_FileSystem, __construct);
PHP_METHOD(Yb_Upload_FileSystem, store);
PHP_METHOD(Yb_Upload_FileSystem, remove);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_upload_filesystem___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, baseDirectory)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_upload_filesystem_store, 0, 0, 1)
	ZEND_ARG_INFO(0, source)
	ZEND_ARG_INFO(0, group)
	ZEND_ARG_INFO(0, extension)
	ZEND_ARG_INFO(0, flag)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_upload_filesystem_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_upload_filesystem_method_entry) {
	PHP_ME(Yb_Upload_FileSystem, __construct, arginfo_yb_upload_filesystem___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_Upload_FileSystem, store, arginfo_yb_upload_filesystem_store, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Upload_FileSystem, remove, arginfo_yb_upload_filesystem_remove, ZEND_ACC_PUBLIC)
	PHP_FE_END
};


extern zend_class_entry *yb_upload_ftp_ce;

ZEPHIR_INIT_CLASS(Yb_Upload_Ftp);

PHP_METHOD(Yb_Upload_Ftp, __construct);
PHP_METHOD(Yb_Upload_Ftp, store);
PHP_METHOD(Yb_Upload_Ftp, remove);
PHP_METHOD(Yb_Upload_Ftp, __destruct);
PHP_METHOD(Yb_Upload_Ftp, mkDirIfNotExists);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_upload_ftp___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_upload_ftp_store, 0, 0, 1)
	ZEND_ARG_INFO(0, source)
	ZEND_ARG_INFO(0, group)
	ZEND_ARG_INFO(0, extension)
	ZEND_ARG_INFO(0, flag)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_upload_ftp_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_upload_ftp_mkdirifnotexists, 0, 0, 1)
	ZEND_ARG_INFO(0, dir)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_upload_ftp_method_entry) {
	PHP_ME(Yb_Upload_Ftp, __construct, arginfo_yb_upload_ftp___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_Upload_Ftp, store, arginfo_yb_upload_ftp_store, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Upload_Ftp, remove, arginfo_yb_upload_ftp_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Upload_Ftp, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(Yb_Upload_Ftp, mkDirIfNotExists, arginfo_yb_upload_ftp_mkdirifnotexists, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

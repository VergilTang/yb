
extern zend_class_entry *yb_upload_uploadedfile_ce;

ZEPHIR_INIT_CLASS(Yb_Upload_UploadedFile);

PHP_METHOD(Yb_Upload_UploadedFile, __construct);
PHP_METHOD(Yb_Upload_UploadedFile, isValid);
PHP_METHOD(Yb_Upload_UploadedFile, save);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_upload_uploadedfile___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, uploader, Yb\\Upload\\Uploader, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_upload_uploadedfile_save, 0, 0, 0)
	ZEND_ARG_INFO(0, prefix)
	ZEND_ARG_INFO(0, keep)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_upload_uploadedfile_method_entry) {
	PHP_ME(Yb_Upload_UploadedFile, __construct, arginfo_yb_upload_uploadedfile___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_Upload_UploadedFile, isValid, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Upload_UploadedFile, save, arginfo_yb_upload_uploadedfile_save, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

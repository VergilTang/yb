
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#if PHP_VERSION_ID < 50500
#include <locale.h>
#endif

#include "php_ext.h"
#include "yb.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *yb_view_viewinterface_ce;
zend_class_entry *yb_factory_factoryinterface_ce;
zend_class_entry *yb_logger_loggerbackendinterface_ce;
zend_class_entry *yb_upload_urigeneratorinterface_ce;
zend_class_entry *yb_task_taskexecutorinterface_ce;
zend_class_entry *yb_exception_ce;
zend_class_entry *yb_db_dbabstract_ce;
zend_class_entry *yb_image_imageabstract_ce;
zend_class_entry *yb_logger_loggerabstract_ce;
zend_class_entry *yb_upload_storageabstract_ce;
zend_class_entry *yb_db_exception_ce;
zend_class_entry *yb_db_pdoabstract_ce;
zend_class_entry *yb_image_imagebackendabstract_ce;
zend_class_entry *yb_loader_loaderabstract_ce;
zend_class_entry *yb_task_taskmanagerabstract_ce;
zend_class_entry *yb_di_ce;
zend_class_entry *yb_factory_classnameabstract_ce;
zend_class_entry *yb_image_image_ce;
zend_class_entry *yb_application_ce;
zend_class_entry *yb_db_collection_ce;
zend_class_entry *yb_db_entity_ce;
zend_class_entry *yb_db_model_ce;
zend_class_entry *yb_db_oci8_ce;
zend_class_entry *yb_db_pdomysql_ce;
zend_class_entry *yb_db_pdopgsql_ce;
zend_class_entry *yb_db_queryexception_ce;
zend_class_entry *yb_db_transactionexception_ce;
zend_class_entry *yb_factory_exception_ce;
zend_class_entry *yb_factory_factories_ce;
zend_class_entry *yb_factory_namespaced_ce;
zend_class_entry *yb_factory_shared_ce;
zend_class_entry *yb_image_captcha_ce;
zend_class_entry *yb_image_exception_ce;
zend_class_entry *yb_image_gd_ce;
zend_class_entry *yb_image_imagick_ce;
zend_class_entry *yb_image_text_ce;
zend_class_entry *yb_loader_exception_ce;
zend_class_entry *yb_loader_namepath_ce;
zend_class_entry *yb_loader_namespacedirectory_ce;
zend_class_entry *yb_logger_backends_ce;
zend_class_entry *yb_logger_exception_ce;
zend_class_entry *yb_logger_file_ce;
zend_class_entry *yb_logger_nil_ce;
zend_class_entry *yb_std_ce;
zend_class_entry *yb_task_exception_ce;
zend_class_entry *yb_task_queueredis_ce;
zend_class_entry *yb_task_rundirectly_ce;
zend_class_entry *yb_upload_exception_ce;
zend_class_entry *yb_upload_fastdfs_ce;
zend_class_entry *yb_upload_filesystem_ce;
zend_class_entry *yb_upload_ftp_ce;
zend_class_entry *yb_upload_uploadedfile_ce;
zend_class_entry *yb_upload_uploader_ce;
zend_class_entry *yb_view_content_ce;
zend_class_entry *yb_view_exception_ce;
zend_class_entry *yb_view_facade_ce;
zend_class_entry *yb_view_httpresponse_ce;
zend_class_entry *yb_view_json_ce;
zend_class_entry *yb_view_nil_ce;
zend_class_entry *yb_view_readfile_ce;
zend_class_entry *yb_view_redirect_ce;
zend_class_entry *yb_view_tpl_ce;

ZEND_DECLARE_MODULE_GLOBALS(yb)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(yb)
{
#if PHP_VERSION_ID < 50500
	char* old_lc_all = setlocale(LC_ALL, NULL);
	if (old_lc_all) {
		size_t len = strlen(old_lc_all);
		char *tmp  = calloc(len+1, 1);
		if (UNEXPECTED(!tmp)) {
			return FAILURE;
		}

		memcpy(tmp, old_lc_all, len);
		old_lc_all = tmp;
	}

	setlocale(LC_ALL, "C");
#endif
	REGISTER_INI_ENTRIES();
	ZEPHIR_INIT(Yb_View_ViewInterface);
	ZEPHIR_INIT(Yb_Factory_FactoryInterface);
	ZEPHIR_INIT(Yb_Logger_LoggerBackendInterface);
	ZEPHIR_INIT(Yb_Upload_UriGeneratorInterface);
	ZEPHIR_INIT(Yb_Task_TaskExecutorInterface);
	ZEPHIR_INIT(Yb_Exception);
	ZEPHIR_INIT(Yb_Db_DbAbstract);
	ZEPHIR_INIT(Yb_Image_ImageAbstract);
	ZEPHIR_INIT(Yb_Logger_LoggerAbstract);
	ZEPHIR_INIT(Yb_Upload_StorageAbstract);
	ZEPHIR_INIT(Yb_Db_Exception);
	ZEPHIR_INIT(Yb_Db_PdoAbstract);
	ZEPHIR_INIT(Yb_Image_ImageBackendAbstract);
	ZEPHIR_INIT(Yb_Loader_LoaderAbstract);
	ZEPHIR_INIT(Yb_Task_TaskManagerAbstract);
	ZEPHIR_INIT(Yb_Di);
	ZEPHIR_INIT(Yb_Factory_ClassNameAbstract);
	ZEPHIR_INIT(Yb_Image_Image);
	ZEPHIR_INIT(Yb_Application);
	ZEPHIR_INIT(Yb_Db_Collection);
	ZEPHIR_INIT(Yb_Db_Entity);
	ZEPHIR_INIT(Yb_Db_Model);
	ZEPHIR_INIT(Yb_Db_Oci8);
	ZEPHIR_INIT(Yb_Db_PdoMysql);
	ZEPHIR_INIT(Yb_Db_PdoPgsql);
	ZEPHIR_INIT(Yb_Db_QueryException);
	ZEPHIR_INIT(Yb_Db_TransactionException);
	ZEPHIR_INIT(Yb_Factory_Exception);
	ZEPHIR_INIT(Yb_Factory_Factories);
	ZEPHIR_INIT(Yb_Factory_Namespaced);
	ZEPHIR_INIT(Yb_Factory_Shared);
	ZEPHIR_INIT(Yb_Image_Captcha);
	ZEPHIR_INIT(Yb_Image_Exception);
	ZEPHIR_INIT(Yb_Image_Gd);
	ZEPHIR_INIT(Yb_Image_Imagick);
	ZEPHIR_INIT(Yb_Image_Text);
	ZEPHIR_INIT(Yb_Loader_Exception);
	ZEPHIR_INIT(Yb_Loader_NamePath);
	ZEPHIR_INIT(Yb_Loader_NamespaceDirectory);
	ZEPHIR_INIT(Yb_Logger_Backends);
	ZEPHIR_INIT(Yb_Logger_Exception);
	ZEPHIR_INIT(Yb_Logger_File);
	ZEPHIR_INIT(Yb_Logger_Nil);
	ZEPHIR_INIT(Yb_Std);
	ZEPHIR_INIT(Yb_Task_Exception);
	ZEPHIR_INIT(Yb_Task_QueueRedis);
	ZEPHIR_INIT(Yb_Task_RunDirectly);
	ZEPHIR_INIT(Yb_Upload_Exception);
	ZEPHIR_INIT(Yb_Upload_Fastdfs);
	ZEPHIR_INIT(Yb_Upload_FileSystem);
	ZEPHIR_INIT(Yb_Upload_Ftp);
	ZEPHIR_INIT(Yb_Upload_UploadedFile);
	ZEPHIR_INIT(Yb_Upload_Uploader);
	ZEPHIR_INIT(Yb_View_Content);
	ZEPHIR_INIT(Yb_View_Exception);
	ZEPHIR_INIT(Yb_View_Facade);
	ZEPHIR_INIT(Yb_View_HttpResponse);
	ZEPHIR_INIT(Yb_View_Json);
	ZEPHIR_INIT(Yb_View_Nil);
	ZEPHIR_INIT(Yb_View_ReadFile);
	ZEPHIR_INIT(Yb_View_Redirect);
	ZEPHIR_INIT(Yb_View_Tpl);

#if PHP_VERSION_ID < 50500
	setlocale(LC_ALL, old_lc_all);
	free(old_lc_all);
#endif
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(yb)
{

	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_yb_globals *yb_globals TSRMLS_DC)
{
	yb_globals->initialized = 0;

	/* Memory options */
	yb_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	yb_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	yb_globals->cache_enabled = 1;

	/* Recursive Lock */
	yb_globals->recursive_lock = 0;

	/* Static cache */
	memset(yb_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);


}

static PHP_RINIT_FUNCTION(yb)
{

	zend_yb_globals *yb_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(yb_globals_ptr TSRMLS_CC);
	//zephir_init_interned_strings(TSRMLS_C);

	zephir_initialize_memory(yb_globals_ptr TSRMLS_CC);


	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(yb)
{

	

	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(yb)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_YB_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_YB_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_YB_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_YB_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_YB_ZEPVERSION);
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(yb)
{
	php_zephir_init_globals(yb_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(yb)
{

}


zend_function_entry php_yb_functions[] = {
ZEND_FE_END

};

zend_module_entry yb_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_YB_EXTNAME,
	php_yb_functions,
	PHP_MINIT(yb),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(yb),
#else
	NULL,
#endif
	PHP_RINIT(yb),
	PHP_RSHUTDOWN(yb),
	PHP_MINFO(yb),
	PHP_YB_VERSION,
	ZEND_MODULE_GLOBALS(yb),
	PHP_GINIT(yb),
	PHP_GSHUTDOWN(yb),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_YB
ZEND_GET_MODULE(yb)
#endif

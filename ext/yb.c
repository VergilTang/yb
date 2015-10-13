
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



zend_class_entry *yb_config_ce;
zend_class_entry *yb_exception_ce;

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
	ZEPHIR_INIT(Yb_Config);
	ZEPHIR_INIT(Yb_Exception);

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


/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_YB_H
#define PHP_YB_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_YB_NAME        "Yb Framework"
#define PHP_YB_VERSION     "1.2.151215"
#define PHP_YB_EXTNAME     "yb"
#define PHP_YB_AUTHOR      "Hylent"
#define PHP_YB_ZEPVERSION  "0.9.1a-dev"
#define PHP_YB_DESCRIPTION "~"



ZEND_BEGIN_MODULE_GLOBALS(yb)

	int initialized;

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	/* Global constants */
	zval *global_true;
	zval *global_false;
	zval *global_null;
	
ZEND_END_MODULE_GLOBALS(yb)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(yb)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(yb_globals_id, zend_yb_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (yb_globals.v)
#endif

#ifdef ZTS
	#define ZEPHIR_VGLOBAL ((zend_yb_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(yb_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(yb_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def yb_globals
#define zend_zephir_globals_def zend_yb_globals

extern zend_module_entry yb_module_entry;
#define phpext_yb_ptr &yb_module_entry

#endif

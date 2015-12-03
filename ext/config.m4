PHP_ARG_ENABLE(yb, whether to enable yb, [ --enable-yb   Enable Yb])

if test "$PHP_YB" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, YB_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_YB, 1, [Whether you have Yb])
	yb_sources="yb.c kernel/main.c kernel/memory.c kernel/exception.c kernel/hash.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/extended/array.c kernel/string.c kernel/fcall.c kernel/extended/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c yb/exception.zep.c
	yb/view/viewinterface.zep.c
	yb/db/dbabstract.zep.c
	yb/factory/factoryinterface.zep.c
	yb/upload/urigeneratorinterface.zep.c
	yb/image/imageabstract.zep.c
	yb/upload/storageabstract.zep.c
	yb/db/exception.zep.c
	yb/db/pdoabstract.zep.c
	yb/image/imagebackendabstract.zep.c
	yb/loader/loaderabstract.zep.c
	yb/logger/loggerabstract.zep.c
	yb/task/taskmanagerabstract.zep.c
	yb/di.zep.c
	yb/factory/classnameabstract.zep.c
	yb/image/image.zep.c
	yb/application.zep.c
	yb/db/collection.zep.c
	yb/db/entity.zep.c
	yb/db/model.zep.c
	yb/db/oci8.zep.c
	yb/db/pdomysql.zep.c
	yb/db/pdopgsql.zep.c
	yb/db/queryexception.zep.c
	yb/db/transactionexception.zep.c
	yb/factory/exception.zep.c
	yb/factory/factories.zep.c
	yb/factory/namespaced.zep.c
	yb/factory/shared.zep.c
	yb/image/captcha.zep.c
	yb/image/exception.zep.c
	yb/image/gd.zep.c
	yb/image/imagick.zep.c
	yb/image/text.zep.c
	yb/loader/exception.zep.c
	yb/loader/namepath.zep.c
	yb/loader/namespacedirectory.zep.c
	yb/logger/exception.zep.c
	yb/logger/filelogger.zep.c
	yb/logger/nulllogger.zep.c
	yb/std.zep.c
	yb/task/exception.zep.c
	yb/task/queueredis.zep.c
	yb/task/rundirectly.zep.c
	yb/task/taskexecutorinterface.zep.c
	yb/upload/exception.zep.c
	yb/upload/fastdfs.zep.c
	yb/upload/filesystem.zep.c
	yb/upload/ftp.zep.c
	yb/upload/uploadedfile.zep.c
	yb/upload/uploader.zep.c
	yb/view/content.zep.c
	yb/view/exception.zep.c
	yb/view/facade.zep.c
	yb/view/httpresponse.zep.c
	yb/view/json.zep.c
	yb/view/nil.zep.c
	yb/view/readfile.zep.c
	yb/view/redirect.zep.c
	yb/view/tpl.zep.c "
	PHP_NEW_EXTENSION(yb, $yb_sources, $ext_shared,, )
	PHP_SUBST(YB_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([yb], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([yb], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/yb], [php_YB.h])

fi

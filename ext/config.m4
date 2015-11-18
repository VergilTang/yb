PHP_ARG_ENABLE(yb, whether to enable yb, [ --enable-yb   Enable Yb])

if test "$PHP_YB" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, YB_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_YB, 1, [Whether you have Yb])
	yb_sources="yb.c kernel/main.c kernel/memory.c kernel/exception.c kernel/hash.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/extended/array.c kernel/string.c kernel/fcall.c kernel/extended/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c yb/exception.zep.c
	yb/collection/collectioninterface.zep.c
	yb/db/dbabstract.zep.c
	yb/sequence/sequenceinterface.zep.c
	yb/factory/factoryinterface.zep.c
	yb/image/imageabstract.zep.c
	yb/upload/storageabstract.zep.c
	yb/datacacher/datacacherinterface.zep.c
	yb/db/exception.zep.c
	yb/db/pdoabstract.zep.c
	yb/factory/classname.zep.c
	yb/image/imagebackendabstract.zep.c
	yb/loader/loaderabstract.zep.c
	yb/logger/loggerabstract.zep.c
	yb/rediscluster/error.zep.c
	yb/router/routerabstract.zep.c
	yb/collection/redishash.zep.c
	yb/image/image.zep.c
	yb/mailer/mailerinterface.zep.c
	yb/ratelimiter/ratelimiterinterface.zep.c
	yb/rediscluster/exception.zep.c
	yb/router/exception.zep.c
	yb/router/uri.zep.c
	yb/application.zep.c
	yb/collection/exception.zep.c
	yb/collection/mongocollection.zep.c
	yb/collection/proxy.zep.c
	yb/collection/redishashserialized.zep.c
	yb/datacacher/apc.zep.c
	yb/datacacher/exception.zep.c
	yb/datacacher/file.zep.c
	yb/db/oci8.zep.c
	yb/db/pdomysql.zep.c
	yb/db/pdopgsql.zep.c
	yb/db/queryexception.zep.c
	yb/db/transactionexception.zep.c
	yb/factory/exception.zep.c
	yb/factory/generated.zep.c
	yb/factory/namespaced.zep.c
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
	yb/mailer/exception.zep.c
	yb/mailer/smtp.zep.c
	yb/ratelimiter/exception.zep.c
	yb/ratelimiter/redis.zep.c
	yb/rediscluster/client.zep.c
	yb/rediscluster/connection.zep.c
	yb/rediscluster/errorask.zep.c
	yb/rediscluster/errormoved.zep.c
	yb/rediscluster/socketexception.zep.c
	yb/router/notfoundexception.zep.c
	yb/router/uripatterns.zep.c
	yb/sequence/dbpdomysql.zep.c
	yb/sequence/exception.zep.c
	yb/sequence/mongocollection.zep.c
	yb/sequence/redis.zep.c
	yb/sequence/redishash.zep.c
	yb/std.zep.c
	yb/upload/exception.zep.c
	yb/upload/fastdfs.zep.c
	yb/upload/filesystem.zep.c
	yb/upload/ftp.zep.c
	yb/upload/uploadedfile.zep.c
	yb/upload/uploader.zep.c utils.c"
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

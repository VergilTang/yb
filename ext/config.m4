PHP_ARG_ENABLE(yb, whether to enable yb, [ --enable-yb   Enable Yb])

if test "$PHP_YB" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, YB_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_YB, 1, [Whether you have Yb])
	yb_sources="yb.c kernel/main.c kernel/memory.c kernel/exception.c kernel/hash.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/extended/array.c kernel/string.c kernel/fcall.c kernel/extended/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c yb/exception.zep.c
	yb/image/imageabstract.zep.c
	yb/serializer/serializerinterface.zep.c
	yb/image/imagebackendabstract.zep.c
	yb/loader/loaderabstract.zep.c
	yb/application/applicationfilterinterface.zep.c
	yb/image/image.zep.c
	yb/router/routerabstract.zep.c
	yb/application/core.zep.c
	yb/application/exception.zep.c
	yb/application/modulerouter.zep.c
	yb/config.zep.c
	yb/image/captcha.zep.c
	yb/image/exception.zep.c
	yb/image/gd.zep.c
	yb/image/imagick.zep.c
	yb/image/text.zep.c
	yb/loader/classpath.zep.c
	yb/loader/exception.zep.c
	yb/loader/namespacedirectory.zep.c
	yb/router/uri.zep.c
	yb/serializer/exception.zep.c
	yb/serializer/igbinary.zep.c
	yb/serializer/json.zep.c
	yb/serializer/php.zep.c
	yb/std.zep.c
	yb/tools/exception.zep.c
	yb/tools/smtpmailer.zep.c "
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

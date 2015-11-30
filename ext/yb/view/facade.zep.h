
extern zend_class_entry *yb_view_facade_ce;

ZEPHIR_INIT_CLASS(Yb_View_Facade);

PHP_METHOD(Yb_View_Facade, __construct);
PHP_METHOD(Yb_View_Facade, content);
PHP_METHOD(Yb_View_Facade, httpResponse);
PHP_METHOD(Yb_View_Facade, json);
PHP_METHOD(Yb_View_Facade, nil);
PHP_METHOD(Yb_View_Facade, readFile);
PHP_METHOD(Yb_View_Facade, redirect);
PHP_METHOD(Yb_View_Facade, tpl);
PHP_METHOD(Yb_View_Facade, setView);
PHP_METHOD(Yb_View_Facade, getView);
PHP_METHOD(Yb_View_Facade, __invoke);
PHP_METHOD(Yb_View_Facade, setOptions);
PHP_METHOD(Yb_View_Facade, __set);
PHP_METHOD(Yb_View_Facade, __get);
PHP_METHOD(Yb_View_Facade, __isset);
PHP_METHOD(Yb_View_Facade, __unset);
PHP_METHOD(Yb_View_Facade, setData);
PHP_METHOD(Yb_View_Facade, offsetSet);
PHP_METHOD(Yb_View_Facade, offsetGet);
PHP_METHOD(Yb_View_Facade, offsetExists);
PHP_METHOD(Yb_View_Facade, offsetUnset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_view_facade___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 1)
	ZEND_ARG_INFO(0, view)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_view_facade_content, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, contentType)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_view_facade_httpresponse, 0, 0, 1)
	ZEND_ARG_INFO(0, httpResponseCode)
	ZEND_ARG_INFO(0, httpResponseOutput)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_view_facade_json, 0, 0, 0)
	ZEND_ARG_INFO(0, jsonCallback)
	ZEND_ARG_INFO(0, jsonCors)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_view_facade_readfile, 0, 0, 1)
	ZEND_ARG_INFO(0, readFile)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_view_facade_redirect, 0, 0, 1)
	ZEND_ARG_INFO(0, redirectUrl)
	ZEND_ARG_INFO(0, redirectDataAsQueries)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_view_facade_tpl, 0, 0, 1)
	ZEND_ARG_INFO(0, tplId)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_view_facade_setview, 0, 0, 1)
	ZEND_ARG_INFO(0, view)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_view_facade_setoptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_view_facade___set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_view_facade___get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_view_facade___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_view_facade___unset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_view_facade_setdata, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_view_facade_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_view_facade_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_view_facade_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_view_facade_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_view_facade_method_entry) {
	PHP_ME(Yb_View_Facade, __construct, arginfo_yb_view_facade___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_View_Facade, content, arginfo_yb_view_facade_content, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_View_Facade, httpResponse, arginfo_yb_view_facade_httpresponse, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_View_Facade, json, arginfo_yb_view_facade_json, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_View_Facade, nil, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_View_Facade, readFile, arginfo_yb_view_facade_readfile, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_View_Facade, redirect, arginfo_yb_view_facade_redirect, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_View_Facade, tpl, arginfo_yb_view_facade_tpl, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_View_Facade, setView, arginfo_yb_view_facade_setview, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_View_Facade, getView, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_View_Facade, __invoke, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_View_Facade, setOptions, arginfo_yb_view_facade_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_View_Facade, __set, arginfo_yb_view_facade___set, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_View_Facade, __get, arginfo_yb_view_facade___get, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_View_Facade, __isset, arginfo_yb_view_facade___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_View_Facade, __unset, arginfo_yb_view_facade___unset, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_View_Facade, setData, arginfo_yb_view_facade_setdata, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_View_Facade, offsetSet, arginfo_yb_view_facade_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_View_Facade, offsetGet, arginfo_yb_view_facade_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_View_Facade, offsetExists, arginfo_yb_view_facade_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_View_Facade, offsetUnset, arginfo_yb_view_facade_offsetunset, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

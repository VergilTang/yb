
extern zend_class_entry *yb_tools_smtpmailer_ce;

ZEPHIR_INIT_CLASS(Yb_Tools_SmtpMailer);

PHP_METHOD(Yb_Tools_SmtpMailer, __construct);
PHP_METHOD(Yb_Tools_SmtpMailer, sendTo);
PHP_METHOD(Yb_Tools_SmtpMailer, __destruct);
PHP_METHOD(Yb_Tools_SmtpMailer, cmd);
PHP_METHOD(Yb_Tools_SmtpMailer, pack);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_tools_smtpmailer___construct, 0, 0, 3)
	ZEND_ARG_INFO(0, host)
	ZEND_ARG_INFO(0, user)
	ZEND_ARG_INFO(0, passwd)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_tools_smtpmailer_sendto, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, message, 0)
	ZEND_ARG_ARRAY_INFO(0, to, 0)
	ZEND_ARG_ARRAY_INFO(0, cc, 1)
	ZEND_ARG_ARRAY_INFO(0, bcc, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_tools_smtpmailer_cmd, 0, 0, 3)
	ZEND_ARG_INFO(0, step)
	ZEND_ARG_INFO(0, cmd)
	ZEND_ARG_INFO(0, expected)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_tools_smtpmailer_pack, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, addr)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_tools_smtpmailer_method_entry) {
	PHP_ME(Yb_Tools_SmtpMailer, __construct, arginfo_yb_tools_smtpmailer___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Yb_Tools_SmtpMailer, sendTo, arginfo_yb_tools_smtpmailer_sendto, ZEND_ACC_PUBLIC)
	PHP_ME(Yb_Tools_SmtpMailer, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(Yb_Tools_SmtpMailer, cmd, arginfo_yb_tools_smtpmailer_cmd, ZEND_ACC_PROTECTED)
	PHP_ME(Yb_Tools_SmtpMailer, pack, arginfo_yb_tools_smtpmailer_pack, ZEND_ACC_PROTECTED)
	PHP_FE_END
};

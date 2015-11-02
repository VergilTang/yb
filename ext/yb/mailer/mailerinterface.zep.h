
extern zend_class_entry *yb_mailer_mailerinterface_ce;

ZEPHIR_INIT_CLASS(Yb_Mailer_MailerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_yb_mailer_mailerinterface_sendmessageto, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, message, 0)
	ZEND_ARG_ARRAY_INFO(0, to, 0)
	ZEND_ARG_ARRAY_INFO(0, cc, 1)
	ZEND_ARG_ARRAY_INFO(0, bcc, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(yb_mailer_mailerinterface_method_entry) {
	PHP_ABSTRACT_ME(Yb_Mailer_MailerInterface, sendMessageTo, arginfo_yb_mailer_mailerinterface_sendmessageto)
	PHP_FE_END
};

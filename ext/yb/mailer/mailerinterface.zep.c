
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Yb_Mailer_MailerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Yb\\Mailer, MailerInterface, yb, mailer_mailerinterface, yb_mailer_mailerinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Yb_Mailer_MailerInterface, sendMessageTo);


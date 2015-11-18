
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/string.h"
#include "kernel/file.h"


ZEPHIR_INIT_CLASS(Yb_Mailer_Smtp) {

	ZEPHIR_REGISTER_CLASS(Yb\\Mailer, Smtp, yb, mailer_smtp, yb_mailer_smtp_method_entry, 0);

	zend_declare_property_null(yb_mailer_smtp_ce, SL("socket"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_mailer_smtp_ce, SL("from"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(yb_mailer_smtp_ce, SL("CRLF"), "\r\n" TSRMLS_CC);

	zend_class_implements(yb_mailer_smtp_ce TSRMLS_CC, 1, yb_mailer_mailerinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Yb_Mailer_Smtp, __construct) {

	zend_bool secure = 0, _26, _34;
	double ioTimeout = 0;
	long timeout = 0, port = 0, ioTimeoutSeconds = 0, ioTimeoutMicroSeconds = 0;
	zval *host = NULL, *user = NULL, *passwd = NULL, *from = NULL, *name = NULL, *_3 = NULL, *_5 = NULL, *_7 = NULL, *_9 = NULL, *_12 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_39 = NULL, *_41 = NULL;
	zval *options_param = NULL, *socket = NULL, *errStr = NULL, *_0 = NULL, *_2 = NULL, *_4 = NULL, *_6 = NULL, *_8 = NULL, *_10 = NULL, *_11 = NULL, *_13 = NULL, *_14 = NULL, *_15 = NULL, _22 = zval_used_for_init, _23 = zval_used_for_init, *_27 = NULL, _28, *_29 = NULL, *_30 = NULL, *_35 = NULL, *_36 = NULL, *_37 = NULL, *_38 = NULL, *_40 = NULL, *_42 = NULL, *_16$$3 = NULL, *_17$$3, *_18$$3, *_19$$4 = NULL, *_20$$4, *_21$$4, *_24$$5, *_25$$5, _31$$8, _32$$8, *_33$$8 = NULL;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	zephir_get_arrval(options, options_param);


	ZEPHIR_INIT_VAR(errStr);
	ZVAL_NULL(errStr);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "host", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_0, yb_std_ce, "valueat", &_1, 9, options, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_get_strval(_3, _0);
	ZEPHIR_CPY_WRT(host, _3);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "user", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_4, yb_std_ce, "valueat", &_1, 9, options, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_get_strval(_5, _4);
	ZEPHIR_CPY_WRT(user, _5);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "passwd", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_6, yb_std_ce, "valueat", &_1, 9, options, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_get_strval(_7, _6);
	ZEPHIR_CPY_WRT(passwd, _7);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "from", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_8, yb_std_ce, "valueat", &_1, 9, options, _2, user);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	zephir_get_strval(_9, _8);
	ZEPHIR_CPY_WRT(from, _9);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "name", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_11);
	ZVAL_STRING(_11, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_CE_STATIC(&_10, yb_std_ce, "valueat", &_1, 9, options, _2, _11);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_11);
	zephir_check_call_status();
	zephir_get_strval(_12, _10);
	ZEPHIR_CPY_WRT(name, _12);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "timeout", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_LONG(_11, 10);
	ZEPHIR_CALL_CE_STATIC(&_13, yb_std_ce, "valueat", &_1, 9, options, _2, _11);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	timeout = zephir_get_intval(_13);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "ioTimeout", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_LONG(_11, timeout);
	ZEPHIR_CALL_CE_STATIC(&_14, yb_std_ce, "valueat", &_1, 9, options, _2, _11);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ioTimeout = zephir_get_doubleval(_14);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "secure", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_BOOL(_11, 0);
	ZEPHIR_CALL_CE_STATIC(&_15, yb_std_ce, "valueat", &_1, 9, options, _2, _11);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	secure = zephir_get_boolval(_15);
	if (secure) {
		ZEPHIR_INIT_VAR(_17$$3);
		ZVAL_STRING(_17$$3, "port", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_18$$3);
		ZVAL_LONG(_18$$3, 465);
		ZEPHIR_CALL_CE_STATIC(&_16$$3, yb_std_ce, "valueat", &_1, 9, options, _17$$3, _18$$3);
		zephir_check_temp_parameter(_17$$3);
		zephir_check_call_status();
		port = zephir_get_intval(_16$$3);
	} else {
		ZEPHIR_INIT_VAR(_20$$4);
		ZVAL_STRING(_20$$4, "port", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_21$$4);
		ZVAL_LONG(_21$$4, 25);
		ZEPHIR_CALL_CE_STATIC(&_19$$4, yb_std_ce, "valueat", &_1, 9, options, _20$$4, _21$$4);
		zephir_check_temp_parameter(_20$$4);
		zephir_check_call_status();
		port = zephir_get_intval(_19$$4);
	}
	ZEPHIR_SINIT_VAR(_22);
	ZVAL_STRING(&_22, "tcp://%s:%d", 0);
	ZEPHIR_SINIT_VAR(_23);
	ZVAL_LONG(&_23, port);
	ZEPHIR_CALL_FUNCTION(&_15, "sprintf", NULL, 1, &_22, host, &_23);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_NULL(_2);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_LONG(_11, timeout);
	ZEPHIR_MAKE_REF(_2);
	ZEPHIR_CALL_FUNCTION(&socket, "stream_socket_client", NULL, 82, _15, _2, errStr, _11);
	ZEPHIR_UNREF(_2);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(socket))) {
		ZEPHIR_INIT_VAR(_24$$5);
		object_init_ex(_24$$5, yb_mailer_exception_ce);
		ZEPHIR_INIT_VAR(_25$$5);
		ZEPHIR_CONCAT_SV(_25$$5, "Cannot connect to mail server: ", errStr);
		ZEPHIR_CALL_METHOD(NULL, _24$$5, "__construct", NULL, 2, _25$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_24$$5, "yb/mailer/smtp.zep", 38 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_26 = (zephir_function_exists_ex(SS("socket_import_stream") TSRMLS_CC) == SUCCESS);
	if (_26) {
		ZEPHIR_CALL_FUNCTION(&_27, "socket_import_stream", NULL, 83, socket);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_22);
		ZVAL_LONG(&_22, 6);
		ZEPHIR_SINIT_NVAR(_23);
		ZVAL_LONG(&_23, 1);
		ZEPHIR_SINIT_VAR(_28);
		ZVAL_LONG(&_28, 1);
		ZEPHIR_CALL_FUNCTION(&_29, "socket_set_option", NULL, 84, _27, &_22, &_23, &_28);
		zephir_check_call_status();
		_26 = !zephir_is_true(_29);
	}
	if (unlikely(_26)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_mailer_exception_ce, "Cannot set tcp_nodelay", "yb/mailer/smtp.zep", 43);
		return;
	}
	ZEPHIR_SINIT_NVAR(_22);
	ZVAL_LONG(&_22, 1);
	ZEPHIR_CALL_FUNCTION(&_30, "stream_set_blocking", NULL, 85, socket, &_22);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_30))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_mailer_exception_ce, "Cannot set blocking socket", "yb/mailer/smtp.zep", 47);
		return;
	}
	if (ioTimeout > 0) {
		ioTimeoutSeconds = (long) (ioTimeout);
		ioTimeoutMicroSeconds = (long) ((((ioTimeout -  (double) ioTimeoutSeconds)) * 1000000.0));
		ZEPHIR_SINIT_VAR(_31$$8);
		ZVAL_LONG(&_31$$8, ioTimeoutSeconds);
		ZEPHIR_SINIT_VAR(_32$$8);
		ZVAL_LONG(&_32$$8, ioTimeoutMicroSeconds);
		ZEPHIR_CALL_FUNCTION(&_33$$8, "stream_set_timeout", NULL, 86, socket, &_31$$8, &_32$$8);
		zephir_check_call_status();
		if (unlikely(!zephir_is_true(_33$$8))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_mailer_exception_ce, "Cannot set io timeout", "yb/mailer/smtp.zep", 55);
			return;
		}
	}
	_34 = secure;
	if (_34) {
		ZEPHIR_SINIT_NVAR(_22);
		ZVAL_STRING(&_22, "STREAM_CRYPTO_METHOD_SSLv23_CLIENT", 0);
		ZEPHIR_CALL_FUNCTION(&_35, "constant", NULL, 87, &_22);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_36, "stream_socket_enable_crypto", NULL, 88, socket, ZEPHIR_GLOBAL(global_true), _35);
		zephir_check_call_status();
		_34 = !zephir_is_true(_36);
	}
	if (unlikely(_34)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_mailer_exception_ce, "Cannot enable crypto socket", "yb/mailer/smtp.zep", 61);
		return;
	}
	zephir_update_property_this(this_ptr, SL("socket"), socket TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_37, this_ptr, "pack", NULL, 0, name, from);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("from"), _37 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "CONNECT", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_STRING(_11, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_38);
	ZVAL_LONG(_38, 220);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", &_39, 0, _2, _11, _38);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_11);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "EHLO HELO", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_STRING(_11, "EHLO HELO", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_38);
	ZVAL_LONG(_38, 250);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", &_39, 0, _2, _11, _38);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_11);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "AUTH LOGIN", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_STRING(_11, "AUTH LOGIN", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_38);
	ZVAL_LONG(_38, 334);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", &_39, 0, _2, _11, _38);
	zephir_check_temp_parameter(_2);
	zephir_check_temp_parameter(_11);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_40, "base64_encode", &_41, 89, user);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "AUTH USER", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_LONG(_11, 334);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", &_39, 0, _2, _40, _11);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_42, "base64_encode", &_41, 89, passwd);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "AUTH PASSWD", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_11);
	ZVAL_LONG(_11, 235);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", &_39, 0, _2, _42, _11);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Mailer_Smtp, sendMessageTo) {

	zend_bool _39, _40, _49;
	HashTable *_8, *_17$$5, *_26$$7, *_60$$14;
	HashPosition _7, _16$$5, _25$$7, _59$$14;
	zval *boundary = NULL, *_45 = NULL, *_46, *_47;
	zephir_fcall_cache_entry *_4 = NULL, *_11 = NULL, *_54 = NULL, *_56 = NULL, *_64 = NULL, *_65 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *to_param = NULL, *cc_param = NULL, *bcc_param = NULL, *data = NULL, *temp = NULL, *addr = NULL, *name = NULL, *attachments = NULL, *path = NULL, *mine = NULL, *type = NULL, *subject = NULL, *plain = NULL, *_0, *_1, *_2 = NULL, *_3 = NULL, *_5, *_6, **_9, *_15, _36 = zval_used_for_init, *_37 = NULL, *_38, *_43 = NULL, *_44 = NULL, *_48 = NULL, *_52, *_53 = NULL, *_55 = NULL, *_57, *_75 = NULL, *_76 = NULL, *_10$$4 = NULL, *_12$$4 = NULL, *_13$$4 = NULL, *_14$$4 = NULL, **_18$$5, *_23$$5, *_24$$5, *_19$$6 = NULL, *_20$$6 = NULL, *_21$$6 = NULL, *_22$$6 = NULL, **_27$$7, *_32$$7, *_33$$7, *_28$$8 = NULL, *_29$$8 = NULL, *_30$$8 = NULL, *_31$$8 = NULL, *_34$$9 = NULL, *_35$$9, *_41$$10, *_42$$11, *_50$$12, *_51$$13, _58$$14, **_61$$14, *_62$$16 = NULL, *_63$$16 = NULL, *_66$$17 = NULL, *_67$$18 = NULL, *_68$$15 = NULL, *_69$$15 = NULL, *_70$$15 = NULL, *_71$$15 = NULL, *_72$$15 = NULL, *_73$$15 = NULL, *_74$$15 = NULL;
	zval *message = NULL, *to = NULL, *cc = NULL, *bcc = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &message_param, &to_param, &cc_param, &bcc_param);

	zephir_get_arrval(message, message_param);
	zephir_get_arrval(to, to_param);
	if (!cc_param) {
		ZEPHIR_INIT_VAR(cc);
		array_init(cc);
	} else {
		zephir_get_arrval(cc, cc_param);
	}
	if (!bcc_param) {
		ZEPHIR_INIT_VAR(bcc);
		array_init(bcc);
	} else {
		zephir_get_arrval(bcc, bcc_param);
	}


	ZEPHIR_INIT_VAR(data);
	array_init(data);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("from"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SV(_1, "MAIL FROM: ", _0);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "MAIL FROM", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 250);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", &_4, 0, _2, _1, _3);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("from"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_CONCAT_SV(_6, "FROM: ", _5);
	zephir_array_append(&data, _6, PH_SEPARATE, "yb/mailer/smtp.zep", 80);
	if (zephir_fast_count_int(to TSRMLS_CC) < 1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_mailer_exception_ce, "No one to send", "yb/mailer/smtp.zep", 83);
		return;
	}
	ZEPHIR_INIT_VAR(temp);
	array_init(temp);
	zephir_is_iterable(to, &_8, &_7, 0, 0, "yb/mailer/smtp.zep", 92);
	for (
	  ; zephir_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
	  ; zephir_hash_move_forward_ex(_8, &_7)
	) {
		ZEPHIR_GET_HMKEY(addr, _8, _7);
		ZEPHIR_GET_HVALUE(name, _9);
		ZEPHIR_CALL_METHOD(&_10$$4, this_ptr, "pack", &_11, 0, name, addr);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(name, _10$$4);
		zephir_array_append(&temp, name, PH_SEPARATE, "yb/mailer/smtp.zep", 89);
		ZEPHIR_INIT_LNVAR(_12$$4);
		ZEPHIR_CONCAT_SV(_12$$4, "RCPT TO: ", name);
		ZEPHIR_INIT_NVAR(_13$$4);
		ZVAL_STRING(_13$$4, "RCPT TO", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_NVAR(_14$$4);
		ZVAL_LONG(_14$$4, 250);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", &_4, 0, _13$$4, _12$$4, _14$$4);
		zephir_check_temp_parameter(_13$$4);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_2);
	zephir_fast_join_str(_2, SL(","), temp TSRMLS_CC);
	ZEPHIR_INIT_VAR(_15);
	ZEPHIR_CONCAT_SV(_15, "TO: ", _2);
	zephir_array_append(&data, _15, PH_SEPARATE, "yb/mailer/smtp.zep", 92);
	if (zephir_fast_count_int(cc TSRMLS_CC) > 0) {
		ZEPHIR_INIT_NVAR(temp);
		array_init(temp);
		zephir_is_iterable(cc, &_17$$5, &_16$$5, 0, 0, "yb/mailer/smtp.zep", 101);
		for (
		  ; zephir_hash_get_current_data_ex(_17$$5, (void**) &_18$$5, &_16$$5) == SUCCESS
		  ; zephir_hash_move_forward_ex(_17$$5, &_16$$5)
		) {
			ZEPHIR_GET_HMKEY(addr, _17$$5, _16$$5);
			ZEPHIR_GET_HVALUE(name, _18$$5);
			ZEPHIR_CALL_METHOD(&_19$$6, this_ptr, "pack", &_11, 0, name, addr);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(name, _19$$6);
			zephir_array_append(&temp, name, PH_SEPARATE, "yb/mailer/smtp.zep", 98);
			ZEPHIR_INIT_LNVAR(_20$$6);
			ZEPHIR_CONCAT_SV(_20$$6, "RCPT TO: ", name);
			ZEPHIR_INIT_NVAR(_21$$6);
			ZVAL_STRING(_21$$6, "RCPT TO", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_22$$6);
			ZVAL_LONG(_22$$6, 250);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", &_4, 0, _21$$6, _20$$6, _22$$6);
			zephir_check_temp_parameter(_21$$6);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_VAR(_23$$5);
		zephir_fast_join_str(_23$$5, SL(","), temp TSRMLS_CC);
		ZEPHIR_INIT_VAR(_24$$5);
		ZEPHIR_CONCAT_SV(_24$$5, "CC: ", _23$$5);
		zephir_array_append(&data, _24$$5, PH_SEPARATE, "yb/mailer/smtp.zep", 101);
	}
	if (zephir_fast_count_int(bcc TSRMLS_CC) > 0) {
		ZEPHIR_INIT_NVAR(temp);
		array_init(temp);
		zephir_is_iterable(bcc, &_26$$7, &_25$$7, 0, 0, "yb/mailer/smtp.zep", 110);
		for (
		  ; zephir_hash_get_current_data_ex(_26$$7, (void**) &_27$$7, &_25$$7) == SUCCESS
		  ; zephir_hash_move_forward_ex(_26$$7, &_25$$7)
		) {
			ZEPHIR_GET_HMKEY(addr, _26$$7, _25$$7);
			ZEPHIR_GET_HVALUE(name, _27$$7);
			ZEPHIR_CALL_METHOD(&_28$$8, this_ptr, "pack", &_11, 0, name, addr);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(name, _28$$8);
			zephir_array_append(&temp, name, PH_SEPARATE, "yb/mailer/smtp.zep", 107);
			ZEPHIR_INIT_LNVAR(_29$$8);
			ZEPHIR_CONCAT_SV(_29$$8, "RCPT TO: ", name);
			ZEPHIR_INIT_NVAR(_30$$8);
			ZVAL_STRING(_30$$8, "RCPT TO", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_31$$8);
			ZVAL_LONG(_31$$8, 250);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", &_4, 0, _30$$8, _29$$8, _31$$8);
			zephir_check_temp_parameter(_30$$8);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_VAR(_32$$7);
		zephir_fast_join_str(_32$$7, SL(","), temp TSRMLS_CC);
		ZEPHIR_INIT_VAR(_33$$7);
		ZEPHIR_CONCAT_SV(_33$$7, "BCC: ", _32$$7);
		zephir_array_append(&data, _33$$7, PH_SEPARATE, "yb/mailer/smtp.zep", 110);
	}
	ZEPHIR_OBS_VAR(subject);
	if (zephir_array_isset_string_fetch(&subject, message, SS("subject"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_34$$9, this_ptr, "pack", &_11, 0, subject);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_35$$9);
		ZEPHIR_CONCAT_SV(_35$$9, "Subject: ", _34$$9);
		zephir_array_append(&data, _35$$9, PH_SEPARATE, "yb/mailer/smtp.zep", 114);
	}
	ZEPHIR_SINIT_VAR(_36);
	ZVAL_STRING(&_36, "r", 0);
	ZEPHIR_CALL_FUNCTION(&_37, "gmdate", NULL, 90, &_36);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_38);
	ZEPHIR_CONCAT_SV(_38, "Date: ", _37);
	zephir_array_append(&data, _38, PH_SEPARATE, "yb/mailer/smtp.zep", 117);
	ZEPHIR_OBS_VAR(attachments);
	_39 = zephir_array_isset_string_fetch(&attachments, message, SS("attachments"), 0 TSRMLS_CC);
	if (_39) {
		_39 = Z_TYPE_P(attachments) == IS_ARRAY;
	}
	_40 = _39;
	if (_40) {
		_40 = zephir_fast_count_int(attachments TSRMLS_CC) > 0;
	}
	if (_40) {
		ZEPHIR_INIT_VAR(_41$$10);
		ZVAL_STRING(_41$$10, "Content-Type: multipart/mixed;", 1);
		zephir_array_append(&data, _41$$10, PH_SEPARATE, "yb/mailer/smtp.zep", 120);
	} else {
		ZEPHIR_INIT_NVAR(attachments);
		array_init(attachments);
		ZEPHIR_INIT_VAR(_42$$11);
		ZVAL_STRING(_42$$11, "Content-Type: multipart/alternative;", 1);
		zephir_array_append(&data, _42$$11, PH_SEPARATE, "yb/mailer/smtp.zep", 123);
	}
	ZEPHIR_INIT_NVAR(_3);
	ZEPHIR_CALL_FUNCTION(&_43, "mt_rand", NULL, 91);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_44, "uniqid", NULL, 92, _43, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	zephir_md5(_3, _44);
	zephir_get_strval(_45, _3);
	ZEPHIR_INIT_VAR(boundary);
	ZEPHIR_CONCAT_SV(boundary, "Boundary-", _45);
	ZEPHIR_INIT_VAR(_46);
	ZEPHIR_CONCAT_SVS(_46, "\tboundary=\"", boundary, "\"");
	zephir_array_append(&data, _46, PH_SEPARATE, "yb/mailer/smtp.zep", 127);
	ZEPHIR_INIT_VAR(_47);
	ZEPHIR_CONCAT_SV(_47, "--", boundary);
	ZEPHIR_CPY_WRT(boundary, _47);
	ZEPHIR_INIT_VAR(_48);
	ZVAL_STRING(_48, "MIME-Version: 1.0", 1);
	zephir_array_append(&data, _48, PH_SEPARATE, "yb/mailer/smtp.zep", 130);
	ZEPHIR_INIT_NVAR(_48);
	ZVAL_STRING(_48, "", 1);
	zephir_array_append(&data, _48, PH_SEPARATE, "yb/mailer/smtp.zep", 131);
	zephir_array_append(&data, boundary, PH_SEPARATE, "yb/mailer/smtp.zep", 133);
	ZEPHIR_OBS_VAR(plain);
	_49 = zephir_array_isset_string_fetch(&plain, message, SS("plain"), 0 TSRMLS_CC);
	if (_49) {
		_49 = zephir_is_true(plain);
	}
	if (_49) {
		ZEPHIR_INIT_VAR(_50$$12);
		ZVAL_STRING(_50$$12, "Content-Type: text/plain; charset=UTF-8", 1);
		zephir_array_append(&data, _50$$12, PH_SEPARATE, "yb/mailer/smtp.zep", 135);
	} else {
		ZEPHIR_INIT_VAR(_51$$13);
		ZVAL_STRING(_51$$13, "Content-Type: text/html; charset=UTF-8", 1);
		zephir_array_append(&data, _51$$13, PH_SEPARATE, "yb/mailer/smtp.zep", 137);
	}
	ZEPHIR_INIT_NVAR(_48);
	ZVAL_STRING(_48, "Content-Transfer-Encoding: base64", 1);
	zephir_array_append(&data, _48, PH_SEPARATE, "yb/mailer/smtp.zep", 139);
	ZEPHIR_INIT_NVAR(_48);
	ZVAL_STRING(_48, "", 1);
	zephir_array_append(&data, _48, PH_SEPARATE, "yb/mailer/smtp.zep", 140);
	zephir_array_fetch_string(&_52, message, SL("body"), PH_NOISY | PH_READONLY, "yb/mailer/smtp.zep", 141 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_53, "base64_encode", &_54, 89, _52);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_55, "chunk_split", &_56, 93, _53);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_57);
	ZEPHIR_CONCAT_VV(_57, _55, boundary);
	zephir_array_append(&data, _57, PH_SEPARATE, "yb/mailer/smtp.zep", 141);
	if (zephir_is_true(attachments)) {
		ZEPHIR_SINIT_VAR(_58$$14);
		ZVAL_LONG(&_58$$14, 16);
		ZEPHIR_CALL_FUNCTION(&mine, "finfo_open", NULL, 94, &_58$$14);
		zephir_check_call_status();
		zephir_is_iterable(attachments, &_60$$14, &_59$$14, 0, 0, "yb/mailer/smtp.zep", 163);
		for (
		  ; zephir_hash_get_current_data_ex(_60$$14, (void**) &_61$$14, &_59$$14) == SUCCESS
		  ; zephir_hash_move_forward_ex(_60$$14, &_59$$14)
		) {
			ZEPHIR_GET_HVALUE(path, _61$$14);
			if (unlikely(!((zephir_file_exists(path TSRMLS_CC) == SUCCESS)))) {
				ZEPHIR_INIT_NVAR(_62$$16);
				object_init_ex(_62$$16, yb_mailer_exception_ce);
				ZEPHIR_INIT_LNVAR(_63$$16);
				ZEPHIR_CONCAT_SV(_63$$16, "Cannot find attachment: ", path);
				ZEPHIR_CALL_METHOD(NULL, _62$$16, "__construct", &_64, 2, _63$$16);
				zephir_check_call_status();
				zephir_throw_exception_debug(_62$$16, "yb/mailer/smtp.zep", 147 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_FUNCTION(&type, "finfo_file", &_65, 95, mine, path);
			zephir_check_call_status();
			if (zephir_is_true(type)) {
				ZEPHIR_INIT_LNVAR(_66$$17);
				ZEPHIR_CONCAT_SV(_66$$17, "Content-Type: ", type);
				zephir_array_append(&data, _66$$17, PH_SEPARATE, "yb/mailer/smtp.zep", 152);
			} else {
				ZEPHIR_INIT_NVAR(_67$$18);
				ZVAL_STRING(_67$$18, "Content-Type: application/octet-stream", 1);
				zephir_array_append(&data, _67$$18, PH_SEPARATE, "yb/mailer/smtp.zep", 154);
			}
			ZEPHIR_INIT_NVAR(_68$$15);
			ZVAL_STRING(_68$$15, "Content-Transfer-Encoding: base64", 1);
			zephir_array_append(&data, _68$$15, PH_SEPARATE, "yb/mailer/smtp.zep", 157);
			ZEPHIR_INIT_NVAR(_68$$15);
			zephir_basename(_68$$15, path TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_69$$15, this_ptr, "pack", &_11, 0, _68$$15);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_70$$15);
			ZEPHIR_CONCAT_SVS(_70$$15, "Content-Disposition: attachment; filename=\"", _69$$15, "\"");
			zephir_array_append(&data, _70$$15, PH_SEPARATE, "yb/mailer/smtp.zep", 158);
			ZEPHIR_INIT_NVAR(_71$$15);
			ZVAL_STRING(_71$$15, "", 1);
			zephir_array_append(&data, _71$$15, PH_SEPARATE, "yb/mailer/smtp.zep", 159);
			ZEPHIR_INIT_NVAR(_71$$15);
			zephir_file_get_contents(_71$$15, path TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_72$$15, "base64_encode", &_54, 89, _71$$15);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&_73$$15, "chunk_split", &_56, 93, _72$$15);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_74$$15);
			ZEPHIR_CONCAT_VV(_74$$15, _73$$15, boundary);
			zephir_array_append(&data, _74$$15, PH_SEPARATE, "yb/mailer/smtp.zep", 160);
		}
		ZEPHIR_CALL_FUNCTION(NULL, "finfo_close", NULL, 96, mine);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_48);
	ZVAL_STRING(_48, ".", 1);
	zephir_array_append(&data, _48, PH_SEPARATE, "yb/mailer/smtp.zep", 166);
	ZEPHIR_INIT_NVAR(_48);
	ZVAL_STRING(_48, "DATA", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_75);
	ZVAL_STRING(_75, "DATA", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_76);
	ZVAL_LONG(_76, 354);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", &_4, 0, _48, _75, _76);
	zephir_check_temp_parameter(_48);
	zephir_check_temp_parameter(_75);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_48);
	ZEPHIR_SINIT_NVAR(_36);
	ZVAL_STRING(&_36, "\r\n", 0);
	zephir_fast_join(_48, &_36, data TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_75);
	ZVAL_STRING(_75, "END DATA", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_76);
	ZVAL_LONG(_76, 250);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", &_4, 0, _75, _48, _76);
	zephir_check_temp_parameter(_75);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Mailer_Smtp, __destruct) {

	zval *_0$$3, *_1$$3, *_2$$3, *_3;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();


	/* try_start_1: */

		ZEPHIR_INIT_VAR(_0$$3);
		ZVAL_STRING(_0$$3, "QUIT", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_1$$3);
		ZVAL_STRING(_1$$3, "QUIT", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_LONG(_2$$3, 221);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", NULL, 0, _0$$3, _1$$3, _2$$3);
		zephir_check_temp_parameter(_0$$3);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	zend_clear_exception(TSRMLS_C);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("socket"), PH_NOISY_CC);
	zephir_fclose(_3 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Mailer_Smtp, cmd) {

	zend_bool _0, _9;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *step_param = NULL, *cmd_param = NULL, *expected_param = NULL, *_1, *_3 = NULL, *_6, _7, *_8 = NULL, *_10, *_4$$3, *_11$$4;
	zval *step = NULL, *cmd = NULL, *expected = NULL, *output = NULL, *_2, *_5$$3, *_12$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &step_param, &cmd_param, &expected_param);

	zephir_get_strval(step, step_param);
	zephir_get_strval(cmd, cmd_param);
	zephir_get_strval(expected, expected_param);


	_0 = zephir_is_true(cmd);
	if (_0) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("socket"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_VS(_2, cmd, "\r\n");
		ZEPHIR_CALL_FUNCTION(&_3, "fputs", NULL, 97, _1, _2);
		zephir_check_call_status();
		_0 = !zephir_is_true(_3);
	}
	if (unlikely(_0)) {
		ZEPHIR_INIT_VAR(_4$$3);
		object_init_ex(_4$$3, yb_mailer_exception_ce);
		ZEPHIR_INIT_VAR(_5$$3);
		ZEPHIR_CONCAT_SV(_5$$3, "Cannot fputs to socket on step: ", step);
		ZEPHIR_CALL_METHOD(NULL, _4$$3, "__construct", NULL, 2, _5$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_4$$3, "yb/mailer/smtp.zep", 186 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("socket"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_LONG(&_7, 1024);
	ZEPHIR_CALL_FUNCTION(&_8, "fread", NULL, 98, _6, &_7);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(output);
	zephir_fast_trim(output, _8, NULL , ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	_9 = zephir_is_true(expected);
	if (_9) {
		ZEPHIR_INIT_VAR(_10);
		zephir_fast_strpos(_10, output, expected, 0 );
		_9 = !ZEPHIR_IS_LONG_IDENTICAL(_10, 0);
	}
	if (_9) {
		ZEPHIR_INIT_VAR(_11$$4);
		object_init_ex(_11$$4, yb_mailer_exception_ce);
		ZEPHIR_INIT_VAR(_12$$4);
		ZEPHIR_CONCAT_SVSV(_12$$4, "Unexpected response on step: ", step, ", with output: ", output);
		ZEPHIR_CALL_METHOD(NULL, _11$$4, "__construct", NULL, 2, _12$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_11$$4, "yb/mailer/smtp.zep", 192 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Mailer_Smtp, pack) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *addr_param = NULL, *_0$$3 = NULL, *_1$$3;
	zval *name = NULL, *addr = NULL, *s, *_2$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &name_param, &addr_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(name);
		ZVAL_STRING(name, "", 1);
	} else {
		zephir_get_strval(name, name_param);
	}
	if (!addr_param) {
		ZEPHIR_INIT_VAR(addr);
		ZVAL_STRING(addr, "", 1);
	} else {
		zephir_get_strval(addr, addr_param);
	}


	ZEPHIR_INIT_VAR(s);
	ZVAL_EMPTY_STRING(s);
	if (!(!name) && Z_STRLEN_P(name)) {
		ZEPHIR_CALL_FUNCTION(&_0$$3, "base64_encode", NULL, 89, name);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_1$$3);
		ZEPHIR_CONCAT_SVS(_1$$3, "=?UTF-8?B?", _0$$3, "?=");
		zephir_concat_self(&s, _1$$3 TSRMLS_CC);
	}
	if (!(!addr) && Z_STRLEN_P(addr)) {
		ZEPHIR_INIT_VAR(_2$$4);
		ZEPHIR_CONCAT_SVS(_2$$4, "<", addr, ">");
		zephir_concat_self(&s, _2$$4 TSRMLS_CC);
	}
	RETURN_CTOR(s);

}


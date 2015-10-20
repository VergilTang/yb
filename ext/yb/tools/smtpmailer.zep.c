
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/hash.h"
#include "kernel/string.h"
#include "kernel/file.h"


ZEPHIR_INIT_CLASS(Yb_Tools_SmtpMailer) {

	ZEPHIR_REGISTER_CLASS(Yb\\Tools, SmtpMailer, yb, tools_smtpmailer, yb_tools_smtpmailer_method_entry, 0);

	zend_declare_property_null(yb_tools_smtpmailer_ce, SL("socket"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(yb_tools_smtpmailer_ce, SL("from"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(yb_tools_smtpmailer_ce, SL("EOL"), "\r\n" TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Yb_Tools_SmtpMailer, __construct) {

	zend_bool _0, _9;
	zephir_fcall_cache_entry *_17 = NULL, *_20 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, *socket = NULL, *timeout = NULL, *secure = NULL, *port = NULL, *from = NULL, *name = NULL, _10 = zval_used_for_init, *_11 = NULL, *_12 = NULL, *_13 = NULL, *_14 = NULL, *_15 = NULL, *_16 = NULL, *_18, *_19 = NULL, *_21, *_22 = NULL, *_23 = NULL, *_1$$4, _2$$4, *_3$$4 = NULL, *_4$$4, *_5$$4, *_6$$6, *_7$$6, *_8$$6;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	zephir_get_arrval(options, options_param);


	ZEPHIR_OBS_VAR(timeout);
	if (!(zephir_array_isset_string_fetch(&timeout, options, SS("timeout"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(timeout);
		ZVAL_LONG(timeout, 10);
	}
	ZEPHIR_OBS_VAR(secure);
	_0 = zephir_array_isset_string_fetch(&secure, options, SS("secure"), 0 TSRMLS_CC);
	if (_0) {
		_0 = zephir_is_true(secure);
	}
	if (_0) {
		ZEPHIR_OBS_VAR(port);
		if (!(zephir_array_isset_string_fetch(&port, options, SS("port"), 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(port);
			ZVAL_LONG(port, 465);
		}
		zephir_array_fetch_string(&_1$$4, options, SL("host"), PH_NOISY | PH_READONLY, "yb/tools/smtpmailer.zep", 22 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_2$$4);
		ZVAL_STRING(&_2$$4, "tcp://%s:%d", 0);
		ZEPHIR_CALL_FUNCTION(&_3$$4, "sprintf", NULL, 49, &_2$$4, _1$$4, port);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_4$$4);
		ZVAL_NULL(_4$$4);
		ZEPHIR_INIT_VAR(_5$$4);
		ZVAL_NULL(_5$$4);
		ZEPHIR_CALL_FUNCTION(&socket, "stream_socket_client", NULL, 58, _3$$4, _4$$4, _5$$4, timeout);
		zephir_check_call_status();
	} else {
		ZEPHIR_OBS_NVAR(port);
		if (!(zephir_array_isset_string_fetch(&port, options, SS("port"), 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(port);
			ZVAL_LONG(port, 25);
		}
		zephir_array_fetch_string(&_6$$6, options, SL("host"), PH_NOISY | PH_READONLY, "yb/tools/smtpmailer.zep", 27 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_7$$6);
		ZVAL_NULL(_7$$6);
		ZEPHIR_INIT_VAR(_8$$6);
		ZVAL_NULL(_8$$6);
		ZEPHIR_CALL_FUNCTION(&socket, "fsockopen", NULL, 59, _6$$6, port, _7$$6, _8$$6, timeout);
		zephir_check_call_status();
	}
	if (unlikely(!zephir_is_true(socket))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_tools_exception_ce, "Cannot connect to mail server", "yb/tools/smtpmailer.zep", 31);
		return;
	}
	_9 = zephir_is_true(secure);
	if (_9) {
		ZEPHIR_SINIT_VAR(_10);
		ZVAL_STRING(&_10, "STREAM_CRYPTO_METHOD_SSLv23_CLIENT", 0);
		ZEPHIR_CALL_FUNCTION(&_11, "constant", NULL, 60, &_10);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_12, "stream_socket_enable_crypto", NULL, 61, socket, ZEPHIR_GLOBAL(global_true), _11);
		zephir_check_call_status();
		_9 = !zephir_is_true(_12);
	}
	if (unlikely(_9)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_tools_exception_ce, "Cannot enable crypto socket", "yb/tools/smtpmailer.zep", 36);
		return;
	}
	ZEPHIR_SINIT_NVAR(_10);
	ZVAL_LONG(&_10, 1);
	ZEPHIR_CALL_FUNCTION(&_13, "stream_set_blocking", NULL, 62, socket, &_10);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_13))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_tools_exception_ce, "Cannot set blocking socket", "yb/tools/smtpmailer.zep", 40);
		return;
	}
	zephir_update_property_this(this_ptr, SL("socket"), socket TSRMLS_CC);
	ZEPHIR_INIT_VAR(_14);
	ZVAL_STRING(_14, "CONNECT", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_15);
	ZVAL_STRING(_15, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_16);
	ZVAL_LONG(_16, 220);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", &_17, 0, _14, _15, _16);
	zephir_check_temp_parameter(_14);
	zephir_check_temp_parameter(_15);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_14);
	ZVAL_STRING(_14, "EHLO HELO", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_15);
	ZVAL_STRING(_15, "EHLO HELO", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_16);
	ZVAL_LONG(_16, 250);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", &_17, 0, _14, _15, _16);
	zephir_check_temp_parameter(_14);
	zephir_check_temp_parameter(_15);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_14);
	ZVAL_STRING(_14, "AUTH LOGIN", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_15);
	ZVAL_STRING(_15, "AUTH LOGIN", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_16);
	ZVAL_LONG(_16, 334);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", &_17, 0, _14, _15, _16);
	zephir_check_temp_parameter(_14);
	zephir_check_temp_parameter(_15);
	zephir_check_call_status();
	zephir_array_fetch_string(&_18, options, SL("user"), PH_NOISY | PH_READONLY, "yb/tools/smtpmailer.zep", 48 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_19, "base64_encode", &_20, 63, _18);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_14);
	ZVAL_STRING(_14, "AUTH USER", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_15);
	ZVAL_LONG(_15, 334);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", &_17, 0, _14, _19, _15);
	zephir_check_temp_parameter(_14);
	zephir_check_call_status();
	zephir_array_fetch_string(&_21, options, SL("passwd"), PH_NOISY | PH_READONLY, "yb/tools/smtpmailer.zep", 49 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_22, "base64_encode", &_20, 63, _21);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_14);
	ZVAL_STRING(_14, "AUTH PASSWD", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_15);
	ZVAL_LONG(_15, 235);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "cmd", &_17, 0, _14, _22, _15);
	zephir_check_temp_parameter(_14);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(from);
	if (!(zephir_array_isset_string_fetch(&from, options, SS("from"), 0 TSRMLS_CC))) {
		ZEPHIR_OBS_NVAR(from);
		zephir_array_fetch_string(&from, options, SL("user"), PH_NOISY, "yb/tools/smtpmailer.zep", 52 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(name);
	if (!(zephir_array_isset_string_fetch(&name, options, SS("name"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(name);
		ZVAL_STRING(name, "", 1);
	}
	ZEPHIR_CALL_METHOD(&_23, this_ptr, "pack", NULL, 0, name, from);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("from"), _23 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Tools_SmtpMailer, sendTo) {

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
	zephir_array_append(&data, _6, PH_SEPARATE, "yb/tools/smtpmailer.zep", 67);
	if (zephir_fast_count_int(to TSRMLS_CC) < 1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(yb_tools_exception_ce, "No one to send", "yb/tools/smtpmailer.zep", 70);
		return;
	}
	ZEPHIR_INIT_VAR(temp);
	array_init(temp);
	zephir_is_iterable(to, &_8, &_7, 0, 0, "yb/tools/smtpmailer.zep", 79);
	for (
	  ; zephir_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
	  ; zephir_hash_move_forward_ex(_8, &_7)
	) {
		ZEPHIR_GET_HMKEY(addr, _8, _7);
		ZEPHIR_GET_HVALUE(name, _9);
		ZEPHIR_CALL_METHOD(&_10$$4, this_ptr, "pack", &_11, 0, name, addr);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(name, _10$$4);
		zephir_array_append(&temp, name, PH_SEPARATE, "yb/tools/smtpmailer.zep", 76);
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
	zephir_array_append(&data, _15, PH_SEPARATE, "yb/tools/smtpmailer.zep", 79);
	if (zephir_fast_count_int(cc TSRMLS_CC) > 0) {
		ZEPHIR_INIT_NVAR(temp);
		array_init(temp);
		zephir_is_iterable(cc, &_17$$5, &_16$$5, 0, 0, "yb/tools/smtpmailer.zep", 88);
		for (
		  ; zephir_hash_get_current_data_ex(_17$$5, (void**) &_18$$5, &_16$$5) == SUCCESS
		  ; zephir_hash_move_forward_ex(_17$$5, &_16$$5)
		) {
			ZEPHIR_GET_HMKEY(addr, _17$$5, _16$$5);
			ZEPHIR_GET_HVALUE(name, _18$$5);
			ZEPHIR_CALL_METHOD(&_19$$6, this_ptr, "pack", &_11, 0, name, addr);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(name, _19$$6);
			zephir_array_append(&temp, name, PH_SEPARATE, "yb/tools/smtpmailer.zep", 85);
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
		zephir_array_append(&data, _24$$5, PH_SEPARATE, "yb/tools/smtpmailer.zep", 88);
	}
	if (zephir_fast_count_int(bcc TSRMLS_CC) > 0) {
		ZEPHIR_INIT_NVAR(temp);
		array_init(temp);
		zephir_is_iterable(bcc, &_26$$7, &_25$$7, 0, 0, "yb/tools/smtpmailer.zep", 97);
		for (
		  ; zephir_hash_get_current_data_ex(_26$$7, (void**) &_27$$7, &_25$$7) == SUCCESS
		  ; zephir_hash_move_forward_ex(_26$$7, &_25$$7)
		) {
			ZEPHIR_GET_HMKEY(addr, _26$$7, _25$$7);
			ZEPHIR_GET_HVALUE(name, _27$$7);
			ZEPHIR_CALL_METHOD(&_28$$8, this_ptr, "pack", &_11, 0, name, addr);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(name, _28$$8);
			zephir_array_append(&temp, name, PH_SEPARATE, "yb/tools/smtpmailer.zep", 94);
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
		zephir_array_append(&data, _33$$7, PH_SEPARATE, "yb/tools/smtpmailer.zep", 97);
	}
	ZEPHIR_OBS_VAR(subject);
	if (zephir_array_isset_string_fetch(&subject, message, SS("subject"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_34$$9, this_ptr, "pack", &_11, 0, subject);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_35$$9);
		ZEPHIR_CONCAT_SV(_35$$9, "Subject: ", _34$$9);
		zephir_array_append(&data, _35$$9, PH_SEPARATE, "yb/tools/smtpmailer.zep", 101);
	}
	ZEPHIR_SINIT_VAR(_36);
	ZVAL_STRING(&_36, "r", 0);
	ZEPHIR_CALL_FUNCTION(&_37, "gmdate", NULL, 64, &_36);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_38);
	ZEPHIR_CONCAT_SV(_38, "Date: ", _37);
	zephir_array_append(&data, _38, PH_SEPARATE, "yb/tools/smtpmailer.zep", 104);
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
		zephir_array_append(&data, _41$$10, PH_SEPARATE, "yb/tools/smtpmailer.zep", 107);
	} else {
		ZEPHIR_INIT_NVAR(attachments);
		array_init(attachments);
		ZEPHIR_INIT_VAR(_42$$11);
		ZVAL_STRING(_42$$11, "Content-Type: multipart/alternative;", 1);
		zephir_array_append(&data, _42$$11, PH_SEPARATE, "yb/tools/smtpmailer.zep", 110);
	}
	ZEPHIR_INIT_NVAR(_3);
	ZEPHIR_CALL_FUNCTION(&_43, "mt_rand", NULL, 51);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_44, "uniqid", NULL, 52, _43, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	zephir_md5(_3, _44);
	zephir_get_strval(_45, _3);
	ZEPHIR_INIT_VAR(boundary);
	ZEPHIR_CONCAT_SV(boundary, "Boundary-", _45);
	ZEPHIR_INIT_VAR(_46);
	ZEPHIR_CONCAT_SVS(_46, "\tboundary=\"", boundary, "\"");
	zephir_array_append(&data, _46, PH_SEPARATE, "yb/tools/smtpmailer.zep", 114);
	ZEPHIR_INIT_VAR(_47);
	ZEPHIR_CONCAT_SV(_47, "--", boundary);
	ZEPHIR_CPY_WRT(boundary, _47);
	ZEPHIR_INIT_VAR(_48);
	ZVAL_STRING(_48, "MIME-Version: 1.0", 1);
	zephir_array_append(&data, _48, PH_SEPARATE, "yb/tools/smtpmailer.zep", 117);
	ZEPHIR_INIT_NVAR(_48);
	ZVAL_STRING(_48, "", 1);
	zephir_array_append(&data, _48, PH_SEPARATE, "yb/tools/smtpmailer.zep", 118);
	zephir_array_append(&data, boundary, PH_SEPARATE, "yb/tools/smtpmailer.zep", 120);
	ZEPHIR_OBS_VAR(plain);
	_49 = zephir_array_isset_string_fetch(&plain, message, SS("plain"), 0 TSRMLS_CC);
	if (_49) {
		_49 = zephir_is_true(plain);
	}
	if (_49) {
		ZEPHIR_INIT_VAR(_50$$12);
		ZVAL_STRING(_50$$12, "Content-Type: text/plain; charset=UTF-8", 1);
		zephir_array_append(&data, _50$$12, PH_SEPARATE, "yb/tools/smtpmailer.zep", 122);
	} else {
		ZEPHIR_INIT_VAR(_51$$13);
		ZVAL_STRING(_51$$13, "Content-Type: text/html; charset=UTF-8", 1);
		zephir_array_append(&data, _51$$13, PH_SEPARATE, "yb/tools/smtpmailer.zep", 124);
	}
	ZEPHIR_INIT_NVAR(_48);
	ZVAL_STRING(_48, "Content-Transfer-Encoding: base64", 1);
	zephir_array_append(&data, _48, PH_SEPARATE, "yb/tools/smtpmailer.zep", 126);
	ZEPHIR_INIT_NVAR(_48);
	ZVAL_STRING(_48, "", 1);
	zephir_array_append(&data, _48, PH_SEPARATE, "yb/tools/smtpmailer.zep", 127);
	zephir_array_fetch_string(&_52, message, SL("body"), PH_NOISY | PH_READONLY, "yb/tools/smtpmailer.zep", 128 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_53, "base64_encode", &_54, 63, _52);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_55, "chunk_split", &_56, 65, _53);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_57);
	ZEPHIR_CONCAT_VV(_57, _55, boundary);
	zephir_array_append(&data, _57, PH_SEPARATE, "yb/tools/smtpmailer.zep", 128);
	if (zephir_is_true(attachments)) {
		ZEPHIR_SINIT_VAR(_58$$14);
		ZVAL_LONG(&_58$$14, 16);
		ZEPHIR_CALL_FUNCTION(&mine, "finfo_open", NULL, 66, &_58$$14);
		zephir_check_call_status();
		zephir_is_iterable(attachments, &_60$$14, &_59$$14, 0, 0, "yb/tools/smtpmailer.zep", 150);
		for (
		  ; zephir_hash_get_current_data_ex(_60$$14, (void**) &_61$$14, &_59$$14) == SUCCESS
		  ; zephir_hash_move_forward_ex(_60$$14, &_59$$14)
		) {
			ZEPHIR_GET_HVALUE(path, _61$$14);
			if (unlikely(!((zephir_file_exists(path TSRMLS_CC) == SUCCESS)))) {
				ZEPHIR_INIT_NVAR(_62$$16);
				object_init_ex(_62$$16, yb_tools_exception_ce);
				ZEPHIR_INIT_LNVAR(_63$$16);
				ZEPHIR_CONCAT_SV(_63$$16, "Cannot find attachment: ", path);
				ZEPHIR_CALL_METHOD(NULL, _62$$16, "__construct", &_64, 3, _63$$16);
				zephir_check_call_status();
				zephir_throw_exception_debug(_62$$16, "yb/tools/smtpmailer.zep", 134 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_FUNCTION(&type, "finfo_file", &_65, 67, mine, path);
			zephir_check_call_status();
			if (zephir_is_true(type)) {
				ZEPHIR_INIT_LNVAR(_66$$17);
				ZEPHIR_CONCAT_SV(_66$$17, "Content-Type: ", type);
				zephir_array_append(&data, _66$$17, PH_SEPARATE, "yb/tools/smtpmailer.zep", 139);
			} else {
				ZEPHIR_INIT_NVAR(_67$$18);
				ZVAL_STRING(_67$$18, "Content-Type: application/octet-stream", 1);
				zephir_array_append(&data, _67$$18, PH_SEPARATE, "yb/tools/smtpmailer.zep", 141);
			}
			ZEPHIR_INIT_NVAR(_68$$15);
			ZVAL_STRING(_68$$15, "Content-Transfer-Encoding: base64", 1);
			zephir_array_append(&data, _68$$15, PH_SEPARATE, "yb/tools/smtpmailer.zep", 144);
			ZEPHIR_INIT_NVAR(_68$$15);
			zephir_basename(_68$$15, path TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_69$$15, this_ptr, "pack", &_11, 0, _68$$15);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_70$$15);
			ZEPHIR_CONCAT_SVS(_70$$15, "Content-Disposition: attachment; filename=\"", _69$$15, "\"");
			zephir_array_append(&data, _70$$15, PH_SEPARATE, "yb/tools/smtpmailer.zep", 145);
			ZEPHIR_INIT_NVAR(_71$$15);
			ZVAL_STRING(_71$$15, "", 1);
			zephir_array_append(&data, _71$$15, PH_SEPARATE, "yb/tools/smtpmailer.zep", 146);
			ZEPHIR_INIT_NVAR(_71$$15);
			zephir_file_get_contents(_71$$15, path TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_72$$15, "base64_encode", &_54, 63, _71$$15);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&_73$$15, "chunk_split", &_56, 65, _72$$15);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_74$$15);
			ZEPHIR_CONCAT_VV(_74$$15, _73$$15, boundary);
			zephir_array_append(&data, _74$$15, PH_SEPARATE, "yb/tools/smtpmailer.zep", 147);
		}
		ZEPHIR_CALL_FUNCTION(NULL, "finfo_close", NULL, 68, mine);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_48);
	ZVAL_STRING(_48, ".", 1);
	zephir_array_append(&data, _48, PH_SEPARATE, "yb/tools/smtpmailer.zep", 153);
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

PHP_METHOD(Yb_Tools_SmtpMailer, __destruct) {

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

PHP_METHOD(Yb_Tools_SmtpMailer, cmd) {

	zend_bool _1, _11;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *step_param = NULL, *cmd_param = NULL, *expected_param = NULL, *_0 = NULL, *_2, *_4 = NULL, *_7, _8, *_9 = NULL, *_10 = NULL, *_12, *_5$$3, *_13$$4;
	zval *step = NULL, *cmd = NULL, *expected = NULL, *output = NULL, *_3, *_6$$3, *_14$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &step_param, &cmd_param, &expected_param);

	zephir_get_strval(step, step_param);
	zephir_get_strval(cmd, cmd_param);
	zephir_get_strval(expected, expected_param);


	_1 = zephir_fast_strlen_ev(cmd) > 0;
	if (_1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("socket"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_CONCAT_VS(_3, cmd, "\r\n");
		ZEPHIR_CALL_FUNCTION(&_4, "fputs", NULL, 69, _2, _3);
		zephir_check_call_status();
		_1 = !zephir_is_true(_4);
	}
	if (unlikely(_1)) {
		ZEPHIR_INIT_VAR(_5$$3);
		object_init_ex(_5$$3, yb_tools_exception_ce);
		ZEPHIR_INIT_VAR(_6$$3);
		ZEPHIR_CONCAT_SV(_6$$3, "Cannot fputs to socket on step: ", step);
		ZEPHIR_CALL_METHOD(NULL, _5$$3, "__construct", NULL, 3, _6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_5$$3, "yb/tools/smtpmailer.zep", 173 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("socket"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_LONG(&_8, 1024);
	ZEPHIR_CALL_FUNCTION(&_9, "fread", NULL, 70, _7, &_8);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(output);
	zephir_fast_trim(output, _9, NULL , ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	_11 = zephir_fast_strlen_ev(expected) > 0;
	if (_11) {
		ZEPHIR_INIT_VAR(_12);
		zephir_fast_strpos(_12, output, expected, 0 );
		_11 = !ZEPHIR_IS_LONG_IDENTICAL(_12, 0);
	}
	if (_11) {
		ZEPHIR_INIT_VAR(_13$$4);
		object_init_ex(_13$$4, yb_tools_exception_ce);
		ZEPHIR_INIT_VAR(_14$$4);
		ZEPHIR_CONCAT_SVSV(_14$$4, "Unexpected response on step: ", step, ", with output: ", output);
		ZEPHIR_CALL_METHOD(NULL, _13$$4, "__construct", NULL, 3, _14$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_13$$4, "yb/tools/smtpmailer.zep", 179 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Yb_Tools_SmtpMailer, pack) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *addr_param = NULL, *_0 = NULL, *_3 = NULL, *_1$$3 = NULL, *_2$$3;
	zval *name = NULL, *addr = NULL, *s, *_4$$4;

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
	if (zephir_fast_strlen_ev(name) > 0) {
		ZEPHIR_CALL_FUNCTION(&_1$$3, "base64_encode", NULL, 63, name);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_2$$3);
		ZEPHIR_CONCAT_SVS(_2$$3, "=?UTF-8?B?", _1$$3, "?=");
		zephir_concat_self(&s, _2$$3 TSRMLS_CC);
	}
	if (zephir_fast_strlen_ev(addr) > 0) {
		ZEPHIR_INIT_VAR(_4$$4);
		ZEPHIR_CONCAT_SVS(_4$$4, "<", addr, ">");
		zephir_concat_self(&s, _4$$4 TSRMLS_CC);
	}
	RETURN_CTOR(s);

}


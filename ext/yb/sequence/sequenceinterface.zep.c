
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Yb_Sequence_SequenceInterface) {

	ZEPHIR_REGISTER_INTERFACE(Yb\\Sequence, SequenceInterface, yb, sequence_sequenceinterface, yb_sequence_sequenceinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Yb_Sequence_SequenceInterface, getNextSequence);

ZEPHIR_DOC_METHOD(Yb_Sequence_SequenceInterface, restoreSequences);


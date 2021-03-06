
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */
/**
 * This class offers contextual information of a fired event in the EventsManager
 */
ZEPHIR_INIT_CLASS(Lynx_Stdlib_Events_Event) {

	ZEPHIR_REGISTER_CLASS(Lynx\\Stdlib\\Events, Event, lynx, stdlib_events_event, lynx_stdlib_events_event_method_entry, 0);

	zend_declare_property_null(lynx_stdlib_events_event_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_stdlib_events_event_ce, SL("_source"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(lynx_stdlib_events_event_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(lynx_stdlib_events_event_ce, SL("_stopped"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(lynx_stdlib_events_event_ce, SL("_cancelable"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Lynx_Stdlib_Events_Event, setType) {

	zval *type;

	zephir_fetch_params(0, 1, 0, &type);



	zephir_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);

}

PHP_METHOD(Lynx_Stdlib_Events_Event, getType) {


	RETURN_MEMBER(this_ptr, "_type");

}

PHP_METHOD(Lynx_Stdlib_Events_Event, getSource) {


	RETURN_MEMBER(this_ptr, "_source");

}

PHP_METHOD(Lynx_Stdlib_Events_Event, setData) {

	zval *data;

	zephir_fetch_params(0, 1, 0, &data);



	zephir_update_property_this(this_ptr, SL("_data"), data TSRMLS_CC);

}

PHP_METHOD(Lynx_Stdlib_Events_Event, getData) {


	RETURN_MEMBER(this_ptr, "_data");

}

PHP_METHOD(Lynx_Stdlib_Events_Event, getCancelable) {


	RETURN_MEMBER(this_ptr, "_cancelable");

}

/**
 * @param string type
 * @param object source
 * @param mixed data
 * @param boolean cancelable
 */
PHP_METHOD(Lynx_Stdlib_Events_Event, __construct) {

	zval *type_param = NULL, *source, *data = NULL, *cancelable = NULL;
	zval *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &type_param, &source, &data, &cancelable);

	if (unlikely(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(type, type_param);
	} else {
		ZEPHIR_INIT_VAR(type);
		ZVAL_EMPTY_STRING(type);
	}
	if (!data) {
		data = ZEPHIR_GLOBAL(global_null);
	}
	if (!cancelable) {
		cancelable = ZEPHIR_GLOBAL(global_true);
	}


	zephir_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_source"), source TSRMLS_CC);
	if (Z_TYPE_P(data) != IS_NULL) {
		zephir_update_property_this(this_ptr, SL("_data"), data TSRMLS_CC);
	}
	if (!ZEPHIR_IS_TRUE_IDENTICAL(cancelable)) {
		zephir_update_property_this(this_ptr, SL("_cancelable"), cancelable TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Stops the event preventing propagation
 */
PHP_METHOD(Lynx_Stdlib_Events_Event, stop) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_cancelable"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		zephir_update_property_this(this_ptr, SL("_stopped"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(zend_exception_get_default(TSRMLS_C), "Trying to cancel a non-cancelable event", "lynx/Stdlib/Events/Event.zep", 51);
		return;
	}

}

/**
 * Check whether the event is currently stopped
 *
 * @return boolean
 */
PHP_METHOD(Lynx_Stdlib_Events_Event, isStopped) {


	RETURN_MEMBER(this_ptr, "_stopped");

}


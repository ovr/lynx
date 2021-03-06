
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/main.h"


/**
 * @author Patsura Dmitry <zaets28rus@gmail.com>
 */
ZEPHIR_INIT_CLASS(Lynx_DBAL_Driver_Pdo_Statement) {

	ZEPHIR_REGISTER_CLASS_EX(Lynx\\DBAL\\Driver\\Pdo, Statement, lynx, dbal_driver_pdo_statement, zephir_get_internal_ce(SS("pdostatement") TSRMLS_CC), NULL, 0);

	return SUCCESS;

}


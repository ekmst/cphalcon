
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
#include "kernel/fcall.h"
#include "kernel/memory.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Filter\Sanitize\String
 *
 * Sanitizes a value to string
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Sanitize_StringVal) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Filter\\Sanitize, StringVal, phalcon, filter_sanitize_stringval, phalcon_filter_sanitize_stringval_method_entry, 0);

	return SUCCESS;

}

/**
 * @var mixed input The text to sanitize
 */
PHP_METHOD(Phalcon_Filter_Sanitize_StringVal, __invoke) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *input, input_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &input);



	ZVAL_LONG(&_0, 513);
	ZEPHIR_RETURN_CALL_FUNCTION("filter_var", NULL, 185, input, &_0);
	zephir_check_call_status();
	RETURN_MM();

}


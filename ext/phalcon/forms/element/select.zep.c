
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
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
 * Phalcon\Forms\Element\Select
 *
 * Component SELECT (choice) for forms
 */
ZEPHIR_INIT_CLASS(Phalcon_Forms_Element_Select) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Forms\\Element, Select, phalcon, forms_element_select, phalcon_forms_element_ce, phalcon_forms_element_select_method_entry, 0);

	zend_declare_property_null(phalcon_forms_element_select_ce, SL("optionsValues"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Forms\Element constructor
 *
 * @param object|array options
 * @param array attributes
 */
PHP_METHOD(Phalcon_Forms_Element_Select, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *name_param = NULL, *options = NULL, options_sub, *attributes = NULL, attributes_sub, __$null;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&options_sub);
	ZVAL_UNDEF(&attributes_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &name_param, &options, &attributes);

	zephir_get_strval(&name, name_param);
	if (!options) {
		options = &options_sub;
		options = &__$null;
	}
	if (!attributes) {
		attributes = &attributes_sub;
		attributes = &__$null;
	}


	zephir_update_property_zval(this_ptr, SL("optionsValues"), options);
	ZEPHIR_CALL_PARENT(NULL, phalcon_forms_element_select_ce, getThis(), "__construct", &_0, 0, &name, attributes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Adds an option to the current options
 *
 * @param array option
 */
PHP_METHOD(Phalcon_Forms_Element_Select, addOption) {

	zend_string *_2$$3;
	zend_ulong _1$$3;
	zval *option, option_sub, key, value, *_0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &option);



	if (Z_TYPE_P(option) == IS_ARRAY) {
		zephir_is_iterable(option, 0, "phalcon/Forms/Element/Select.zep", 50);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(option), _1$$3, _2$$3, _0$$3)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_2$$3 != NULL) { 
				ZVAL_STR_COPY(&key, _2$$3);
			} else {
				ZVAL_LONG(&key, _1$$3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0$$3);
			zephir_update_property_array(this_ptr, SL("optionsValues"), &key, &value TSRMLS_CC);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
	} else {
		zephir_update_property_array_append(this_ptr, SL("optionsValues"), option TSRMLS_CC);
	}
	RETURN_THIS();

}

/**
 * Returns the choices' options
 *
 * @return array|object
 */
PHP_METHOD(Phalcon_Forms_Element_Select, getOptions) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "optionsValues");

}

/**
 * Renders the element widget returning html
 */
PHP_METHOD(Phalcon_Forms_Element_Select, render) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *attributes_param = NULL, _1, _2;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &attributes_param);

	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}


	ZEPHIR_CALL_METHOD(&_1, this_ptr, "prepareattributes", NULL, 0, &attributes);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, SL("optionsValues"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_CE_STATIC(phalcon_tag_select_ce, "selectfield", &_0, 0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Set the choice's options
 *
 * @param array|object options
 */
PHP_METHOD(Phalcon_Forms_Element_Select, setOptions) {

	zval *options, options_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options_sub);

	zephir_fetch_params(0, 1, 0, &options);



	zephir_update_property_zval(this_ptr, SL("optionsValues"), options);
	RETURN_THISW();

}


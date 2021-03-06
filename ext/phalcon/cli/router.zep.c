
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
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Cli\Router
 *
 * <p>Phalcon\Cli\Router is the standard framework router. Routing is the
 * process of taking a command-line arguments and
 * decomposing it into parameters to determine which module, task, and
 * action of that task should receive the request</p>
 *
 *<code>
 * $router = new \Phalcon\Cli\Router();
 *
 * $router->handle(
 *     [
 *         "module" => "main",
 *         "task"   => "videos",
 *         "action" => "process",
 *     ]
 * );
 *
 * echo $router->getTaskName();
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Cli_Router) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Cli, Router, phalcon, cli_router, phalcon_cli_router_method_entry, 0);

	zend_declare_property_null(phalcon_cli_router_ce, SL("action"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_cli_router_ce, SL("container"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_cli_router_ce, SL("defaultAction"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_cli_router_ce, SL("defaultModule"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_cli_router_ce, SL("defaultParams"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_cli_router_ce, SL("defaultTask"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_cli_router_ce, SL("matchedRoute"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_cli_router_ce, SL("matches"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_cli_router_ce, SL("module"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_cli_router_ce, SL("params"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_cli_router_ce, SL("routes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_cli_router_ce, SL("task"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_cli_router_ce, SL("wasMatched"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_cli_router_ce->create_object = zephir_init_properties_Phalcon_Cli_Router;

	zend_class_implements(phalcon_cli_router_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Cli\Router constructor
 */
PHP_METHOD(Phalcon_Cli_Router, __construct) {

	zval routes, _1$$3, _3$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *defaultRoutes_param = NULL, _0$$3, _2$$3, _4$$3;
	zend_bool defaultRoutes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&routes);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &defaultRoutes_param);

	if (!defaultRoutes_param) {
		defaultRoutes = 1;
	} else {
		defaultRoutes = zephir_get_boolval(defaultRoutes_param);
	}


	ZEPHIR_INIT_VAR(&routes);
	array_init(&routes);
	if (defaultRoutes) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_cli_router_route_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 1, 0 TSRMLS_CC);
		add_assoc_long_ex(&_1$$3, SL("task"), 1);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "#^(?::delimiter)?([a-zA-Z0-9\\_\\-]+)[:delimiter]{0,1}$#");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 138, &_2$$3, &_1$$3);
		zephir_check_call_status();
		zephir_array_append(&routes, &_0$$3, PH_SEPARATE, "phalcon/Cli/Router.zep", 91);
		ZEPHIR_INIT_NVAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_cli_router_route_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_create_array(&_3$$3, 3, 0 TSRMLS_CC);
		add_assoc_long_ex(&_3$$3, SL("task"), 1);
		add_assoc_long_ex(&_3$$3, SL("action"), 2);
		add_assoc_long_ex(&_3$$3, SL("params"), 3);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "#^(?::delimiter)?([a-zA-Z0-9\\_\\-]+):delimiter([a-zA-Z0-9\\.\\_]+)(:delimiter.*)*$#");
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 138, &_4$$3, &_3$$3);
		zephir_check_call_status();
		zephir_array_append(&routes, &_2$$3, PH_SEPARATE, "phalcon/Cli/Router.zep", 100);
	}
	zephir_update_property_zval(this_ptr, SL("routes"), &routes);
	ZEPHIR_MM_RESTORE();

}

/**
 * Adds a route to the router
 *
 *<code>
 * $router->add("/about", "About::main");
 *</code>
 *
 * @param string|array paths
 */
PHP_METHOD(Phalcon_Cli_Router, add) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *pattern_param = NULL, *paths = NULL, paths_sub, __$null, route;
	zval pattern;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&route);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pattern_param, &paths);

	if (UNEXPECTED(Z_TYPE_P(pattern_param) != IS_STRING && Z_TYPE_P(pattern_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'pattern' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(pattern_param) == IS_STRING)) {
		zephir_get_strval(&pattern, pattern_param);
	} else {
		ZEPHIR_INIT_VAR(&pattern);
		ZVAL_EMPTY_STRING(&pattern);
	}
	if (!paths) {
		paths = &paths_sub;
		paths = &__$null;
	}


	ZEPHIR_INIT_VAR(&route);
	object_init_ex(&route, phalcon_cli_router_route_ce);
	ZEPHIR_CALL_METHOD(NULL, &route, "__construct", NULL, 138, &pattern, paths);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("routes"), &route TSRMLS_CC);
	RETURN_CCTOR(&route);

}

/**
 * Returns processed action name
 */
PHP_METHOD(Phalcon_Cli_Router, getActionName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "action");

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalcon_Cli_Router, getDI) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "container");

}

/**
 * Returns the route that matches the handled URI
 */
PHP_METHOD(Phalcon_Cli_Router, getMatchedRoute) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "matchedRoute");

}

/**
 * Returns the sub expressions in the regular expression matched
 */
PHP_METHOD(Phalcon_Cli_Router, getMatches) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "matches");

}

/**
 * Returns processed module name
 */
PHP_METHOD(Phalcon_Cli_Router, getModuleName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "module");

}

/**
 * Returns processed extra params
 */
PHP_METHOD(Phalcon_Cli_Router, getParams) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "params");

}

/**
 * Returns a route object by its id
 *
 * @param int id
 */
PHP_METHOD(Phalcon_Cli_Router, getRouteById) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id, id_sub, route, _0, *_1, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id);



	zephir_read_property(&_0, this_ptr, SL("routes"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalcon/Cli/Router.zep", 188);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
	{
		ZEPHIR_INIT_NVAR(&route);
		ZVAL_COPY(&route, _1);
		ZEPHIR_CALL_METHOD(&_2$$3, &route, "getrouteid", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_EQUAL(&_2$$3, id)) {
			RETURN_CCTOR(&route);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&route);
	RETURN_MM_BOOL(0);

}

/**
 * Returns a route object by its name
 */
PHP_METHOD(Phalcon_Cli_Router, getRouteByName) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, route, _0, *_1, _2$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_read_property(&_0, this_ptr, SL("routes"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalcon/Cli/Router.zep", 204);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
	{
		ZEPHIR_INIT_NVAR(&route);
		ZVAL_COPY(&route, _1);
		ZEPHIR_CALL_METHOD(&_2$$3, &route, "getname", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_EQUAL(&_2$$3, &name)) {
			RETURN_CCTOR(&route);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&route);
	RETURN_MM_BOOL(0);

}

/**
 * Returns all the routes defined in the router
 */
PHP_METHOD(Phalcon_Cli_Router, getRoutes) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "routes");

}

/**
 * Returns processed task name
 */
PHP_METHOD(Phalcon_Cli_Router, getTaskName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "task");

}

/**
 * Handles routing information received from command-line arguments
 *
 * @param array arguments
 */
PHP_METHOD(Phalcon_Cli_Router, handle) {

	zval _15$$30;
	zend_string *_6$$12;
	zend_ulong _5$$12;
	zval _3$$9, _8$$16, _10$$19;
	zend_bool _0$$3;
	zephir_fcall_cache_entry *_18 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arguments = NULL, arguments_sub, __$true, __$false, __$null, moduleName, taskName, actionName, params, route, parts, pattern, routeFound, matches, paths, beforeMatch, converters, converter, part, position, matchPosition, strParams, _1$$3, *_2$$3, *_4$$12, _7$$16, _9$$19, _11$$21, _12$$21, _13$$21, _14$$21, _16$$30, _17$$31, _19$$33;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arguments_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&moduleName);
	ZVAL_UNDEF(&taskName);
	ZVAL_UNDEF(&actionName);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&route);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&routeFound);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&paths);
	ZVAL_UNDEF(&beforeMatch);
	ZVAL_UNDEF(&converters);
	ZVAL_UNDEF(&converter);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&matchPosition);
	ZVAL_UNDEF(&strParams);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_7$$16);
	ZVAL_UNDEF(&_9$$19);
	ZVAL_UNDEF(&_11$$21);
	ZVAL_UNDEF(&_12$$21);
	ZVAL_UNDEF(&_13$$21);
	ZVAL_UNDEF(&_14$$21);
	ZVAL_UNDEF(&_16$$30);
	ZVAL_UNDEF(&_17$$31);
	ZVAL_UNDEF(&_19$$33);
	ZVAL_UNDEF(&_3$$9);
	ZVAL_UNDEF(&_8$$16);
	ZVAL_UNDEF(&_10$$19);
	ZVAL_UNDEF(&_15$$30);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &arguments);

	if (!arguments) {
		arguments = &arguments_sub;
		arguments = &__$null;
	}


	ZEPHIR_INIT_VAR(&routeFound);
	ZVAL_BOOL(&routeFound, 0);
	ZEPHIR_INIT_VAR(&parts);
	array_init(&parts);
	ZEPHIR_INIT_VAR(&params);
	array_init(&params);
	ZEPHIR_INIT_VAR(&matches);
	ZVAL_NULL(&matches);
	if (0) {
		zephir_update_property_zval(this_ptr, SL("wasMatched"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("wasMatched"), &__$false);
	}
	zephir_update_property_zval(this_ptr, SL("matchedRoute"), &__$null);
	if (Z_TYPE_P(arguments) != IS_ARRAY) {
		_0$$3 = Z_TYPE_P(arguments) != IS_STRING;
		if (_0$$3) {
			_0$$3 = Z_TYPE_P(arguments) != IS_NULL;
		}
		if (UNEXPECTED(_0$$3)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cli_router_exception_ce, "Arguments must be an array or string", "phalcon/Cli/Router.zep", 243);
			return;
		}
		zephir_read_property(&_1$$3, this_ptr, SL("routes"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_1$$3, 0, "phalcon/Cli/Router.zep", 354);
		ZEND_HASH_REVERSE_FOREACH_VAL(Z_ARRVAL_P(&_1$$3), _2$$3)
		{
			ZEPHIR_INIT_NVAR(&route);
			ZVAL_COPY(&route, _2$$3);
			ZEPHIR_CALL_METHOD(&pattern, &route, "getcompiledpattern", NULL, 0);
			zephir_check_call_status();
			if (zephir_memnstr_str(&pattern, SL("^"), "phalcon/Cli/Router.zep", 252)) {
				ZEPHIR_INIT_NVAR(&routeFound);
				zephir_preg_match(&routeFound, &pattern, arguments, &matches, 0, 0 , 0  TSRMLS_CC);
			} else {
				ZEPHIR_INIT_NVAR(&routeFound);
				ZVAL_BOOL(&routeFound, ZEPHIR_IS_EQUAL(&pattern, arguments));
			}
			if (zephir_is_true(&routeFound)) {
				ZEPHIR_CALL_METHOD(&beforeMatch, &route, "getbeforematch", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&beforeMatch) != IS_NULL) {
					if (UNEXPECTED(!(zephir_is_callable(&beforeMatch TSRMLS_CC)))) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_cli_router_exception_ce, "Before-Match callback is not callable in matched route", "phalcon/Cli/Router.zep", 271);
						return;
					}
					ZEPHIR_INIT_NVAR(&_3$$9);
					zephir_create_array(&_3$$9, 3, 0 TSRMLS_CC);
					zephir_array_fast_append(&_3$$9, arguments);
					zephir_array_fast_append(&_3$$9, &route);
					zephir_array_fast_append(&_3$$9, this_ptr);
					ZEPHIR_INIT_NVAR(&routeFound);
					ZEPHIR_CALL_USER_FUNC_ARRAY(&routeFound, &beforeMatch, &_3$$9);
					zephir_check_call_status();
				}
			}
			if (zephir_is_true(&routeFound)) {
				ZEPHIR_CALL_METHOD(&paths, &route, "getpaths", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&parts, &paths);
				if (Z_TYPE_P(&matches) == IS_ARRAY) {
					ZEPHIR_CALL_METHOD(&converters, &route, "getconverters", NULL, 0);
					zephir_check_call_status();
					zephir_is_iterable(&paths, 0, "phalcon/Cli/Router.zep", 341);
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&paths), _5$$12, _6$$12, _4$$12)
					{
						ZEPHIR_INIT_NVAR(&part);
						if (_6$$12 != NULL) { 
							ZVAL_STR_COPY(&part, _6$$12);
						} else {
							ZVAL_LONG(&part, _5$$12);
						}
						ZEPHIR_INIT_NVAR(&position);
						ZVAL_COPY(&position, _4$$12);
						ZEPHIR_OBS_NVAR(&matchPosition);
						if (zephir_array_isset_fetch(&matchPosition, &matches, &position, 0 TSRMLS_CC)) {
							if (Z_TYPE_P(&converters) == IS_ARRAY) {
								ZEPHIR_OBS_NVAR(&converter);
								if (zephir_array_isset_fetch(&converter, &converters, &part, 0 TSRMLS_CC)) {
									ZEPHIR_INIT_NVAR(&_7$$16);
									ZEPHIR_INIT_NVAR(&_8$$16);
									zephir_create_array(&_8$$16, 1, 0 TSRMLS_CC);
									zephir_array_fast_append(&_8$$16, &matchPosition);
									ZEPHIR_CALL_USER_FUNC_ARRAY(&_7$$16, &converter, &_8$$16);
									zephir_check_call_status();
									zephir_array_update_zval(&parts, &part, &_7$$16, PH_COPY | PH_SEPARATE);
									continue;
								}
							}
							zephir_array_update_zval(&parts, &part, &matchPosition, PH_COPY | PH_SEPARATE);
						} else {
							if (Z_TYPE_P(&converters) == IS_ARRAY) {
								ZEPHIR_OBS_NVAR(&converter);
								if (zephir_array_isset_fetch(&converter, &converters, &part, 0 TSRMLS_CC)) {
									ZEPHIR_INIT_NVAR(&_9$$19);
									ZEPHIR_INIT_NVAR(&_10$$19);
									zephir_create_array(&_10$$19, 1, 0 TSRMLS_CC);
									zephir_array_fast_append(&_10$$19, &position);
									ZEPHIR_CALL_USER_FUNC_ARRAY(&_9$$19, &converter, &_10$$19);
									zephir_check_call_status();
									zephir_array_update_zval(&parts, &part, &_9$$19, PH_COPY | PH_SEPARATE);
								}
							}
						}
					} ZEND_HASH_FOREACH_END();
					ZEPHIR_INIT_NVAR(&position);
					ZEPHIR_INIT_NVAR(&part);
					zephir_update_property_zval(this_ptr, SL("matches"), &matches);
				}
				zephir_update_property_zval(this_ptr, SL("matchedRoute"), &route);
				break;
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&route);
		if (zephir_is_true(&routeFound)) {
			if (1) {
				zephir_update_property_zval(this_ptr, SL("wasMatched"), &__$true);
			} else {
				zephir_update_property_zval(this_ptr, SL("wasMatched"), &__$false);
			}
		} else {
			if (0) {
				zephir_update_property_zval(this_ptr, SL("wasMatched"), &__$true);
			} else {
				zephir_update_property_zval(this_ptr, SL("wasMatched"), &__$false);
			}
			zephir_read_property(&_11$$21, this_ptr, SL("defaultModule"), PH_NOISY_CC | PH_READONLY);
			zephir_update_property_zval(this_ptr, SL("module"), &_11$$21);
			zephir_read_property(&_12$$21, this_ptr, SL("defaultTask"), PH_NOISY_CC | PH_READONLY);
			zephir_update_property_zval(this_ptr, SL("task"), &_12$$21);
			zephir_read_property(&_13$$21, this_ptr, SL("defaultAction"), PH_NOISY_CC | PH_READONLY);
			zephir_update_property_zval(this_ptr, SL("action"), &_13$$21);
			zephir_read_property(&_14$$21, this_ptr, SL("defaultParams"), PH_NOISY_CC | PH_READONLY);
			zephir_update_property_zval(this_ptr, SL("params"), &_14$$21);
			RETURN_THIS();
		}
	} else {
		ZEPHIR_CPY_WRT(&parts, arguments);
	}
	ZEPHIR_INIT_VAR(&moduleName);
	ZVAL_NULL(&moduleName);
	ZEPHIR_INIT_VAR(&taskName);
	ZVAL_NULL(&taskName);
	ZEPHIR_INIT_VAR(&actionName);
	ZVAL_NULL(&actionName);
	ZEPHIR_OBS_NVAR(&moduleName);
	if (zephir_array_isset_string_fetch(&moduleName, &parts, SL("module"), 0)) {
		zephir_array_unset_string(&parts, SL("module"), PH_SEPARATE);
	} else {
		ZEPHIR_OBS_NVAR(&moduleName);
		zephir_read_property(&moduleName, this_ptr, SL("defaultModule"), PH_NOISY_CC);
	}
	ZEPHIR_OBS_NVAR(&taskName);
	if (zephir_array_isset_string_fetch(&taskName, &parts, SL("task"), 0)) {
		zephir_array_unset_string(&parts, SL("task"), PH_SEPARATE);
	} else {
		ZEPHIR_OBS_NVAR(&taskName);
		zephir_read_property(&taskName, this_ptr, SL("defaultTask"), PH_NOISY_CC);
	}
	ZEPHIR_OBS_NVAR(&actionName);
	if (zephir_array_isset_string_fetch(&actionName, &parts, SL("action"), 0)) {
		zephir_array_unset_string(&parts, SL("action"), PH_SEPARATE);
	} else {
		ZEPHIR_OBS_NVAR(&actionName);
		zephir_read_property(&actionName, this_ptr, SL("defaultAction"), PH_NOISY_CC);
	}
	ZEPHIR_OBS_NVAR(&params);
	if (zephir_array_isset_string_fetch(&params, &parts, SL("params"), 0)) {
		if (Z_TYPE_P(&params) != IS_ARRAY) {
			zephir_get_strval(&_15$$30, &params);
			ZVAL_LONG(&_16$$30, 1);
			ZEPHIR_INIT_VAR(&strParams);
			zephir_substr(&strParams, &_15$$30, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			if (zephir_is_true(&strParams)) {
				ZEPHIR_CALL_CE_STATIC(&_17$$31, phalcon_cli_router_route_ce, "getdelimiter", &_18, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&params);
				zephir_fast_explode(&params, &_17$$31, &strParams, LONG_MAX TSRMLS_CC);
			} else {
				ZEPHIR_INIT_NVAR(&params);
				array_init(&params);
			}
		}
		zephir_array_unset_string(&parts, SL("params"), PH_SEPARATE);
	}
	if (zephir_fast_count_int(&params TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_19$$33);
		zephir_fast_array_merge(&_19$$33, &params, &parts TSRMLS_CC);
		ZEPHIR_CPY_WRT(&params, &_19$$33);
	} else {
		ZEPHIR_CPY_WRT(&params, &parts);
	}
	zephir_update_property_zval(this_ptr, SL("module"), &moduleName);
	zephir_update_property_zval(this_ptr, SL("task"), &taskName);
	zephir_update_property_zval(this_ptr, SL("action"), &actionName);
	zephir_update_property_zval(this_ptr, SL("params"), &params);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the default action name
 */
PHP_METHOD(Phalcon_Cli_Router, setDefaultAction) {

	zval *actionName_param = NULL;
	zval actionName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&actionName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &actionName_param);

	zephir_get_strval(&actionName, actionName_param);


	zephir_update_property_zval(this_ptr, SL("defaultAction"), &actionName);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the name of the default module
 */
PHP_METHOD(Phalcon_Cli_Router, setDefaultModule) {

	zval *moduleName_param = NULL;
	zval moduleName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&moduleName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &moduleName_param);

	zephir_get_strval(&moduleName, moduleName_param);


	zephir_update_property_zval(this_ptr, SL("defaultModule"), &moduleName);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets an array of default paths. If a route is missing a path the router
 * will use the defined here. This method must not be used to set a 404
 * route
 *
 *<code>
 * $router->setDefaults(
 *     [
 *         "module" => "common",
 *         "action" => "index",
 *     ]
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Cli_Router, setDefaults) {

	zval *defaults_param = NULL, module, task, action, params;
	zval defaults;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaults);
	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&task);
	ZVAL_UNDEF(&action);
	ZVAL_UNDEF(&params);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &defaults_param);

	ZEPHIR_OBS_COPY_OR_DUP(&defaults, defaults_param);


	if (zephir_array_isset_string_fetch(&module, &defaults, SL("module"), 1)) {
		zephir_update_property_zval(this_ptr, SL("defaultModule"), &module);
	}
	if (zephir_array_isset_string_fetch(&task, &defaults, SL("task"), 1)) {
		zephir_update_property_zval(this_ptr, SL("defaultTask"), &task);
	}
	if (zephir_array_isset_string_fetch(&action, &defaults, SL("action"), 1)) {
		zephir_update_property_zval(this_ptr, SL("defaultAction"), &action);
	}
	if (zephir_array_isset_string_fetch(&params, &defaults, SL("params"), 1)) {
		zephir_update_property_zval(this_ptr, SL("defaultParams"), &params);
	}
	RETURN_THIS();

}

/**
 * Sets the default controller name
 */
PHP_METHOD(Phalcon_Cli_Router, setDefaultTask) {

	zval *taskName_param = NULL;
	zval taskName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&taskName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &taskName_param);

	zephir_get_strval(&taskName, taskName_param);


	zephir_update_property_zval(this_ptr, SL("defaultTask"), &taskName);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the dependency injector
 */
PHP_METHOD(Phalcon_Cli_Router, setDI) {

	zval *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);

	zephir_fetch_params(0, 1, 0, &container);



	zephir_update_property_zval(this_ptr, SL("container"), container);

}

/**
 * Checks if the router matches any of the defined routes
 */
PHP_METHOD(Phalcon_Cli_Router, wasMatched) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "wasMatched");

}

zend_object *zephir_init_properties_Phalcon_Cli_Router(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("params"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("params"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("defaultParams"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("defaultParams"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}


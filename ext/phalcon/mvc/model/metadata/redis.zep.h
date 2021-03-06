
extern zend_class_entry *phalcon_mvc_model_metadata_redis_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Redis);

PHP_METHOD(Phalcon_Mvc_Model_MetaData_Redis, __construct);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Redis, reset);
zend_object *zephir_init_properties_Phalcon_Mvc_Model_MetaData_Redis(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_redis___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, factory, Phalcon\\Cache\\AdapterFactory, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_metadata_redis_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_MetaData_Redis, __construct, arginfo_phalcon_mvc_model_metadata_redis___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Redis, reset, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

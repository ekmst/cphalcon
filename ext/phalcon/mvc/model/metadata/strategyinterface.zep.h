
extern zend_class_entry *phalcon_mvc_model_metadata_strategyinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData_StrategyInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_strategyinterface_getcolumnmaps, 0, 2, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_strategyinterface_getcolumnmaps, 0, 2, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_strategyinterface_getmetadata, 0, 2, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_strategyinterface_getmetadata, 0, 2, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_metadata_strategyinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaData_StrategyInterface, getColumnMaps, arginfo_phalcon_mvc_model_metadata_strategyinterface_getcolumnmaps)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_MetaData_StrategyInterface, getMetaData, arginfo_phalcon_mvc_model_metadata_strategyinterface_getmetadata)
	PHP_FE_END
};

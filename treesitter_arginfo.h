/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 67b3875364f02871ba22e30a9e7e106fbf376f95 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_TreeSitter_Grammar___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_TreeSitter_Parser___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, grammar, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_TreeSitter_Parser_parse, 0, 1, TreeSitter\\Tree, 0)
	ZEND_ARG_TYPE_INFO(0, source_code, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_TreeSitter_Tree_getRootNode, 0, 0, TreeSitter\\\116ode, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_TreeSitter_Node_getType, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_TreeSitter_Node_hasChildren, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_TreeSitter_Node_countChildren, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_TreeSitter_Node_getStartByte arginfo_class_TreeSitter_Node_countChildren

#define arginfo_class_TreeSitter_Node_getEndByte arginfo_class_TreeSitter_Node_countChildren

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_TreeSitter_Node_getStartPoint, 0, 0, TreeSitter\\Point, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_TreeSitter_Node_getEndPoint arginfo_class_TreeSitter_Node_getStartPoint

#define arginfo_class_TreeSitter_Node___toString arginfo_class_TreeSitter_Node_getType


ZEND_METHOD(TreeSitter_Grammar, __construct);
ZEND_METHOD(TreeSitter_Parser, __construct);
ZEND_METHOD(TreeSitter_Parser, parse);
ZEND_METHOD(TreeSitter_Tree, getRootNode);
ZEND_METHOD(TreeSitter_Node, getType);
ZEND_METHOD(TreeSitter_Node, hasChildren);
ZEND_METHOD(TreeSitter_Node, countChildren);
ZEND_METHOD(TreeSitter_Node, getStartByte);
ZEND_METHOD(TreeSitter_Node, getEndByte);
ZEND_METHOD(TreeSitter_Node, getStartPoint);
ZEND_METHOD(TreeSitter_Node, getEndPoint);
ZEND_METHOD(TreeSitter_Node, __toString);


static const zend_function_entry class_TreeSitter_Grammar_methods[] = {
	ZEND_ME(TreeSitter_Grammar, __construct, arginfo_class_TreeSitter_Grammar___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_TreeSitter_Parser_methods[] = {
	ZEND_ME(TreeSitter_Parser, __construct, arginfo_class_TreeSitter_Parser___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(TreeSitter_Parser, parse, arginfo_class_TreeSitter_Parser_parse, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_TreeSitter_Tree_methods[] = {
	ZEND_ME(TreeSitter_Tree, getRootNode, arginfo_class_TreeSitter_Tree_getRootNode, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_TreeSitter_Node_methods[] = {
	ZEND_ME(TreeSitter_Node, getType, arginfo_class_TreeSitter_Node_getType, ZEND_ACC_PUBLIC)
	ZEND_ME(TreeSitter_Node, hasChildren, arginfo_class_TreeSitter_Node_hasChildren, ZEND_ACC_PUBLIC)
	ZEND_ME(TreeSitter_Node, countChildren, arginfo_class_TreeSitter_Node_countChildren, ZEND_ACC_PUBLIC)
	ZEND_ME(TreeSitter_Node, getStartByte, arginfo_class_TreeSitter_Node_getStartByte, ZEND_ACC_PUBLIC)
	ZEND_ME(TreeSitter_Node, getEndByte, arginfo_class_TreeSitter_Node_getEndByte, ZEND_ACC_PUBLIC)
	ZEND_ME(TreeSitter_Node, getStartPoint, arginfo_class_TreeSitter_Node_getStartPoint, ZEND_ACC_PUBLIC)
	ZEND_ME(TreeSitter_Node, getEndPoint, arginfo_class_TreeSitter_Node_getEndPoint, ZEND_ACC_PUBLIC)
	ZEND_ME(TreeSitter_Node, __toString, arginfo_class_TreeSitter_Node___toString, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};


static const zend_function_entry class_TreeSitter_Point_methods[] = {
	ZEND_FE_END
};


static const zend_function_entry class_TreeSitter_SyntaxError_methods[] = {
	ZEND_FE_END
};

static zend_class_entry *register_class_TreeSitter_Grammar(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "TreeSitter", "Grammar", class_TreeSitter_Grammar_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_NO_DYNAMIC_PROPERTIES|ZEND_ACC_NOT_SERIALIZABLE;

	zval const_PHP_value;
	ZVAL_LONG(&const_PHP_value, PHP_TREESITTER_GRAMMAR_PHP);
	zend_string *const_PHP_name = zend_string_init_interned("PHP", sizeof("PHP") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_PHP_name, &const_PHP_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_PHP_name);

	zval const_HTML_value;
	ZVAL_LONG(&const_HTML_value, PHP_TREESITTER_GRAMMAR_HTML);
	zend_string *const_HTML_name = zend_string_init_interned("HTML", sizeof("HTML") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_HTML_name, &const_HTML_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_HTML_name);

	zval const_CSS_value;
	ZVAL_LONG(&const_CSS_value, PHP_TREESITTER_GRAMMAR_CSS);
	zend_string *const_CSS_name = zend_string_init_interned("CSS", sizeof("CSS") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_CSS_name, &const_CSS_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_CSS_name);

	zval const_JAVASCRIPT_value;
	ZVAL_LONG(&const_JAVASCRIPT_value, PHP_TREESITTER_GRAMMAR_JAVASCRIPT);
	zend_string *const_JAVASCRIPT_name = zend_string_init_interned("JAVASCRIPT", sizeof("JAVASCRIPT") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_JAVASCRIPT_name, &const_JAVASCRIPT_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_JAVASCRIPT_name);

	zval const_TYPESCRIPT_value;
	ZVAL_LONG(&const_TYPESCRIPT_value, PHP_TREESITTER_GRAMMAR_TYPESCRIPT);
	zend_string *const_TYPESCRIPT_name = zend_string_init_interned("TYPESCRIPT", sizeof("TYPESCRIPT") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_TYPESCRIPT_name, &const_TYPESCRIPT_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_TYPESCRIPT_name);

	zval const_PYTHON_value;
	ZVAL_LONG(&const_PYTHON_value, PHP_TREESITTER_GRAMMAR_PYTHON);
	zend_string *const_PYTHON_name = zend_string_init_interned("PYTHON", sizeof("PYTHON") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_PYTHON_name, &const_PYTHON_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_PYTHON_name);

	zval const_JSON_value;
	ZVAL_LONG(&const_JSON_value, PHP_TREESITTER_GRAMMAR_JSON);
	zend_string *const_JSON_name = zend_string_init_interned("JSON", sizeof("JSON") - 1, 1);
	zend_declare_typed_class_constant(class_entry, const_JSON_name, &const_JSON_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(const_JSON_name);

	return class_entry;
}

static zend_class_entry *register_class_TreeSitter_Parser(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "TreeSitter", "Parser", class_TreeSitter_Parser_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_NO_DYNAMIC_PROPERTIES|ZEND_ACC_NOT_SERIALIZABLE;

	return class_entry;
}

static zend_class_entry *register_class_TreeSitter_Tree(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "TreeSitter", "Tree", class_TreeSitter_Tree_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_NO_DYNAMIC_PROPERTIES|ZEND_ACC_NOT_SERIALIZABLE;

	return class_entry;
}

static zend_class_entry *register_class_TreeSitter_Node(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "TreeSitter", "Node", class_TreeSitter_Node_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_NO_DYNAMIC_PROPERTIES|ZEND_ACC_NOT_SERIALIZABLE;

	return class_entry;
}

static zend_class_entry *register_class_TreeSitter_Point(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "TreeSitter", "Point", class_TreeSitter_Point_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL|ZEND_ACC_NO_DYNAMIC_PROPERTIES|ZEND_ACC_NOT_SERIALIZABLE;

	zval property_row_default_value;
	ZVAL_UNDEF(&property_row_default_value);
	zend_string *property_row_name = zend_string_init("row", sizeof("row") - 1, 1);
	zend_declare_typed_property(class_entry, property_row_name, &property_row_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_row_name);

	zval property_column_default_value;
	ZVAL_UNDEF(&property_column_default_value);
	zend_string *property_column_name = zend_string_init("column", sizeof("column") - 1, 1);
	zend_declare_typed_property(class_entry, property_column_name, &property_column_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_column_name);

	return class_entry;
}

static zend_class_entry *register_class_TreeSitter_SyntaxError(zend_class_entry *class_entry_TreeSitter_Exception)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "TreeSitter", "SyntaxError", class_TreeSitter_SyntaxError_methods);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_TreeSitter_Exception);
	class_entry->ce_flags |= ZEND_ACC_FINAL;

	return class_entry;
}

/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: aef0141b733f4fdc5f965fd9d128c52a10d3efa8 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_TreeSitter_Grammar___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_TreeSitter_Parser___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, grammar, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_TreeSitter_Parser_parse, 0, 1, TreeSitter\\Tree, 0)
	ZEND_ARG_TYPE_INFO(0, source_code, IS_STRING, 0)
ZEND_END_ARG_INFO()


ZEND_METHOD(TreeSitter_Grammar, __construct);
ZEND_METHOD(TreeSitter_Parser, __construct);
ZEND_METHOD(TreeSitter_Parser, parse);


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
	ZEND_FE_END
};


static const zend_function_entry class_TreeSitter_Node_methods[] = {
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
	class_entry->ce_flags |= ZEND_ACC_NO_DYNAMIC_PROPERTIES|ZEND_ACC_NOT_SERIALIZABLE;

	return class_entry;
}

static zend_class_entry *register_class_TreeSitter_Tree(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "TreeSitter", "Tree", class_TreeSitter_Tree_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_NO_DYNAMIC_PROPERTIES|ZEND_ACC_NOT_SERIALIZABLE;

	return class_entry;
}

static zend_class_entry *register_class_TreeSitter_Node(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "TreeSitter", "Node", class_TreeSitter_Node_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_NO_DYNAMIC_PROPERTIES|ZEND_ACC_NOT_SERIALIZABLE;

	return class_entry;
}

/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 6bd55c8efcb74a321e2a09d7db4b5e55d9d5738b */




static const zend_function_entry class_TreeSitter_Grammar_methods[] = {
	ZEND_FE_END
};

static zend_class_entry *register_class_TreeSitter_Grammar(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "TreeSitter", "Grammar", class_TreeSitter_Grammar_methods);
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL;

	zval const_PHP_value;
	ZVAL_LONG(&const_PHP_value, 7366768);
	zend_string *const_PHP_name = zend_string_init_interned("PHP", sizeof("PHP") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_PHP_name, &const_PHP_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_PHP_name);

	zval const_HTML_value;
	ZVAL_LONG(&const_HTML_value, 1752460652);
	zend_string *const_HTML_name = zend_string_init_interned("HTML", sizeof("HTML") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_HTML_name, &const_HTML_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_HTML_name);

	zval const_CSS_value;
	ZVAL_LONG(&const_CSS_value, 6517619);
	zend_string *const_CSS_name = zend_string_init_interned("CSS", sizeof("CSS") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_CSS_name, &const_CSS_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_CSS_name);

	zval const_JAVASCRIPT_value;
	ZVAL_LONG(&const_JAVASCRIPT_value, 27251);
	zend_string *const_JAVASCRIPT_name = zend_string_init_interned("JAVASCRIPT", sizeof("JAVASCRIPT") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_JAVASCRIPT_name, &const_JAVASCRIPT_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_JAVASCRIPT_name);

	zval const_TYPESCRIPT_value;
	ZVAL_LONG(&const_TYPESCRIPT_value, 29811);
	zend_string *const_TYPESCRIPT_name = zend_string_init_interned("TYPESCRIPT", sizeof("TYPESCRIPT") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_TYPESCRIPT_name, &const_TYPESCRIPT_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_TYPESCRIPT_name);

	zval const_PYTHON_value;
	ZVAL_LONG(&const_PYTHON_value, 123666946355054);
	zend_string *const_PYTHON_name = zend_string_init_interned("PYTHON", sizeof("PYTHON") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_PYTHON_name, &const_PYTHON_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_PYTHON_name);

	zval const_JSON_value;
	ZVAL_LONG(&const_JSON_value, 1785950062);
	zend_string *const_JSON_name = zend_string_init_interned("JSON", sizeof("JSON") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_JSON_name, &const_JSON_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_JSON_name);

	return class_entry;
}

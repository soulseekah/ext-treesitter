#include "php.h"
#include "ext/standard/info.h"

#include "php_treesitter.h"
#include "treesitter_arginfo.h"

#include "tree_sitter/api.h"

const TSLanguage *tree_sitter_json(void);

PHP_FUNCTION(test1)
{
    ZEND_PARSE_PARAMETERS_NONE();

	TSParser *parser = ts_parser_new();

	ts_parser_set_language(parser, tree_sitter_json());

	const char *source_code = "[1, null]";
	TSTree *tree = ts_parser_parse_string(
		parser,
		NULL,
		source_code,
		strlen(source_code)
	);

	// Get the root node of the syntax tree.
	TSNode root_node = ts_tree_root_node(tree);

	// Get some child nodes.
	TSNode array_node = ts_node_named_child(root_node, 0);
	TSNode number_node = ts_node_named_child(array_node, 0);

	// Check that the nodes have the expected types.
	assert(strcmp(ts_node_type(root_node), "document") == 0);
	assert(strcmp(ts_node_type(array_node), "array") == 0);
	assert(strcmp(ts_node_type(number_node), "number") == 0);

	// Check that the nodes have the expected child counts.
	assert(ts_node_child_count(root_node) == 1);
	assert(ts_node_child_count(array_node) == 5);
	assert(ts_node_named_child_count(array_node) == 2);
	assert(ts_node_child_count(number_node) == 0);

	// Print the syntax tree as an S-expression.
	char *string = ts_node_string(root_node);
	php_printf("Syntax tree: %s\n", string);

	// Free all of the heap-allocated memory.
	free(string);
	ts_tree_delete(tree);
	ts_parser_delete(parser);
}

PHP_RINIT_FUNCTION(treesitter)
{
    return SUCCESS;
}

PHP_MINFO_FUNCTION(treesitter)
{
    php_info_print_table_start();
    php_info_print_table_row(2, "Tree sitter bindings", "available");
    php_info_print_table_end();
}

zend_module_entry treesitter_module_entry = {
	STANDARD_MODULE_HEADER,
    "treesitter",                   /* Extension name */
    ext_functions,                  /* zend_function_entry */
    NULL,                           /* PHP_MINIT - Module initialization */
    NULL,                           /* PHP_MSHUTDOWN - Module shutdown */
    PHP_RINIT(treesitter),          /* PHP_RINIT - Request initialization */
    NULL,                           /* PHP_RSHUTDOWN - Request shutdown */
    PHP_MINFO(treesitter),          /* PHP_MINFO - Module info */
    PHP_TREESITTER_VERSION,         /* Version */
    STANDARD_MODULE_PROPERTIES
};

ZEND_GET_MODULE(treesitter)

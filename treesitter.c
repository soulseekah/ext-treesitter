#include "php.h"
#include "ext/standard/info.h"

#include "php_treesitter.h"
#include "treesitter_arginfo.h"

#include "tree_sitter/api.h"

#include "lib/parsers/parsers.h"

static zend_class_entry *php_treesitter_grammar_ce = NULL;
static zend_object_handlers php_treesitter_grammar_handlers;
static zend_object *php_treesitter_grammar_object = NULL;

static zend_object *php_treesitter_grammar_object_create(zend_class_entry *ce)
{
    zend_object *php_treesitter_grammar_object = zend_object_alloc(sizeof(zend_object), ce);

    zend_object_std_init(php_treesitter_grammar_object, ce);
    object_properties_init(php_treesitter_grammar_object, ce);
    php_treesitter_grammar_object->handlers = &php_treesitter_grammar_handlers;

    return php_treesitter_grammar_object;
}

static zend_function *php_treesitter_grammar_object_get_constructor(zend_object *object)
{
    zend_throw_error(NULL, "TreeSitter\\Grammar class is non-instantiable");
    return NULL;
}

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

PHP_MINIT_FUNCTION(treesitter)
{
	php_treesitter_grammar_ce = register_class_TreeSitter_Grammar();
	php_treesitter_grammar_ce->create_object = php_treesitter_grammar_object_create;

	memcpy(&php_treesitter_grammar_handlers, &std_object_handlers, sizeof(zend_object_handlers));
    php_treesitter_grammar_handlers.clone_obj = NULL;
    php_treesitter_grammar_handlers.get_constructor = php_treesitter_grammar_object_get_constructor;

    return SUCCESS;
}

PHP_MINFO_FUNCTION(treesitter)
{
    char ts_abi_version[4];
    sprintf(ts_abi_version, "%d", TREE_SITTER_LANGUAGE_VERSION);

    php_info_print_table_start();
    php_info_print_table_row(2, "Version", PHP_TREESITTER_VERSION "-unstable");
    php_info_print_table_row(2, "Tree-sitter ABI", ts_abi_version);
    php_info_print_table_row(2, "Parsers", "PHP HTML CSS JAVASCRIPT TYPESCRIPT PYTHON JSON");
    php_info_print_table_end();
}

zend_module_entry treesitter_module_entry = {
    STANDARD_MODULE_HEADER,
    "treesitter",                   /* Extension name */
    NULL,                           /* zend_function_entry */
    PHP_MINIT(treesitter),                           /* PHP_MINIT - Module initialization */
    NULL,                           /* PHP_MSHUTDOWN - Module shutdown */
    NULL,                           /* PHP_RINIT - Request initialization */
    NULL,                           /* PHP_RSHUTDOWN - Request shutdown */
    PHP_MINFO(treesitter),          /* PHP_MINFO - Module info */
    PHP_TREESITTER_VERSION,         /* Version */
    STANDARD_MODULE_PROPERTIES
};

ZEND_GET_MODULE(treesitter)

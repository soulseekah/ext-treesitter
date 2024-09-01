#include "php.h"
#include "ext/standard/info.h"

#include "tree_sitter/api.h"

#include "php_treesitter.h"
#include "lib/parsers/parsers.h"
#include "treesitter_arginfo.h"

static zend_class_entry *php_treesitter_grammar_ce = NULL;
static zend_class_entry *php_treesitter_parser_ce = NULL;
static zend_class_entry *php_treesitter_tree_ce = NULL;
static zend_class_entry *php_treesitter_node_ce = NULL;

static zend_object_handlers php_treesitter_grammar_handlers;
static zend_object_handlers php_treesitter_parser_handlers;
static zend_object_handlers php_treesitter_tree_handlers;
static zend_object_handlers php_treesitter_node_handlers;

typedef struct {
    int _; // TODO: remove, experimental
    TSParser *parser;
    int __; // TODO: remove, experimental
    const TSLanguage *grammar;
    zend_object std;
} php_treesitter_parser_object;

static inline php_treesitter_parser_object *php_treesitter_parser_object_from_zend_object(zend_object *obj) {
    return (php_treesitter_parser_object *)((char *)obj - XtOffsetOf(php_treesitter_parser_object, std));
}

static zend_object *php_treesitter_grammar_object_create(zend_class_entry *ce)
{
    zend_object *php_treesitter_grammar_object = zend_object_alloc(sizeof(zend_object), ce);

    zend_object_std_init(php_treesitter_grammar_object, ce);
    object_properties_init(php_treesitter_grammar_object, ce);
    php_treesitter_grammar_object->handlers = &php_treesitter_grammar_handlers;

    return php_treesitter_grammar_object;
}

static zend_object *php_treesitter_parser_object_create(zend_class_entry *ce)
{
    php_treesitter_parser_object *obj = zend_object_alloc(sizeof(php_treesitter_parser_object), ce);

    obj->parser = ts_parser_new();

    zend_object_std_init(&obj->std, ce);
    object_properties_init(&obj->std, ce);

    return &obj->std;
}

ZEND_METHOD(TreeSitter_Grammar, __construct)
{
    zend_throw_error(NULL, "%s class is non-instantiable", ZSTR_VAL(Z_OBJCE_P(ZEND_THIS)->name));
    RETURN_THROWS();
}

ZEND_METHOD(TreeSitter_Parser, __construct)
{
    zval *grammar;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_NUMBER(grammar)
    ZEND_PARSE_PARAMETERS_END();

    php_treesitter_parser_object *parser = php_treesitter_parser_object_from_zend_object(Z_OBJ_P(ZEND_THIS));

    switch (Z_LVAL_P(grammar)) {
        case PHP_TREESITTER_GRAMMAR_PHP:
            parser->grammar = tree_sitter_php();
            break;
        case PHP_TREESITTER_GRAMMAR_HTML:
            parser->grammar = tree_sitter_html();
            break;
        case PHP_TREESITTER_GRAMMAR_CSS:
            parser->grammar = tree_sitter_css();
            break;
        case PHP_TREESITTER_GRAMMAR_JAVASCRIPT:
            parser->grammar = tree_sitter_javascript();
            break;
        case PHP_TREESITTER_GRAMMAR_TYPESCRIPT:
            parser->grammar = tree_sitter_typescript();
            break;
        case PHP_TREESITTER_GRAMMAR_PYTHON:
            parser->grammar = tree_sitter_python();
            break;
        case PHP_TREESITTER_GRAMMAR_JSON:
            parser->grammar = tree_sitter_json();
            break;
        default:
            zend_throw_error(NULL, "Unknown grammar");
            RETURN_THROWS();
    }

    ts_parser_set_language(parser->parser, parser->grammar);
}

ZEND_METHOD(TreeSitter_Parser, parse)
{
    zend_string *source_code;

    php_treesitter_parser_object *parser = php_treesitter_parser_object_from_zend_object(Z_OBJ_P(ZEND_THIS));

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(source_code)
    ZEND_PARSE_PARAMETERS_END();

    TSTree *tree = ts_parser_parse_string(
        parser->parser,
        NULL,
        ZSTR_VAL(source_code),
        ZSTR_LEN(source_code)
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
    ts_parser_delete(parser->parser); // TODO: free on object deletion
}

PHP_MINIT_FUNCTION(treesitter)
{
    php_treesitter_grammar_ce = register_class_TreeSitter_Grammar();
    php_treesitter_grammar_ce->create_object = php_treesitter_grammar_object_create;

    memcpy(&php_treesitter_grammar_handlers, &std_object_handlers, sizeof(zend_object_handlers));
    php_treesitter_grammar_handlers.clone_obj = NULL;

    php_treesitter_parser_ce = register_class_TreeSitter_Parser();
    php_treesitter_parser_ce->create_object = php_treesitter_parser_object_create;

    memcpy(&php_treesitter_parser_handlers, &std_object_handlers, sizeof(zend_object_handlers));

    // TODO: tree, node

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
    PHP_MINIT(treesitter),          /* PHP_MINIT - Module initialization */
    NULL,                           /* PHP_MSHUTDOWN - Module shutdown */
    NULL,                           /* PHP_RINIT - Request initialization */
    NULL,                           /* PHP_RSHUTDOWN - Request shutdown */
    PHP_MINFO(treesitter),          /* PHP_MINFO - Module info */
    PHP_TREESITTER_VERSION,         /* Version */
    STANDARD_MODULE_PROPERTIES
};

ZEND_GET_MODULE(treesitter)

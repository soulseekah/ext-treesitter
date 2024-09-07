#include "tree_sitter/api.h"

#include "php_treesitter.h"
#include "lib/parsers/parsers.h"
#include "treesitter_arginfo.h"

/**
 * TODO
 *
 * To implement core:
 *    - ts_node_named_child
 *    - ts_node_is_named
 *    - ts_node_start_byte
 *    - ts_node_end_byte
 *    - ts_node_start_point
 *    - ts_node_end_point
 *  - ts_node_child
 *  - ts_node_next_sibling
 *  - ts_node_prev_sibling
 *  - ts_node_parent
 *  - ts_node_is_null
 *
 * To implement query:
 *
 *    - ts_query_new
 *    - ...
 */

static zend_class_entry *php_treesitter_grammar_ce = NULL;
static zend_object_handlers php_treesitter_grammar_handlers;

static zend_object *php_treesitter_grammar_object_create(zend_class_entry *ce)
{
    zend_object *php_treesitter_grammar_object = zend_object_alloc(sizeof(zend_object), ce);

    zend_object_std_init(php_treesitter_grammar_object, ce);
    object_properties_init(php_treesitter_grammar_object, ce);

    return php_treesitter_grammar_object;
}

ZEND_METHOD(TreeSitter_Grammar, __construct)
{
    zend_throw_error(NULL, "%s class is non-instantiable", ZSTR_VAL(Z_OBJCE_P(ZEND_THIS)->name));
    RETURN_THROWS();
}

static void php_treesitter_grammar_object_free(zend_object *obj)
{
    zend_object_std_dtor(obj);
}

static zend_class_entry *php_treesitter_point_ce = NULL;
static zend_object_handlers php_treesitter_point_handlers;

static zend_object *php_treesitter_point_object_create(zend_class_entry *ce)
{
    zend_object *php_treesitter_point_object = zend_object_alloc(sizeof(zend_object), ce);

    zend_object_std_init(php_treesitter_point_object, ce);
    object_properties_init(php_treesitter_point_object, ce);

    return php_treesitter_point_object;
}

ZEND_METHOD(TreeSitter_Point, __construct)
{
    zend_throw_error(NULL, "%s class is non-instantiable", ZSTR_VAL(Z_OBJCE_P(ZEND_THIS)->name));
    RETURN_THROWS();
}

static void php_treesitter_point_object_free(zend_object *obj)
{
    zend_object_std_dtor(obj);
}

static zend_class_entry *php_treesitter_node_ce = NULL;
static zend_object_handlers php_treesitter_node_handlers;

typedef struct {
    TSNode node;
    zend_object std;
} php_treesitter_node_object;

static inline php_treesitter_node_object *php_treesitter_node_object_from_zend_object(zend_object *obj) {
    return (php_treesitter_node_object *)((char *)obj - XtOffsetOf(php_treesitter_node_object, std));
}

static zend_object *php_treesitter_node_object_create(zend_class_entry *ce)
{
    php_treesitter_node_object *obj = zend_object_alloc(sizeof(php_treesitter_node_object), ce);

    zend_object_std_init(&obj->std, ce);
    object_properties_init(&obj->std, ce);

    return &obj->std;
}

ZEND_METHOD(TreeSitter_Node, __construct)
{
    zend_throw_error(NULL, "%s class is non-instantiable", ZSTR_VAL(Z_OBJCE_P(ZEND_THIS)->name));
    RETURN_THROWS();
}

ZEND_METHOD(TreeSitter_Node, hasChildren)
{
    php_treesitter_node_object *node = php_treesitter_node_object_from_zend_object(Z_OBJ_P(ZEND_THIS));

    ZVAL_BOOL(return_value, ts_node_child_count(node->node) > 0);
}

ZEND_METHOD(TreeSitter_Node, countChildren)
{
    php_treesitter_node_object *node = php_treesitter_node_object_from_zend_object(Z_OBJ_P(ZEND_THIS));

    ZVAL_LONG(return_value, ts_node_child_count(node->node));
}

ZEND_METHOD(TreeSitter_Node, getType)
{
    php_treesitter_node_object *node = php_treesitter_node_object_from_zend_object(Z_OBJ_P(ZEND_THIS));

    const char *type = ts_node_type(node->node);

    zend_string *return_string = zend_string_init(type, strlen(type), 0);
    RETURN_NEW_STR(return_string);
}

ZEND_METHOD(TreeSitter_Node, getStartByte)
{
    php_treesitter_node_object *node = php_treesitter_node_object_from_zend_object(Z_OBJ_P(ZEND_THIS));

    ZVAL_LONG(return_value, ts_node_start_byte(node->node));
}

ZEND_METHOD(TreeSitter_Node, getEndByte)
{
    php_treesitter_node_object *node = php_treesitter_node_object_from_zend_object(Z_OBJ_P(ZEND_THIS));

    ZVAL_LONG(return_value, ts_node_end_byte(node->node));
}

ZEND_METHOD(TreeSitter_Node, getStartPoint)
{
    php_treesitter_node_object *node = php_treesitter_node_object_from_zend_object(Z_OBJ_P(ZEND_THIS));

    TSPoint point = ts_node_start_point(node->node);

    object_init_ex(return_value, php_treesitter_point_ce);

	add_property_long(return_value, "row", point.row);
	add_property_long(return_value, "column", point.column);
}

ZEND_METHOD(TreeSitter_Node, getEndPoint)
{
    php_treesitter_node_object *node = php_treesitter_node_object_from_zend_object(Z_OBJ_P(ZEND_THIS));

    TSPoint point = ts_node_end_point(node->node);

    object_init_ex(return_value, php_treesitter_point_ce);

	add_property_long(return_value, "row", point.row);
	add_property_long(return_value, "column", point.column);
}

ZEND_METHOD(TreeSitter_Node, __toString)
{
    php_treesitter_node_object *node = php_treesitter_node_object_from_zend_object(Z_OBJ_P(ZEND_THIS));

    char *string = ts_node_string(node->node);

    zend_string *return_string = zend_string_init(string, strlen(string), 0);
    RETURN_NEW_STR(return_string);

    free(string);
}

static void php_treesitter_node_object_free(zend_object *obj)
{
    zend_object_std_dtor(obj);
}

static zend_class_entry *php_treesitter_tree_ce = NULL;
static zend_object_handlers php_treesitter_tree_handlers;

typedef struct {
    TSTree *tree;
    zend_object std;
} php_treesitter_tree_object;

static inline php_treesitter_tree_object *php_treesitter_tree_object_from_zend_object(zend_object *obj) {
    return (php_treesitter_tree_object *)((char *)obj - XtOffsetOf(php_treesitter_tree_object, std));
}

static zend_object *php_treesitter_tree_object_create(zend_class_entry *ce)
{
    php_treesitter_tree_object *obj = zend_object_alloc(sizeof(php_treesitter_tree_object), ce);

    zend_object_std_init(&obj->std, ce);
    object_properties_init(&obj->std, ce);

    return &obj->std;
}

ZEND_METHOD(TreeSitter_Tree, __construct)
{
    zend_throw_error(NULL, "%s class is non-instantiable", ZSTR_VAL(Z_OBJCE_P(ZEND_THIS)->name));
    RETURN_THROWS();
}

ZEND_METHOD(TreeSitter_Tree, getRootNode)
{
    php_treesitter_tree_object *tree = php_treesitter_tree_object_from_zend_object(Z_OBJ_P(ZEND_THIS));

    ZEND_PARSE_PARAMETERS_NONE();

    object_init_ex(return_value, php_treesitter_node_ce);

    php_treesitter_node_object *node = php_treesitter_node_object_from_zend_object(Z_OBJ_P(return_value));

    node->node = ts_tree_root_node(tree->tree);
}

static void php_treesitter_tree_object_free(zend_object *obj)
{
    php_treesitter_tree_object *tree = php_treesitter_tree_object_from_zend_object(obj);

    ts_tree_delete(tree->tree);

    zend_object_std_dtor(obj);
}

static zend_class_entry *php_treesitter_parser_ce = NULL;
static zend_object_handlers php_treesitter_parser_handlers;

typedef struct {
    TSParser *parser;
    zend_object std;
} php_treesitter_parser_object;

static inline php_treesitter_parser_object *php_treesitter_parser_object_from_zend_object(zend_object *obj) {
    return (php_treesitter_parser_object *)((char *)obj - XtOffsetOf(php_treesitter_parser_object, std));
}

static zend_object *php_treesitter_parser_object_create(zend_class_entry *ce)
{
    php_treesitter_parser_object *obj = zend_object_alloc(sizeof(php_treesitter_parser_object), ce);

    obj->parser = ts_parser_new();

    zend_object_std_init(&obj->std, ce);
    object_properties_init(&obj->std, ce);

    return &obj->std;
}

ZEND_METHOD(TreeSitter_Parser, __construct)
{
    // TODO: should grammar be an enum class instead?
    zval *grammar_param;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_NUMBER(grammar_param)
    ZEND_PARSE_PARAMETERS_END();

    php_treesitter_parser_object *parser = php_treesitter_parser_object_from_zend_object(Z_OBJ_P(ZEND_THIS));

    const TSLanguage *grammar;

    switch (Z_LVAL_P(grammar_param)) {
        case PHP_TREESITTER_GRAMMAR_PHP:
            grammar = tree_sitter_php();
            break;
        case PHP_TREESITTER_GRAMMAR_HTML:
            grammar = tree_sitter_html();
            break;
        case PHP_TREESITTER_GRAMMAR_CSS:
            grammar = tree_sitter_css();
            break;
        case PHP_TREESITTER_GRAMMAR_JAVASCRIPT:
            grammar = tree_sitter_javascript();
            break;
        case PHP_TREESITTER_GRAMMAR_TYPESCRIPT:
            grammar = tree_sitter_typescript();
            break;
        case PHP_TREESITTER_GRAMMAR_PYTHON:
            grammar = tree_sitter_python();
            break;
        case PHP_TREESITTER_GRAMMAR_JSON:
            grammar = tree_sitter_json();
            break;
        default:
            zend_throw_error(NULL, "Unknown grammar");
            RETURN_THROWS();
    }

    ts_parser_set_language(parser->parser, grammar);
}

ZEND_METHOD(TreeSitter_Parser, parse)
{
    zend_string *source_code;

    php_treesitter_parser_object *parser = php_treesitter_parser_object_from_zend_object(Z_OBJ_P(ZEND_THIS));

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(source_code)
    ZEND_PARSE_PARAMETERS_END();

    object_init_ex(return_value, php_treesitter_tree_ce);
    php_treesitter_tree_object *tree = php_treesitter_tree_object_from_zend_object(Z_OBJ_P(return_value));

    tree->tree = ts_parser_parse_string(
        parser->parser,
        NULL,
        ZSTR_VAL(source_code),
        ZSTR_LEN(source_code)
    );
}

static void php_treesitter_parser_object_free(zend_object *obj)
{
    php_treesitter_parser_object *parser = php_treesitter_parser_object_from_zend_object(obj);

    ts_parser_delete(parser->parser);

    zend_object_std_dtor(&parser->std);
}

PHP_MINIT_FUNCTION(treesitter)
{
    php_treesitter_grammar_ce = register_class_TreeSitter_Grammar();
    php_treesitter_grammar_ce->default_object_handlers = &php_treesitter_grammar_handlers;
    php_treesitter_grammar_ce->create_object = php_treesitter_grammar_object_create;

    memcpy(&php_treesitter_grammar_handlers, &std_object_handlers, sizeof(zend_object_handlers));
    php_treesitter_grammar_handlers.free_obj = php_treesitter_grammar_object_free;
    php_treesitter_grammar_handlers.compare = zend_objects_not_comparable;
    php_treesitter_grammar_handlers.clone_obj = NULL;

    php_treesitter_parser_ce = register_class_TreeSitter_Parser();
    php_treesitter_parser_ce->default_object_handlers = &php_treesitter_parser_handlers;
    php_treesitter_parser_ce->create_object = php_treesitter_parser_object_create;

    memcpy(&php_treesitter_parser_handlers, &std_object_handlers, sizeof(zend_object_handlers));
    php_treesitter_parser_handlers.offset = XtOffsetOf(php_treesitter_parser_object, std);
    php_treesitter_parser_handlers.free_obj = php_treesitter_parser_object_free;
    php_treesitter_parser_handlers.compare = zend_objects_not_comparable;
    php_treesitter_parser_handlers.clone_obj = NULL;

    php_treesitter_tree_ce = register_class_TreeSitter_Tree();
    php_treesitter_tree_ce->default_object_handlers = &php_treesitter_tree_handlers;
    php_treesitter_tree_ce->create_object = php_treesitter_tree_object_create;

    memcpy(&php_treesitter_tree_handlers, &std_object_handlers, sizeof(zend_object_handlers));
    php_treesitter_tree_handlers.offset = XtOffsetOf(php_treesitter_tree_object, std);
    php_treesitter_tree_handlers.free_obj = php_treesitter_tree_object_free;
    php_treesitter_tree_handlers.compare = zend_objects_not_comparable;
    php_treesitter_tree_handlers.clone_obj = NULL;

    php_treesitter_node_ce = register_class_TreeSitter_Node();
    php_treesitter_node_ce->default_object_handlers = &php_treesitter_node_handlers;
    php_treesitter_node_ce->create_object = php_treesitter_node_object_create;

    memcpy(&php_treesitter_node_handlers, &std_object_handlers, sizeof(zend_object_handlers));
    php_treesitter_node_handlers.offset = XtOffsetOf(php_treesitter_node_object, std);
    php_treesitter_node_handlers.free_obj = php_treesitter_node_object_free;
    php_treesitter_node_handlers.compare = zend_objects_not_comparable;
    php_treesitter_node_handlers.clone_obj = NULL;

    php_treesitter_point_ce = register_class_TreeSitter_Point();
    php_treesitter_point_ce->default_object_handlers = &php_treesitter_point_handlers;
    php_treesitter_point_ce->create_object = php_treesitter_point_object_create;

    memcpy(&php_treesitter_point_handlers, &std_object_handlers, sizeof(zend_object_handlers));
    php_treesitter_point_handlers.free_obj = php_treesitter_point_object_free;
    php_treesitter_point_handlers.compare = zend_objects_not_comparable; // TODO: should be, though :D
    php_treesitter_point_handlers.clone_obj = NULL;

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

#ifndef PHP_TREESITTER_PARSERS_H
#define PHP_TREESITTER_PARSERS_H

#include "tree_sitter/api.h"

#define PHP_TREESITTER_GRAMMAR_PHP           0x706870L
#define PHP_TREESITTER_GRAMMAR_HTML          0x68746d6cL
#define PHP_TREESITTER_GRAMMAR_CSS           0x637373L
#define PHP_TREESITTER_GRAMMAR_JAVASCRIPT    0x6a73L
#define PHP_TREESITTER_GRAMMAR_TYPESCRIPT    0x7473L
#define PHP_TREESITTER_GRAMMAR_PYTHON        0x707974686f6eL
#define PHP_TREESITTER_GRAMMAR_JSON          0x6a736f6eL

const TSLanguage *tree_sitter_php(void);
const TSLanguage *tree_sitter_html(void);
const TSLanguage *tree_sitter_css(void);
const TSLanguage *tree_sitter_javascript(void);
const TSLanguage *tree_sitter_typescript(void);
const TSLanguage *tree_sitter_python(void);
const TSLanguage *tree_sitter_json(void);

#endif /* PHP_TREESITTER_PARSERS_H */

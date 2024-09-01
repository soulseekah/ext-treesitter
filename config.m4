AC_DEFINE(HAVE_TREESITTER, 1, [ Have treesitter ])

TS_FLAGS="-O0"

TS_CFLAGS="$TS_CFLAGS -Ilib/tree-sitter/lib/include/ -Ilib/tree-sitter/lib/src/"

TS_PARSERS="$TS_PARSERS lib/parsers/tree-sitter-php/php/src/parser.c lib/parsers/tree-sitter-php/php/src/scanner.c"
TS_CFLAGS="$TS_CFLAGS -Ilib/parsers/tree-sitter-php/php/src/"
TS_PARSERS="$TS_PARSERS lib/parsers/tree-sitter-html/src/parser.c lib/parsers/tree-sitter-html/src/scanner.c"
TS_PARSERS="$TS_PARSERS lib/parsers/tree-sitter-css/src/parser.c lib/parsers/tree-sitter-css/src/scanner.c"
TS_PARSERS="$TS_PARSERS lib/parsers/tree-sitter-javascript/src/parser.c lib/parsers/tree-sitter-javascript/src/scanner.c"
TS_PARSERS="$TS_PARSERS lib/parsers/tree-sitter-typescript/typescript/src/parser.c lib/parsers/tree-sitter-typescript/typescript/src/scanner.c"
TS_PARSERS="$TS_PARSERS lib/parsers/tree-sitter-typescript/tsx/src/parser.c lib/parsers/tree-sitter-typescript/tsx/src/scanner.c"
TS_PARSERS="$TS_PARSERS lib/parsers/tree-sitter-json/src/parser.c"
TS_PARSERS="$TS_PARSERS lib/parsers/tree-sitter-python/src/parser.c lib/parsers/tree-sitter-python/src/scanner.c"

PHP_NEW_EXTENSION(treesitter, treesitter.c lib/tree-sitter/lib/src/lib.c $TS_PARSERS, yes,, [$TS_CFLAGS])

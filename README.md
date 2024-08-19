# PHP8 bindings for Tree-sitter

https://tree-sitter.github.io/tree-sitter/

## Building

```bash
git submodule update --init --recursive

phpize

./configure

make
make test
make install
```

`extension=treesitter.so` has to be added to your PHP ini file.

## Usage

TBD

## Parsers

These bindings come with the following parsers:

 - PHP (https://github.com/tree-sitter/tree-sitter-php)
 - HTML (https://github.com/tree-sitter/tree-sitter-html)
 - CSS (https://github.com/tree-sitter/tree-sitter-css)
 - JavaScript & JSX (https://github.com/tree-sitter/tree-sitter-javascript)
 - TypeScript & TSX (https://github.com/tree-sitter/tree-sitter-typscript)
 - JSON (https://github.com/tree-sitter/tree-sitter-json)
 - Python (https://github.com/tree-sitter/tree-sitter-python)

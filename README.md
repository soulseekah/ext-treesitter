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

```php
use TreeSitter as TS;

$parser = new TS\Parser(TS\Grammar::JSON);

$tree = $parser->parse("[1, null]");

$rootNode = $tree->getRootNode();

echo $rootNode; // (document (array (number) (null)))
```

## Parsers

This extension includes the following parsers:

|Parser|Constant||
|-|-|-|
|[PHP](https://github.com/tree-sitter/tree-sitter-php)|`TreeSitter\Grammar::PHP`||
|[HTML](https://github.com/tree-sitter/tree-sitter-html)|`TreeSitter\Grammar::HTML`||
|[CSS](https://github.com/tree-sitter/tree-sitter-css)|`TreeSitter\Grammar::CSS`||
|[JavaScript & JSX](https://github.com/tree-sitter/tree-sitter-javascript)|`TreeSitter\Grammar::JAVASCRIPT`||
|[TypeScript & TSX](https://github.com/tree-sitter/tree-sitter-typscript)|`TreeSitter\Grammar::TYPESCRIPT`||
|[JSON](https://github.com/tree-sitter/tree-sitter-json)|`TreeSitter\Grammar::JSON`||
|[Python](https://github.com/tree-sitter/tree-sitter-python)|`TreeSitter\Grammar::PYTHON`||

### Custom parsers

Custom parsers can be added to this extension.

(TODO)

## Contributing

`ext-treesitter` is undergoing initial **heavy development and is highly unstable**.

Missing something? File an [issue](https://github.com/soulseekah/ext-treesitter/issues) and/or open a PR.

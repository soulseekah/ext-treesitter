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

## API

### `TreeSitter\Parser`

#### `::__construct(TreeSitter\Grammar $grammar): TreeSitter\Parser`

Creates a new Parser object with the given `TreeSitter\Grammar` grammar. See built-in parser grammars in the Parsers section below.

#### `::parse(string $source_code): TreeSitter\Tree`

Parses the source code and produces a `TreeSitter\Tree` instance or throws `TreeSitter\SyntaxError` exception.

#### `::parseWithErrors(string $source_code): TreeSitter\Tree`

Parses the source code and returns `TreeSitter\Tree` instance with error nodes.

### `TreeSitter\Tree`

#### `::getRootNode(void): TreeSitter\Node`

Returns the root `TreeSitter\Node` instance that contains the AST (Abstract Syntax Tree).

### `TreeSitter\Node`

#### `::getType(): string`

Returns the type of the node as per the grammar selected.

#### `::hasChildren(): bool`

Whether this node has any children or not.

#### `::countChildren(): int`

Return the number of children this node has.

#### `::getStartByte(): int`

The start byte for this node within the `$source_code`. Note that the position will include multibyte characters. See `::getStartPoint`. Is relative to the root.

#### `::getEndByte(): int`

The end byte for this node within the `$source_code`. Note that the result will count multibyte characters as individual bytes. See `::getEndPoint`. Is relative to the root.

#### `::getStartPoint(): TreeSitter\Point`

Returns a `TreeSitter\Point` instance with the `int $row` and `int $column` properties set to the starting point of this node, taking into account multi-byte characters. Is relative to the root.

#### `::getEndPoint(): TreeSitter\Point`

Returns a `TreeSitter\Point` instance with the `int $row` and `int $column` properties set to the ending point of this node, taking into account multi-byte characters. Is relative to the root.

#### `::__toString(void): string`

Ouputs the S-expression syntax tree for the current node and its siblings.

### `TreeSitter\Point`

#### `int $row`

The row within the source tree. See `TreeSitter\Node::getStartPoint()` and `TreeSitter\Node::getEndPoint()`.

#### `int $column`

The column within the source tree. See `TreeSitter\Node::getStartPoint()` and `TreeSitter\Node::getEndPoint()`.

### `TreeSitter\SyntaxError`

Extends `Exception`. Thrown from `TreeSitter\Parser::parse` if a syntax error is detected.

## Parsers and Grammars

This extension includes the following parsers:

|Parser|Constant|
|-|-|
|[PHP](https://github.com/tree-sitter/tree-sitter-php)|`TreeSitter\Grammar::PHP`|
|[HTML](https://github.com/tree-sitter/tree-sitter-html)|`TreeSitter\Grammar::HTML`|
|[CSS](https://github.com/tree-sitter/tree-sitter-css)|`TreeSitter\Grammar::CSS`|
|[JavaScript & JSX](https://github.com/tree-sitter/tree-sitter-javascript)|`TreeSitter\Grammar::JAVASCRIPT`|
|[TypeScript & TSX](https://github.com/tree-sitter/tree-sitter-typscript)|`TreeSitter\Grammar::TYPESCRIPT`|
|[JSON](https://github.com/tree-sitter/tree-sitter-json)|`TreeSitter\Grammar::JSON`|
|[Python](https://github.com/tree-sitter/tree-sitter-python)|`TreeSitter\Grammar::PYTHON`|

## Contributing

`ext-treesitter` is undergoing initial **heavy development and is highly unstable**.

Missing something? File an [issue](https://github.com/soulseekah/ext-treesitter/issues) and/or open a PR.

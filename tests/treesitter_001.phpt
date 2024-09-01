--TEST--
Tree-sitter: Check registered Grammar constants
--FILE--
<?php
	echo implode(PHP_EOL, array_map(fn($id) => hex2bin(dechex($id)), $grammars = [
		TreeSitter\Grammar::PHP,
		TreeSitter\Grammar::HTML,
		TreeSitter\Grammar::CSS,
		TreeSitter\Grammar::JAVASCRIPT,
		TreeSitter\Grammar::TYPESCRIPT,
		TreeSitter\Grammar::PYTHON,
		TreeSitter\Grammar::JSON,
	])) . PHP_EOL;

	try {
		new TreeSitter\Grammar;
		echo '__SENTINEL__';
	} catch (Error $e) {
		echo $e->getMessage();
	}

	foreach ($grammars as $grammar) {
		new TreeSitter\Parser($grammar);
	}
?>
--EXPECT--
php
html
css
js
ts
python
json
TreeSitter\Grammar class is non-instantiable

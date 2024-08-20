--TEST--
Tree-sitter: Check registered Grammar constants
--FILE--
<?php
	echo implode(PHP_EOL, array_map(fn($id) => hex2bin(dechex($id)), [
		TreeSitter\Grammar::PHP,
		TreeSitter\Grammar::HTML,
		TreeSitter\Grammar::CSS,
		TreeSitter\Grammar::JAVASCRIPT,
		TreeSitter\Grammar::TYPESCRIPT,
		TreeSitter\Grammar::PYTHON,
		TreeSitter\Grammar::JSON,
	]));
?>
--EXPECT--
php
html
css
js
ts
python
json

--TEST--
Tree-sitter: Simple JSON __toString
--FILE--
<?php
	$parser = new TreeSitter\Parser(TreeSitter\Grammar::JSON);
	$tree = $parser->parse("[1, null]");
	$rootNode = $tree->getRootNode();

	echo $rootNode . PHP_EOL;

	try {
		new TreeSitter\Parser(0x696e76616c6964);
		echo '__SENTINEL__';
	} catch (Error $e) {
		echo $e->getMessage();
	}
?>
--EXPECT--
(document (array (number) (null)))
Unknown grammar

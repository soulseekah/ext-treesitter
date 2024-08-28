--TEST--
Tree-sitter: Simple JSON __toString
--FILE--
<?php
	$parser = new TreeSitter\Parser(TreeSitter\Grammar::JSON);
	var_dump($parser);
	$tree = $parser->parse();
	var_dump($tree);
	// $rootNode = $tree->getRootNode();
	// echo $rootNode;

	try {
		new TreeSitter\Parser(0x696e76616c6964);
		echo '__SENTINEL__';
	} catch (Error $e) {
		echo $e->getMessage();
	}
?>
--EXPECT--
Unknown grammar

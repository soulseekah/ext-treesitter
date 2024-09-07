--TEST--
Tree-sitter: Node::getType
--FILE--
<?php
	$parser = new TreeSitter\Parser(TreeSitter\Grammar::PHP);
	$tree = $parser->parse("<?php test();");
	$rootNode = $tree->getRootNode();

	var_dump($rootNode->getType());

	var_dump($rootNode->hasChildren());
	var_dump($rootNode->countChildren());

	var_dump($rootNode->getStartByte());
	var_dump($rootNode->getEndByte());

	echo implode(',', [
		($point = $rootNode->getStartPoint())->row, $point->column,
		($point = $rootNode->getEndPoint())->row, $point->column
	]) . PHP_EOL;
?>
--EXPECT--
string(7) "program"
bool(true)
int(2)
int(0)
int(13)
0,0,0,13

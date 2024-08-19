--TEST--
Tree sitter: Experimental JSON test
--FILE--
<?php
	echo test1();
?>
--EXPECT--
Syntax tree: (document (array (number) (null)))

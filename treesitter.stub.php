<?php

/** @generate-class-entries */

namespace TreeSitter {
	/**
	 * @strict-properties
	 * @not-serializable
	 */
	final class Grammar {
		/**
		 * @cvalue PHP_TREESITTER_GRAMMAR_PHP
		 */
		public const int PHP = UNKNOWN;

		/**
		 * @cvalue PHP_TREESITTER_GRAMMAR_HTML
		 */
		public const int HTML = UNKNOWN;

		/**
		 * @cvalue PHP_TREESITTER_GRAMMAR_CSS
		 */
		public const int CSS = UNKNOWN;

		/**
		 * @cvalue PHP_TREESITTER_GRAMMAR_JAVASCRIPT
		 */
		public const int JAVASCRIPT = UNKNOWN;

		/**
		 * @cvalue PHP_TREESITTER_GRAMMAR_TYPESCRIPT
		 */
		public const int TYPESCRIPT = UNKNOWN;

		/**
		 * @cvalue PHP_TREESITTER_GRAMMAR_PYTHON
		 */
		public const int PYTHON = UNKNOWN;

		/**
		 * @cvalue PHP_TREESITTER_GRAMMAR_JSON
		 */
		public const int JSON = UNKNOWN;

		public function __construct() {}
	}

	/**
	 * @strict-properties
	 * @not-serializable
	 */
	final class Parser {
		public function __construct(int $grammar) {}

		public function parse(string $source_code): Tree {}
	}

	/**
	 * @strict-properties
	 * @not-serializable
	 */
	final class Tree {
		public function getRootNode(): Node {}
	}

	/**
	 * @strict-properties
	 * @not-serializable
	 */
	final class Node {
		public function getType(): string {}

		public function hasChildren(): bool {}

		public function countChildren(): int {}

		public function getStartByte(): int {}

		public function getEndByte(): int {}

		public function getStartPoint(): Point {}

		public function getEndPoint(): Point {}

		public function __toString(): string {}
	}

	/**
	 * @strict-properties
	 * @not-serializable
	 */
	final class Point {
		public int $row;

		public int $column;
	}

	final class SyntaxError extends Exception {
	}
}

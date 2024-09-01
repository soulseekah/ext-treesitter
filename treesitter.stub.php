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
	class Parser {
		public function __construct(int $grammar) {}

		public function parse(string $source_code): Tree {}
	}

	/**
	 * @strict-properties
	 * @not-serializable
	 */
	class Tree {
	}

	/**
	 * @strict-properties
	 * @not-serializable
	 */
	class Node {
	}
}

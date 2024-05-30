#pragma once
#include <unordered_set>

enum TokenType {
	KEYWORD,
	IDENTIFIER,
	LITERAL,
	OPERATOR,
	PUNCTUATION,
	COMMENT,
	UNKNOWN
};

TokenType getTokenType(const std::string& lexeme);
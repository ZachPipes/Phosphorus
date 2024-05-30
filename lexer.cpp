#include <iostream>
#include <string>
#include "lexer.h"

//Keywords
std::unordered_set<std::string> keywords = {
	"if", "else", "while",
	"bool", "int", "double", "string"
};

TokenType getTokenType(const std::string& lexeme) {
	//Checks if the lexeme is empty
	if (lexeme.empty()) {
		return UNKNOWN;
	}

	//Checks if index[0] is alphanumeric or an underscore
	bool isIdentifier = std::isalpha(lexeme[0]) || lexeme[0] == '_';
	//Checks if index[0] is a digit
	bool isLiteral = std::isdigit(lexeme[0]);

	//Runs through every character in the lexeme
	for (char c : lexeme) {
		//If index[0] is NOT alphanumeric AND is NOT an underscore
		if (!std::isalnum(c) && c != '_') {
			//Sets both bool variables to false and breaksthe for loop
			isIdentifier = false;
			isLiteral = false;
			break;
		}
	}

	//If isIdentifier is still true (from previous for loop)
	if (isIdentifier) {
		//If the lexeme is in the keywords set return keyword
		if (keywords.count(lexeme)) {
			return KEYWORD;
		}
		//If it's not in the keywords set, return identifier
		else { return IDENTIFIER; }
	}
	//If isLiteral is still true (from previous for loop)
	else if (isLiteral) {
		//Return literal
		return LITERAL;
	}
	//If it's anything else it's punctuation
	else { return PUNCTUATION; }
}
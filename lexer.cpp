#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <unordered_set>

//Keywords
std::unordered_set<std::string> keywords = {
	"if", "else", "while", 
	"int", "double", "string"
};

enum TokenType {
	KEYWORD,
	IDENTIFIER,
	LITERAL,
	OPERATOR,
	PUNCTUATION,
	COMMENT,
	UNKNOWN
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
			//Sets both bool variables to false and breaks
			isIdentifier = false;
			isLiteral = false;
			break;
		}
	}

	//If isIdentifier variable is still true (from previous for loop)
	if (isIdentifier) {
		//If 
		if (keywords.count(lexeme)) {
			return KEYWORD;
		}
		else { return IDENTIFIER; }
	}
	else if (isLiteral) {
		return LITERAL;
	}
	else { return PUNCTUATION; }
}

int main() {
	std::string input;
	std::cout << "Enter input: ";
	std::getline(std::cin, input);

	std::string lexeme;
	for (char c : input) {
		if (std::isalnum(c) || c == '_') {
			lexeme += c;
		}
		else {
			if (!lexeme.empty()) {
				TokenType tokenType = getTokenType(lexeme);
				std::cout << "Lexeme: " << lexeme << ", Token Type: ";
				switch (tokenType) {
				case IDENTIFIER:
					std::cout << "IDENTIFIER" << std::endl;
					break;
				case KEYWORD:
					std::cout << "KEYWORD" << std::endl;
					break;
				case LITERAL:
					std::cout << "LITERAL" << std::endl;
					break;
				case OPERATOR:
					std::cout << "OPERATOR" << std::endl;
					break;
				case PUNCTUATION:
					std::cout << "PUNCTUATION" << std::endl;
					break;
				}
				lexeme.clear();
			}
			if (!std::isspace(c)) {
				std::cout << "Lexeme: " << c << ", Token Type: Operator/Punctuation" << std::endl;
			}
		}
	}

	if (!lexeme.empty()) {
		TokenType tokenType = getTokenType(lexeme);
		std::cout << "Lexeme: " << lexeme << ", Token Type: ";
		switch (tokenType) {
		case IDENTIFIER:
			std::cout << "Identifier" << std::endl;
			break;
		case KEYWORD:
			std::cout << "Keyword" << std::endl;
			break;
		case LITERAL:
			std::cout << "Literal" << std::endl;
			break;
		case OPERATOR:
			std::cout << "Operator/Punctuation" << std::endl;
			break;
		}
	}

	return 0;
}

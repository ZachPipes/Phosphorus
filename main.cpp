#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include "preprocessor.h"
#include "lexer.h"

int main() {
	//Interactions with user
	std::string input;
	std::cout << "Enter file name: ";
	std::getline(std::cin, input);
	std::ifstream inputFileStream(input);
	//Verifying file
	if (!inputFileStream) {
		std::cerr << "Error opnening file\n";
		return 1;
	}

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
#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include "preprocessor.h"
#include "lexer.h"

extern std::unordered_set<std::string> keywords;

int main() {
	//Interactions with user
	std::string input;
	std::cout << "Enter file name(or input): ";
	std::getline(std::cin, input);

	/*std::ifstream inputFileStream(input);
	//Verifying file
	if (!inputFileStream) {
		std::cerr << "Error opnening file\n";
		return 1;
	}*/

	std::string lexeme;
	for (char c : input) {
		//Detects when the lexeme ends 
		if (std::isalnum(c) || c == '_') {
			lexeme += c;
		}
		else {
			if (!lexeme.empty()) {
				TokenType tokenType = getTokenType(lexeme);
				std::cout << "Lexeme: " << lexeme << " \n- Token Type: ";
				//Switch statement that determines the output based on the tokenType
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
					std::cout << "PUCNTUATION" << std::endl;
				}
			}
			if (!std::isspace(c)) {
				std::cout << "Lexeme: " << c << " \n- Token Type: Punctuation" << std::endl;
			}
			lexeme.clear();
		}
	}

	return 0;
}
//
// Created by issa on 17/05/24.
//

#ifndef DEMOPROJECT_HELPERS_H
#define DEMOPROJECT_HELPERS_H


#include <regex>
#include "Token.h"

const std::regex LETTER{R"([a-zA-Z])"};
const std::regex WHITESPACE{R"(\s+)"};
const std::regex NUM{R"(^[0-9]+$)"};
const std::regex EQ("=");
const std::regex DOT("/.");
const std::vector<char> OPERATORS = {'+', '-', '*', '/'};

class Helpers {
public:
    static std::unordered_map<TokenType, std::string> tokenTypeMap;

    static std::string getTokenTypeStr(TokenType type);
    static bool isDot(char character);
    static bool isEqual(char character);

    static bool isLetter(char character);

    static bool isWhitespace(char character);

    static bool isNumber(char character);

    static bool isOpeneningParenthesis(char character);

    static bool isClosingParenthesis(char character);

    static bool isParenthesis(char character);

    static bool isQuote(char character);

    static bool isOperator(char character);
};

#endif //DEMOPROJECT_HELPERS_H

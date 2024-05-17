//
// Created by issa on 17/05/24.
//
#include <iostream>
#include "Helpers.h"

bool Helpers::isEqual(char character) {
    return std::regex_match(std::string(1, character), EQ);
}

bool Helpers::isLetter(char character) {
    return std::regex_match(std::string(1, character), LETTER);
}

bool Helpers::isWhitespace(char character) {
    return std::regex_match(std::string(1, character), WHITESPACE);
}

bool Helpers::isNumber(char character) {
    return std::regex_match(std::string(1, character), NUM);
}

bool Helpers::isOpeneningParenthesis(char character) {
    return character == '(';
}

bool Helpers::isClosingParenthesis(char character) {
    return character == ')';
}

bool Helpers::isParenthesis(char character) {
    return isOpeneningParenthesis(character) || isClosingParenthesis(character);
}

bool Helpers::isQuote(char character) {
    return character == '"';
}

bool Helpers::isOperator(char character) {
    return std::find(OPERATORS.begin(), OPERATORS.end(), character) != OPERATORS.end();
}

std::string Helpers::getTokenTypeStr(TokenType type) {
    auto it = tokenTypeMap.find(type);
    if (it != tokenTypeMap.end()) {
        return it->second;
    }
    return {"Unknown Type"};
}

std::unordered_map<TokenType, std::string> Helpers::tokenTypeMap = {{TokenType::NUMBER,      "Number"},
                                                                    {TokenType::NAME,        "Name"},
                                                                    {TokenType::PARENTHESIS, "Parenthesis"},
                                                                    {TokenType::STRING,      "String"},
                                                                    {TokenType::OPERATOR,    "Operator"},
                                                                    {TokenType::EQUAL,       "Equal"}};
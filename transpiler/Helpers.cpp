//
// Created by issa on 17/05/24.
//

#include <iostream>
#include "Helpers.h"

/**
 * @brief Checks if a character is a comma.
 * @param character The character to check.
 * @return True if the character is a comma, otherwise false.
 */
bool Helpers::isComma(char character) {
    return std::regex_match(std::string(1, character), COMMA);
}

/**
 * @brief Checks if a character is a low precedence operator (+ or -).
 * @param character The character to check.
 * @return True if the character is a low precedence operator, otherwise false.
 */
bool Helpers::isLowOperator(char character) {
    return std::find(LOW_TIER_OPERATORS.begin(), LOW_TIER_OPERATORS.end(), character) != LOW_TIER_OPERATORS.end();
}

/**
 * @brief Checks if a character is a high precedence operator (* or /).
 * @param character The character to check.
 * @return True if the character is a high precedence operator, otherwise false.
 */
bool Helpers::isHighOperator(char character) {
    return std::find(HIGH_TIER_OPERATORS.begin(), HIGH_TIER_OPERATORS.end(), character) != HIGH_TIER_OPERATORS.end();
}

/**
 * @brief Checks if a character is a dot.
 * @param character The character to check.
 * @return True if the character is a dot, otherwise false.
 */
bool Helpers::isDot(char character) {
    return std::regex_match(std::string(1, character), DOT);
}

/**
 * @brief Checks if a character is an equal sign.
 * @param character The character to check.
 * @return True if the character is an equal sign, otherwise false.
 */
bool Helpers::isEqual(char character) {
    return std::regex_match(std::string(1, character), EQ);
}

/**
 * @brief Checks if a character is a letter.
 * @param character The character to check.
 * @return True if the character is a letter, otherwise false.
 */
bool Helpers::isLetter(char character) {
    return std::regex_match(std::string(1, character), LETTER);
}

/**
 * @brief Checks if a character is a whitespace character.
 * @param character The character to check.
 * @return True if the character is a whitespace character, otherwise false.
 */
bool Helpers::isWhitespace(char character) {
    return std::regex_match(std::string(1, character), WHITESPACE);
}

/**
 * @brief Checks if a character is a number.
 * @param character The character to check.
 * @return True if the character is a number, otherwise false.
 */
bool Helpers::isNumber(char character) {
    return std::regex_match(std::string(1, character), NUM);
}

/**
 * @brief Checks if a character is an opening parenthesis.
 * @param character The character to check.
 * @return True if the character is an opening parenthesis, otherwise false.
 */
bool Helpers::isOpeningParenthesis(char character) {
    return character == '(';
}

/**
 * @brief Checks if a character is a closing parenthesis.
 * @param character The character to check.
 * @return True if the character is a closing parenthesis, otherwise false.
 */
bool Helpers::isClosingParenthesis(char character) {
    return character == ')';
}

/**
 * @brief Checks if a character is any parenthesis (opening or closing).
 * @param character The character to check.
 * @return True if the character is a parenthesis, otherwise false.
 */
bool Helpers::isParenthesis(char character) {
    return isOpeningParenthesis(character) || isClosingParenthesis(character);
}

/**
 * @brief Checks if a character is a quote.
 * @param character The character to check.
 * @return True if the character is a quote, otherwise false.
 */
bool Helpers::isQuote(char character) {
    return character == '"';
}

/**
 * @brief Checks if a character is an operator.
 * @param character The character to check.
 * @return True if the character is an operator, otherwise false.
 */
bool Helpers::isOperator(char character) {
    return std::find(OPERATORS.begin(), OPERATORS.end(), character) != OPERATORS.end();
}

/**
 * @brief Checks if a given word is a keyword.
 * @param word The word to check.
 * @return True if the word is a keyword, otherwise false.
 */
bool Helpers::isKeyWord(const std::string& word) {
    return std::find(KEYWORDS.begin(), KEYWORDS.end(), word) != KEYWORDS.end();
}

/**
 * @brief Retrieves the string representation of a given TokenType.
 * @param type The TokenType to convert.
 * @return The string representation of the TokenType.
 */
std::string Helpers::getTokenTypeStr(TokenType type) {
    auto it = tokenTypeMap.find(type);
    if (it != tokenTypeMap.end()) {
        return it->second;
    }
    return {"Unknown Type"};
}

// Initialize the tokenTypeMap with TokenType to string mappings.
std::unordered_map<TokenType, std::string> Helpers::tokenTypeMap = {
        {TokenType::NUMBER, "Number"},
        {TokenType::NAME, "Name"},
        {TokenType::PARENTHESIS, "Parenthesis"},
        {TokenType::STRING, "String"},
        {TokenType::OPERATOR, "Operator"},
        {TokenType::EQUAL, "Equal"},
        {TokenType::DOTACCESS, "DotAccess"},
        {TokenType::KEYWORD, "KeyWord"}
};

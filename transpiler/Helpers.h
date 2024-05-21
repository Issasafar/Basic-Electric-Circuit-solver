//
// Created by issa on 17/05/24.
//

#ifndef DEMOPROJECT_HELPERS_H
#define DEMOPROJECT_HELPERS_H

#include <regex>
#include "Token.h"

// Regular expressions for different patterns
const std::regex LETTER{R"([a-zA-Z])"};  // Matches any single letter
const std::regex WHITESPACE{R"(\s+)"};  // Matches one or more whitespace characters
const std::regex NUM{R"(^[0-9]+$)"};  // Matches a string that consists entirely of digits
const std::regex EQ{"="};  // Matches an equal sign
const std::regex DOT{"\\."};  // Matches a dot
const std::regex COMMA{","};  // Matches a comma

// Operators and keywords
const std::vector<char> OPERATORS = {'+', '-', '*', '/'};  // List of basic arithmetic operators
const std::vector<std::string> KEYWORDS = {"let", "print"};  // List of keywords
const std::vector<char> HIGH_TIER_OPERATORS = {'*', '/'};  // Operators with higher precedence
const std::vector<char> LOW_TIER_OPERATORS = {'+', '-'};  // Operators with lower precedence

/**
 * @class Helpers
 * @brief A utility class that provides various helper functions for token parsing and classification.
 */
class Helpers {
public:
    /**
     * @brief Checks if a given word is a keyword.
     * @param word The word to check.
     * @return True if the word is a keyword, otherwise false.
     */
    static bool isKeyWord(const std::string& word);

    /**
     * @brief A map that associates TokenType with its string representation.
     */
    static std::unordered_map<TokenType, std::string> tokenTypeMap;

    /**
     * @brief Retrieves the string representation of a given TokenType.
     * @param type The TokenType to convert.
     * @return The string representation of the TokenType.
     */
    static std::string getTokenTypeStr(TokenType type);

    /**
     * @brief Checks if a character is a comma.
     * @param character The character to check.
     * @return True if the character is a comma, otherwise false.
     */
    static bool isComma(char character);

    /**
     * @brief Checks if a character is a low precedence operator (+ or -).
     * @param character The character to check.
     * @return True if the character is a low precedence operator, otherwise false.
     */
    static bool isLowOperator(char character);

    /**
     * @brief Checks if a character is a high precedence operator (* or /).
     * @param character The character to check.
     * @return True if the character is a high precedence operator, otherwise false.
     */
    static bool isHighOperator(char character);

    /**
     * @brief Checks if a character is a dot.
     * @param character The character to check.
     * @return True if the character is a dot, otherwise false.
     */
    static bool isDot(char character);

    /**
     * @brief Checks if a character is an equal sign.
     * @param character The character to check.
     * @return True if the character is an equal sign, otherwise false.
     */
    static bool isEqual(char character);

    /**
     * @brief Checks if a character is a letter.
     * @param character The character to check.
     * @return True if the character is a letter, otherwise false.
     */
    static bool isLetter(char character);

    /**
     * @brief Checks if a character is a whitespace character.
     * @param character The character to check.
     * @return True if the character is a whitespace character, otherwise false.
     */
    static bool isWhitespace(char character);

    /**
     * @brief Checks if a character is a number.
     * @param character The character to check.
     * @return True if the character is a number, otherwise false.
     */
    static bool isNumber(char character);

    /**
     * @brief Checks if a character is an opening parenthesis.
     * @param character The character to check.
     * @return True if the character is an opening parenthesis, otherwise false.
     */
    static bool isOpeningParenthesis(char character);

    /**
     * @brief Checks if a character is a closing parenthesis.
     * @param character The character to check.
     * @return True if the character is a closing parenthesis, otherwise false.
     */
    static bool isClosingParenthesis(char character);

    /**
     * @brief Checks if a character is any parenthesis (opening or closing).
     * @param character The character to check.
     * @return True if the character is a parenthesis, otherwise false.
     */
    static bool isParenthesis(char character);

    /**
     * @brief Checks if a character is a quote.
     * @param character The character to check.
     * @return True if the character is a quote, otherwise false.
     */
    static bool isQuote(char character);

    /**
     * @brief Checks if a character is an operator.
     * @param character The character to check.
     * @return True if the character is an operator, otherwise false.
     */
    static bool isOperator(char character);
};

#endif // DEMOPROJECT_HELPERS_H

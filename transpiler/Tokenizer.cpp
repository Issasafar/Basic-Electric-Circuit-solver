//
// Created by issa on 17/05/24.
//

#include <vector>
#include <iostream>
#include "Tokenizer.h"
#include "Helpers.h"
#include "Token.h"
#include "TranspilerException.h"
#include <algorithm>

/**
 * Repeat a string a specified number of times.
 *
 * @param str The string to be repeated.
 * @param count The number of times to repeat the string.
 * @return The repeated string.
 */
std::string repeat(const std::string &str, unsigned long count) {
    std::stringstream ss;
    while (count--) {
        ss << str;
    }
    return ss.str();
}

/**
 * Tokenize the input string into a vector of tokens.
 *
 * @param input The input string to be tokenized.
 * @return A vector of tokens representing the input string.
 * @throws TranspilerException if the input contains an invalid character.
 */
std::vector<Token> tokenize(const std::string &input) {
    std::vector<Token> tokens;
    int cursor = 0;
    std::stringstream text;
    while (cursor < input.length()) {
        text.str(std::string());
        const char character = input[cursor];
        if (Helpers::isComma(character)) {
            text << character;
            tokens.emplace_back(TokenType::PUNCTUATOR, cursor, text.str());
            cursor++;
            continue;
        }
        if (Helpers::isParenthesis(character)) {
            text << character;
            tokens.emplace_back(TokenType::PARENTHESIS, cursor, text.str());
            cursor++;
            continue;
        }
        if (Helpers::isWhitespace(character)) {
            cursor++;
            continue;
        }
        if (Helpers::isNumber(character)) {
            text << character;
            char atPosition = input[++cursor];
            while (Helpers::isNumber(atPosition) || Helpers::isDot(atPosition)) {
                text << atPosition;
                atPosition = input[++cursor];
            }
            tokens.emplace_back(TokenType::NUMBER, cursor, text.str());
            continue;
        }
        if (Helpers::isLetter(character)) {
            text << character;
            char atPosition = input[++cursor];
            while (Helpers::isLetter(atPosition) || Helpers::isNumber(atPosition)) {
                text << input[cursor];
                atPosition = input[++cursor];
            }
            tokens.emplace_back(TokenType::NAME, cursor, text.str());
            continue;
        }
        if (Helpers::isQuote(character)) {
            while (!Helpers::isQuote(input[++cursor])) {
                text << input[cursor];
            }
            tokens.emplace_back(TokenType::STRING, cursor, text.str());
            cursor++;
            continue;
        }
        if (Helpers::isOperator(character)) {
            text << character;
            tokens.emplace_back(TokenType::OPERATOR, cursor, text.str());
            cursor++;
            continue;
        }
        if (Helpers::isEqual(character)) {
            text << character;
            tokens.emplace_back(TokenType::EQUAL, cursor, text.str());
            cursor++;
            continue;
        }
        if (Helpers::isDot(character)) {
            text << character;
            tokens.emplace_back(TokenType::DOTACCESS, cursor, text.str());
            cursor++;
            continue;
        }
        text << character;
        throw TranspilerException("'" + text.str() + "'" + " is not a valid character\n" + input + "\n" + repeat(" ", cursor) + "^");
    }
    return tokens;
}

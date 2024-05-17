//
// Created by issa on 17/05/24.
//

#include <vector>
#include "Tokenizer.h"
#include "Helpers.h"
#include "Token.h"

std::vector<Token> tokenize(const std::string& input){
    std::vector<Token> tokens;
    int cursor = 0;
    while (cursor < input.length()) {
        const char character = input[cursor];
        if (Helpers::isParenthesis(character)) {
            tokens.emplace_back(
                TokenType::PARENTHESIS,
                character
            );
            cursor++;
            continue;
        }
        if (Helpers::isWhitespace(character)) {
            cursor++;
            continue;
        }
        if(Helpers::isNumber(character)){
            int number = (int)character - (int)'0';

            while (Helpers::isNumber(input[++cursor])) {
                number *= 10;
                number += (int)input[cursor] - (int)'0';
            }
            tokens.emplace_back(
                    TokenType::NUMBER,
                    number
                    );
            continue;
        }
        if(Helpers::isLetter(character)){
            std::stringstream symbol;
            symbol<<character;
            while (Helpers::isLetter(input[++cursor])) {
                symbol << input[cursor];
            }
            tokens.emplace_back(
                    TokenType::NAME,
                    symbol.str()
                    );
            continue;
        }
        if(Helpers::isQuote(character)){
            std::stringstream string_;
            while (!Helpers::isQuote(input[++cursor])) {
                string_ << input[cursor];
            }
            tokens.emplace_back(
                    TokenType::STRING,
                    string_.str()
                    );
            cursor++;
            continue;
        }
        if(Helpers::isOperator(character)){
            tokens.emplace_back(
                    TokenType::OPERATOR,
                    character
                    );
            cursor++;
            continue;
        }
        if(Helpers::isEqual(character)){
            tokens.emplace_back(
                    TokenType::EQUAL,
                    character
                    );
            cursor++;
            continue;
        }
        throw std::runtime_error(std::to_string(character) +" is not valid");
    }
    return tokens;
}


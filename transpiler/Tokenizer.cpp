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
    std::stringstream text;
    while (cursor < input.length()) {
        text.str(std::string());
        const char character = input[cursor];
        if (Helpers::isParenthesis(character)) {
            text<<character;
            tokens.emplace_back(
                TokenType::PARENTHESIS,
                cursor,
                text.str()
            );
            cursor++;
            continue;
        }
        if (Helpers::isWhitespace(character)) {
            cursor++;
            continue;
        }
        if(Helpers::isNumber(character)){
            text<<character;
            char atPosition = input[++cursor];
            while (Helpers::isNumber(atPosition) || Helpers::isDot(atPosition)) {
                text<<character;
                atPosition = input[++cursor];
            }
            tokens.emplace_back(
                    TokenType::NUMBER,
                    cursor,
                    text.str()
                    );
            continue;
        }
        if(Helpers::isLetter(character)){
            text<<character;
            while (Helpers::isLetter(input[++cursor])) {
                text << input[cursor];
            }
            tokens.emplace_back(
                    TokenType::NAME,
                    cursor,
                    text.str()
                    );
            continue;
        }
        if(Helpers::isQuote(character)){
            while (!Helpers::isQuote(input[++cursor])) {
                text << input[cursor];
            }
            tokens.emplace_back(
                    TokenType::STRING,
                    cursor,
                    text.str()
                    );
            cursor++;
            continue;
        }
        if(Helpers::isOperator(character)){
            text<<character;
            tokens.emplace_back(
                    TokenType::OPERATOR,
                    cursor,
                    text.str()
                    );
            cursor++;
            continue;
        }
        if(Helpers::isEqual(character)){
            text<<character;
            tokens.emplace_back(
                    TokenType::EQUAL,
                    cursor,
                    text.str()
                    );
            cursor++;
            continue;
        }
        throw std::runtime_error(std::to_string(character) +" is not valid for token");
    }
    return tokens;
}


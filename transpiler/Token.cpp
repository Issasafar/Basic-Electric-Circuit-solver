//
// Created by issa on 17/05/24.
//

#include <string>
#include <utility>
#include "Token.h"
#include "Helpers.h"

TokenType Token::getType() const {
    return type;
}


Token::Token(TokenType type, std::variant<std::string, int, char> value) : type(type), value(std::move(value)) {}

const std::variant<std::string, int, char> &Token::getValue() const {
    return value;
}

std::ostream &operator<<(std::ostream &os, const Token &token) {

    os << "type: " << Helpers::getTokenTypeStr(token.type)<< ", value: ";
    if (std::holds_alternative<std::string>(token.value)) {
        os << std::get<std::string>(token.value);
    } else if (std::holds_alternative<char>(token.value)) {
        os << std::get<char>(token.value);
    } else if (std::holds_alternative<int>(token.value)) {
        os << std::get<int>(token.value);
    }
    return os;
}



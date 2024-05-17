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



std::ostream &operator<<(std::ostream &os, const Token &token) {
    os << "type: " << Helpers::getTokenTypeStr(token.type)<< ", value: "<<token.getValue();
    return os;
}

int Token::getCursorPosition() const {
    return cursorPosition;
}

Token::Token(TokenType type, int cursorPosition, const std::string &value) : type(type), cursorPosition(cursorPosition),
                                                                             value(value) {}

const std::string &Token::getValue() const {
    return value;
}




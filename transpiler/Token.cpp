//
// Created by issa on 17/05/24.
//

#include <string>
#include <utility>
#include "Token.h"
#include "Helpers.h"

TokenType Token::getType() const {
    return type_;
}



std::ostream &operator<<(std::ostream &os, const Token &token) {
    os << "(TOKEN) type: " << Helpers::getTokenTypeStr(token.type_) << ", value: " << token.getValue();
    return os;
}

int Token::getCursorPosition() const {
    return cursorPosition_;
}

Token::Token(TokenType type, int cursorPosition, const std::string &value) : type_(type), cursorPosition_(cursorPosition),
                                                                             value_(value) {
if(Helpers::isKeyWord(value)){
    type_ = TokenType::KEYWORD;
}
}

const std::string &Token::getValue() const {
    return value_;
}




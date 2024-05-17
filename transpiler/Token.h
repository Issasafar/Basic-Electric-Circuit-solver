//
// Created by issa on 17/05/24.
//

#ifndef DEMOPROJECT_TOKEN_H
#define DEMOPROJECT_TOKEN_H


#include <variant>
#include <ostream>

enum TokenType {
    PARENTHESIS,
    NUMBER,
    NAME,
    STRING,
    OPERATOR,
    EQUAL,
    ASSIGN
};

class Token {
public:


    Token(TokenType type, int cursorPosition, const std::string &value);

    TokenType getType() const;


    friend std::ostream &operator<<(std::ostream &os, const Token &token);

    int getCursorPosition() const;

    const std::string &getValue() const;

private:
    TokenType type;
    int cursorPosition;
    std::string value;
};


#endif //DEMOPROJECT_TOKEN_H

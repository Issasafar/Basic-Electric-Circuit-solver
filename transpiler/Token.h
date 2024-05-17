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
    Token(TokenType type, std::variant<std::string, int, char> value);

    TokenType getType() const;

    const std::variant<std::string, int, char> &getValue() const;

    friend std::ostream &operator<<(std::ostream &os, const Token &token);

private:
    TokenType type;
    std::variant<std::string, int, char> value;
};


#endif //DEMOPROJECT_TOKEN_H

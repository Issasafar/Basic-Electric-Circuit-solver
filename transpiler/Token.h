//
// Created by issa on 17/05/24.
//

#ifndef DEMOPROJECT_TOKEN_H
#define DEMOPROJECT_TOKEN_H

#include <variant>
#include <ostream>

// Enum defining different types of tokens
enum TokenType {
    PARENTHESIS,   // Parentheses: (, )
    NUMBER,        // Numeric literals
    NAME,          // Identifier names
    STRING,        // String literals
    OPERATOR,      // Operators: +, -, *, /, etc.
    EQUAL,         // Equality operator: =
    DOTACCESS,     // Dot access operator: .
    KEYWORD,       // Keywords: e.g., let, if, else, etc.
    PUNCTUATOR,    // Punctuation marks: comma, semicolon, etc.
};

// Class representing a token in the source code
class Token {
public:
    /**
     * Constructor to initialize token properties.
     *
     * @param type The type of the token.
     * @param cursorPosition The cursor position in the source code where the token occurs.
     * @param value The value of the token.
     */
    Token(TokenType type, int cursorPosition, const std::string &value);

    // Getter method for retrieving the token type
    TokenType getType() const;

    // Getter method for retrieving the cursor position of the token
    int getCursorPosition() const;

    // Getter method for retrieving the value of the token
    const std::string &getValue() const;

    // Overloaded stream insertion operator for printing token information
    friend std::ostream &operator<<(std::ostream &os, const Token &token);

private:
    TokenType type_;           // Type of the token
    int cursorPosition_;       // Cursor position in the source code
    std::string value_;        // Value of the token
};

#endif //DEMOPROJECT_TOKEN_H

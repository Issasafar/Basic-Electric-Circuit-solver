//
// Created by issa on 17/05/24.
//

#include <string>
#include <utility>
#include "Token.h"
#include "Helpers.h"

/**
 * Getter method for retrieving the token type.
 *
 * @return The type of the token.
 */
TokenType Token::getType() const {
    return type_;
}

/**
 * Overloaded stream insertion operator for printing token information.
 *
 * @param os The output stream.
 * @param token The token to be printed.
 * @return The modified output stream.
 */
std::ostream &operator<<(std::ostream &os, const Token &token) {
    os << "(TOKEN) type: " << Helpers::getTokenTypeStr(token.type_) << ", value: " << token.getValue();
    return os;
}

/**
 * Getter method for retrieving the cursor position of the token.
 *
 * @return The cursor position of the token.
 */
int Token::getCursorPosition() const {
    return cursorPosition_;
}

/**
 * Constructor to initialize token properties.
 *
 * @param type The type of the token.
 * @param cursorPosition The cursor position in the source code where the token occurs.
 * @param value The value of the token.
 */
Token::Token(TokenType type, int cursorPosition, const std::string &value)
        : type_(type), cursorPosition_(cursorPosition), value_(value) {
    // Check if the token is a keyword and update its type if necessary
    if (Helpers::isKeyWord(value)) {
        type_ = TokenType::KEYWORD;
    }
}

/**
 * Getter method for retrieving the value of the token.
 *
 * @return The value of the token.
 */
const std::string &Token::getValue() const {
    return value_;
}

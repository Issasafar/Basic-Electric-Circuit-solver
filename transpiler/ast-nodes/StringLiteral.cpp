/**
 * @file StringLiteral.cpp
 * @brief Implementation of the StringLiteral class.
 * @date 17/05/24
 */

#include "StringLiteral.h"

/**
 * @brief Constructor for StringLiteral.
 *
 * @param text The string text.
 */
StringLiteral::StringLiteral(std::string text) : AstNodeBase() {
    text_ = std::move(text);
    type_ = NodeType::STRINGLITERAL;
}

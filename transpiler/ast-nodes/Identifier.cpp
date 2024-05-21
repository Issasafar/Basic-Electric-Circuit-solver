/**
 * @file Identifier.cpp
 * @brief Implementation of the Identifier class.
 * @date 17/05/24
 */

#include "Identifier.h"

/**
 * @brief Constructor for Identifier.
 *
 * @param name The identifier name.
 */
Identifier::Identifier(std::string name) : AstNodeBase() {
    text_ = name;
    type_ = NodeType::IDENTIFIER;
}

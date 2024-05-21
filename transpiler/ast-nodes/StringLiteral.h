/**
 * @file StringLiteral.h
 * @brief Declaration of the StringLiteral class.
 * @date 17/05/24
 */

#ifndef DEMOPROJECT_STRINGLITERAL_H
#define DEMOPROJECT_STRINGLITERAL_H

#include <memory>
#include <vector>
#include "AstNodeBase.h"

/**
 * @class StringLiteral
 * @brief Represents a string literal AST node.
 */
class StringLiteral : public AstNodeBase {
public:
    /**
     * @brief Constructor for StringLiteral.
     *
     * @param text The string text.
     */
    StringLiteral(std::string text);
};

#endif //DEMOPROJECT_STRINGLITERAL_H

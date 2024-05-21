/**
 * @file Identifier.h
 * @brief Declaration of the Identifier class.
 * @date 17/05/24
 */

#ifndef DEMOPROJECT_IDENTIFIER_H
#define DEMOPROJECT_IDENTIFIER_H

#include "AstNodeBase.h"

/**
 * @class Identifier
 * @brief Represents an identifier AST node.
 */
class Identifier : public AstNodeBase {
public:
    /**
     * @brief Constructor for Identifier.
     *
     * @param name The identifier name.
     */
    Identifier(std::string name);
};

#endif //DEMOPROJECT_IDENTIFIER_H

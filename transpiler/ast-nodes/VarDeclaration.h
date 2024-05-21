/**
 * @file VarDeclaration.h
 * @brief Declaration of the VarDeclaration class.
 * @date 18/05/24
 */

#ifndef DEMOPROJECT_VARDECLARATION_H
#define DEMOPROJECT_VARDECLARATION_H

#include "AstNodeBase.h"

/**
 * @class VarDeclaration
 * @brief Represents a variable declaration AST node.
 */
class VarDeclaration : public AstNodeBase {
public:
    /**
     * @brief Constructor for VarDeclaration.
     *
     * @param left The left child node.
     * @param right The right child node.
     */
    VarDeclaration(std::shared_ptr<AstNodeBase> left, std::shared_ptr<AstNodeBase> right);
};

#endif //DEMOPROJECT_VARDECLARATION_H

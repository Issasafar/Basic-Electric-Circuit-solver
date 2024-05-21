/**
 * @file VarDeclaration.cpp
 * @brief Implementation of the VarDeclaration class.
 * @date 18/05/24
 */

#include "VarDeclaration.h"

/**
 * @brief Constructor for VarDeclaration.
 *
 * @param left The left child node.
 * @param right The right child node.
 */
VarDeclaration::VarDeclaration(std::shared_ptr<AstNodeBase> left, std::shared_ptr<AstNodeBase> right) : AstNodeBase() {
    left_ = std::move(left);
    right_ = std::move(right);
    type_ = NodeType::VARDECLARATION;
}

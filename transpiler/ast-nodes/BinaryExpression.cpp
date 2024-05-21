/**
 * @file BinaryExpression.cpp
 * @brief Implementation of the BinaryExpression class.
 * @date 18/05/24
 */

#include "BinaryExpression.h"

/**
 * @brief Constructor for BinaryExpression.
 *
 * @param op The operator of the binary expression.
 * @param left The left operand.
 * @param right The right operand.
 */
BinaryExpression::BinaryExpression(std::string op, std::shared_ptr<AstNodeBase> left,
                                   std::shared_ptr<AstNodeBase> right) : AstNodeBase() {
    op_ = op;
    left_ = std::move(left);
    right_ = std::move(right);
    type_ = NodeType::BINARYEXPRESSION;
}

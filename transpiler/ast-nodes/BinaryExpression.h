/**
 * @file BinaryExpression.h
 * @brief Declaration of the BinaryExpression class.
 * @date 18/05/24
 */

#ifndef DEMOPROJECT_BINARYEXPRESSION_H
#define DEMOPROJECT_BINARYEXPRESSION_H

#include "AstNodeBase.h"

/**
 * @class BinaryExpression
 * @brief Represents a binary expression AST node.
 */
class BinaryExpression : public AstNodeBase {
public:
    /**
     * @brief Constructor for BinaryExpression.
     *
     * @param op The operator of the binary expression.
     * @param left The left operand.
     * @param right The right operand.
     */
    BinaryExpression(std::string op, std::shared_ptr<AstNodeBase> left, std::shared_ptr<AstNodeBase> right);
};

#endif //DEMOPROJECT_BINARYEXPRESSION_H

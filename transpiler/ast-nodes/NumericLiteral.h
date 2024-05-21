/**
 * @file NumericLiteral.h
 * @brief Declaration of the NumericLiteral class.
 * @date 17/05/24
 */

#ifndef DEMOPROJECT_NUMERICLITERAL_H
#define DEMOPROJECT_NUMERICLITERAL_H

#include "AstNodeBase.h"

/**
 * @class NumericLiteral
 * @brief Represents a numeric literal AST node.
 */
class NumericLiteral : public AstNodeBase {
public:
    /**
     * @brief Constructor for NumericLiteral.
     *
     * @param value The numeric value.
     */
    NumericLiteral(double value);
};

#endif //DEMOPROJECT_NUMERICLITERAL_H

/**
 * @file NumericLiteral.cpp
 * @brief Implementation of the NumericLiteral class.
 * @date 17/05/24
 */

#include "NumericLiteral.h"

/**
 * @brief Constructor for NumericLiteral.
 *
 * @param value The numeric value.
 */
NumericLiteral::NumericLiteral(double value) : AstNodeBase() {
    number_ = value;
    type_ = NodeType::NUMERICALLITERAL;
}

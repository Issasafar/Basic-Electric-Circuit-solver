//
// Created by issa on 17/05/24.
//

#include "NumericLiteral.h"

NumericLiteral::NumericLiteral(double value) : ASTNode("NumericLiteral"), value(value) {}

double NumericLiteral::getValue() const {
    return value;
}

void NumericLiteral::setValue(double value) {
    NumericLiteral::value = value;
}

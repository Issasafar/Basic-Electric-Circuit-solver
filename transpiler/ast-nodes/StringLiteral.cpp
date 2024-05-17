//
// Created by issa on 17/05/24.
//

#include "StringLiteral.h"

StringLiteral::StringLiteral( const std::string &value) : ASTNode("StringLiteral"), value(value) {}

const std::string &StringLiteral::getValue() const {
    return value;
}

void StringLiteral::setValue(const std::string &value) {
    StringLiteral::value = value;
}

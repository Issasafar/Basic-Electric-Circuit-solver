//
// Created by issa on 17/05/24.
//

#include "StringLiteral.h"

#include <utility>

StringLiteral::StringLiteral(std::string text) : AstNodeBase(){ text_ = std::move(text);}
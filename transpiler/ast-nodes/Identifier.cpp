//
// Created by issa on 17/05/24.
//

#include "Identifier.h"

Identifier::Identifier(std::string name) : AstNodeBase(){
    text_ = name;
    type_ = NodeType::IDENTIFIER;
}

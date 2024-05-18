//
// Created by issa on 18/05/24.
//

#include "VarDeclaration.h"

VarDeclaration::VarDeclaration(std::shared_ptr<AstNodeBase> left, std::shared_ptr<AstNodeBase> right) : AstNodeBase(){
    left_ = std::move(left);
    right_ = std::move(right);
    type_ = NodeType::VARDECLARATION;
}

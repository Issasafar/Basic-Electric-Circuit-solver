//
// Created by issa on 18/05/24.
//

#include "BinaryExpression.h"

BinaryExpression::BinaryExpression(std::string op, std::shared_ptr<AstNodeBase> left,
                                   std::shared_ptr<AstNodeBase> right) : AstNodeBase(){
op_ = op;
left_ = std::move(left);
right_ = std::move(right);
type_ = NodeType::BINARYEXPRESSION;
}

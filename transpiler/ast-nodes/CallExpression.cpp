//
// Created by issa on 17/05/24.
//

#include "CallExpression.h"

CallExpression::CallExpression(std::string name, std::vector<std::shared_ptr<AstNodeBase>> args) :AstNodeBase(){
    arguments_ = std::move(args);
    text_ = std::move(name);

}

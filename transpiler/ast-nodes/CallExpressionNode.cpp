//
// Created by issa on 17/05/24.
//

#include "CallExpressionNode.h"

const std::string &CallExpressionNode::getName() const {
    return name;
}

void CallExpressionNode::setName(const std::string &name) {
    CallExpressionNode::name = name;
}

const std::vector<std::shared_ptr<ASTNode>> &CallExpressionNode::getArguments() const {
    return arguments;
}

void CallExpressionNode::setArguments(const std::vector<std::shared_ptr<ASTNode>> &arguments) {
    CallExpressionNode::arguments = arguments;
}

CallExpressionNode::CallExpressionNode(const std::string &type, const std::string &name,
                                       const std::vector<std::shared_ptr<ASTNode>> &arguments) : ASTNode(type),
                                                                                                 name(name),
                                                                                                 arguments(arguments) {}

CallExpressionNode::CallExpressionNode(const std::string &name,
                                       const std::vector<std::shared_ptr<ASTNode>> &arguments) : ASTNode("CallExpression"), name(name), arguments(arguments){

}

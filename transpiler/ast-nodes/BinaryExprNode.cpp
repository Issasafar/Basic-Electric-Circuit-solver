//
// Created by issa on 17/05/24.
//

#include "BinaryExprNode.h"

const std::string &BinaryExprNode::getOp() const {
    return op_;
}

void BinaryExprNode::setOp(const std::string &op) {
    op_ = op;
}

const std::shared_ptr<ASTNode> &BinaryExprNode::getLeft() const {
    return left_;
}

void BinaryExprNode::setLeft(const std::shared_ptr<ASTNode> &left) {
    left_ = left;
}

const std::shared_ptr<ASTNode> &BinaryExprNode::getRight() const {
    return right_;
}

void BinaryExprNode::setRight(const std::shared_ptr<ASTNode> &right) {
    right_ = right;
}

std::string BinaryExprNode::to_string() const {
    return std::string("BinNode");
}

BinaryExprNode::BinaryExprNode(const std::string &type, const std::string &op, const std::shared_ptr<ASTNode> &left,
                               const std::shared_ptr<ASTNode> &right) : ASTNode(type), op_(op), left_(left),
                                                                        right_(right) {}

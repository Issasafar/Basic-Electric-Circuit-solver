//
// Created by issa on 17/05/24.
//

#ifndef DEMOPROJECT_BINARYEXPRNODE_H
#define DEMOPROJECT_BINARYEXPRNODE_H

#include <string>
#include <memory>
#include "ASTNode.h"
class BinaryExprNode : public ASTNode {
public:
    BinaryExprNode();

    BinaryExprNode(const std::string &type, const std::string &op, const std::shared_ptr<ASTNode> &left,
                   const std::shared_ptr<ASTNode> &right);

    std::string to_string() const override;

    const std::string &getOp() const;

    void setOp(const std::string &op);

    const std::shared_ptr<ASTNode> &getLeft() const;

    void setLeft(const std::shared_ptr<ASTNode> &left);

    const std::shared_ptr<ASTNode> &getRight() const;

    void setRight(const std::shared_ptr<ASTNode> &right);

private:
    std::string op_;
    std::shared_ptr<ASTNode> left_;
    std::shared_ptr<ASTNode> right_;

};


#endif //DEMOPROJECT_BINARYEXPRNODE_H

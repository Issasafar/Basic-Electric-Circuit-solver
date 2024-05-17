//
// Created by issa on 17/05/24.
//

#ifndef DEMOPROJECT_IDENTIFIERNODE_H
#define DEMOPROJECT_IDENTIFIERNODE_H

#include "ASTNode.h"
#include "boost/any.hpp"
template <typename T>
class IdentifierNode : public ASTNode{
public:
    IdentifierNode(const std::string &type, T identifier) : ASTNode(type), identifier(identifier) {}

    T getIdentifier() const {
        return identifier;
    }

    void setIdentifier(T identifier) {
        IdentifierNode::identifier = identifier;
    }

private:
    T identifier;
};


#endif //DEMOPROJECT_IDENTIFIERNODE_H

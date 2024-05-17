//
// Created by issa on 17/05/24.
//

#ifndef DEMOPROJECT_CALLEXPRESSIONNODE_H
#define DEMOPROJECT_CALLEXPRESSIONNODE_H

#include <vector>
#include <memory>
#include "ASTNode.h"
class CallExpressionNode : public ASTNode{
public:
    CallExpressionNode(const std::string &type, const std::string &name,
                       const std::vector<std::shared_ptr<ASTNode>> &arguments);
    CallExpressionNode( const std::string &name,
                       const std::vector<std::shared_ptr<ASTNode>> &arguments);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::vector<std::shared_ptr<ASTNode>> &getArguments() const;

    void setArguments(const std::vector<std::shared_ptr<ASTNode>> &arguments);

private:
    std::string name;
    std::vector<std::shared_ptr<ASTNode>> arguments;

};


#endif //DEMOPROJECT_CALLEXPRESSIONNODE_H

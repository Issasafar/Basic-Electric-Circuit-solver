//
// Created by issa on 17/05/24.
//

#ifndef DEMOPROJECT_ASTNODE_H
#define DEMOPROJECT_ASTNODE_H

#include <string>
class ASTNode {
private:
    std::string type;
public:
    explicit ASTNode(const std::string &type);

    virtual ~ASTNode() = default;
    virtual std::string to_string() const;
};


#endif //DEMOPROJECT_ASTNODE_H

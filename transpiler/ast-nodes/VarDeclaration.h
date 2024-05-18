//
// Created by issa on 18/05/24.
//

#ifndef DEMOPROJECT_VARDECLARATION_H
#define DEMOPROJECT_VARDECLARATION_H

#include "AstNodeBase.h"
class VarDeclaration : public AstNodeBase{
private:
    using AstNodeBase::getNumber;
    using AstNodeBase::getOp;
public:
    VarDeclaration(std::shared_ptr<AstNodeBase> left, std::shared_ptr<AstNodeBase> right);
};


#endif //DEMOPROJECT_VARDECLARATION_H

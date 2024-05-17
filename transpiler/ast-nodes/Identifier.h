//
// Created by issa on 17/05/24.
//

#ifndef DEMOPROJECT_IDENTIFIER_H
#define DEMOPROJECT_IDENTIFIER_H
#include "AstNodeBase.h"

class Identifier : public AstNodeBase{
private:
    using AstNodeBase::getLeft;
    using AstNodeBase::getRight;
    using AstNodeBase::getNumber;
    using AstNodeBase::getOp;
public:
    Identifier(std::string name);
};


#endif //DEMOPROJECT_IDENTIFIER_H

//
// Created by issa on 17/05/24.
//

#ifndef DEMOPROJECT_STRINGLITERAL_H
#define DEMOPROJECT_STRINGLITERAL_H

#include <memory>
#include <vector>
#include "AstNodeBase.h"
class StringLiteral :public AstNodeBase{
public:
StringLiteral(std::string text);
private:
    using AstNodeBase::getNumber;
    using AstNodeBase::getOp;
    using AstNodeBase::getLeft;
    using AstNodeBase::getRight;
    using AstNodeBase::getArguments;
};


#endif //DEMOPROJECT_STRINGLITERAL_H

//
// Created by issa on 18/05/24.
//

#ifndef DEMOPROJECT_BINARYEXPRESSION_H
#define DEMOPROJECT_BINARYEXPRESSION_H

#include "AstNodeBase.h"
class BinaryExpression : public AstNodeBase{
private:
    using AstNodeBase::getText;
    using AstNodeBase::getArguments;
    using AstNodeBase::getNumber;
public:
    BinaryExpression(std::string op, std::shared_ptr<AstNodeBase> left, std::shared_ptr<AstNodeBase> right);
};


#endif //DEMOPROJECT_BINARYEXPRESSION_H

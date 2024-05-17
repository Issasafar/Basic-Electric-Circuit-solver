//
// Created by issa on 17/05/24.
//

#ifndef DEMOPROJECT_CALLEXPRESSION_H
#define DEMOPROJECT_CALLEXPRESSION_H

#include "AstNodeBase.h"
class CallExpression : public AstNodeBase{
private:
    using AstNodeBase::getNumber;
    using AstNodeBase::getText;
    using AstNodeBase::getOp;
    using AstNodeBase::getRight;
    using AstNodeBase::getLeft;
public:
    CallExpression(std::string name, std::vector<std::shared_ptr<AstNodeBase>> args);
};


#endif //DEMOPROJECT_CALLEXPRESSION_H

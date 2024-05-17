//
// Created by issa on 17/05/24.
//

#ifndef DEMOPROJECT_NUMERICLITERAL_H
#define DEMOPROJECT_NUMERICLITERAL_H

#include "AstNodeBase.h"
class NumericLiteral :public AstNodeBase{
private:
    using AstNodeBase::getText;
    using AstNodeBase::getRight;
    using AstNodeBase::getLeft;
    using AstNodeBase::getArguments;
public:
    NumericLiteral(double value);

};


#endif //DEMOPROJECT_NUMERICLITERAL_H

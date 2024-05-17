//
// Created by issa on 17/05/24.
//

#ifndef DEMOPROJECT_NUMERICLITERAL_H
#define DEMOPROJECT_NUMERICLITERAL_H

#include "ASTNode.h"
class NumericLiteral:public ASTNode {
public:
    NumericLiteral( double value);

    double getValue() const;

    void setValue(double value);

public:

private:
    double value;
};


#endif //DEMOPROJECT_NUMERICLITERAL_H

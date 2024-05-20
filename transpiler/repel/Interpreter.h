//
// Created by issa on 20/05/24.
//

#ifndef DEMOPROJECT_INTERPRETER_H
#define DEMOPROJECT_INTERPRETER_H


#include "AstNodeVisitor.h"

class Interpreter: public AstNodeVisitor {
public:
    VisitResult visit(std::shared_ptr<AstNodeBase> node)override;
    VisitResult visitBinaryExpression(std::shared_ptr<AstNodeBase> node)override;
};


#endif //DEMOPROJECT_INTERPRETER_H

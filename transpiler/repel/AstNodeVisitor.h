//
// Created by issa on 20/05/24.
//

#ifndef DEMOPROJECT_ASTNODEVISITOR_H
#define DEMOPROJECT_ASTNODEVISITOR_H

#include "../ast-nodes/AstNodeBase.h"
#include "VisitResult.h"
#include <memory>
class AstNodeBase;
class AstNodeVisitor {
public:
    virtual ~AstNodeVisitor() = default;
    virtual VisitResult visit(std::shared_ptr<AstNodeBase> node) = 0;
    virtual VisitResult visitBinaryExpression(std::shared_ptr<AstNodeBase> node) = 0;
//    virtual VisitResult visitVarDeclaration(std::shared_ptr<AstNodeBase> node) = 0;
    virtual VisitResult visitCallExpression(std::shared_ptr<AstNodeBase> node) = 0;
};


#endif //DEMOPROJECT_ASTNODEVISITOR_H

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
//    virtual void visitCallExpression(std::shared_ptr<AstNodeBase> node) = 0;
//    virtual void visitVarDeclaration(std::shared_ptr<AstNodeBase> node) = 0;
//    virtual void visitStringLiteral(std::shared_ptr<AstNodeBase> node) = 0;
//    virtual void visitNumericLiteral(std::shared_ptr<AstNodeBase> node) = 0;
//    virtual void visitIdentifier(std::shared_ptr<AstNodeBase> node) = 0;
};


#endif //DEMOPROJECT_ASTNODEVISITOR_H

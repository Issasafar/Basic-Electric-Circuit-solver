/**
 * @file AstNodeVisitor.h
 * @brief Declaration of the AstNodeVisitor interface.
 * @date 20/05/24
 */

#ifndef DEMOPROJECT_ASTNODEVISITOR_H
#define DEMOPROJECT_ASTNODEVISITOR_H

#include "../ast-nodes/AstNodeBase.h"
#include "VisitResult.h"
#include <memory>
class AstNodeBase;

/**
 * @class AstNodeVisitor
 * @brief Interface for visiting AST nodes.
 */
class AstNodeVisitor {
public:
    /**
     * @brief Destructor for the AstNodeVisitor class.
     */
    virtual ~AstNodeVisitor() = default;

    /**
     * @brief Visits an AST node.
     *
     * @param node The AST node to visit.
     * @return The result of visiting the node.
     */
    virtual VisitResult visit(std::shared_ptr<AstNodeBase> node) = 0;

    /**
     * @brief Visits a binary expression node in the AST.
     *
     * @param node The binary expression node to visit.
     * @return The result of visiting the node.
     */
    virtual VisitResult visitBinaryExpression(std::shared_ptr<AstNodeBase> node) = 0;

    /**
     * @brief Visits a call expression node in the AST.
     *
     * @param node The call expression node to visit.
     * @return The result of visiting the node.
     */
    virtual VisitResult visitCallExpression(std::shared_ptr<AstNodeBase> node) = 0;
};

#endif //DEMOPROJECT_ASTNODEVISITOR_H

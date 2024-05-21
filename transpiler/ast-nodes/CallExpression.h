/**
 * @file CallExpression.h
 * @brief Declaration of the CallExpression class.
 * @date 17/05/24
 */

#ifndef DEMOPROJECT_CALLEXPRESSION_H
#define DEMOPROJECT_CALLEXPRESSION_H

#include "AstNodeBase.h"

/**
 * @class CallExpression
 * @brief Represents a function call expression AST node.
 */
class CallExpression : public AstNodeBase {
public:
    /**
     * @brief Constructor for CallExpression.
     *
     * @param name The name of the function being called.
     * @param args The arguments passed to the function.
     */
    CallExpression(std::string name, std::vector<std::shared_ptr<AstNodeBase>> args);
};

#endif //DEMOPROJECT_CALLEXPRESSION_H

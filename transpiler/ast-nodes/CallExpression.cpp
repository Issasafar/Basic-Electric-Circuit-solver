/**
 * @file CallExpression.cpp
 * @brief Implementation of the CallExpression class.
 * @date 17/05/24
 */

#include "CallExpression.h"

/**
 * @brief Constructor for CallExpression.
 *
 * @param name The name of the function being called.
 * @param args The arguments passed to the function.
 */
CallExpression::CallExpression(std::string name, std::vector<std::shared_ptr<AstNodeBase>> args) : AstNodeBase() {
    arguments_ = std::move(args);
    text_ = std::move(name);
    type_ = NodeType::CALLEXPRESSION;
}

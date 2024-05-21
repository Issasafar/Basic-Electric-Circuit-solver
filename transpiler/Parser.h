//
// Created by issa on 17/05/24.
//

#ifndef DEMOPROJECT_PARSER_H
#define DEMOPROJECT_PARSER_H

#include "Token.h"
#include "ast-nodes/AstNodeBase.h"  // Include the base class for AST nodes
#include <memory>
#include "boost/any.hpp"

/**
 * @brief Parses a sequence of tokens into an abstract syntax tree (AST).
 * @param tokens The tokens to be parsed.
 * @return A shared pointer to the root of the AST.
 */
std::shared_ptr<AstNodeBase> parse(std::vector<Token> tokens);

/**
 * @brief Creates a parenthesized expression AST node from a sequence of tokens.
 * @param tokens The tokens representing the parenthesized expression.
 * @return A shared pointer to the parenthesized expression AST node.
 */
std::shared_ptr<AstNodeBase> parenthesize(std::vector<Token> tokens);

/**
 * @brief Builds an abstract syntax tree (AST) from a sequence of tokens.
 * @param tokens The tokens to build the AST from.
 * @return A shared pointer to the root of the AST.
 */
std::shared_ptr<AstNodeBase> buildAstTree(std::vector<Token> tokens);

#endif // DEMOPROJECT_PARSER_H

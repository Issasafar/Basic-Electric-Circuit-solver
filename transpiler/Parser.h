//
// Created by issa on 17/05/24.
//

#ifndef DEMOPROJECT_PARSER_H
#define DEMOPROJECT_PARSER_H
#include "Token.h"
#include "ast-nodes/AstNodeBase.h"
#include <memory>
#include "boost/any.hpp"
std::shared_ptr<AstNodeBase> parse(std::vector<Token> tokens);
std::shared_ptr<AstNodeBase> parenthesize(std::vector<Token> tokens);
std::shared_ptr<AstNodeBase> buildAstTree(std::vector<Token> tokens);


#endif //DEMOPROJECT_PARSER_H

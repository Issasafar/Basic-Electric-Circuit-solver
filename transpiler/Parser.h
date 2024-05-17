//
// Created by issa on 17/05/24.
//

#ifndef DEMOPROJECT_PARSER_H
#define DEMOPROJECT_PARSER_H
#include<memory>
#include "ast-nodes/ASTNode.h"
#include "Token.h"
std::shared_ptr<ASTNode> parse(Token token);


#endif //DEMOPROJECT_PARSER_H

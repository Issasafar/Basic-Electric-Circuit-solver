//
// Created by issa on 17/05/24.
//

#include "Parser.h"
#include "ast-nodes/ASTNode.h"
#include "ast-nodes/BinaryExprNode.h"
#include "ast-nodes/CallExpressionNode.h"
#include "ast-nodes/IdentifierNode.h"
#include "ast-nodes/NumericLiteral.h"
#include "ast-nodes/StringLiteral.h"

std::shared_ptr<ASTNode> parse(Token token){
   if(token.getType() == TokenType::NUMBER) {
       return std::make_shared<ASTNode>(NumericLiteral(std::get<int>(token.getValue())));
   }
   if(token.getType() == TokenType::STRING){
       return std::make_shared<ASTNode>(StringLiteral(std::get<std::string>(token.getValue())));
   }
throw std::runtime_error("invalid syntax");
}
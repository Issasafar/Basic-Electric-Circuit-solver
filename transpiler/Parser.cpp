//
// Created by issa on 17/05/24.
//

#include "Parser.h"
#include "ast-nodes/NumericLiteral.h"
#include "ast-nodes/StringLiteral.h"
#include "ast-nodes/Identifier.h"
#include <sstream>

boost::any parse(Token token){
    if(token.getType()  == TokenType::NUMBER){
        return {(NumericLiteral(std::stod(token.getValue())))};
    }
    if(token.getType() == TokenType::STRING){
        return {(StringLiteral(token.getValue()))};
    }
    if(token.getType() == TokenType::NAME){
        return {(Identifier(token.getValue()))};
    }
    std::stringstream ss;
    ss<<"parser error"<<token;
    throw std::runtime_error(ss.str());

}
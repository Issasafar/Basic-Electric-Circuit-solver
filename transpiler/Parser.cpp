//
// Created by issa on 17/05/24.
//

#include "Parser.h"
#include "ast-nodes/NumericLiteral.h"
#include "ast-nodes/StringLiteral.h"
#include "ast-nodes/Identifier.h"
#include "ast-nodes/CallExpression.h"
#include "ast-nodes/VarDeclaration.h"
#include "ast-nodes/BinaryExpression.h"
#include "TranspilerException.h"
#include <sstream>
#include <iostream>
#include "Helpers.h"

std::vector<std::shared_ptr<AstNodeBase>> buildAstTree(std::vector<Token> tokens) {
    for (auto it = tokens.begin(); it != tokens.end(); ++it) {
        if (it->getType() == TokenType::NAME) {
            auto next = std::next(it);
            if ((next != tokens.end())&&((next)->getType() == TokenType::DOTACCESS)) {
                int tokensToRemove = 1;
                next = std::next(next);
                std::vector<Token> arguments;
                if (std::next(next)->getType() == TokenType::PARENTHESIS) {
                    while ((std::next(next) != tokens.end()) && (!Helpers::isClosingParenthesis(std::next(next)->getValue()[0]))) {
                        // collect the arguments
                        arguments.push_back(*next);
                        ++tokensToRemove;
                        next;
                    }
                    tokensToRemove += 2;
                }
                Token nameTk = *it;
                tokens.erase(it, it + tokensToRemove);
                tokens.insert(it, Token(TokenType::PARENTHESIS, 0, ")"));
                for (Token tk: arguments) {
                    tokens.insert(it,tk);
                }
                tokens.insert(it, nameTk);
                tokens.insert(it, Token(TokenType::PARENTHESIS, 0, "("));
                tokens.insert(it, Token(TokenType::NAME, 0, next->getValue()));
            }
        }
    }
    std::vector<std::shared_ptr<AstNodeBase>> result;
    result.push_back(parenthesize(tokens));
    return result;
}

std::shared_ptr<AstNodeBase> parenthesize(std::vector<Token> tokens) {
    Token token = tokens.at(0);
    if (Helpers::isOpeneningParenthesis(token.getValue()[0])) {
        tokens.erase(tokens.begin());
        std::shared_ptr<AstNodeBase> expression;
        std::vector<Token> args;
        while (!Helpers::isClosingParenthesis(tokens.at(0).getValue()[0])) {
            // here is the logic
            // collect the arguments
            args.push_back(tokens.at(0));
            tokens.erase(tokens.begin());
        }
        expression = parse(args);
        tokens.erase(tokens.begin());
        return expression;
    }
    return parse(tokens);
}

std::shared_ptr<AstNodeBase> parse(std::vector<Token> tokens) {
//    if(Helpers::isOpeneningParenthesis(tokens.at(0).getValue()[0])){
//       return parenthesize(tokens);
//    }
    Token first = tokens.at(0);
    if (tokens.size() >= 2 && (first.getType() == TokenType::NUMBER || first.getType() == STRING ||
                               first.getType() == NAME)) {
        if (tokens.at(1).getType() == OPERATOR) {
            std::string opr = tokens.at(1).getValue();
            if (tokens.at(2).getType() == TokenType::NUMBER || tokens.at(2).getType() == TokenType::NAME ||
                tokens.at(2).getType() == TokenType::STRING || tokens.at(2).getType() == TokenType::PARENTHESIS) {
                // remove first arg and op
                tokens.erase(tokens.begin(), tokens.begin() + 2);
                return (
                        std::make_shared<AstNodeBase>(BinaryExpression(opr, parse({first}), parenthesize(tokens))));
            } else {
                throw TranspilerException("invalid operation: " + first.getValue() + opr + tokens.at(2).getValue());
            }
        }
    }
    if (tokens.size() > 1 && tokens.at(0).getType() == TokenType::KEYWORD && tokens.at(0).getValue() == "let") {
        tokens.erase(tokens.begin());
        Token varToken = Token(TokenType::NAME, tokens.at(0).getCursorPosition(), tokens.at(0).getValue());
        tokens.erase(tokens.begin());
        if (tokens.at(0).getType() == TokenType::EQUAL) {
            tokens.erase(tokens.begin());
        } else {
            throw TranspilerException("variable assigment need =");
        }
        return std::make_shared<AstNodeBase>(VarDeclaration(parse({varToken}), parenthesize(tokens)));
    }
    if (tokens.size() > 1) {
        tokens.erase(tokens.begin());
        std::vector<std::shared_ptr<AstNodeBase>> args;
        if (Helpers::isOpeneningParenthesis(tokens.at(0).getValue()[0])) {
            tokens.erase(tokens.begin());
            while (!Helpers::isClosingParenthesis(tokens.at(0).getValue()[0])) {
                args.push_back(parse({tokens.at(0)}));
                tokens.erase(tokens.begin());
            }
            tokens.erase(tokens.begin());
        }
        return std::make_shared<AstNodeBase>(CallExpression(first.getValue(), args));
    }
    if (first.getType() == TokenType::NUMBER) {
        return std::make_shared<AstNodeBase>(NumericLiteral(std::stod(first.getValue())));
    }
    if (first.getType() == TokenType::STRING) {
        return std::make_shared<AstNodeBase>(StringLiteral(first.getValue()));
    }
    if (first.getType() == TokenType::NAME) {
        std::cout << "Parsing Name" << first << std::endl;
        return std::make_shared<AstNodeBase>(Identifier(first.getValue()));
    }
    std::stringstream ss;
    ss << "Syntax Error " << first;
    throw TranspilerException(ss.str());

}
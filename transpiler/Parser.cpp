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

std::shared_ptr<AstNodeBase> buildAstTree(std::vector<Token> tokens) {
    int i = 0;
    for (auto it = tokens.begin(); it != tokens.end(); ++it) {
        // convert the var.call(args) into call(var args)
        if (it->getType() == TokenType::NAME) {
            auto dotPosition = it + 1;
            auto namePosition = it + 2;
            auto openParenthesisPosition = it + 3;
            bool isNextDot =
                    (dotPosition != tokens.end()) && (dotPosition->getType() == TokenType::DOTACCESS);
            bool namePresent = (namePosition != tokens.end()) && (namePosition->getType() == TokenType::NAME);
            bool openParenthesisPresent =
                    (openParenthesisPosition != tokens.end()) && (openParenthesisPosition->getValue() == "(");
            if (isNextDot && namePresent && openParenthesisPresent) {
                Token variable = *it;
                tokens.insert(openParenthesisPosition + 1, variable);
                it = tokens.begin() + i;
                tokens.erase(it, it + 2);
                it = tokens.begin() + i;
            }
        }
        if (it->getType() == TokenType::OPERATOR) {
            auto nextArgumentPosition = it + 1;
            auto nextOperatorPosition = it + 2;
            bool nextIsNotParenthesis =
                    (nextArgumentPosition != tokens.end()) && nextArgumentPosition->getType() != TokenType::PARENTHESIS;
            bool nextOperatorPresent =
                    (nextOperatorPosition != tokens.end()) && nextOperatorPosition->getType() == TokenType::OPERATOR;
            bool isNextHigher = (nextOperatorPosition != tokens.end()) &&
                                Helpers::isHighOperator(nextOperatorPosition->getValue()[0]) &&
                                Helpers::isLowOperator(it->getValue()[0]);
            if (nextOperatorPresent && nextIsNotParenthesis && isNextHigher) {
                // insert () to insure the operator precedent
                tokens.insert(nextArgumentPosition, Token(TokenType::PARENTHESIS, 0, "("));
                it = tokens.begin() + i;
                auto closingPosition = it + 5;
                tokens.insert(closingPosition, Token(TokenType::PARENTHESIS, 0, ")"));
                it = tokens.begin() + i + 4;
                i += 4;
            }
        }

        ++i;
    }
    return parenthesize(tokens);
}


std::shared_ptr<AstNodeBase> parenthesize(std::vector<Token> tokens) {
    Token token = tokens.at(0);
    if (Helpers::isOpeneningParenthesis(token.getValue()[0])) {
        tokens.erase(tokens.begin());
        std::shared_ptr<AstNodeBase> expression;
        std::vector<Token> args;
        while (!Helpers::isClosingParenthesis(tokens.at(0).getValue()[0])) {
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
    ss << "Syntax Error: Unexpected token at -> " << first;
    throw TranspilerException(ss.str());

}
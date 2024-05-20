//
// Created by issa on 20/05/24.
//

#include "Interpreter.h"
#include "AstHelpers.h"
#include "VisitResult.h"

VisitResult Interpreter::visit(std::shared_ptr<AstNodeBase> node) {
    if(node->getType() == BINARYEXPRESSION){
        return visitBinaryExpression(node);
    }
    throw std::runtime_error("sthg went wrong");
}

VisitResult Interpreter::visitBinaryExpression(std::shared_ptr<AstNodeBase> node) {
   if(AstHelpers::isLeafNode((node))){
       if(node->getType() == NUMERICALLITERAL){
           return { std::stod(node->getText()),NUMERIC_ };
       }
   }
   if(AstHelpers::isInternalNode(node)){
       VisitResult left = visit(node->getLeft());
       VisitResult right = visit(node->getRight());
   }
    throw std::runtime_error("sthg went wrong");
}

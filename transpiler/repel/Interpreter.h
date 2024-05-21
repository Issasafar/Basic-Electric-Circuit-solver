//
// Created by issa on 20/05/24.
//

#ifndef DEMOPROJECT_INTERPRETER_H
#define DEMOPROJECT_INTERPRETER_H


#include "AstNodeVisitor.h"
#include "../../concrete/ComponentsFactory.h"
const std::vector<std::string> callers {"print","variables","erase","solve","Node","Ground","Component","Resistance","Branch","Circuit","VoltageSource","CurrentSource"};
class Interpreter: public AstNodeVisitor {
public:
    VisitResult visit(std::shared_ptr<AstNodeBase> node)override;
    VisitResult visitBinaryExpression(std::shared_ptr<AstNodeBase> node)override;
//    VisitResult visitVarDeclaration(std::shared_ptr<AstNodeBase> node) override;
    VisitResult visitCallExpression(std::shared_ptr<AstNodeBase> node) override;
private:
    std::string operatorErrorMessage = "Invalid arguments for operator: ";
    std::unordered_map<std::string, VisitResult> variables;
    ComponentsFactory cf = ComponentsFactory();
    std::string findCaller(std::string caller);
    VisitResult multiply(VisitResult result, VisitResult result1);

    VisitResult divide(VisitResult left, VisitResult right);

    VisitResult add(VisitResult left, VisitResult right);

    VisitResult subtract(VisitResult left, VisitResult right);

    std::vector<double> getDoubleValues(VisitResult left, VisitResult right);

    VisitResult findVariable(const std::string &variableName);

    std::vector<VisitResult> getVisitedArgs(const std::shared_ptr<AstNodeBase> &node);

    Component getComponent(VisitResult temp);

    Component handleComponents(VisitResult left, VisitResult right, std::string op);
};


#endif //DEMOPROJECT_INTERPRETER_H

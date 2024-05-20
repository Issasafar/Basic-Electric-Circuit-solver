//
// Created by issa on 20/05/24.
//

#include <variant>
#include "Interpreter.h"
#include "AstHelpers.h"
#include "VisitResult.h"
#include "../TranspilerException.h"
#include <sstream>

VisitResult Interpreter::visit(std::shared_ptr<AstNodeBase> node) {
    if (node->getType() == BINARYEXPRESSION) {
        return visitBinaryExpression(node);
    }
    if (node->getType() == CALLEXPRESSION) {
        return visitCallExpression(node);
    }
    if (node->getType() == VARDECLARATION) {
        std::string newVariable = node->getLeft()->getText();
        auto it = variables.insert({(newVariable), visit(node->getRight())});
        if (it.second) {
            auto inserted = *it.first;
            return inserted.second;
        } else {
            throw TranspilerException("Unable to Declare object " + newVariable);
        }
    }
    if (node->getType() == IDENTIFIER) {
        std::string variableName = node->getText();
        return findVariable(variableName);
    }
    if (AstHelpers::isLeafNode((node))) {
        if (node->getType() == NUMERICALLITERAL) {
            return {node->getNumber(), NUMERIC_};
        }
        if (node->getType() == STRINGLITERAL) {
            return {node->getText(), STRING_};
        }
    }
    throw TranspilerException("something went wrong");
}

VisitResult Interpreter::findVariable(const std::string &variableName) {
    auto it = variables.find(variableName);
    if (it != variables.end()) {
        return variables.at(variableName);
    } else {
        throw TranspilerException("Undefined symbol " + variableName);
    }
}

VisitResult Interpreter::visitBinaryExpression(std::shared_ptr<AstNodeBase> node) {
    if (AstHelpers::isLeafNode((node))) {
        if (node->getType() == NUMERICALLITERAL) {
            return {node->getNumber(), NUMERIC_};
        }
        if (node->getType() == STRINGLITERAL) {
            return {node->getText(), STRING_};
        }
    }
    if (AstHelpers::isInternalNode(node)) {
        VisitResult left = visit(node->getLeft());
        VisitResult right = visit(node->getRight());
        if (left.getType() == right.getType()) {
            if (node->getOp() == "*") {
                return multiply(left, right);
            } else if (node->getOp() == "/") {
                return divide(left, right);
            } else if (node->getOp() == "+") {
                return add(left, right);
            } else if (node->getOp() == "-") {
                return subtract(left, right);
            }
        }
        if (left.getType() == STRING_ && right.getType() == NUMERIC_ && node->getOp() == "*") {
            int rightValue = boost::get<double>(right.getValue());
            std::string leftString = boost::get<std::string>(left.getValue());
            std::stringstream ss;
            while (rightValue--) {
                ss << leftString;
            }
            return {ss.str(), STRING_};
        }

    }
    throw std::runtime_error("BinaryExpressionError");
}

VisitResult Interpreter::multiply(VisitResult left, VisitResult right) {
    if (left.getType() == NUMERIC_) {
        std::vector<double> values = getDoubleValues(left, right);
        return {values[0] * values[1], NUMERIC_};
    }
    throw TranspilerException(operatorErrorMessage + "*");
}

VisitResult Interpreter::divide(VisitResult left, VisitResult right) {
    if (left.getType() == NUMERIC_) {
        std::vector<double> values = getDoubleValues(left, right);
        return {values[0] / values[1], NUMERIC_};
    }
    throw TranspilerException(operatorErrorMessage + "/");
}

VisitResult Interpreter::add(VisitResult left, VisitResult right) {
    if (left.getType() == NUMERIC_) {
        std::vector<double> values = getDoubleValues(left, right);
        return {values[0] + values[1], NUMERIC_};
    }
    if (left.getType() == STRING_) {
        std::string leftStr = boost::get<std::string>(left.getValue());
        std::string rightStr = boost::get<std::string>(right.getValue());
        return {leftStr + rightStr, STRING_};
    }
    throw TranspilerException(operatorErrorMessage + "+");
}

VisitResult Interpreter::subtract(VisitResult left, VisitResult right) {
    if (left.getType() == NUMERIC_) {
        std::vector<double> values = getDoubleValues(left, right);
        return {values[0] - values[1], NUMERIC_};
    }
    throw TranspilerException(operatorErrorMessage + "-");
}

std::vector<double> Interpreter::getDoubleValues(VisitResult left, VisitResult right) {
    return std::vector<double>{boost::get<double>(left.getValue()), boost::get<double>(right.getValue())};
}

std::string Interpreter::findCaller(std::string caller) {
    auto it = std::find(callers.begin(), callers.end(), caller);
    if (it != callers.end()) {
        return *it;
    } else {
        throw TranspilerException("Unknown function or caller: '" + caller + "'");
    }
}

VisitResult Interpreter::visitCallExpression(std::shared_ptr<AstNodeBase> node) {
    std::string caller = findCaller(node->getText());
    if (caller == "print") {
        std::stringstream ss;
        for (auto arg: node->getArguments()) {
            VisitResult result = visit(arg);
            ss << result.to_string();
        }
        std::cout << ss.str();
        return {0, NUMERIC_};
    }
    if (caller == "erase") {
        variables.erase(variables.begin(), variables.end());
        return {0, NUMERIC_};
    }
    if (caller == "variables") {
        std::vector<std::string> strVector;
        std::stringstream ss;
        ss<<"Variables: ";
        for (auto &variable: variables) {
            strVector.push_back(variable.first);
        }
        for (auto it = strVector.begin(); it != strVector.end(); ++it) {
            ss<<*it;
            if(it+1 != strVector.end()){
                ss<<", ";
            }
        }
        ss << std::endl;
        std::cout << ss.str();
        return {0, NUMERIC_};
    }
    if (caller == "solve") {
        std::string circuitName = node->getArguments().at(0)->getText();
        VisitResult circuitNameVariable = findVariable(circuitName);
        Circuit circuit = boost::get<Circuit>(circuitNameVariable.getValue());
        circuit.solve();
        std::cout << circuit.get_matrix_string() << std::endl;
        variables.at(circuitName) = VisitResult(circuit, COMPONENT);
        return variables.at(circuitName);
    }
    if (caller == "Node") {
        return {cf.get_node(), NODE_};
    }
    if (caller == "Ground") {
        return {cf.get_ground(), NODE_};
    }
    if (caller == "Circuit") {
        std::vector<VisitResult> visitedArgs = getVisitedArgs(node);
        std::vector<Branch> branches;
        for (VisitResult branchVariable: visitedArgs) {
            branches.push_back(boost::get<Branch>(branchVariable.getValue()));
        }
        Circuit circuit = Circuit(branches);
        circuit.solve();
        return {circuit, CIRCUIT};
    }
    if (caller == "Resistance" || caller == "VoltageSource" || caller == "CurrentSource" || caller == "Component") {
        std::vector<VisitResult> visitedArguments = getVisitedArgs(node);
        if (visitedArguments.at(0).getType() == NUMERIC_ && visitedArguments.at(1).getType() == NODE_ &&
            visitedArguments.at(2).getType() == NODE_) {
            double value = boost::get<double>(visitedArguments.at(0).getValue());
            std::shared_ptr<Node> startNode = boost::get<std::shared_ptr<Node>>(visitedArguments.at(1).getValue());
            std::shared_ptr<Node> endNode = boost::get<std::shared_ptr<Node>>(visitedArguments.at(2).getValue());
            if (caller == "Resistance") {
                Resistance resistance = cf.get_resistance(value, startNode, endNode);
                return {resistance, RESISTANCE};
            }
            if (caller == "VoltageSource") {
                VoltageSource voltageSource = cf.get_voltage_source(value, startNode, endNode);
                return {voltageSource, VOLTAGESOURCE};
            }
            if (caller == "CurrentSource") {
                CurrentSource currentSource = cf.get_current_source(value, startNode, endNode);
                return {currentSource, CURRENTSOURCE};
            }
            if (caller == "Component") {
                Component component = Component(value, startNode, endNode);
                return {component, COMPONENT};
            }
        } else {
            throw TranspilerException("Invalid arguments for calling: '" + caller + "'");
        }
    }
    if (caller == "Branch") {
        std::vector<VisitResult> visitedArgs = getVisitedArgs(node);
        std::vector<boost::any> components;
        for (VisitResult componentVariable: visitedArgs) {
            if (componentVariable.getType() == RESISTANCE) {
                Resistance r = boost::get<Resistance>(componentVariable.getValue());
                components.emplace_back(r);
            }
            if (componentVariable.getType() == VOLTAGESOURCE) {
                VoltageSource vs = boost::get<VoltageSource>(componentVariable.getValue());
                components.emplace_back(vs);
            }
            if (componentVariable.getType() == CURRENTSOURCE) {
                CurrentSource cs = boost::get<CurrentSource>(componentVariable.getValue());
                components.emplace_back(cs);
            }
        }
        Branch branch = cf.get_branch(components);
        return {branch, BRANCH};
    }
    throw TranspilerException("Unknown caller: '" + caller + "'");

}

std::vector<VisitResult> Interpreter::getVisitedArgs(const std::shared_ptr<AstNodeBase> &node) {
    std::vector<VisitResult> visitedArguments;
    for (const auto &it: node->getArguments()) {
        visitedArguments.push_back(visit(it));
    }
    return visitedArguments;
}

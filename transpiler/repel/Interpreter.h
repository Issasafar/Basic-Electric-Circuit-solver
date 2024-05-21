//
// Created by issa on 20/05/24.
//

#ifndef DEMOPROJECT_INTERPRETER_H
#define DEMOPROJECT_INTERPRETER_H

#include "AstNodeVisitor.h"
#include "../../concrete/ComponentsFactory.h"

/**
 * Class for interpreting abstract syntax tree nodes.
 */
class Interpreter : public AstNodeVisitor {
public:
    /**
     * Visit a node in the abstract syntax tree.
     *
     * @param node The node to visit.
     * @return The result of visiting the node.
     */
    VisitResult visit(std::shared_ptr<AstNodeBase> node) override;

    /**
     * Visit a binary expression node in the abstract syntax tree.
     *
     * @param node The binary expression node to visit.
     * @return The result of visiting the binary expression node.
     */
    VisitResult visitBinaryExpression(std::shared_ptr<AstNodeBase> node) override;

    /**
     * Visit a call expression node in the abstract syntax tree.
     *
     * @param node The call expression node to visit.
     * @return The result of visiting the call expression node.
     */
    VisitResult visitCallExpression(std::shared_ptr<AstNodeBase> node) override;

private:
    std::string operatorErrorMessage = "Invalid arguments for operator: ";  // Error message for invalid operator arguments
    std::unordered_map<std::string, VisitResult> variables;  // Map to store variable values
    ComponentsFactory cf = ComponentsFactory();  // Factory for creating components
    const std::vector<std::string> callers {"print", "variables", "describe", "erase", "solve", "Node", "Ground", "Component", "Resistance", "Branch", "Circuit", "VoltageSource", "CurrentSource"};  // List of function callers

    /**
     * Find the appropriate caller for a given name.
     *
     * @param caller The name of the caller.
     * @return The appropriate caller.
     */
    std::string findCaller(std::string caller);

    /**
     * Perform multiplication operation.
     *
     * @param result The first operand.
     * @param result1 The second operand.
     * @return The result of the multiplication.
     */
    VisitResult multiply(VisitResult result, VisitResult result1);

    /**
     * Perform division operation.
     *
     * @param left The numerator.
     * @param right The denominator.
     * @return The result of the division.
     */
    VisitResult divide(VisitResult left, VisitResult right);

    /**
     * Perform addition operation.
     *
     * @param left The first operand.
     * @param right The second operand.
     * @return The result of the addition.
     */
    VisitResult add(VisitResult left, VisitResult right);

    /**
     * Perform subtraction operation.
     *
     * @param left The minuend.
     * @param right The subtrahend.
     * @return The result of the subtraction.
     */
    VisitResult subtract(VisitResult left, VisitResult right);

    /**
     * Get the double values from visit results.
     *
     * @param left The left operand.
     * @param right The right operand.
     * @return The double values of the operands.
     */
    std::vector<double> getDoubleValues(VisitResult left, VisitResult right);

    /**
     * Find the value of a variable.
     *
     * @param variableName The name of the variable.
     * @return The value of the variable.
     */
    VisitResult findVariable(const std::string &variableName);

    /**
     * Get the visited arguments from a call expression node.
     *
     * @param node The call expression node.
     * @return The visited arguments.
     */
    std::vector<VisitResult> getVisitedArgs(const std::shared_ptr<AstNodeBase> &node);

    /**
     * Get the component from a visit result.
     *
     * @param temp The visit result containing the component.
     * @return The component.
     */
    Component getComponent(VisitResult temp);

    /**
     * Handle component operations.
     *
     * @param left The left operand.
     * @param right The right operand.
     * @param op The operator.
     * @return The result of the operation.
     */
    Component handleComponents(VisitResult left, VisitResult right, std::string op);
};

#endif //DEMOPROJECT_INTERPRETER_H

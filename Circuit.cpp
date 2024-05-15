//
// Created by issa on 11/05/24.
//

#include "Circuit.h"
#include "CircuitException.h"
#include <Eigen/Dense>
#include <utility>
#include <algorithm>

using Eigen::MatrixXd;
using Eigen::VectorXd;

// Default constructor for the Circuit class.
Circuit::Circuit() = default;

// Constructor for the Circuit class initializing with a vector of Branches.
Circuit::Circuit(std::vector<Branch> branches) {
    branchesVector = std::move(branches);
    // Calculate the total number of equations required based on the number of components in all branches.
    for (Branch branch: branchesVector) {
        equationsCount += branch.components().size();
    }
}

// Returns the vector of branches in the circuit.
b_vec Circuit::branches() { return branchesVector; }

// Inserts a node into the set of nodes in the circuit.
void Circuit::insert_node(std::shared_ptr<Node> node) {
    setOfNodes.insert(node);
}

// Adds a branch to the circuit and updates the equations count accordingly.
void Circuit::add_branch(Branch branch) {
    branchesVector.push_back(branch);
    equationsCount += branch.components().size();
}

// Solves the circuit using matrix equations and returns the solution vector.
VectorXd Circuit::solve() {
    // Initialize the matrix and vector for solving the circuit equations.
    matrix = MatrixXd::Zero(equationsCount, equationsCount);
    vector = VectorXd::Zero(equationsCount);
    int row{0};

    // Iterate through each branch and each component within the branch to fill the matrix and vector.
    for (auto branch: branches()) {
        for (auto component: branch.components()) {
            insert_node(component->startNode());
            insert_node(component->endNode());

            // Handle VoltageSource components.
            if (branch.types_map().at(component) == "VoltageSource") {
                if (component->startNode()->number() != Node::ground().number()) {
                    matrix(row, component->startNode()->number()) = -1;
                }
                if (component->endNode()->number() != Node::ground().number()) {
                    matrix(row, component->endNode()->number()) = 1;
                }
                vector(row) = component->voltage();
            }

            // Handle CurrentSource components.
            if (branch.types_map().at(component) == "CurrentSource") {
                matrix(row, equationsCount - 1 - branch.number()) = 1;
                vector(row) = component->current();
            }

            // Handle Resistance components.
            if (branch.types_map().at(component) == "Resistance") {
                if (component->startNode()->number() != Node::ground().number()) {
                    matrix(row, component->startNode()->number()) = 1;
                }
                if (component->endNode()->number() != Node::ground().number()) {
                    matrix(row, component->endNode()->number()) = -1;
                }
                matrix(row, equationsCount - 1 - branch.number()) = -component->resistance();
                insert_branch(std::make_shared<Branch>(branch));
            }

            // Move to the next row in the matrix for the next component'setOfNodes equation.
            ++row;
        }
    }
    auto it = std::find_if(setOfNodes.begin(), setOfNodes.end(), [](std::shared_ptr<Node> node){return node->number() == -1;});
    bool ground_found = it != setOfNodes.end();
    if (!ground_found) {
        throw CircuitException("The Circuit is not grounded");
    }
    // Solve the matrix equation.
    VectorXd result = VectorXd::Zero(equationsCount);
    result = matrix.colPivHouseholderQr().solve(vector);

    // Update the circuit'setOfNodes state with the solution.
    is_solved = true;
    solution = result;
    update_node_voltages(result);
    update_branches_current(result);

    return result;
}

// Inserts a branch into the set of branches in the circuit.
void Circuit::insert_branch(std::shared_ptr<Branch> branch) {
    setOfBranches.insert(branch);
}

// Updates the currents in all branches based on the solution vector.
void Circuit::update_branches_current(Eigen::VectorXd data) {
    for (auto branch: setOfBranches) {
        branch->current(data(data.size() - 1 - branch->number()));
    }
}

// Updates the voltages at all nodes based on the solution vector.
void Circuit::update_node_voltages(Eigen::VectorXd data) {
    for (auto node: setOfNodes) {
        if (node->number() != -1) {
            node->set_voltage(data(node->number()));
        }
    }
}

// Prints the matrix, vector, and solution if the circuit is solved.
void Circuit::print_matrix() {
    if (!is_solved) {
        throw CircuitException("The circuit is not solved");
    }

    std::stringstream ss;
    unsigned long maxMatrixLength = 0;
    unsigned long maxVectorLength = 0;
    unsigned long maxSolutionLength = 0;

    // Iterate through the matrix, vector, and solution to determine the maximum lengths for formatting.
    for (int j = 0; j < equationsCount; ++j) {
        std::stringstream tempStream;
        for (int i = 0; i < equationsCount; ++i) {
            tempStream.str(std::string());
            tempStream << " " << matrix(i, j) << "\t";
            if (tempStream.str().length() > maxMatrixLength) {
                maxMatrixLength = tempStream.str().length();
            }
            ss << tempStream.str();
        }
        tempStream.str(std::string());
        tempStream << "|\t" << vector(j) << "\t";
        if (tempStream.str().length() > maxVectorLength) {
            maxVectorLength = tempStream.str().length();
        }
        ss << tempStream.str();
        tempStream.str(std::string());
        tempStream << "||\t" << solution(j) << std::endl;
        if (tempStream.str().length() > maxSolutionLength) {
            maxSolutionLength = tempStream.str().length();
        }
        ss << tempStream.str();
    }

    maxMatrixLength *= 3;

    // Print formatted matrix, vector, and solution headers.
    for (int i = 0; i <= maxMatrixLength; ++i) {
        if (i == maxMatrixLength / 2) {
            std::cout << " MATRIX ";
        } else {
            std::cout << "-";
        }
    }

    for (int i = 0; i <= maxVectorLength; ++i) {
        if (i == maxVectorLength / 2) {
            std::cout << " VECTOR ";
        } else {
            std::cout << "-";
        }
    }

    for (int i = 0; i <= maxSolutionLength; ++i) {
        if (i == maxSolutionLength / 2) {
            std::cout << " SOLUTION ";
        } else {
            std::cout << "-";
        }
    }

    std::cout << std::endl;
    std::cout << ss.str() << std::endl;
}

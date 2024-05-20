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

std::string Circuit::to_string() {
    std::stringstream ss;
    ss<<"Circuit with: "<<std::endl;
    for(auto branch : branches()){
        ss<<branch.to_string();
    }
    return ss.str();

}
// Default constructor for the Circuit class.
Circuit::Circuit() = default;

// Constructor for the Circuit class initializing with a vector of Branches.
Circuit::Circuit(std::vector<Branch> branches) {
    branchesVector = std::move(branches);
    // Calculate the total number of equations required based on the get_number of components in all branches.
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
                if (component->startNode()->get_number() != Node::ground().get_number()) {
                    matrix(row, component->startNode()->get_number()) = -1;
                }
                if (component->endNode()->get_number() != Node::ground().get_number()) {
                    matrix(row, component->endNode()->get_number()) = 1;
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
                if (component->startNode()->get_number() != Node::ground().get_number()) {
                    matrix(row, component->startNode()->get_number()) = 1;
                }
                if (component->endNode()->get_number() != Node::ground().get_number()) {
                    matrix(row, component->endNode()->get_number()) = -1;
                }
                matrix(row, equationsCount - 1 - branch.number()) = -component->resistance();
                insert_branch(std::make_shared<Branch>(branch));
            }

            // Move to the next row in the matrix for the next component'setOfNodes equation.
            ++row;
        }
    }
    // search in the setOfNodes for the ground
    auto it = std::find_if(setOfNodes.begin(), setOfNodes.end(), [](std::shared_ptr<Node> node){return
            node->get_number() == -1;});
    bool ground_found = it != setOfNodes.end();
    // if there is no ground node the circuit cannot be solved
    if (!ground_found) {
        throw CircuitException("The Circuit is not grounded");
    }
    // Solve the matrix equation.
    VectorXd result = VectorXd::Zero(equationsCount);
    result = matrix.colPivHouseholderQr().solve(vector);

    // Update the circuit'setOfNodes state with the solution.
    is_solved = true;
    solution = result;
    update_branches_current(result);
    update_node_voltages(result);

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
        if (node->get_number() != -1) {
            node->set_voltage(data(node->get_number()));
        }
    }
}

// Prints the matrix, vector, and solution if the circuit is solved.
void Circuit::print_matrix() {
    if (!is_solved) {
        throw CircuitException("The circuit is not solved");
    }
    std::cout<<get_matrix_string();
}
std::string Circuit::get_matrix_string() {

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
    std::stringstream headers;
    // Print formatted matrix, vector, and solution headers.
    for (int i = 0; i <= maxMatrixLength; ++i) {
        if (i == maxMatrixLength / 2) {
            headers << " MATRIX ";
        } else {
            headers << "-";
        }
    }

    for (int i = 0; i <= maxVectorLength; ++i) {
        if (i == maxVectorLength / 2) {
            headers << " VECTOR ";
        } else {
            headers << "-";
        }
    }

    for (int i = 0; i <= maxSolutionLength; ++i) {
        if (i == maxSolutionLength / 2) {
            headers << " SOLUTION ";
        } else {
            headers << "-";
        }
    }

    headers<< std::endl;
    headers<<ss.str();
    return headers.str();
}

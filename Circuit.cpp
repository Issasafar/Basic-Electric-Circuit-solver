//
// Created by issa on 11/05/24.
//

#include "Circuit.h"
#include "CircuitException.h"
#include <Eigen/Dense>
#include <utility>

using Eigen::MatrixXd;
using Eigen::VectorXd;

Circuit::Circuit() = default;

Circuit::Circuit(std::vector<Branch> branches) {
    b = std::move(branches);
    for (Branch branch: b) {
        equationsCount += branch.components().size();
    }
}

b_vec Circuit::branches() { return b; }

void Circuit::insert_node(std::shared_ptr<Node> node) {
    s.insert(node);
}

void Circuit::add_branch(Branch branch) {
    b.push_back(branch);
    equationsCount += branch.components().size();
}

VectorXd Circuit::solve() {
    matrix = MatrixXd::Zero(equationsCount, equationsCount);
    vector = VectorXd::Zero(equationsCount);
    int row{0};
    for (auto branch: branches()) {
        // append each component's equation to the matrix
        // number of required equation is always equal to the number of components in all branches
        for (auto component: branch.components()) {
            insert_node(component->startNode());
            insert_node(component->endNode());
            if (branch.types_map().at(component) == "VoltageSource") {
                if (component->startNode()->number() != Node::ground().number()) {
                    matrix(row, component->startNode()->number()) = -1;
                }
                if (component->endNode()->number() != Node::ground().number()) {
                    matrix(row, component->endNode()->number()) = 1;
                }
                vector(row) = component->voltage();

            }
            if (branch.types_map().at(component) == "CurrentSource") {
                matrix(row, equationsCount - 1 - branch.number()) = 1;
                vector(row) = component->current();
            }
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
            // go to next row in the matrix to fill up
            ++row;
        }
    }
    VectorXd result = VectorXd::Zero(equationsCount);
    result = matrix.colPivHouseholderQr().solve(vector);
    is_solved = true;
    solution = result;
    update_node_voltages(result);
    update_branches_current(result);
    return result;
}

void Circuit::insert_branch(std::shared_ptr<Branch> branch) {
    bSet.insert(branch);
}

void Circuit::update_branches_current(Eigen::VectorXd data) {
    for (auto branch: bSet) {
        branch->current(data(data.size() - 1 - branch->number()));
    }
}

void Circuit::update_node_voltages(Eigen::VectorXd data) {
    for (auto node: s) {
        if (node->number() != -1) {
            node->set_voltage(data(node->number()));
        }
    }
}

void Circuit::print_matrix() {
    if (!is_solved) {
        throw CircuitException("The circuit is not solved");
    }
//    for (int k = 0; k < 10*equationsCount; ++k) {
//        if(k == 10*equationsCount/2){
//            std::cout<<"MATRIX";
//        }else{
//            std::cout<<"#";
//        }
//    }
//    std::cout<<std::endl;
    std::stringstream ss;
    unsigned long maxMatrixLength = 0;
    unsigned long maxVectorLength = 0;
    unsigned long maxSolutionLength = 0;
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

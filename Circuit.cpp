//
// Created by issa on 11/05/24.
//

#include "Circuit.h"
#include <Eigen/Dense>
#include <utility>

using Eigen::MatrixXd;
using Eigen::VectorXd;

Circuit::Circuit() = default;

Circuit::Circuit(std::vector<Branch> branches) {
    b = std::move(branches);
    for (Branch branch: b) {
        equations_count += branch.components().size();
    }
}

b_vec Circuit::branches() { return b; }

void Circuit::insert_node(std::shared_ptr<Node> node) {
    s.insert(node);
}

void Circuit::add_branch(Branch branch) {
    b.push_back(branch);
    equations_count += branch.components().size();
}

VectorXd Circuit::solve() {
    MatrixXd matrix = MatrixXd::Zero(equations_count, equations_count);
    VectorXd vector = VectorXd::Zero(equations_count);

    int row{0};
    for (auto branch: branches()) {
        // append each component's equation to the matrix
        // number of required equation is always equal to the number of components in all branches
        for (auto component: branch.components()) {
            insert_node(component->startNode());
            insert_node(component->endNode());
            if (branch.types_map().at(component) == "VoltageSource") {
                if (component->startNode()->value() != Node::ground().value()) {
                    matrix(row, component->startNode()->value()) = -1;
                }
                if (component->endNode()->value() != Node::ground().value()) {
                    matrix(row, component->endNode()->value()) = 1;
                }
                vector(row) = component->voltage();

            }
            if (branch.types_map().at(component) == "CurrentSource") {
                matrix(row, equations_count - 1 - branch.number()) = 1;
                vector(row) = component->current();
            }
            if (branch.types_map().at(component) == "Resistance") {
                if (component->startNode()->value() != Node::ground().value()) {
                    matrix(row, component->startNode()->value()) = 1;
                }
                if (component->endNode()->value() != Node::ground().value()) {
                    matrix(row, component->endNode()->value()) = -1;
                }
                matrix(row, equations_count - 1 - branch.number()) = -component->resistance();
                insert_branch(std::make_shared<Branch>(branch));
            }
            // go to next row in the matrix to fill up
            ++row;
        }
    }
    VectorXd result = VectorXd::Zero(equations_count);
    result = matrix.colPivHouseholderQr().solve(vector);
    std::cout << "################ MATRIX ###################" << std::endl;
    std::cout << matrix << std::endl;
    std::cout << "################ VECTOR ###################" << std::endl;
    std::cout << vector << std::endl;
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
        if (node->value() != -1) {
            node->set_voltage(data(node->value()));
        }
    }

}

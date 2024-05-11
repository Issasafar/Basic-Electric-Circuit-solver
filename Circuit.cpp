//
// Created by issa on 11/05/24.
//

#include "Circuit.h"
#include <Eigen/Dense>

using Eigen::MatrixXf;
using Eigen::VectorXd;

b_vec Circuit::branches() { return b; }

void Circuit::add_branch(Branch branch) {
    b.push_back(branch);
    equations_count += branch.components().size();
}

void Circuit::solve() {
    MatrixXf matrix = MatrixXf::Zero(equations_count, equations_count);
    VectorXd vector = VectorXd::Zero(equations_count);

    int row{0};
    for (auto branch: branches()) {
        // append each component's equation to the matrix
        // number of required equation is always equal to the number of components in all branches
        for (auto component: branch.components()) {
            if (branch.types_map().at(component) == "VoltageSource") {
                // std::cout<<"Voltage source found"<<std::endl;
                // use for loop to iterate over columns
                    if (component->startNode()->value() != Node::ground().value()) {
                        matrix(row, component->startNode()->value()) = -1;
                    }
                    if (component->endNode()->value() != Node::ground().value()) {
                        matrix(row, component->endNode()->value()) = 1;
                    }
//                    if (col == equations_count - branch.number()) {
//
//                    }
                vector(row) = component->voltage();

            }
            if (branch.types_map().at(component) == "CurrentSource") {
                // std::cout<<"Current source found"<<std::endl;
                matrix(row, equations_count - branch.number()) = 1;
                vector(row) = component->current();
            }
            if (branch.types_map().at(component) == "Resistance") {
                // std::cout<<"Resistor found"<<std::endl;
                if (component->startNode()->value() != Node::ground().value()) {
                    matrix(row, component->startNode()->value()) = -1;
                }
                if (component->endNode()->value() != Node::ground().value()) {
                    matrix(row, component->endNode()->value()) = 1;
                }
                matrix(row,equations_count - branch.number()) = -component->resistance();

            }
            // go to next row in the matrix to fill up
            std::cout<<"################ MATRIX ###################"<<std::endl;
            std::cout<<matrix<<std::endl;
            std::cout<<"################ VECTOR ###################"<<std::endl;
            std::cout<<vector<<std::endl;
            ++row;
        }
    }
    VectorXd re = VectorXd::Zero(equations_count);
    std::cout<<"The result is: "<<std::endl;
    Eigen::BDCSVD bdcsvd = Eigen::BDCSVD(matrix);
    std::cout<<"The solution is: \n"<<bdcsvd.solve(b)<<std::endl;
//    << matrix.template bdcSvd<Eigen::ComputeThinU | Eigen::ComputeThinV>().solve(b);
//    std::cout<<result<<std::endl;
}
//if (branch.types_map().at(el) == "VoltageSource") {
//std::cout << "found a voltagesource" << std::endl;
//}

//
// Created by issa on 11/05/24.
//

#ifndef DEMOPROJECT_CIRCUIT_H
#define DEMOPROJECT_CIRCUIT_H


#include "Branch.h"
#include "Eigen/Dense"
#include <unordered_set>
using Eigen::VectorXd;
using b_vec = std::vector<Branch>;
using n_set = std::unordered_set<std::shared_ptr<Node>>;
using b_set = std::unordered_set<std::shared_ptr<Branch>>;
class Circuit {
private:
    b_vec b;
    n_set s;
    b_set bSet;
    int equations_count = 0;
    void update_branches_current(VectorXd data);
    void update_node_voltages(VectorXd data);

public:
    Circuit();
    Circuit(std::vector<Branch> branches);
    b_vec branches();
    void add_branch(Branch branch);
    void insert_node(std::shared_ptr<Node> node);
    void insert_branch(std::shared_ptr<Branch> branch);
    VectorXd solve();
};


#endif //DEMOPROJECT_CIRCUIT_H

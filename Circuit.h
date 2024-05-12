//
// Created by issa on 11/05/24.
//

#ifndef DEMOPROJECT_CIRCUIT_H
#define DEMOPROJECT_CIRCUIT_H


#include "Branch.h"

using b_vec = std::vector<Branch>;
class Circuit {
private:
    b_vec b;
    int equations_count = 0;
public:
    Circuit();
    Circuit(std::vector<Branch> branches);
    b_vec branches();
    void add_branch(Branch branch);
    void solve();
};


#endif //DEMOPROJECT_CIRCUIT_H

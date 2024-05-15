//
// Created by issa on 11/05/24.
//

#ifndef CIRCUITSOLVER_CIRCUIT_H
#define CIRCUITSOLVER_CIRCUIT_H


#include "Branch.h"
#include "Eigen/Dense"
#include <unordered_set>
// aliasing
using Eigen::VectorXd;
using b_vec = std::vector<Branch>;
using n_set = std::unordered_set<std::shared_ptr<Node>>;
using b_set = std::unordered_set<std::shared_ptr<Branch>>;

/**
 * @file Circuit.h
 * @brief electrical circuit
 */
class Circuit {
private:
    /**@var branchesVector @brief circuit branches vector*/
    b_vec branchesVector;
    /**@var setOfNodes @brief circuit nodes set*/
    n_set setOfNodes;
    /**@var setOfBranches @brief circuit branches set*/
    b_set setOfBranches;
    /**@var equationsCount @brief required equations count for solving the circuit*/
    int equationsCount = 0;
    /**@var is_solved @brief is the circuit solved or not*/
    bool is_solved = false;
    /**@Var matrix @brief represent A in Ax = branchesVector equation*/
    Eigen::MatrixXd matrix;
    /**@Var vector @brief represent branchesVector in Ax = branchesVector equation*/
    Eigen::VectorXd vector;
    /**@Var solution @brief represent x in Ax = branchesVector equation*/
    Eigen::VectorXd solution;

    /**
     * @brief updates each branch current
     * @param data
     */
    void update_branches_current(VectorXd data);

    /**
     * @brief updates each node voltage
     * @param data
     */
    void update_node_voltages(VectorXd data);

public:
    Circuit();

    Circuit(std::vector<Branch> branches);

    /**
     * @fn branches
     * @return circuit branches vector
     */
    b_vec branches();

    /**
     * @fn print_matrix
     * @brief prints the equation Ax=branchesVector matrix
     */
    void print_matrix();

    /**
     * @brief adds a branch to circuit branches vector
     * @param branch
     */
    void add_branch(Branch branch);

    /**
     * @brief insert node into the nodes set
     * @param node
     */
    void insert_node(std::shared_ptr<Node> node);

    /**
     * @brief insert branch into the branches set
     * @param branch
     */
    void insert_branch(std::shared_ptr<Branch> branch);

    /**
     * @brief solves the circuit
     * @return result
     */
    VectorXd solve();
};


#endif //CIRCUITSOLVER_CIRCUIT_H

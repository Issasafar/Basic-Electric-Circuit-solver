//
// Created by issa on 23/04/24.
//

#ifndef DEMOPROJECT_BRANCH_H
#define DEMOPROJECT_BRANCH_H


#include "Node.h"
#include "Resistance.h"
#include <vector>

class Branch {
private:
    Node *staringNd;
    Node *endingNd;
    std::vector<Resistance> v;
public:
    Branch(Node &startNode, Node &endNode);

    Branch(Node &startNode, Node &endNode, std::vector<Resistance> resistances);

    std::vector<Resistance> branchResistors();

    void addResistor(Resistance resistance);

    void startingNode(Node &node);

    void endingNode(Node &node);

    Node &startingNode();

    Node &endingNode();
};


#endif //DEMOPROJECT_BRANCH_H

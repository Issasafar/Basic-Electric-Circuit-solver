//
// Created by issa on 23/04/24.
//

#include "Branch.h"

#include <utility>

Branch::Branch(Node &startNode, Node &endNode, std::vector<Resistance> resistances) : staringNd{&startNode},
                                                                                      endingNd{&endNode},
                                                                                      v{std::move(resistances)} {}

Branch::Branch(Node &startNode, Node &endNode) : staringNd{&startNode}, endingNd{&endNode} {}

void Branch::addResistor(Resistance resistance) {
    v.push_back(resistance);
}

std::vector<Resistance> Branch::branchResistors() { return v; }

Node &Branch::endingNode() { return *endingNd; }

Node &Branch::startingNode() { return *staringNd; }

void Branch::startingNode(Node &node) { this->staringNd = &node; }

void Branch::endingNode(Node &node) { this->endingNd = &node; }

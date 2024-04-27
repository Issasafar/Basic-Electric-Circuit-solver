//
// Created by issa on 21/04/24.
//

#include "Resistance.h"
#include <iostream>

using namespace std;

Resistance::Resistance() : r{0} {}

Resistance::Resistance(double val) : r{val} {}

Resistance::Resistance(double val, Node& start, Node& end) : r{val}, startNd{&start}, endNd{&end} {
    startNd->addConnection();
    endNd->addConnection();
}


void Resistance::endNode(Node left) {
    endNd->removeConnection();
    endNd = &left;
    left.addConnection();
}

void Resistance::startNode(Node start) {
    startNd->removeConnection();
    startNd = &start;
    start.removeConnection();
}

Node &Resistance::startNode() { return *startNd; }

Node &Resistance::endNode() { return *endNd; }

double Resistance::value() const { return r; }



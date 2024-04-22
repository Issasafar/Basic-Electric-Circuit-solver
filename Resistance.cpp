//
// Created by issa on 21/04/24.
//

#include "Resistance.h"
#include <iostream>

using namespace std;

Resistance::Resistance() : r{0} {}

Resistance::Resistance(double val) : r{val} {}

Resistance::Resistance(double val, Node& right, Node& left) : r{val}, rightNd{&right}, leftNd{&left} {
    rightNd->addConnection();
    leftNd->addConnection();
}


void Resistance::leftNode(Node left) {
    leftNd->removeConnection();
    leftNd = &left;
    left.addConnection();
}

void Resistance::rightNode(Node right) {
    leftNd->removeConnection();
    rightNd = &right;
    right.removeConnection();
}

Node Resistance::rightNode() { return *rightNd; }

Node Resistance::leftNode() { return *leftNd; }

double Resistance::value() const { return r; }



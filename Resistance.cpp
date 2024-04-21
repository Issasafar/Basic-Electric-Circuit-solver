//
// Created by issa on 21/04/24.
//

#include "Resistance.h"

Resistance::Resistance() : r{0} {}

Resistance::Resistance(double val) : r{val} {}

Resistance::Resistance(double val, Node right, Node left) : r{val}, rightNd{right}, leftNd{left} {}

void Resistance::leftNode(Node left) { leftNd = left; }

void Resistance::rightNode(Node right) { rightNd = right; }

Node Resistance::rightNode() { return rightNd; }

Node Resistance::leftNode() { return leftNd; }

double Resistance::value() const { return r; }



//
// Created by issa on 21/04/24.
//

#include "Resistance.h"
#include "Component.h"
#include <iostream>
Resistance::Resistance() : Component()  {}

Resistance::Resistance(double val)  : Component() {r = val;}

Resistance::Resistance(double val, std::shared_ptr<Node> start, std::shared_ptr<Node> end) : Component(val, start, end){}
double Resistance::resistance() const { return r; }
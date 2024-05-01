//
// Created by issa on 21/04/24.
//

#include "Resistance.h"
#include "Component.h"
#include <iostream>
#include <utility>
Resistance::Resistance() : Component()  {}

Resistance::Resistance(double val)  : Component() {r = val;}

Resistance::Resistance(double val, std::shared_ptr<Node> start, std::shared_ptr<Node> end) : Component(val, std::move(start), std::move(end)){}
double Resistance::resistance() const { return r; }
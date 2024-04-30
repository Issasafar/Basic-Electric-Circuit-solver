//
// Created by issa on 21/04/24.
//

#include "Resistance.h"
#include "Component.h"
#include <iostream>
Resistance::Resistance() : Component()  {}

Resistance::Resistance(double val)  : Component() {r = val;}

Resistance::Resistance(double val, Node& start, Node& end) : Component(start,end){
    r = val;
    startNd->addConnection();
    endNd->addConnection();
}

double Resistance::resistance() const { return r; }
void Resistance::printValue() {std::cout<<"hello world";}



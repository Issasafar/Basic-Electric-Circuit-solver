//
// Created by issa on 21/04/24.
//

#include "Resistance.h"
#include "Component.h"
#include "VoltageSource.h"
#include <iostream>
#include <utility>

Resistance::Resistance() : Component() {}

Resistance::Resistance(double val) : Component() { r = val; }

Resistance::Resistance(double val, std::shared_ptr<Node> start, std::shared_ptr<Node> end) : Component(val,
                                                                                                       std::move(start),
                                                                                                       std::move(
                                                                                                               end)) {}

double Resistance::resistance() const { return r; }

Component &Resistance::add_equal(Component *thisObj, Component *other) {

    if (dynamic_cast<VoltageSource *>(other) != nullptr) {
        std::cout<<"its a vsource in add resistance";
    }

    if (dynamic_cast<Resistance *>(other) != nullptr) {
        std::cout<<"its a resistor in add resistance";
    }

    std::cout<<"Resistance::add_equal "<<this->resistance()<<", "<<other->resistance()<<std::endl;
    thisObj->resistance(thisObj->resistance() +other->resistance());
    return *thisObj;
}
Component &Resistance::subtract_equal(Component*thisObj,Component *other) {
    r -= other->resistance();
    return *this;
}
Component Resistance::add(Component *thisObj,Component *other) {
    std::cout<<"Resistance::add "<<thisObj->resistance()<<", "<<other->resistance()<<std::endl;
    return add_equal(thisObj, other);
}

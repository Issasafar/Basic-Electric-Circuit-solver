//
// Created by issa on 21/04/24.
//

#include "Resistance.h"
#include "Component.h"
#include <iostream>
#include <utility>
#include <regex>

Resistance::Resistance() : Component() {}

Resistance::Resistance(double val) : Component() { r = val; }

Resistance::Resistance(double val, std::shared_ptr<Node> start, std::shared_ptr<Node> end) : Component(val,
                                                                                                       std::move(start),
                                                                                                       std::move(
                                                                                                               end)) {}

double Resistance::resistance() const { return r; }

Component &Resistance::add_equal(Component *thisObj, Component *other) {
    if (dynamic_cast<Resistance *>(other)) {
        return Component::add_equal(thisObj, other);
    } else {
        std::string error_message = "Cannot add a Resistance with "+std::string(typeid(*other).name());
        error_message = std::regex_replace(error_message, std::regex("[0-9]+"), "");
        throw std::runtime_error(error_message);
    }

}
Component &Resistance::subtract_equal(Component*thisObj,Component *other) {
    if (dynamic_cast<Resistance *>(other)) {
        return Component::subtract_equal(thisObj, other);
    } else {
        std::string error_message ="error in reisistor";
       // std::string error_message = "Cannot add a "+ get_class_name(*this)+ " with "+get_class_name(*other);
        throw std::runtime_error(error_message);
    }
}
Component Resistance::add(Component *thisObj,Component *other) {
    std::cout<<"Resistance::add "<<thisObj->resistance()<<", "<<other->resistance()<<std::endl;
    return add_equal(thisObj, other);
}

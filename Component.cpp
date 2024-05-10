//
// Created by issa on 27/04/24.
//

#include <utility>
#include <regex>
#include "Component.h"
#include "CircuitException.h"


bool is_valid_operation(Component *thisObj, Component *other){
    if (thisObj->get_class_name() == other->get_class_name()) {
        return true;
    }
    return false;
}
Component::~Component() = default;

Component::Component() : r{0}, v{0}, c{0} {}


Component::Component(double resistance, std::shared_ptr<Node> start, std::shared_ptr<Node> end) : startNd{
        std::move(start)},
                                                                                                  endNd{std::move(end)},
                                                                                                  r{resistance},
                                                                                                  v{0},
                                                                                                  c{0} {
    startNd->addConnection();
    endNd->addConnection();
}

std::string Component::get_class_name() {
    return std::regex_replace(std::string(typeid(*this).name()), std::regex("[0-9]+"), "");
}
Component Component::add(Component *thisObj, Component *other) {
    return add_equal(thisObj, other);
}

Component &Component::add_equal(Component *thisObj, Component *other) {
    if (!is_valid_operation(this, other)) {throw CircuitException("invalid operation add: "+this->to_string()+", "+other->to_string());}
    thisObj->r += other->r;
    thisObj->v += other->v;
    thisObj->c += other->c;
    return *thisObj;
}

Component &Component::subtract_equal(Component *thisObj, Component *other) {
    if (!is_valid_operation(this, other)) {throw CircuitException("invalid operation subtract: "+this->to_string()+", "+other->to_string());}
    thisObj->r -= other->r;
    thisObj->v -= other->v;
    thisObj->c -= other->c;
    return *thisObj;
}

Component Component::subtract(Component *thisObj, Component *other) {
    return subtract_equal(thisObj, other);
}

Component Component::multiply(Component *thisObj, Component *other) {
    if (!is_valid_operation(this, other)) {throw CircuitException("invalid operation multiply: "+this->to_string()+", "+other->to_string());}
    thisObj->r *= other->r;
    thisObj->v *= other->v;
    thisObj->c *= other->c;
    return *thisObj;
}

Component Component::divide(Component *thisObj, Component *other) {
    if (!is_valid_operation(this, other)) {throw CircuitException("invalid operation divide: "+this->to_string()+", "+other->to_string());}
    thisObj->r /= other->r;
    thisObj->v /= other->v;
    thisObj->c /= other->c;
    return *thisObj;
}


void Component::endNode(std::shared_ptr<Node> &end) {
    endNd->removeConnection();
    end->addConnection();
    endNd = end;
}

void Component::startNode(const std::shared_ptr<Node> &start) {
    startNd->removeConnection();

    start->addConnection();
    startNd = start;

}

std::string Component::to_string() {
    Component* this_component { dynamic_cast<Component*>(this)};
    std::string message = this->get_class_name()+":";
    if (this_component->r != 0) {
       message += " R= "+std::to_string(this_component->r);
    }
    if (this_component->v != 0) {
        message += ", V= "+std::to_string(this_component->v);
    }
    if (this_component->c != 0) {
        message += ", C= "+std::to_string(this_component->c);
    }
//    message += "\n";
    return message;
}

std::shared_ptr<Node> Component::startNode() { return startNd; }

std::shared_ptr<Node> Component::endNode() { return endNd; }

double Component::resistance() const { return r; }

double Component::voltage() const { return v; }

double Component::current() const { return c; }

void Component::voltage(double val) { v = val; }

void Component::resistance(double val) { r = val; }

void Component::current(double val) { c = val; }
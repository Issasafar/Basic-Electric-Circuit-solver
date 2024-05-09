//
// Created by issa on 27/04/24.
//

#include <iostream>
#include <utility>
#include "Component.h"

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

Component Component::add(Component *thisObj, Component *other) {
    return add_equal(thisObj, other);
}

Component &Component::add_equal(Component *thisObj, Component *other) {
    thisObj->r += other->r;
    thisObj->v += other->v;
    thisObj->c += other->c;
    return *thisObj;
}

Component &Component::subtract_equal(Component *thisObj, Component *other) {
    thisObj->r -= other->r;
    thisObj->v -= other->v;
    thisObj->c -= other->c;
    return *thisObj;
}

Component Component::subtract(Component *thisObj, Component *other) {
    return subtract_equal(thisObj, other);
}

Component Component::multiply(Component *thisObj, Component *other) {
    thisObj->r *= other->r;
    thisObj->v *= other->v;
    thisObj->c *= other->c;
    return *thisObj;
}

Component Component::divide(Component *thisObj, Component *other) {
    return {};
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
    return "Component with: R= " + std::to_string(this->r) + ", V= " + std::to_string(this->v) + ", C= " +
           std::to_string(this->c) + "\n";
}

std::shared_ptr<Node> Component::startNode() { return startNd; }

std::shared_ptr<Node> Component::endNode() { return endNd; }

double Component::resistance() const { return r; }

double Component::voltage() const { return v; }

double Component::current() const { return c; }

void Component::voltage(double val) { v = val; }

void Component::resistance(double val) { r = val; }

void Component::current(double val) { c = val; }
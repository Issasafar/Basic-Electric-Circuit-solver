//
// Created by issa on 27/04/24.
//

#include <iostream>
#include "Component.h"

Component::~Component() = default;

Component::Component() : r{0}, v{0}, c{0} {}


Component::Component(double resistance, Node &start, Node &end) : startNd{&start}, endNd{&end}, r{resistance}, v{0},
                                                                  c{0} {
    start.addConnection();
    end.addConnection();
}

void Component::endNode(Node end) {
    endNd->removeConnection();
    endNd = &end;
    end.addConnection();
}

void Component::startNode(Node start) {
    startNd->removeConnection();
    startNd = &start;
    start.addConnection();
}

Node &Component::startNode() { return *startNd; }

Node &Component::endNode() { return *endNd; }

double Component::resistance() const { return r; }

double Component::voltage() const { return v; }

double Component::current() const { return c; }

void Component::voltage(double val) { v = val; }

void Component::resistance(double val) { r = val; }

void Component::current(double val) { c = val; }
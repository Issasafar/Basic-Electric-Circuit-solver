//
// Created by issa on 21/04/24.
//

#include <algorithm>
#include <iostream>
#include "Node.h"

Node::Node() : n{-1}, volt{Voltage(0, false)} {
}

Node Node::ground() {
    return {-1, 0};
}

Node::Node(int val) : n{val >= -1 ? val : -1}, volt{Voltage(0, false)} {}

Node::Node(int val, double voltage) : n{val}, volt(Voltage(voltage, true)) {
}

Node::Node(int val, const Voltage &voltage) : n{val}, volt{voltage} {}

double Node::get_voltage() {
    return this->volt.get_value();
}

void Node::set_voltage(double val) {
    volt.set_value(val);
    volt.set_known(true);
    for (auto &observer: observers) {
        observer->on_voltage_changed(val);
    }
}

void Node::number(int val) { n = val; }

int Node::number() const {
    return n;
}

int Node::connections_count() const {
    return c;
}

void Node::add_connection() {
    ++c;
}

void Node::remove_connection() {
    --c;
}

Voltage Node::voltage_object() {
    return volt;
}





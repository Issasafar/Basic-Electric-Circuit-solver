//
// Created by issa on 21/04/24.
//

#include <algorithm>
#include <iostream>
#include "Node.h"

Node::Node() : v{-1},volt{Voltage(0, false)}{
}

Node Node::ground() {
    return {-1,0};
}

Node::Node(int val) : v{val >= -1 ? val : -1}, volt{Voltage(0, false)} {}
Node::Node(int val, double voltage): v{val}, volt(Voltage(voltage, true)){
}
Node::Node(int val,  const Voltage& voltage): v{val},volt{voltage}{}

double Node::get_voltage() {
    return this->volt.get_value();
}
void Node::set_voltage(double val) {
    volt.set_value(val);
    volt.set_known(true);
    for (auto &observer: observers) {
        observer->on_value_changed(val);
        std::cout<<"Observing change in voltage "<<val<<std::endl;
    }
}
void Node::value(int val) { v = val; }

int Node::value() const {
    return v;
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





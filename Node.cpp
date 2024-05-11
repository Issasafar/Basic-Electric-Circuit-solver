//
// Created by issa on 21/04/24.
//

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

double Node::voltage() {
    return this->volt.voltage();
}
void Node::voltage(double val) {
    volt.voltage(val);
    volt.known(true);
}
void Node::value(int val) { v = val; }

int Node::value() const {
    return v;
}
int Node::connectionsCount() const {
    return c;
}
void Node::addConnection() {
    ++c;
}
void Node::removeConnection() {
    --c;
}

Voltage Node::get_voltage() {
    return volt;
}





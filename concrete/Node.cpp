//
// Created by issa on 21/04/24.
//

#include <algorithm>
#include <iostream>
#include "Node.h"

// Default constructor for Node class.
Node::Node() : n{-1}, volt{Voltage(0, false)} {
}

// Static method to create a ground node.
Node Node::ground() {
    return {-1, 0};
}

// Parameterized constructor for Node class.
Node::Node(int val) : n{val >= -1 ? val : -1}, volt{Voltage(0, false)} {}

// Parameterized constructor for Node class with initial voltage value.
Node::Node(int val, double voltage) : n{val}, volt(Voltage(voltage, true)) {
}

// Parameterized constructor for Node class with initial Voltage object.
Node::Node(int val, const Voltage &voltage) : n{val}, volt{voltage} {}

// Get the voltage value of the node.
double Node::get_voltage() {
    return this->volt.get_value();
}

// Set the voltage value of the node.
void Node::set_voltage(double val) {
    volt.set_value(val);
    volt.set_known(true);
    // Notify observers about the voltage change.
    for (auto &observer: observers) {
        observer->on_voltage_changed(val);
    }
}

// Set the node number.
void Node::number(int val) { n = val; }

// Get the node number.
int Node::number() const {
    return n;
}

// Get the number of connections to the node.
int Node::connections_count() const {
    return c;
}

// Add a connection to the node.
void Node::add_connection() {
    ++c;
}

// Remove a connection from the node.
void Node::remove_connection() {
    --c;
}

// Get the Voltage object associated with the node.
Voltage Node::voltage_object() {
    return volt;
}

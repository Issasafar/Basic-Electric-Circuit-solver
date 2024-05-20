//
// Created by issa on 21/04/24.
//

#include <algorithm>
#include <iostream>
#include "Node.h"
#include <sstream>

// Default constructor for Node class.
Node::Node() : n{-1}, volt{Voltage(0, false)} {
}

// Static method to create a ground node.
Node Node::ground() {
    return {-1, 0};
}

// Parameterized constructor for Node class.
Node::Node(int val) : n{val >= -1 ? val : -1}, volt{Voltage(0, false)} {}

// Parameterized constructor for Node class with initial voltage value_.
Node::Node(int val, double voltage) : n{val}, volt(Voltage(voltage, true)) {
}

// Parameterized constructor for Node class with initial Voltage object.
Node::Node(int val, const Voltage &voltage) : n{val}, volt{voltage} {}

// Get the voltage value_ of the node.
double Node::get_voltage() {
    return this->volt.get_value();
}

// Set the voltage value_ of the node.
void Node::set_voltage(double val) {
    volt.set_value(val);
    volt.set_known(true);
    // Notify observers about the voltage change.
    for (auto &observer: observers) {
        observer->on_voltage_changed(val);
    }
}

// Set the node get_number.
void Node::number(int val) { n = val; }

// Get the node get_number.
int Node::get_number() const {
    return n;
}

// Get the get_number of connections to the node.
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

std::string Node::to_string() {
   std::stringstream temp;
   temp<<"Node Number= "<<this->get_number()<<", Voltage= ";
   if(this->volt.get_known()){
       temp<<this->get_voltage();
   }else{
       temp<<"Unknown";
   }
   temp<<std::endl;
    return temp.str();
}

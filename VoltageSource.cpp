//
// Created by issa on 30/04/24.
//

#include "VoltageSource.h"

// Default constructor for VoltageSource class.
VoltageSource::VoltageSource() : Component() {}

// Parameterized constructor for VoltageSource class with voltage, resistance, start, and end nodes.
VoltageSource::VoltageSource(double val, double resistance, std::shared_ptr<Node> start, std::shared_ptr<Node> end)
        : Component(resistance, start, end) { v->set_value(val); }

// Parameterized constructor for VoltageSource class with voltage, start, and end nodes.
VoltageSource::VoltageSource(double val, std::shared_ptr<Node> start, std::shared_ptr<Node> end) : VoltageSource(val, 0,
                                                                                                                 std::move(
                                                                                                                         start),
                                                                                                                 std::move(
                                                                                                                         end)) {}

// Alternative parameterized constructor for VoltageSource class with voltage and resistance.
VoltageSource::VoltageSource(double val, double resistance) {
    v->set_value(val);
    r = resistance;
}

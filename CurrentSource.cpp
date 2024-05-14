//
// Created by issa on 30/04/24.
//

#include "CurrentSource.h"

// Default constructor for CurrentSource class.
CurrentSource::CurrentSource() : Component() {}

// Parameterized constructor for CurrentSource class.
CurrentSource::CurrentSource(double val, double resistance, std::shared_ptr<Node> start, std::shared_ptr<Node> end)
        : Component(resistance, std::move(start), std::move(end)) { c->set_value(val); }

// Parameterized constructor for CurrentSource class (without specifying resistance).
CurrentSource::CurrentSource(double val, std::shared_ptr<Node> start, std::shared_ptr<Node> end) : CurrentSource(val, 0,
                                                                                                                 std::move(
                                                                                                                         start),
                                                                                                                 std::move(
                                                                                                                         end)) {}

// Alternative parameterized constructor for CurrentSource class.
CurrentSource::CurrentSource(double val, double resistance) {
    c->set_value(val);
    r = resistance;
}

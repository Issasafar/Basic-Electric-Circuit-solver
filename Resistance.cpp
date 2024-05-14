//
// Created by issa on 21/04/24.
//

#include "Resistance.h"
#include "Component.h"
#include <utility>
#include "CircuitException.h"
#include "Operators.h"

// Default constructor for Resistance class.
Resistance::Resistance() : Component() {}

// Parameterized constructor for Resistance class.
Resistance::Resistance(double val) : Component() { r = val; }

// Parameterized constructor for Resistance class with start and end nodes.
Resistance::Resistance(double val, std::shared_ptr<Node> start, std::shared_ptr<Node> end) : Component(val,
                                                                                                       std::move(start),
                                                                                                       std::move(
                                                                                                               end)) {}

// Get the resistance value.
double Resistance::resistance() const { return r; }

// Overridden method for addition operation.
Component &Resistance::add_equal(Component *thisObj, Component *other) {
    if (dynamic_cast<Resistance *>(other)) {
        return Component::add_equal(thisObj, other);
    } else {
        throw CircuitException(
                circuit::operator_error_message(circuit::Operator::PLUS, this, other)
        );
    }

}

// Overridden method for subtraction operation.
Component &Resistance::subtract_equal(Component *thisObj, Component *other) {
    if (dynamic_cast<Resistance *>(other)) {
        return Component::subtract_equal(thisObj, other);
    } else {
        throw CircuitException(
                circuit::operator_error_message(circuit::Operator::MINUS, this, other)
        );
    }
}

// Overridden method for addition operation.
Component Resistance::add(Component *thisObj, Component *other) {
    return add_equal(thisObj, other);
}

// Overridden method for subtraction operation.
Component Resistance::subtract(Component *thisObj, Component *other) {
    return subtract_equal(thisObj, other);
}

// Overridden method for multiplication operation.
Component Resistance::multiply(Component *thisObj, Component *other) {
    if (dynamic_cast<Resistance *>(other)) {
        return Component::multiply(thisObj, other);
    } else {
        throw CircuitException(circuit::operator_error_message(circuit::Operator::TIMES, this, other));
    }
}

// Overridden method for division operation.
Component Resistance::divide(Component *thisObj, Component *other) {
    if (dynamic_cast<Resistance *>(other)) {
        return Component::divide(thisObj, other);
    } else {
        throw CircuitException(circuit::operator_error_message(circuit::Operator::DIVIDE, this, other));
    }
}

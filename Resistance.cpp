//
// Created by issa on 21/04/24.
//

#include "Resistance.h"
#include "Component.h"
#include <utility>
#include "CircuitException.h"
#include "Operators.h"

Resistance::Resistance() : Component() {}

Resistance::Resistance(double val) : Component() { r = val; }

Resistance::Resistance(double val, std::shared_ptr<Node> start, std::shared_ptr<Node> end) : Component(val,
                                                                                                       std::move(start),
                                                                                                       std::move(
                                                                                                               end)) {}

double Resistance::resistance() const { return r; }

Component &Resistance::add_equal(Component *thisObj, Component *other) {
    if (dynamic_cast<Resistance *>(other)) {
        return Component::add_equal(thisObj, other);
    } else {
        throw CircuitException(
                circuit::operator_error_message(circuit::Operator::PLUS, this, other)
        );
    }

}

Component &Resistance::subtract_equal(Component *thisObj, Component *other) {
    if (dynamic_cast<Resistance *>(other)) {
        return Component::subtract_equal(thisObj, other);
    } else {
        throw CircuitException(
                circuit::operator_error_message(circuit::Operator::MINUS, this, other)
        );
    }
}

Component Resistance::add(Component *thisObj, Component *other) {
    return add_equal(thisObj, other);
}

Component Resistance::subtract(Component *thisObj, Component *other) {
    return subtract_equal(thisObj, other);
}

Component Resistance::multiply(Component *thisObj, Component *other) {
    if (dynamic_cast<Resistance *>(other)) {
        return Component::multiply(thisObj, other);
    } else {
        throw CircuitException(circuit::operator_error_message(circuit::Operator::TIMES, this, other));
    }
}

Component Resistance::divide(Component *thisObj, Component *other) {
    if (dynamic_cast<Resistance *>(other)) {
        return Component::divide(thisObj, other);
    } else {
        throw CircuitException(circuit::operator_error_message(circuit::Operator::DIVIDE, this, other));
    }
}

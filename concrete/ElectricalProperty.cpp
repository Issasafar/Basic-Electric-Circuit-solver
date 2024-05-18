//
// Created by issa on 13/05/24.
//

#include "ElectricalProperty.h"
#include "CircuitException.h"
#include "Component.h"
#include <algorithm>

// Parameterized constructor for ElectricalProperty class.
ElectricalProperty::ElectricalProperty(const double value, bool known) : value_{value}, is_known{known} {}

// Default constructor for ElectricalProperty class.
ElectricalProperty::ElectricalProperty() : value_{0}, is_known{false} {}

// Add an observer to the electrical property.
void ElectricalProperty::add_observer(ElectricalPropertyObserver *observer) {
    observers.push_back(observer);
}

// Remove an observer from the electrical property.
void ElectricalProperty::remove_observer(ElectricalPropertyObserver *observer) {
    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end()) {
        observers.erase(it);
    }
}

// Set the value_ of the electrical property.
void ElectricalProperty::set_value(double value) {
    value_ = value;
    is_known = true;
    // Notify observers based on the type_ of electrical property.
    if (get_type() == "Voltage") {
        for (auto &observer: observers) {
            observer->on_voltage_changed(value);
        }
    }
    if (get_type() == "Current") {
        for (auto &observer: observers) {
            observer->on_current_changed(value);
        }
    }
}

// Get the type_ of the electrical property.
std::string ElectricalProperty::get_type() const {
    return "Electrical Property";
}

// Get the value_ of the electrical property.
double ElectricalProperty::get_value() const {
    if (!is_known) {
        throw CircuitException("Unknown " + get_type());
    }
    return value_;
}

// Set the known status of the electrical property.
void ElectricalProperty::set_known(bool predicate) {
    is_known = predicate;
}

// Get the known status of the electrical property.
bool ElectricalProperty::get_known() const {
    return is_known;
}

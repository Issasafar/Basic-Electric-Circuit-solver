//
// Created by issa on 13/05/24.
//

#include "ElectricalProperty.h"
#include "CircuitException.h"
#include "Component.h"
#include <algorithm>

ElectricalProperty::ElectricalProperty(const double value, bool known): value_{value}, is_known{known} {}
ElectricalProperty::ElectricalProperty(): value_{0}, is_known{false} {}
void ElectricalProperty::add_observer(ElectricalPropertyObserver *observer) {
    observers.push_back(observer);
}

void ElectricalProperty::remove_observer(ElectricalPropertyObserver *observer) {
    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end()) {
        observers.erase(it);
    }
}
void ElectricalProperty::set_value(double value) {
    value_ = value;
    is_known = true;
    for (auto &observer: observers) {
        observer->on_value_changed(value);
    }
}

std::string ElectricalProperty::get_type() const {
    return "Electrical Property";
}
double ElectricalProperty::get_value() const {
    if (!is_known) {
        throw CircuitException("Unknown "+ get_type());
    }
    return value_;
}

void ElectricalProperty::set_known(bool predicate) {
    is_known = predicate;
}

bool ElectricalProperty::get_known() const {
    return is_known;
}

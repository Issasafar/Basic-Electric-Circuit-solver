//
// Created by issa on 10/05/24.
//

#include "Voltage.h"

Voltage::Voltage() : ElectricalProperty() {}

Voltage::Voltage(const double value, bool known) : ElectricalProperty(value, known) {}

std::string Voltage::get_type() const {
    return "Voltage";
}



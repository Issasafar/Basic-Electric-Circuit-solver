//
// Created by issa on 10/05/24.
//

#include "Voltage.h"

// Default constructor for Voltage class.
Voltage::Voltage() : ElectricalProperty() {}

// Parameterized constructor for Voltage class.
Voltage::Voltage(const double value, bool known) : ElectricalProperty(value, known) {}

// Get the type_ of the electrical property (Voltage).
std::string Voltage::get_type() const {
    return "Voltage";
}

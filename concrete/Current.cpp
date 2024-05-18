//
// Created by issa on 12/05/24.
//

#include "Current.h"

// Default constructor for Current class.
Current::Current() : ElectricalProperty() {}

// Parameterized constructor for Current class.
Current::Current(const double value, bool known) : ElectricalProperty(value, known) {}

// Get the type_ of the electrical property (Current).
std::string Current::get_type() const {
    return "Current";
}

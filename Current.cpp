//
// Created by issa on 12/05/24.
//

#include "Current.h"
Current::Current(): ElectricalProperty() {}
Current::Current(const double value, bool known): ElectricalProperty(value, known) {}

std::string Current::get_type() const {
    return "Current";
}

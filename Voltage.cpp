//
// Created by issa on 10/05/24.
//

#include "Voltage.h"
#include "CircuitException.h"

Voltage::Voltage(const double volt, bool known): v{volt}, is_known{known} {}
Voltage::Voltage(): v{0}, is_known{false} {}
double Voltage::voltage() const {
    if(!is_known)
        throw CircuitException("Unknown Voltage");
    return v;
}

bool Voltage::known() const {return is_known;}

void Voltage::known(bool predicate) {is_known = predicate;}

void Voltage::voltage(const double volt) {
    v = volt;
    is_known = true;
}



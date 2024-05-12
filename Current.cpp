//
// Created by issa on 12/05/24.
//

#include "Current.h"
#include "CircuitException.h"
Current::Current(const double current, bool known): c{current}, is_known{known} {}
Current::Current(): c{0}, is_known{false} {}
double Current::current() const {
    if(!is_known)
        throw CircuitException("Unknown Current");
    return c;
}

bool Current::known() const {return is_known;}

void Current::known(bool predicate) {is_known = predicate;}

void Current::current(const double current) {
    c = current;
    is_known = true;
}

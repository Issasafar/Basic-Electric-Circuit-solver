//
// Created by issa on 13/05/24.
//

#ifndef DEMOPROJECT_ELECTRICALPROPERTY_H
#define DEMOPROJECT_ELECTRICALPROPERTY_H


#include "ElectricatPropertyObserver.h"
#include <vector>
#include <string>

class ElectricalProperty {
protected:
    std::vector<ElectricalPropertyObserver*> observers;
    double value_;
    bool is_known;
    virtual std::string get_type() const;
public:
    ElectricalProperty();
    ElectricalProperty(const double value, bool known);
    void add_observer(ElectricalPropertyObserver* observer);
    void remove_observer(ElectricalPropertyObserver* observer);
    void set_value(double value);
    double get_value() const;
    void set_known(bool predicate);
    bool get_known() const;

};


#endif //DEMOPROJECT_ELECTRICALPROPERTY_H

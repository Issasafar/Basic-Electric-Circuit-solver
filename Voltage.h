//
// Created by issa on 10/05/24.
//

#ifndef DEMOPROJECT_VOLTAGE_H
#define DEMOPROJECT_VOLTAGE_H

#include "ElectricalProperty.h"

class Voltage : public ElectricalProperty {
protected:
    std::string get_type() const override;

public:
    Voltage();

    Voltage(const double value, bool known);
};

#endif //DEMOPROJECT_VOLTAGE_H

//
// Created by issa on 10/05/24.
//

#ifndef CIRCUITSOLVER_VOLTAGE_H
#define CIRCUITSOLVER_VOLTAGE_H

#include "ElectricalProperty.h"
/**
 * @file Voltage.h
 * @brief represent the electrical voltage
 */
class Voltage : public ElectricalProperty {
protected:
    /**
     * @brief overrides the parent method
     * @return string "Voltage"
     */
    std::string get_type() const override;

public:
    ~Voltage() override = default;
    Voltage();
    /**
     * @brief constructor
     * @param value the voltage get_number
     * @param known is the voltage known or not
     */
    Voltage(const double value, bool known);
};

#endif //CIRCUITSOLVER_VOLTAGE_H

//
// Created by issa on 12/05/24.
//

#ifndef CIRCUITSOLVER_CURRENT_H
#define CIRCUITSOLVER_CURRENT_H


#include "ElectricalProperty.h"
/**
 * @file Current.h
 * @brief represent the electrical current
 */
class Current : public ElectricalProperty {
protected:
    /**
     * @brief overrides the parent method
     * @return string "Current"
     */
    std::string get_type() const override;

public:
    Current();
    /**
     * @brief constructor
     * @param value current get_number
     * @param known is the current known or not
     */
    Current(const double value, bool known);
};

#endif //CIRCUITSOLVER_CURRENT_H

//
// Created by issa on 13/05/24.
//

#ifndef CIRCUITSOLVER_ELECTRICALPROPERTY_H
#define CIRCUITSOLVER_ELECTRICALPROPERTY_H


#include "ElectricatPropertyObserver.h"
#include <vector>
#include <string>

/**
 * @file ElectricalProperty
 * @brief represent the base for electrical property
 */
class ElectricalProperty {
protected:
    /**@var observers @brief vector containing references to ElectricalPropertyObservers */
    std::vector<ElectricalPropertyObserver *> observers;
    /**@var value_ @brief the property get_number*/
    double value_;
    /**@var is_known @brief is the property known or not*/
    bool is_known;

    /**
     *
     * @return property type_ as string
     */
    virtual std::string get_type() const;

public:
    ElectricalProperty();
    /**
     *
     * @param value property get_number
     * @param known property known or not
     */
    ElectricalProperty(const double value, bool known);
    /**
     * @brief register observer for property change
     * @param observer
     */
    void add_observer(ElectricalPropertyObserver *observer);
    /**
     * @brief remove observer from the observers vector
     * @param observer
     */
    void remove_observer(ElectricalPropertyObserver *observer);
    /**
     * @brief set property get_number
     * @param value new get_number
     */
    void set_value(double value);
    /**
     *
     * @return property get_number
     */
    double get_value() const;
    /**
     * @brief set is_known according to predicate
     * @param predicate
     */
    void set_known(bool predicate);

    /**
     *
     * @return property known or not
     */
    bool get_known() const;

};


#endif //CIRCUITSOLVER_ELECTRICALPROPERTY_H

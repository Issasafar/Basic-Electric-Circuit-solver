//
// Created by issa on 21/04/24.
//
#ifndef CIRCUITSOLVER_NODE_H
#define CIRCUITSOLVER_NODE_H
#include "Voltage.h"
#include "ElectricalProperty.h"
#include <memory>
#include <boost/any.hpp>
#include <vector>

/**
 * @file Node.h
 * @brief electrical node
 */
class Node : public ElectricalProperty {
private:
    // restrict access to some parent methods
    using ElectricalProperty::set_known;
    using ElectricalProperty::get_known;
    using ElectricalProperty::get_value;
    using ElectricalProperty::set_value;
    /**@var n @brief node get_number*/
    int n;
    /**@var c @brief connections count of the node*/
    int c = 0;
    /**@var volt @brief node voltage*/
    Voltage volt;
public:
    /**
     *
     * @return ground of the circuit
     */
    static Node ground();

    Node();

    Node(int val, double voltage);

    Node(int val, const Voltage &voltage);

    explicit Node(int val);
    std::string to_string();

    void add_connection();

    void remove_connection();

    void number(int val);

    void set_voltage(double val);

    double get_voltage();

    Voltage voltage_object();

    int connections_count() const;

    int get_number() const;
};


#endif //CIRCUITSOLVER_NODE_H

//
// Created by issa on 21/04/24.
//
#ifndef UNTITLED_NODE_H
#define UNTITLED_NODE_H

#include "Voltage.h"
#include <memory>
#include <boost/any.hpp>
#include <vector>

class Node : public ElectricalProperty {
private:
    using ElectricalProperty::set_known;
    using ElectricalProperty::get_known;
    using ElectricalProperty::get_value;
    using ElectricalProperty::set_value;
    int v;
    int c = 0;
    Voltage volt;
public:
    static Node ground();

    Node();

    Node(int val, double voltage);

    Node(int val, const Voltage &voltage);

    explicit Node(int val);

    void add_connection();

    void remove_connection();

    void value(int val);

    void set_voltage(double val);

    double get_voltage();

    Voltage voltage_object();

    int connections_count() const;

    [[nodiscard]] int value() const;
};


#endif //UNTITLED_NODE_H

//
// Created by issa on 21/04/24.
//
#ifndef UNTITLED_NODE_H
#define UNTITLED_NODE_H

#include "Voltage.h"
#include <memory>
#include <boost/any.hpp>
#include <vector>

class Node {
private:
    int v;
    int c = 0;
    Voltage volt;
public:
    std::vector<boost::any> observers;
    void register_observer(boost::any observer);
    void remove_observer(boost::any observer);
    void notify_observers();
    static Node ground();
    Node();
    Node(int val, double voltage);
    Node(int val, const Voltage& voltage);
    explicit Node(int val);
    void add_connection();
    void remove_connection();
    void value(int val);
    void voltage(double val);
    double voltage();
    Voltage voltage_object();
    int connections_count() const;
    [[nodiscard]] int value() const;
};


#endif //UNTITLED_NODE_H

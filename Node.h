//
// Created by issa on 21/04/24.
//
#ifndef UNTITLED_NODE_H
#define UNTITLED_NODE_H

#include "Voltage.h"
#include <memory>
#include <boost/any.hpp>
#include <vector>

//using com_ptr = std::shared_ptr<Component>;
class Node {
private:
    int v;
    int c = 0;
    Voltage volt;
public:
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

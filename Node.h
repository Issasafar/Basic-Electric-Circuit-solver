//
// Created by issa on 21/04/24.
//
#ifndef UNTITLED_NODE_H
#define UNTITLED_NODE_H

#include "Voltage.h"
#include <memory>

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
    void addConnection();
    void removeConnection();
    void value(int val);
    void voltage(double val);
    double voltage();
    Voltage get_voltage();
    int connectionsCount() const;
    [[nodiscard]] int value() const;
};


#endif //UNTITLED_NODE_H

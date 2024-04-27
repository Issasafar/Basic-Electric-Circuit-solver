//
// Created by issa on 27/04/24.
//

#ifndef DEMOPROJECT_COMPONENT_H
#define DEMOPROJECT_COMPONENT_H


#include "Node.h"

class Component {
protected:
    double r;
    double v;
    double c;
    Node* startNd{};
    Node* endNd{};
public:
    Component();
    virtual ~Component();

    Component(Node &start, Node &end);
    Node &startNode();
    Node &endNode();

    void startNode(Node r);
    void endNode(Node l);
    double resistance() const;
    double voltage() const;
    double current() const;

    void resistance(double val);
    void voltage(double val);
    void current(double val);
};


#endif //DEMOPROJECT_COMPONENT_H

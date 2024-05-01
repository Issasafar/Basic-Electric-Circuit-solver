//
// Created by issa on 27/04/24.
//

#ifndef DEMOPROJECT_COMPONENT_H
#define DEMOPROJECT_COMPONENT_H


#include <type_traits>
#include "Node.h"
#include <memory>
class Component {
protected:
    double r;
    double v;
    double c;
    Node* startNd{};
    Node* endNd{};
public:
    virtual ~Component();
    Component();
    Component(double resistance, Node& start, Node& end);
    template<class T>
    typename std::enable_if<std::is_base_of<Component, T>::value, Component>::type
    operator+(T &other){
        return Component(r + other.r, startNode(), other.endNode());
    }

//    void operator-();
//    void operator/();
//    void operator*();
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

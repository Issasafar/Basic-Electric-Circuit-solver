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
    std::shared_ptr<Node> startNd{new Node()};
    std::shared_ptr<Node> endNd{new Node()};
public:
    virtual ~Component();

    Component();

    Component(double resistance, std::shared_ptr<Node> start, std::shared_ptr<Node> end);

    template<class T>
    typename std::enable_if<std::is_base_of<Component, T>::value, Component>::type
    operator+(T &other) {
        return Component(r + other.r, startNode(), other.endNode());
    }

//    void operator-();
//    void operator/();
//    void operator*();
    std::shared_ptr<Node> startNode();

    std::shared_ptr<Node> endNode();

    void startNode(const std::shared_ptr<Node> &r);

    void endNode(std::shared_ptr<Node> &l);

    double resistance() const;

    double voltage() const;

    double current() const;

    void resistance(double val);

    void voltage(double val);

    void current(double val);
};


#endif //DEMOPROJECT_COMPONENT_H

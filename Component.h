//
// Created by issa on 27/04/24.
//

#ifndef DEMOPROJECT_COMPONENT_H
#define DEMOPROJECT_COMPONENT_H


#include <type_traits>
#include <iostream>
#include "Node.h"
#include "Current.h"
#include <memory>
#include <boost/any.hpp>

class Component : public ElectricalPropertyObserver {
protected:
    double r;
    std::shared_ptr<Voltage> v{std::make_shared<Voltage>(Voltage{0, false})};
    std::shared_ptr<Current> c{std::make_shared<Current>(Current{0, false})};
    // start node represent the negative pole
    // end node represent the positive pole
    std::shared_ptr<Node> startNd{new Node()};
    std::shared_ptr<Node> endNd{new Node()};

    virtual Component &add_equal(Component *thisObj, Component *other);

    virtual Component &subtract_equal(Component *thisObj, Component *other);

    virtual Component add(Component *thisObj, Component *other);

    virtual Component subtract(Component *thisObj, Component *other);

    virtual Component multiply(Component *thisObj, Component *other);

    virtual Component divide(Component *thisObj, Component *other);

    void handle_node(std::shared_ptr<Node> member, std::shared_ptr<Node> other);

public:
    void on_voltage_changed(double value) override;

    void on_current_changed(double value) override;

    std::string get_class_name();

    static std::string get_class_name(boost::any obj);

    virtual ~Component();

    Component();

    Component(double resistance, std::shared_ptr<Node> start, std::shared_ptr<Node> end);

    virtual std::string to_string();

    template<class T>
    typename std::enable_if<std::is_base_of<Component, T>::value, Component &>::type
    operator+=(T other) {
        *this = add_equal(std::make_unique<Component>(*this).get(), dynamic_cast<Component *>(&other));
        return *this;
    }

    template<class T>
    typename std::enable_if<std::is_base_of<Component, T>::value, Component &>::type
    operator-=(T other) {
        *this = subtract_equal(std::make_unique<Component>(*this).get(), dynamic_cast<Component *>(&other));
        return *this;
    }

    template<class T>
    typename std::enable_if<std::is_base_of<Component, T>::value, Component>::type
    operator+(T other) {
        return add(std::make_unique<Component>(*this).get(), dynamic_cast<Component *>(&other));
    }

    template<class T>
    typename std::enable_if<std::is_base_of<Component, T>::value, Component>::type
    operator-(T other) {
        return subtract(std::make_unique<Component>(*this).get(), dynamic_cast<Component *>(&other));
    }

    template<class T>
    typename std::enable_if<std::is_base_of<Component, T>::value, Component>::type
    operator*(T other) {
        return multiply(std::make_unique<Component>(*this).get(), dynamic_cast<Component *>(&other));
    }

    template<class T>
    typename std::enable_if<std::is_base_of<Component, T>::value, Component>::type
    operator/(T other) {
        return divide(std::make_unique<Component>(*this).get(), dynamic_cast<Component *>(&other));
    }

    std::shared_ptr<Node> startNode();

    std::shared_ptr<Node> endNode();

    void startNode(std::shared_ptr<Node> r);

    void endNode(std::shared_ptr<Node> l);

    double resistance() const;

    double voltage() const;

    virtual double current() const;

    void resistance(double val);

    void voltage(double val);

    virtual void current(double val);

    std::shared_ptr<Current> get_current_object();

    std::shared_ptr<Voltage> get_voltage_object();

};

#endif //DEMOPROJECT_COMPONENT_H

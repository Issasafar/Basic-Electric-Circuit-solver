//
// Created by issa on 27/04/24.
//

#ifndef CIRCUITSOLVER_COMPONENT_H
#define CIRCUITSOLVER_COMPONENT_H

#include <type_traits>
#include <iostream>
#include "Node.h"
#include "Current.h"
#include <memory>
#include <boost/any.hpp>
#include "ElectricalProperty.h"
class ElectricalProperty;
/**
 * @file Component.h
 * @brief Electrical Component Base
 *
 * This class provides a basic implementation of electrical component.
 */
class Component : public ElectricalPropertyObserver {
protected:
    /**@var r @brief internal resistance*/
    double r;

    /**@var n @brief voltage across component (difference between end and start nodes voltage)*/
    std::shared_ptr<Voltage> v{std::make_shared<Voltage>(Voltage{0, false})};
    /**@var c @brief current passing through the component (start -> end)*/
    std::shared_ptr<Current> c{std::make_shared<Current>(Current{0, false})};
    /**@var startNd @brief represent the negative pole*/
    std::shared_ptr<Node> startNd{new Node()};
    /**@var startNd @brief represent the positive pole*/
    std::shared_ptr<Node> endNd{new Node()};
    /**
     * @fn add_equal
     * @param thisObj component
     * @param other component
     * @return thisObj += other
     */
    virtual Component &add_equal(Component *thisObj, Component *other);
    /**
     * @fn subtract_equal
     * @param thisObj component
     * @param other component
     * @return thisObj -= other
     */
    virtual Component &subtract_equal(Component *thisObj, Component *other);
    /**
     * @fn add
     * @param thisObj component
     * @param other component
     * @return thisObj + other
     */
    virtual Component add(Component *thisObj, Component *other);
    /**
     * @fn subtract
     * @param thisObj component
     * @param other component
     * @return thisObj - other
     */
    virtual Component subtract(Component *thisObj, Component *other);
    /**
     * @fn multiply
     * @param thisObj component
     * @param other component
     * @return thisObj * other
     */
    virtual Component multiply(Component *thisObj, Component *other);
    /**
     * @fn divide
     * @param thisObj component
     * @param other component
     * @return thisObj / other
     */

    virtual Component divide(Component *thisObj, Component *other);
    /**
     * @fn handle_node
     * @brief handle the change of start or end node of the component
     * @param member class member node
     * @param other the new node
     */
    void handle_node(std::shared_ptr<Node> member, std::shared_ptr<Node> other);

public:
    /**
     * @brief called whenever the voltage changed in the nodes
     * @param value the new voltage get_number for either start or end node
     */
    void on_voltage_changed(double value) override;
    /**
     * @brief called whenever the current changed in the component
     * @param value the new current passing through the component
     */
    void on_current_changed(double value) override;
    /**
     * @fn get_class_name
     * @return the current object class'setOfNodes name
     */
    std::string get_class_name();
    /**
     * @fn get_class_name
     * @brief can be called without instantiating the component class
     * @param obj can be any object
     * @return object'setOfNodes class name
     */
    static std::string get_class_name(boost::any obj);
    /**
     * @brief the default destructor
     */
    virtual ~Component();

    Component();
    /**
     *
     * @param resistance component'setOfNodes resistance
     * @param start node that represent the start of the component
     * @param end node that represent the end of the component
     */
    Component(double resistance, std::shared_ptr<Node> start, std::shared_ptr<Node> end);
    /**
     * @brief general component
     * @param resistance
     * @param voltage
     * @param current
     * @param start node that represent the start of the component
     * @param end node that represent the end of the component
     */
    Component(double resistance, double voltage, double current, std::shared_ptr<Node> start, std::shared_ptr<Node> end);
    /**
     * @brief can be overridden
     * @return string representation of the current object
     */
    virtual std::string to_string();
    /**
     * Enabled if other object is component or inherits from component
     * @tparam T type_ other object
     * @param other other object
     * @return this += other
     */
    template<class T>
    typename std::enable_if<std::is_base_of<Component, T>::value, Component &>::type
    operator+=(T other) {
        *this = add_equal(std::make_unique<Component>(*this).get(), dynamic_cast<Component *>(&other));
        return *this;
    }

    /**
     * Enabled if other object is component or inherits from component
     * @tparam T type_ other object
     * @param other other object
     * @return this -= other
     */
    template<class T>
    typename std::enable_if<std::is_base_of<Component, T>::value, Component &>::type
    operator-=(T other) {
        *this = subtract_equal(std::make_unique<Component>(*this).get(), dynamic_cast<Component *>(&other));
        return *this;
    }

    /**
     * Enabled if other object is component or inherits from component
     * @tparam T type_ other object
     * @param other other object
     * @return this + other
     */
    template<class T>
    typename std::enable_if<std::is_base_of<Component, T>::value, Component>::type
    operator+(T other) {
        return add(std::make_unique<Component>(*this).get(), dynamic_cast<Component *>(&other));
    }

    /**
     * Enabled if other object is component or inherits from component
     * @tparam T type_ other object
     * @param other other object
     * @return this - other
     */
    template<class T>
    typename std::enable_if<std::is_base_of<Component, T>::value, Component>::type
    operator-(T other) {
        return subtract(std::make_unique<Component>(*this).get(), dynamic_cast<Component *>(&other));
    }

    /**
     * Enabled if other object is component or inherits from component
     * @tparam T type_ other object
     * @param other other object
     * @return this * other
     */
    template<class T>
    typename std::enable_if<std::is_base_of<Component, T>::value, Component>::type
    operator*(T other) {
        return multiply(std::make_unique<Component>(*this).get(), dynamic_cast<Component *>(&other));
    }

    /**
     * Enabled if other object is component or inherits from component
     * @tparam T type_ other object
     * @param other other object
     * @return this / other
     */
    template<class T>
    typename std::enable_if<std::is_base_of<Component, T>::value, Component>::type
    operator/(T other) {
        return divide(std::make_unique<Component>(*this).get(), dynamic_cast<Component *>(&other));
    }
    /**
     * @brief getter for start node
     * @return start node object
     */
    std::shared_ptr<Node> startNode();

    /**
     * @brief getter for end node
     * @return end node object
     */
    std::shared_ptr<Node> endNode();
    /**
     * @brief setter for start node
     * @param r new start node
     */
    void startNode(std::shared_ptr<Node> r);

    /**
     * @brief setter for end node
     * @param l new end node
     */
    void endNode(std::shared_ptr<Node> l);

    // getters for various fields
    double resistance() const;

    double voltage() const;

    virtual double current() const;
    // setters for various fields
    void resistance(double val);

    void voltage(double val);

    virtual void current(double val);

    std::shared_ptr<Current> get_current_object();

    std::shared_ptr<Voltage> get_voltage_object();

};

#endif //CIRCUITSOLVER_COMPONENT_H

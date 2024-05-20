//
// Created by issa on 27/04/24.
//

#include <utility>
#include <regex>
#include "Component.h"
#include "CircuitException.h"

// Function to check if the operation between two components is valid (e.g., addition, subtraction).
bool is_valid_operation(Component *thisObj, Component *other) {
    // Check if the class names of both components match.
    if (thisObj->get_class_name() == other->get_class_name()) {
        return true; // Valid operation.
    }
    return false; // Invalid operation.
}

// Get the voltage object associated with the component.
std::shared_ptr<Voltage> Component::get_voltage_object() { return v; }

// Get the current object associated with the component.
std::shared_ptr<Current> Component::get_current_object() { return c; }

// Destructor for Component class (default implementation).
Component::~Component() = default;

// Default constructor for Component class.
Component::Component() : r{0}, v{std::make_shared<Voltage>(Voltage(0, false))},
                         c{std::make_shared<Current>(Current(0, false))} {}

// Parameterized constructor for Component class with resistance and node connections.
Component::Component(double resistance, std::shared_ptr<Node> start, std::shared_ptr<Node> end) : startNd{
        std::move(start)},
                                                                                                  endNd{std::move(end)},
                                                                                                  r{resistance} {
    // Add connections to the start and end nodes.
    startNd->add_connection();
    startNd->add_observer(std::make_shared<Component>(*this));
    endNd->add_connection();
    endNd->add_observer(std::make_shared<Component>(*this));
}

// Parameterized constructor for Component class with resistance, voltage, current, and node connections.
Component::Component(double resistance, double voltage, double current, std::shared_ptr<Node> start,
                     std::shared_ptr<Node> end) : r{resistance}, startNd{std::move(start)},
                                                  endNd{std::move(end)} {
    // Set initial voltage and current values.
    v->set_value(voltage);
    c->set_value(current);
}

// Get the class name of the component (excluding numerical suffixes).
std::string Component::get_class_name() {
    // Extract the class name from the type_info and remove numerical suffixes.
    return std::regex_replace(std::string(typeid(*this).name()), std::regex("[0-9]+"), "");
}

// Perform addition operation between two components.
Component Component::add(Component *thisObj, Component *other) {
    // Delegate to the add_equal method for in-place addition.
    return add_equal(thisObj, other);
}

// Perform in-place addition operation between two components.
Component &Component::add_equal(Component *thisObj, Component *other) {
    // Check if the operation is valid.
    if (!is_valid_operation(this, other)) {
        throw CircuitException("invalid operation add: " + this->to_string() + ", " + other->to_string());
    }
    // Add resistance, voltage, and current values.
    thisObj->r += other->r;
    thisObj->v->set_value(thisObj->v->get_value() + other->v->get_value());
    thisObj->c->set_value(thisObj->c->get_value() + other->c->get_value());
    return *thisObj;
}

// Perform in-place subtraction operation between two components.
Component &Component::subtract_equal(Component *thisObj, Component *other) {
    // Check if the operation is valid.
    if (!is_valid_operation(this, other)) {
        throw CircuitException("invalid operation subtract: " + this->to_string() + ", " + other->to_string());
    }
    // Subtract resistance, voltage, and current values.
    thisObj->r -= other->r;
    thisObj->v->set_value(thisObj->v->get_value() - other->v->get_value());
    thisObj->c->set_value(thisObj->c->get_value() - other->c->get_value());
    return *thisObj;
}

// Perform subtraction operation between two components.
Component Component::subtract(Component *thisObj, Component *other) {
    // Delegate to the subtract_equal method for in-place subtraction.
    return subtract_equal(thisObj, other);
}

// Perform multiplication operation between two components.
Component Component::multiply(Component *thisObj, Component *other) {
    // Check if the operation is valid.
    if (!is_valid_operation(this, other)) {
        throw CircuitException("invalid operation multiply: " + this->to_string() + ", " + other->to_string());
    }
    // Multiply resistance, voltage, and current values.
    thisObj->r *= other->r;
    thisObj->v->set_value(thisObj->v->get_value() * other->v->get_value());
    thisObj->c->set_value(thisObj->c->get_value() * other->c->get_value());
    return *thisObj;
}

// Perform division operation between two components.
Component Component::divide(Component *thisObj, Component *other) {
    // Check if the operation is valid.
    if (!is_valid_operation(this, other)) {
        throw CircuitException("invalid operation divide: " + this->to_string() + ", " + other->to_string());
    }
    // Divide resistance, voltage, and current values.
    thisObj->r /= other->r;
    thisObj->v->set_value(thisObj->v->get_value() / other->v->get_value());
    thisObj->c->set_value(thisObj->c->get_value() / other->c->get_value());
    return *thisObj;
}

// Handle changes in node connections.
void Component::handle_node(std::shared_ptr<Node> member, std::shared_ptr<Node> other) {
    // Remove connections and observers from the current node, add them to the new node.
    member->remove_connection();
    member->remove_observer(std::make_shared<Component>(*this));
    other->add_connection();
    other->add_observer(std::make_shared<Component>(*this));
    // Update the component'setOfNodes node reference.
    member = other;
}

// Update the end node of the component.
void Component::endNode(std::shared_ptr<Node> end) {
    handle_node(endNd, end);
}

// Update the start node of the component.
void Component::startNode(std::shared_ptr<Node> start) {
    handle_node(startNd, start);
}

// Convert the component'setOfNodes properties to a string representation.
std::string Component::to_string() {
    // Get a pointer to the current object as Component (for dynamic casting).
    Component *this_component{dynamic_cast<Component *>(this)};
    std::string message = this->get_class_name() + ":";
    // Append resistance, voltage, and current information if available.
    if (this_component->r != 0) {
        message += " R= " + std::to_string(this_component->r);
    }
    if (this_component->v->get_known()) {
        message += ", V= " + std::to_string(this_component->v->get_value());
    }
    if (this_component->c->get_known()) {
        message += ", C= " + std::to_string(this_component->c->get_value());
    }
    return message + "\n"; // Return message;
}

// Get the start node of the component.
std::shared_ptr<Node> Component::startNode() { return startNd; }

// Get the end node of the component.
std::shared_ptr<Node> Component::endNode() { return endNd; }

// Get the resistance of the component.
double Component::resistance() const { return r; }

// Get the voltage of the component.
double Component::voltage() const { return v->get_value(); }

// Get the current of the component.
double Component::current() const { return c->get_value(); }

// Set the voltage of the component.
void Component::voltage(double val) {
    v->set_value(val);
    v->set_known(true);
}

// Set the resistance of the component.
void Component::resistance(double val) { r = val; }

// Set the current of the component.
void Component::current(double val) {
    c->set_value(val);
    c->set_known(true);
}

// Get the class name of an object from its type_info.
std::string Component::get_class_name(boost::any obj) {
    // Extract the class name from the type_info and remove numerical suffixes.
    const std::type_info &ti = obj.type();
    return std::regex_replace(std::string(ti.name()), std::regex("[0-9]+"), "");
}

// Handle changes in current associated with the component.
void Component::on_current_changed(double value) {
    // Check if the resistance is non-zero and node voltages are known.
    if (r != 0) {
        // If start node voltage is known and end node voltage is unknown, calculate end node voltage.
        if (startNd->voltage_object().get_known() && !endNd->voltage_object().get_known()) {
            endNd->set_voltage(r * value + startNd->get_voltage());
        }
        // If end node voltage is known and start node voltage is unknown, calculate start node voltage.
        if (endNd->voltage_object().get_known() && !startNd->voltage_object().get_known()) {
            startNd->set_voltage(-r * value + endNd->get_voltage());
        }
    }
}

// Handle changes in voltage associated with the component.
void Component::on_voltage_changed(double value) {
    // If both start and end node voltages are known, update component'setOfNodes voltage.
    if (startNd->voltage_object().get_known() && endNd->voltage_object().get_known()) {
        v->set_value(endNd->get_voltage() - startNd->get_voltage());
    }
}

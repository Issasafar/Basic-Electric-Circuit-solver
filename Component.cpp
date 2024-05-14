//
// Created by issa on 27/04/24.
//

#include <utility>
#include <regex>
#include "Component.h"
#include "CircuitException.h"

bool is_valid_operation(Component *thisObj, Component *other) {
    if (thisObj->get_class_name() == other->get_class_name()) {
        return true;
    }
    return false;
}

std::shared_ptr<Voltage> Component::get_voltage_object() { return v; }

std::shared_ptr<Current> Component::get_current_object() { return c; }

Component::~Component() = default;

Component::Component() : r{0}, v{std::make_shared<Voltage>(Voltage(0, false))},
                         c{std::make_shared<Current>(Current(0, false))} {}


Component::Component(double resistance, std::shared_ptr<Node> start, std::shared_ptr<Node> end) : startNd{
        std::move(start)},
                                                                                                  endNd{std::move(end)},
                                                                                                  r{resistance} {
    startNd->add_connection();
    startNd->add_observer(this);
    endNd->add_connection();
    endNd->add_observer(this);
}

Component::Component(double resistance, double voltage, double current, std::shared_ptr<Node> start,
                     std::shared_ptr<Node> end) : r{resistance}, startNd{std::move(start)},
                                                  endNd{std::move(end)} {
    v->set_value(voltage);
    c->set_value(current);
}

std::string Component::get_class_name() {
    return std::regex_replace(std::string(typeid(*this).name()), std::regex("[0-9]+"), "");
}

Component Component::add(Component *thisObj, Component *other) {
    return add_equal(thisObj, other);
}

Component &Component::add_equal(Component *thisObj, Component *other) {
    if (!is_valid_operation(this, other)) {
        throw CircuitException("invalid operation add: " + this->to_string() + ", " + other->to_string());
    }
    thisObj->r += other->r;
    try {
        thisObj->v->set_value(thisObj->v->get_value() + other->v->get_value());
    } catch (CircuitException &e) {
        std::cout << "invalid operation " << e.what() << std::endl;
    }
    try {
        thisObj->c->set_value(thisObj->c->get_value() + other->c->get_value());
    } catch (CircuitException &e) {
        std::cout << "invalid operation " << e.what() << std::endl;
    }
    return *thisObj;
}

Component &Component::subtract_equal(Component *thisObj, Component *other) {
    if (!is_valid_operation(this, other)) {
        throw CircuitException("invalid operation subtract: " + this->to_string() + ", " + other->to_string());
    }
    thisObj->r -= other->r;
    try {
        thisObj->v->set_value(thisObj->v->get_value() - other->v->get_value());
    } catch (CircuitException &e) {
        std::cout << "invalid operation " << e.what() << std::endl;
    }
    try {
        thisObj->c->set_value(thisObj->c->get_value() - other->c->get_value());
    } catch (CircuitException &e) {
        std::cout << "invalid operation " << e.what() << std::endl;
    }
    return *thisObj;
}

Component Component::subtract(Component *thisObj, Component *other) {
    return subtract_equal(thisObj, other);
}

Component Component::multiply(Component *thisObj, Component *other) {
    if (!is_valid_operation(this, other)) {
        throw CircuitException("invalid operation multiply: " + this->to_string() + ", " + other->to_string());
    }
    thisObj->r *= other->r;
    try {
        thisObj->v->set_value(thisObj->v->get_value() * other->v->get_value());
    } catch (CircuitException &e) {
        std::cout << "invalid operation " << e.what() << std::endl;
    }
    try {
        thisObj->c->set_value(thisObj->c->get_value() * other->c->get_value());
    } catch (CircuitException &e) {
        std::cout << "invalid operation " << e.what() << std::endl;
    }
    return *thisObj;
}

Component Component::divide(Component *thisObj, Component *other) {
    if (!is_valid_operation(this, other)) {
        throw CircuitException("invalid operation divide: " + this->to_string() + ", " + other->to_string());
    }
    thisObj->r /= other->r;
    try {
        thisObj->v->set_value(thisObj->v->get_value() / other->v->get_value());
    } catch (CircuitException &e) {
        std::cout << "invalid operation " << e.what() << std::endl;
    }
    try {
        thisObj->c->set_value(thisObj->c->get_value() / other->c->get_value());
    } catch (CircuitException &e) {
        std::cout << "invalid operation " << e.what() << std::endl;
    }
    return *thisObj;
}

void Component::handle_node(std::shared_ptr<Node> member, std::shared_ptr<Node> other) {
    member->remove_connection();
    member->remove_observer(this);
    other->add_connection();
    other->add_observer(this);
    member = other;


}

void Component::endNode(std::shared_ptr<Node> end) {
    handle_node(endNd, end);
}

void Component::startNode(std::shared_ptr<Node> start) {
    handle_node(startNd, start);

}

std::string Component::to_string() {
    Component *this_component{dynamic_cast<Component *>(this)};
    std::string message = this->get_class_name() + ":";
    if (this_component->r != 0) {
        message += " R= " + std::to_string(this_component->r);
    }
    if (this_component->v->get_known()) {
        message += ", V= " + std::to_string(this_component->v->get_value());
    }
    if (this_component->c->get_known()) {
        message += ", C= " + std::to_string(this_component->c->get_value());
    }
//    message += "\n";
    return message;
}


std::shared_ptr<Node> Component::startNode() { return startNd; }

std::shared_ptr<Node> Component::endNode() { return endNd; }

double Component::resistance() const { return r; }

double Component::voltage() const { return v->get_value(); }

double Component::current() const { return c->get_value(); }

void Component::voltage(double val) {
    v->set_value(val);
    v->set_known(true);
}

void Component::resistance(double val) { r = val; }

void Component::current(double val) {
    c->set_value(val);
    c->set_known(true);
}

std::string Component::get_class_name(boost::any obj) {
    const std::type_info &ti = obj.type();
    return std::regex_replace(std::string(ti.name()), std::regex("[0-9]+"), "");
}

void Component::on_current_changed(double value) {
    if (r != 0) {
        if (startNd->voltage_object().get_known() && !endNd->voltage_object().get_known()) {
            endNd->set_voltage(r * value + startNd->get_voltage());
        }
        if (endNd->voltage_object().get_known() && !startNd->voltage_object().get_known()) {
            startNd->set_voltage(-r * value + endNd->get_voltage());
        }
    }
}

void Component::on_voltage_changed(double value) {
    if (startNd->voltage_object().get_known() && endNd->voltage_object().get_known()) {
        v->set_value(endNd->get_voltage() - startNd->get_voltage());
    }
}


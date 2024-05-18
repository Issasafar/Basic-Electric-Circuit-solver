//
// Created by issa on 27/04/24.
//

#include <boost/smart_ptr/shared_ptr.hpp>
#include <utility>
#include "Branch.h"
#include "Resistance.h"
#include "VoltageSource.h"
#include "CurrentSource.h"

// Branch class constructor initializing branch number.
Branch::Branch(int number) : Component(), branchNumber{number} {}

// Branch class constructor initializing branch number and components.
Branch::Branch(int number, std::vector<boost::any> components) : Branch::Branch(number) {
    Branch::components(std::move(components));
}

// Sets the current for the branch and propagates it to all components.
void Branch::current(double current) {
    c->set_value(current); // Assuming 'c' is a pointer to a current-related object.
    for (std::shared_ptr<Component> component: components()) {
        component->current(current); // Set the current for each component.
        component->on_current_changed(current); // Trigger the current change event for each component.
    }
}

// Returns the list of components in the branch.
std::vector<com_ptr> Branch::components() {
    return vec;
}

// Sets the components of the branch based on the given vector of boost::any objects.
void Branch::components(std::vector<boost::any> components) {
    for (auto component: components) {

        // Check if the component is of type_ 'Resistance'.
        if (Component::get_class_name(component) == "Resistance") {
            auto el = boost::any_cast<Resistance>(component);
            std::shared_ptr<Component> element = std::make_shared<Component>(el);
            map[element] = Component::get_class_name(component);
            vec.push_back(element);
        }

        // Check if the component is of type_ 'VoltageSource'.
        if (Component::get_class_name(component) == "VoltageSource") {
            auto el = boost::any_cast<VoltageSource>(component);
            std::shared_ptr<Component> element = std::make_shared<Component>(el);
            map[element] = Component::get_class_name(component);
            vec.push_back(element);
        }

        // Check if the component is of type_ 'CurrentSource'.
        if (Component::get_class_name(component) == "CurrentSource") {
            auto el = boost::any_cast<CurrentSource>(component);
            std::shared_ptr<Component> element = std::make_shared<Component>(el);
            map[element] = Component::get_class_name(component);
            vec.push_back(element);
        }
    }
}

// Returns the map of component types in the branch.
std::unordered_map<com_ptr, std::string> Branch::types_map() {
    return map;
}

// Returns the branch number.
int Branch::number() {
    return branchNumber;
}

// Returns the current of the branch.
double Branch::current() const {
    return c->get_value(); // Assuming 'c' is a pointer to a current-related object.
}

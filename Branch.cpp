//
// Created by issa on 27/04/24.
//

#include <boost/smart_ptr/shared_ptr.hpp>
#include <utility>
#include "Branch.h"
#include "Resistance.h"
#include "VoltageSource.h"
#include "CurrentSource.h"

Branch::Branch(int number) : Component(), branch_number{number} {}

Branch::Branch(int number, std::vector<boost::any> components) : Branch::Branch(number) {
    Branch::components(std::move(components));
}

void Branch::current(double current) {
    c->set_value(current);
    for (std::shared_ptr<Component> component: components()) {
        component->current(current);
        std::cout<<"calling on current changed from branch with "<<current<<std::endl;
        component->on_current_changed(current);
    }
    for(std::shared_ptr<Component> component: components()){
       std::cout<<"inside branch components: "<<component->current()<<std::endl;
    }

}

std::vector<com_ptr> Branch::components() {
    return vec;
}



void Branch::components(std::vector<boost::any> components) {
    for (auto component: components) {

        if (Component::get_class_name(component) == "Resistance") {
            auto el = boost::any_cast<Resistance>(component);
            std::shared_ptr<Component> element = std::make_shared<Component>(el);
            map[element] = Component::get_class_name(component);
            vec.push_back(element);
        }
        if (Component::get_class_name(component) == "VoltageSource") {
            auto el = boost::any_cast<VoltageSource>(component);
            std::shared_ptr<Component> element = std::make_shared<Component>(el);
            map[element] = Component::get_class_name(component);
            vec.push_back(element);
        }
        if (Component::get_class_name(component) == "CurrentSource") {
            auto el = boost::any_cast<CurrentSource>(component);
            std::shared_ptr<Component> element = std::make_shared<Component>(el);
            map[element] = Component::get_class_name(component);
            vec.push_back(element);
        }
    }
}

std::unordered_map<com_ptr, std::string> Branch::types_map() {
    return map;
}

int Branch::number() { return branch_number; }

double Branch::current() const {
    return c->get_value();
}

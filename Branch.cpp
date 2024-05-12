//
// Created by issa on 27/04/24.
//

#include <boost/smart_ptr/shared_ptr.hpp>
#include "Branch.h"

Branch::Branch(int number) : Component(), branch_number{number}{}


std::vector<com_ptr> Branch::components() {
    return vec;
}

void Branch::components(std::vector<boost::any> components) {
    std::cout<<"########################################"<<std::endl;
    for (auto thing: components) {
        std::cout<<Component::get_class_name(thing)<<std::endl;
    }
    std::cout<<"########################################"<<std::endl;
}
std::unordered_map<com_ptr, std::string> Branch::types_map() {
    return map;
}

int Branch::number() {return branch_number;}



//std::vector<std::shared_ptr<Component>> Branch::components() {return vec;}
//Branch::Branch(std::vector<com_ptr> components) : Component(), vec{std::move(components)}{}
//void Branch::add_component( Component component) {vec.push_back(component);}
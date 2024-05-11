//
// Created by issa on 27/04/24.
//

#include "Branch.h"

#include <utility>
Branch::Branch(int number) : Component(), branch_number{number}{}

Branch::Branch(int number,std::vector<com_ptr> components): branch_number{number}, vec{std::move(components)} {}

std::vector<com_ptr> Branch::components() {
    return vec;
}

std::unordered_map<com_ptr, std::string> Branch::types_map() {
    return map;
}

int Branch::number() {return branch_number;}



//std::vector<std::shared_ptr<Component>> Branch::components() {return vec;}
//Branch::Branch(std::vector<com_ptr> components) : Component(), vec{std::move(components)}{}
//void Branch::addComponent( Component component) {vec.push_back(component);}
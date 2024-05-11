//
// Created by issa on 27/04/24.
//

#include "Branch.h"

#include <utility>
Branch::Branch() : Component(){}

Branch::Branch(std::vector<com_ptr> components) {
 vec = std::move(components);
}

std::vector<com_ptr> Branch::components() {
    return vec;
}




//std::vector<std::shared_ptr<Component>> Branch::components() {return vec;}
//Branch::Branch(std::vector<com_ptr> components) : Component(), vec{std::move(components)}{}
//void Branch::addComponent( Component component) {vec.push_back(component);}
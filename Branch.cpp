//
// Created by issa on 27/04/24.
//

#include "Branch.h"

#include <utility>
Branch::Branch() : Component(){}

std::vector<Component> Branch::components() {return vec;}
Branch::Branch(std::vector<Component> components) : Component(), vec{std::move(components)}{}
void Branch::addComponent(Component component) {vec.push_back(component);}
//
// Created by issa on 14/05/24.
//

#include "ComponentsFactory.h"

#include <utility>

ComponentsFactory::ComponentsFactory() {
    nodeNumber = -1;
    branchNumber = -1;
}

std::shared_ptr<Node> ComponentsFactory::get_node() {
    return std::make_shared<Node>(Node{++nodeNumber});
}

std::shared_ptr<Node> ComponentsFactory::get_ground() {
    return std::make_shared<Node>(Node::ground());
}

Resistance
ComponentsFactory::get_resistance(double resistance, std::shared_ptr<Node> startNode, std::shared_ptr<Node> endNode) {
    return {resistance, std::move(startNode), std::move(endNode)};
}

VoltageSource
ComponentsFactory::get_voltage_source(double voltage, std::shared_ptr<Node> startNode, std::shared_ptr<Node> endNode) {
    return {voltage, 0, std::move(startNode), std::move(endNode)};
}

CurrentSource
ComponentsFactory::get_current_source(double current, std::shared_ptr<Node> startNode, std::shared_ptr<Node> endNode) {
    return {current, std::move(startNode), std::move(endNode)};
}

Circuit ComponentsFactory::get_circuit(std::vector<Branch> branches) {
    return {std::move(branches)};
}

Branch ComponentsFactory::get_branch(std::vector<boost::any> components) {
    return {++branchNumber, std::move(components)};
}


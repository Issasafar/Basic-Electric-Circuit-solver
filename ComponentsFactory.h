//
// Created by issa on 14/05/24.
//

#ifndef DEMOPROJECT_COMPONENTSFACTORY_H
#define DEMOPROJECT_COMPONENTSFACTORY_H

#include "Node.h"
#include "Component.h"
#include "Resistance.h"
#include "VoltageSource.h"
#include "CurrentSource.h"
#include "Branch.h"
#include "Circuit.h"
#include "CircuitException.h"

using com_ptr = std::shared_ptr<Component>;

/**
 * @file ComponentsFactory
 * @brief responsible for providing electrical components
 */
class ComponentsFactory {
private:
    int nodeNumber;
    int branchNumber;
public:
    ComponentsFactory();

    std::shared_ptr<Node> get_node();

    std::shared_ptr<Node> get_ground();

    Resistance get_resistance(double resistance, std::shared_ptr<Node> startNode, std::shared_ptr<Node> endNode);

    VoltageSource get_voltage_source(double voltage, std::shared_ptr<Node> startNode, std::shared_ptr<Node> endNode);

    CurrentSource get_current_source(double current, std::shared_ptr<Node> startNode, std::shared_ptr<Node> endNode);

    Branch get_branch(std::vector<boost::any> components);

    Circuit get_circuit(std::vector<Branch> branches);

};


#endif //DEMOPROJECT_COMPONENTSFACTORY_H

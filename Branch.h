//
// Created by issa on 27/04/24.
//

#ifndef DEMOPROJECT_BRANCH_H
#define DEMOPROJECT_BRANCH_H


#include <vector>
#include "Component.h"

class Branch : public Component {
private:
    std::vector<Component> vec;
public:
    Branch();

    explicit Branch(std::vector<Component> components);

    std::vector<Component> components();

    void addComponent(Component component);
    Component toComponent();
};


#endif //DEMOPROJECT_BRANCH_H

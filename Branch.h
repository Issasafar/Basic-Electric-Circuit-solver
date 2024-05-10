//
// Created by issa on 27/04/24.
//

#ifndef DEMOPROJECT_BRANCH_H
#define DEMOPROJECT_BRANCH_H


#include <vector>
#include "Component.h"

using com_ptr = std::shared_ptr<Component>;
class Branch : public Component {
private:
    std::vector<com_ptr> vec;
public:
    Branch();

    explicit Branch(std::vector<com_ptr> components);

    std::vector<com_ptr> components();

    template<class T>
    void addComponent( T component){
    vec.push_back(std::make_shared<Component>(component));}
};


#endif //DEMOPROJECT_BRANCH_H

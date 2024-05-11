//
// Created by issa on 27/04/24.
//

#ifndef DEMOPROJECT_BRANCH_H
#define DEMOPROJECT_BRANCH_H


#include <vector>
#include "Component.h"
#include <unordered_map>
using com_ptr = std::shared_ptr<Component>;

class Branch : public Component {
private:
    std::vector<com_ptr> vec;
    std::unordered_map<com_ptr,std::string> map;
    int branch_number;
public:
    Branch(int number);

    int number();
    std::vector<com_ptr> components();
    std::unordered_map<com_ptr, std::string> types_map();
    template<class T>
    void addComponent(T component) {
       /* map.insert(std::make_shared<Component>(component), component.get_class_name());*/
       std::shared_ptr<Component> element = std::make_shared<Component>(component);
       map[element] = component.get_class_name();
        vec.push_back(element);
    }
};


#endif //DEMOPROJECT_BRANCH_H

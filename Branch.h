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
    std::shared_ptr<Current> branch_current{new Current()};
public:
    Branch(int number);
    Branch(int number, std::vector<boost::any> components);
    int number();
    std::vector<com_ptr> components();
    void components(std::vector<boost::any> components);
    std::unordered_map<com_ptr, std::string> types_map();
    template<class T>
    void add_component(T component) {
       std::shared_ptr<Component> element = std::make_shared<Component>(component);
       map[element] = component.get_class_name();
        vec.push_back(element);
        element->set_current_object(this->c);
    }
};


#endif //DEMOPROJECT_BRANCH_H

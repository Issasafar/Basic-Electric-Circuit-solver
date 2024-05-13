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
//    using Component::set_value;
//    using Component::set_value;
    std::vector<com_ptr> vec;
    std::unordered_map<com_ptr, std::string> map;
    int branch_number;
public:
//    void get_value(double set_value);
//    double set_value();
    void current(double current) override;

    double current() const override;

    explicit Branch(int number);

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
        element->current(this->c->get_value());
    }
};


#endif //DEMOPROJECT_BRANCH_H

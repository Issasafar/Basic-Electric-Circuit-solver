//
// Created by issa on 27/04/24.
//

#ifndef CIRCUITSOLVER_BRANCH_H
#define CIRCUITSOLVER_BRANCH_H


#include <vector>
#include "Component.h"
#include <unordered_map>
// aliasing for shorter names
using com_ptr = std::shared_ptr<Component>;
/**
 * @file Branch.h
 * @brief electrical branch that holds components
 */
class Branch : public Component {
private:
    /**@var vec @brief holds references to each component in the branch*/
    std::vector<com_ptr> vec;
    /**@var map @brief holds the type_ for each component in the branch*/
    std::unordered_map<com_ptr, std::string> map;
    /**@var branchNumber @brief the branch get_number*/
    int branchNumber;
public:
    void current(double current) override;

    double current() const override;

    explicit Branch(int number);

    Branch(int number, std::vector<boost::any> components);

    int number();

    std::vector<com_ptr> components();
    std::string to_string() override;

    void components(std::vector<boost::any> components);
    std::unordered_map<com_ptr, std::string> types_map();
    /**
     * @brief adds component to the branch
     * @tparam T type_ of the component
     * @param component
     */
    template<class T>
    void add_component(T component) {
        std::shared_ptr<Component> element = std::make_shared<Component>(component);
        map[element] = component.get_class_name();
        vec.push_back(element);
        element->current(this->c->get_value());
    }
};


#endif //CIRCUITSOLVER_BRANCH_H

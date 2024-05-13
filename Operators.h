//
// Created by issa on 10/05/24.
//

#ifndef DEMOPROJECT_OPERATORS_H
#define DEMOPROJECT_OPERATORS_H

#include <string>
#include <unordered_map>
#include "Component.h"

namespace circuit {
    enum class Operator {
        PLUS,
        MINUS,
        TIMES,
        DIVIDE,
        ERROR,
    };

    std::unordered_map<Operator, std::string> operators_map{
            {Operator::PLUS,   "\"+\""},
            {Operator::MINUS,  "\"-\""},
            {Operator::TIMES,  "\"*\""},
            {Operator::DIVIDE, "\"/\""},
            {Operator::ERROR,  "Cannot perform operator "},
    };

    std::string operator_error_message(Operator e, Component *thisObj, Component *other) {
        return operators_map.at(circuit::Operator::ERROR) + operators_map.at(e) + ": " + thisObj->get_class_name() +
               operators_map.at(e) + other->get_class_name();
    }
}
#endif //DEMOPROJECT_OPERATORS_H

//
// Created by issa on 10/05/24.
//

#ifndef CIRCUITSOLVER_OPERATORS_H
#define CIRCUITSOLVER_OPERATORS_H

#include <string>
#include <unordered_map>
#include "Component.h"
/**
 * @file Operators
 * @brief provides some functionality
 */
namespace circuit {
    /**
     * @enum Operator
     * @brief enum for operators
     */
    enum class Operator {
        PLUS,
        MINUS,
        TIMES,
        DIVIDE,
        ERROR,
    };
    /**
     * @brief maps each operator to string representation
     */
    std::unordered_map<Operator, std::string> operators_map{
            {Operator::PLUS,   "\"+\""},
            {Operator::MINUS,  "\"-\""},
            {Operator::TIMES,  "\"*\""},
            {Operator::DIVIDE, "\"/\""},
            {Operator::ERROR,  "Unable to perform operator "},
    };
    /**
     *
     * @param e operator from the enum
     * @param thisObj this object
     * @param other other object
     * @return operator error message
     */
    std::string operator_error_message(Operator e, Component *thisObj, Component *other) {
        return operators_map.at(circuit::Operator::ERROR) + operators_map.at(e) + ": " + thisObj->get_class_name() +
               operators_map.at(e) + other->get_class_name();
    }
}
#endif //CIRCUITSOLVER_OPERATORS_H

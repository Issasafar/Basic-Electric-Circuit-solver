//
// Created by issa on 20/05/24.
//

#ifndef DEMOPROJECT_VISITRESULT_H
#define DEMOPROJECT_VISITRESULT_H

#include "boost/variant.hpp"
#include "../../concrete/Node.h"
#include "../../concrete/Branch.h"
#include "../../concrete/Circuit.h"
#include "../../concrete/Resistance.h"
#include "../../concrete/VoltageSource.h"
#include "../../concrete/CurrentSource.h"

// Enumeration representing different types of visit results
enum ResultType{
    NUMERIC_,       // Numeric value
    STRING_,        // String value
    NODE_,          // Node object
    BRANCH,         // Branch object
    CIRCUIT,        // Circuit object
    RESISTANCE,     // Resistance object
    VOLTAGESOURCE,  // Voltage source object
    CURRENTSOURCE,  // Current source object
    COMPONENT       // Generic component object
};

/**
 * Class representing the result of visiting a node in the abstract syntax tree.
 */
class VisitResult {
public:
    /**
     * Constructor to initialize a visit result.
     *
     * @param value The value of the result, which can be of various types.
     * @param type The type of the result.
     */
    VisitResult(const boost::variant<double, std::string, std::shared_ptr<Node>, Branch, Circuit, Component, Resistance, VoltageSource, CurrentSource> &value, ResultType type);

    /**
     * Getter method for retrieving the value of the result.
     *
     * @return The value of the result.
     */
    const boost::variant<double, std::string, std::shared_ptr<Node>, Branch, Circuit, Component, Resistance, VoltageSource, CurrentSource> &getValue() const;

    /**
     * Getter method for retrieving the type of the result.
     *
     * @return The type of the result.
     */
    ResultType getType() const;

    /**
     * Convert the visit result to a string representation.
     *
     * @return A string representation of the visit result.
     */
    std::string to_string();

    /**
     * Describe the variable represented by the visit result.
     *
     * @return A description of the variable.
     */
    std::string describeVariable();

private:
    boost::variant<double, std::string, std::shared_ptr<Node>, Branch, Circuit, Component, Resistance, VoltageSource, CurrentSource> value_;  // The value of the result
    ResultType type_;  // The type of the result

};

#endif //DEMOPROJECT_VISITRESULT_H

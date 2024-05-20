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

enum ResultType{
    NUMERIC_,
    STRING_,
    NODE_,
    BRANCH,
    CIRCUIT,
    RESISTANCE,
    VOLTAGESOURCE,
    CURRENTSOURCE,
    COMPONENT
};
class VisitResult {
public:
    VisitResult(const boost::variant<double, std::string, std::shared_ptr<Node>, Branch, Circuit, Component, Resistance, VoltageSource, CurrentSource> &value, ResultType type);

    const boost::variant<double, std::string, std::shared_ptr<Node>, Branch, Circuit, Component, Resistance, VoltageSource, CurrentSource> &getValue() const;

    ResultType getType() const;
    std::string to_string();
private:
    boost::variant<double, std::string, std::shared_ptr<Node>, Branch, Circuit, Component, Resistance, VoltageSource, CurrentSource> value_;
    ResultType type_;

};


#endif //DEMOPROJECT_VISITRESULT_H

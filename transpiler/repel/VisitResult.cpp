//
// Created by issa on 20/05/24.
//

#include "VisitResult.h"

const boost::variant<double, std::string> &VisitResult::getValue() const {
    return value_;
}

ResultType VisitResult::getType() const {
    return type_;
}

VisitResult::VisitResult(const boost::variant<double, std::string> &value, ResultType type) : value_(value),
                                                                                              type_(type) {}

//
// Created by issa on 20/05/24.
//

#ifndef DEMOPROJECT_VISITRESULT_H
#define DEMOPROJECT_VISITRESULT_H
#include "boost/variant.hpp"
enum ResultType{
    NUMERIC_,
    STRING_,
};
class VisitResult {
public:
    VisitResult(const boost::variant<double, std::string> &value, ResultType type);

    const boost::variant<double, std::string> &getValue() const;

    ResultType getType() const;

private:
    boost::variant<double, std::string> value_;
    ResultType type_;
};


#endif //DEMOPROJECT_VISITRESULT_H

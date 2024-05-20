//
// Created by issa on 20/05/24.
//

#include "VisitResult.h"

std::string VisitResult::to_string() {
    if(value_.type() == typeid(std::string)){
        return boost::get<std::string>(value_)+"\n";
    }
    if(value_.type() == typeid(double)){
        return std::to_string(boost::get<double>(value_))+"\n";
    }
    if(value_.type() == typeid(std::shared_ptr<Node>)){
        return boost::get<std::shared_ptr<Node>>(value_)->to_string();
    }
    if(value_.type() == typeid(Branch)){
        return boost::get<Branch>(value_).to_string();
    }
    if(value_.type() == typeid(Circuit)){
        return boost::get<Circuit>(value_).to_string();
    }
    if(value_.type() == typeid(Resistance)){
        return boost::get<Resistance>(value_).to_string();
    }
    if(value_.type() == typeid(VoltageSource)){
        return boost::get<VoltageSource>(value_).to_string();
    }
    if(value_.type() == typeid(Component)){
        return boost::get<Component>(value_).to_string();
    }
    if(value_.type() == typeid(CurrentSource)){
        return boost::get<CurrentSource>(value_).to_string();
    }

}
const boost::variant<double, std::string, std::shared_ptr<Node>, Branch, Circuit, Component, Resistance, VoltageSource, CurrentSource> &VisitResult::getValue() const {
    return value_;
}

ResultType VisitResult::getType() const {
    return type_;
}

VisitResult::VisitResult(const boost::variant<double, std::string, std::shared_ptr<Node>, Branch, Circuit, Component, Resistance, VoltageSource, CurrentSource> &value, ResultType type) : value_(value),
                                                                                              type_(type) {}

//
// Created by issa on 20/05/24.
//

#include "VisitResult.h"

std::string VisitResult::to_string() {
    if(value_.type() == typeid(std::string)){
        return boost::get<std::string>(value_)+"\n";
    }
    if(value_.type() == typeid(double)){
        std::string str = std::to_string(boost::get<double>(value_));
        str.erase ( str.find_last_not_of('0') + 1, std::string::npos );
        str.erase ( str.find_last_not_of('.') + 1, std::string::npos );
        return str+"\n";
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

std::string VisitResult::describeVariable() {
    if(value_.type() == typeid(std::string)){
        return "Type: std::string, Size: " + std::to_string(sizeof(std::string)) + " bytes\n";
    }
    if(value_.type() == typeid(double)){
        return "Type: double, Size: " + std::to_string(sizeof(double)) + " bytes\n";
    }
    if(value_.type() == typeid(std::shared_ptr<Node>)){
        return "Type: std::shared_ptr<Node>, Size: " + std::to_string(sizeof(std::shared_ptr<Node>)) + " bytes\n";
    }
    if(value_.type() == typeid(Branch)){
        return "Type: Branch, Size: " + std::to_string(sizeof(Branch)) + " bytes\n";
    }
    if(value_.type() == typeid(Circuit)){
        return "Type: Circuit, Size: " + std::to_string(sizeof(Circuit)) + " bytes\n";
    }
    if(value_.type() == typeid(Resistance)){
        return "Type: Resistance, Size: " + std::to_string(sizeof(Resistance)) + " bytes\n";
    }
    if(value_.type() == typeid(VoltageSource)){
        return "Type: VoltageSource, Size: " + std::to_string(sizeof(VoltageSource)) + " bytes\n";
    }
    if(value_.type() == typeid(Component)){
        return "Type: Component, Size: " + std::to_string(sizeof(Component)) + " bytes\n";
    }
    if(value_.type() == typeid(CurrentSource)){
        return "Type: CurrentSource, Size: " + std::to_string(sizeof(CurrentSource)) + " bytes\n";
    }
    return "Unknown type\n";
}

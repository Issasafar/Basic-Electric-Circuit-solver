//
// Created by issa on 17/05/24.
//

#include <regex>
#include "AstNodeBase.h"

std::string AstNodeBase::get_class_name(boost::any obj) {
    const std::type_info &it = obj.type();
    return std::regex_replace(std::string(it.name()), std::regex("[0-9]+"), "");
}

NodeType AstNodeBase::getType() const {
    return type;
}

double AstNodeBase::getNumber() const {
    return number_;
}

const std::string &AstNodeBase::getText() const {
    return text_;
}

const std::shared_ptr<AstNodeBase> &AstNodeBase::getLeft() const {
    return left_;
}

const std::shared_ptr<AstNodeBase> &AstNodeBase::getRight() const {
    return right_;
}

const std::vector<std::shared_ptr<AstNodeBase>> &AstNodeBase::getArguments() const {
    return arguments_;
}

const std::string &AstNodeBase::getOp() const {
    return op_;
}

AstNodeBase::AstNodeBase(NodeType type, double number, const std::string &text,const std::string &op,
                         const std::shared_ptr<AstNodeBase> &left, const std::shared_ptr<AstNodeBase> &right,
                         const std::vector<std::shared_ptr<AstNodeBase>> &arguments) : type(type), number_(number), text_(text), op_(op),
                                                                                       left_(left), right_(right),
                                                                                       arguments_(arguments) {}

std::string AstNodeBase::get_class_name() {
   return AstNodeBase::get_class_name(*this);
}



//
// Created by issa on 17/05/24.
//

#ifndef DEMOPROJECT_ASTNODEBASE_H
#define DEMOPROJECT_ASTNODEBASE_H

#include "boost/any.hpp"
#include <memory>
#include <vector>
enum NodeType{
    STRINGLITERAL,
    NUMERICALLITERAL,
    IDENTIFIER,
    ASSIGNMENT,
    CALLEXPRESSION,

};
class AstNodeBase {
protected:
    NodeType type;
    double number_;
    std::string text_;
    std::string op_;
    std::shared_ptr<AstNodeBase> left_{nullptr};
    std::shared_ptr<AstNodeBase> right_{nullptr};
    std::vector<std::shared_ptr<AstNodeBase>> arguments_;
public:
    std::string get_class_name();
    AstNodeBase() = default;
    static std::string get_class_name(boost::any obj);

    AstNodeBase(NodeType type, double number, const std::string &text, const std::string &op,
                const std::shared_ptr<AstNodeBase> &left, const std::shared_ptr<AstNodeBase> &right,
                const std::vector<std::shared_ptr<AstNodeBase>> &arguments);

    NodeType getType() const;

    double getNumber() const;

    const std::string &getText() const;


    const std::shared_ptr<AstNodeBase> &getLeft() const;

    const std::shared_ptr<AstNodeBase> &getRight() const;

    const std::vector<std::shared_ptr<AstNodeBase>> &getArguments() const;

    const std::string &getOp() const;

};


#endif //DEMOPROJECT_ASTNODEBASE_H
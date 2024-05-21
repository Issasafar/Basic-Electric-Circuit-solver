//
// Created by issa on 17/05/24.
//

#include <regex>
#include "AstNodeBase.h"

/**
 * @brief Retrieves the class name of an object, stripping out numerical characters from the type name.
 * @param obj The object to retrieve the class name for.
 * @return The class name as a string.
 */
std::string AstNodeBase::get_class_name(boost::any obj) {
    const std::type_info &it = obj.type();
    return std::regex_replace(std::string(it.name()), std::regex("[0-9]+"), "");
}

/**
 * @brief Gets the type of the AST node.
 * @return The type of the node as a NodeType enum value.
 */
NodeType AstNodeBase::getType() const {
    return type_;
}

/**
 * @brief Gets the numeric value associated with the AST node.
 * @return The numeric value as a double.
 */
double AstNodeBase::getNumber() const {
    return number_;
}

/**
 * @brief Gets the text associated with the AST node.
 * @return The text as a string.
 */
const std::string &AstNodeBase::getText() const {
    return text_;
}

/**
 * @brief Gets the left child node of the AST node.
 * @return A shared pointer to the left child node.
 */
const std::shared_ptr<AstNodeBase> &AstNodeBase::getLeft() const {
    return left_;
}

/**
 * @brief Gets the right child node of the AST node.
 * @return A shared pointer to the right child node.
 */
const std::shared_ptr<AstNodeBase> &AstNodeBase::getRight() const {
    return right_;
}

/**
 * @brief Gets the arguments associated with the AST node.
 * @return A vector of shared pointers to the argument nodes.
 */
const std::vector<std::shared_ptr<AstNodeBase>> &AstNodeBase::getArguments() const {
    return arguments_;
}

/**
 * @brief Gets the operator associated with the AST node.
 * @return The operator as a string.
 */
const std::string &AstNodeBase::getOp() const {
    return op_;
}

/**
 * @brief Constructs an AST node with the specified attributes.
 * @param type The type of the node.
 * @param number The numeric value associated with the node.
 * @param text The text associated with the node.
 * @param op The operator associated with the node.
 * @param left A shared pointer to the left child node.
 * @param right A shared pointer to the right child node.
 * @param arguments A vector of shared pointers to the argument nodes.
 */
AstNodeBase::AstNodeBase(NodeType type, double number, const std::string &text, const std::string &op,
                         const std::shared_ptr<AstNodeBase> &left, const std::shared_ptr<AstNodeBase> &right,
                         const std::vector<std::shared_ptr<AstNodeBase>> &arguments) : type_(type), number_(number), text_(text), op_(op),
                                                                                       left_(left), right_(right),
                                                                                       arguments_(arguments) {}

/**
 * @brief Gets the class name of the current AST node instance.
 * @return The class name as a string.
 */
std::string AstNodeBase::get_class_name() {
    return AstNodeBase::get_class_name(*this);
}

/**
 * @brief Default constructor for the AST node, initializing to unknown type and zero numeric value.
 */
AstNodeBase::AstNodeBase() {
    type_ = NodeType::UNKNOWN;
    number_ = 0;
}

/**
 * @brief Accepts a visitor to perform operations on the AST node.
 * @param visitor A shared pointer to the visitor.
 */
void AstNodeBase::accept(const std::shared_ptr<AstNodeVisitor>& visitor) {
    visitor->visit(std::make_shared<AstNodeBase>(*this));
}

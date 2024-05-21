/**
 * @file AstNodeBase.h
 * @brief Declaration of the AstNodeBase class.
 * @date 17/05/24
 */

#ifndef DEMOPROJECT_ASTNODEBASE_H
#define DEMOPROJECT_ASTNODEBASE_H

#include "boost/any.hpp"
#include "../repel/AstNodeVisitor.h"
#include <memory>
#include <vector>

class AstNodeVisitor;

enum NodeType {
    STRINGLITERAL,
    NUMERICALLITERAL,
    IDENTIFIER,
    ASSIGNMENT,
    CALLEXPRESSION,
    BINARYEXPRESSION,
    VARDECLARATION,
    UNKNOWN
};

/**
 * @class AstNodeBase
 * @brief Base class for AST nodes.
 */
class AstNodeBase {
protected:
    NodeType type_;
    double number_;
    std::string text_;
    std::string op_;
    std::shared_ptr<AstNodeBase> left_{nullptr};
    std::shared_ptr<AstNodeBase> right_{nullptr};
    std::vector<std::shared_ptr<AstNodeBase>> arguments_;

public:
    /**
     * @brief Accepts a visitor.
     *
     * @param visitor The visitor to accept.
     */
    void accept(const std::shared_ptr<AstNodeVisitor>& visitor);

    /**
     * @brief Gets the class name of the object.
     *
     * @return The class name.
     */
    std::string get_class_name();

    /**
     * @brief Default constructor.
     */
    AstNodeBase();

    /**
     * @brief Gets the class name of the object.
     *
     * @param obj The object.
     * @return The class name.
     */
    static std::string get_class_name(boost::any obj);

    /**
     * @brief Constructor with parameters.
     *
     * @param type The type of the node.
     * @param number The numeric value.
     * @param text The text value.
     * @param op The operator.
     * @param left The left child node.
     * @param right The right child node.
     * @param arguments The arguments of the node.
     */
    AstNodeBase(NodeType type, double number, const std::string& text, const std::string& op,
                const std::shared_ptr<AstNodeBase>& left, const std::shared_ptr<AstNodeBase>& right,
                const std::vector<std::shared_ptr<AstNodeBase>>& arguments);

    NodeType getType() const;

    double getNumber() const;

    const std::string& getText() const;

    const std::shared_ptr<AstNodeBase>& getLeft() const;

    const std::shared_ptr<AstNodeBase>& getRight() const;

    const std::vector<std::shared_ptr<AstNodeBase>>& getArguments() const;

    const std::string& getOp() const;
};

#endif //DEMOPROJECT_ASTNODEBASE_H

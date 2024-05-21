/**
 * @file AstHelpers.cpp
 * @brief Implementation of helper functions for AST nodes.
 * @date 20/05/24
 */

#include "AstHelpers.h"

/**
 * @brief Checks if a node is a leaf node in the AST.
 *
 * @param node The node to check.
 * @return true if the node is a leaf node, false otherwise.
 */
bool AstHelpers::isLeafNode(std::shared_ptr<AstNodeBase> node) {
    return (node->getLeft() == nullptr) && (node->getRight() == nullptr);
}

/**
 * @brief Checks if a node is an internal node in the AST.
 *
 * @param node The node to check.
 * @return true if the node is an internal node, false otherwise.
 */
bool AstHelpers::isInternalNode(const std::shared_ptr<AstNodeBase>& node) {
    return (node->getLeft() != nullptr) && (node->getRight() != nullptr);
}

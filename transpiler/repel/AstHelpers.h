/**
 * @file AstHelpers.h
 * @brief Declaration of helper functions for AST nodes.
 * @date 20/05/24
 */

#ifndef DEMOPROJECT_ASTHELPERS_H
#define DEMOPROJECT_ASTHELPERS_H

#include <memory>
#include "../ast-nodes/AstNodeBase.h"

/**
 * @class AstHelpers
 * @brief Helper class for AST nodes.
 */
class AstHelpers {
public:
    /**
     * @brief Checks if a node is a leaf node in the AST.
     *
     * @param node The node to check.
     * @return true if the node is a leaf node, false otherwise.
     */
    static bool isLeafNode(std::shared_ptr<AstNodeBase> node);

    /**
     * @brief Checks if a node is an internal node in the AST.
     *
     * @param node The node to check.
     * @return true if the node is an internal node, false otherwise.
     */
    static bool isInternalNode(const std::shared_ptr<AstNodeBase>& node);
};

#endif //DEMOPROJECT_ASTHELPERS_H

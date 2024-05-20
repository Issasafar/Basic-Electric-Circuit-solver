//
// Created by issa on 20/05/24.
//

#include "AstHelpers.h"

bool AstHelpers::isLeafNode(std::shared_ptr<AstNodeBase> node) {
   return (node->getLeft() == nullptr) && (node->getRight() == nullptr);
}
bool AstHelpers::isInternalNode(const std::shared_ptr<AstNodeBase>& node) {
    return (node->getLeft() != nullptr) && (node->getRight() != nullptr);
}

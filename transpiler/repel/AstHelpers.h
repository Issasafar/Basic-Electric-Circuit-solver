//
// Created by issa on 20/05/24.
//

#ifndef DEMOPROJECT_ASTHELPERS_H
#define DEMOPROJECT_ASTHELPERS_H

#include <memory>
#include "../ast-nodes/AstNodeBase.h"
class AstHelpers {
public:
    static bool isLeafNode(std::shared_ptr<AstNodeBase> node);
    static bool isInternalNode(const std::shared_ptr<AstNodeBase>& node);

};


#endif //DEMOPROJECT_ASTHELPERS_H

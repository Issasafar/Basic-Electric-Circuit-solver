//
// Created by issa on 17/05/24.
//

#ifndef DEMOPROJECT_STRINGLITERAL_H
#define DEMOPROJECT_STRINGLITERAL_H

#include "ASTNode.h"
class StringLiteral:public  ASTNode{
public:
    StringLiteral( const std::string &value);

    const std::string &getValue() const;

    void setValue(const std::string &value);

public:
private:
    std::string value;

};


#endif //DEMOPROJECT_STRINGLITERAL_H

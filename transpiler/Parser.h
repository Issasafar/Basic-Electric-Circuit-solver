//
// Created by issa on 17/05/24.
//

#ifndef DEMOPROJECT_PARSER_H
#define DEMOPROJECT_PARSER_H
#include "Token.h"
#include "ast-nodes/AstNodeBase.h"
#include <memory>
#include "boost/any.hpp"
boost::any parse(Token token);


#endif //DEMOPROJECT_PARSER_H

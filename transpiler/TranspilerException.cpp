//
// Created by issa on 18/05/24.
//

#include "TranspilerException.h"
TranspilerException::TranspilerException(std::string message) : message_("\033[1;31m"+std::move(message)+"\033[0m") {}

const char *TranspilerException::what() const noexcept {
    return message_.c_str();
}

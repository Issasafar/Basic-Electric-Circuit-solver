//
// Created by issa on 18/05/24.
//

#include "TranspilerException.h"

/**
 * Constructor to initialize the exception with a message.
 *
 * @param message The error message.
 */
TranspilerException::TranspilerException(std::string message) : message_("\033[1;31m"+std::move(message)+"\033[0m") {}

/**
 * Returns the error message associated with the exception.
 *
 * @return The error message.
 */
const char *TranspilerException::what() const noexcept {
    return message_.c_str();
}

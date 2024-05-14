//
// Created by issa on 10/05/24.
//

#include "CircuitException.h"

#include <utility>

// Constructor for CircuitException that takes a message string and initializes the message_ member.
CircuitException::CircuitException(std::string message) : message_(std::move(message)) {}

// Override the what() function from std::exception to return the stored message.
// noexcept indicates that this function does not throw any exceptions.
const char *CircuitException::what() const noexcept {
    return message_.c_str();
}

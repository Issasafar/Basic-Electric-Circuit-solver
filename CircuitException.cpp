//
// Created by issa on 10/05/24.
//

#include "CircuitException.h"

#include <utility>

CircuitException::CircuitException(std::string  message) : message_(std::move(message)) {}

const char* CircuitException::what() const noexcept  {
return message_.c_str();
}

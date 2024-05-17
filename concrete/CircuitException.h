//
// Created by issa on 10/05/24.
//

#ifndef CIRCUITSOLVER_CIRCUITEXCEPTION_H
#define CIRCUITSOLVER_CIRCUITEXCEPTION_H

#include <exception>
#include <string>
/**
 * @file CircuitException.h
 * @brief custom exception for circuit errors
 */
class CircuitException : public std::exception {
public:
    CircuitException(std::string message);

    const char *what() const noexcept override;

private:
    /**@var message_ @brief error message on fault*/
    std::string message_;
};


#endif //CIRCUITSOLVER_CIRCUITEXCEPTION_H

//
// Created by issa on 10/05/24.
//

#ifndef DEMOPROJECT_CIRCUITEXCEPTION_H
#define DEMOPROJECT_CIRCUITEXCEPTION_H

#include <exception>
#include <string>

class CircuitException : public std::exception {
public:
    CircuitException(std::string message);

    const char *what() const noexcept override;

private:
    std::string message_;
};


#endif //DEMOPROJECT_CIRCUITEXCEPTION_H

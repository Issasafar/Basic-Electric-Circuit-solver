//
// Created by issa on 18/05/24.
//

#ifndef DEMOPROJECT_TRANSPILEREXCEPTION_H
#define DEMOPROJECT_TRANSPILEREXCEPTION_H

#include <exception>
#include <string>

/**
 * Custom exception class for transpiler errors.
 */
class TranspilerException : public std::exception {

public:
    /**
     * Constructor to initialize the exception with a message.
     *
     * @param message The error message.
     */
    TranspilerException(std::string message);

    /**
     * Returns the error message associated with the exception.
     *
     * @return The error message.
     */
    const char *what() const noexcept override;

private:
    std::string message_;  // The error message

};

#endif //DEMOPROJECT_TRANSPILEREXCEPTION_H

//
// Created by issa on 18/05/24.
//

#ifndef DEMOPROJECT_TRANSPILEREXCEPTION_H
#define DEMOPROJECT_TRANSPILEREXCEPTION_H

#include <exception>
#include <string>

class TranspilerException : public std::exception{

public:
    TranspilerException(std::string message);

    const char *what() const noexcept override;

private:
    std::string message_;

};


#endif //DEMOPROJECT_TRANSPILEREXCEPTION_H

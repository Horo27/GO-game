//
// Created by Horo on 12/6/2024.
//

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <exception>
#include <string>
#include <utility>

///when there's already a piece on a certain position
class customException : public std::exception {
    std::string message;
public:
    explicit customException(std::string message) : message(std::move(message)) {};
    virtual const char* what() const throw() {
        return message.c_str();
    }
};


#endif //EXCEPTIONS_H

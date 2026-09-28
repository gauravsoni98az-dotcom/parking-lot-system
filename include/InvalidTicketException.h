#pragma once

#include <stdexcept>
#include <string>

class InvalidTicketException : public std::runtime_error {
public:
    explicit InvalidTicketException(const std::string& message)
        : std::runtime_error(message) {}
};

#pragma once

#include <stdexcept>
#include <string>

class LotFullException : public std::runtime_error {
public:
    explicit LotFullException(const std::string& message)
        : std::runtime_error(message) {}
};

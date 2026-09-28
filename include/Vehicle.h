#pragma once

#include <string>

enum class VehicleSize { SMALL, MEDIUM, LARGE };

class Vehicle {
public:
    explicit Vehicle(std::string licensePlate);
    virtual ~Vehicle() = default;

    virtual VehicleSize getSize() const = 0;

    const std::string& getLicensePlate() const;

protected:
    std::string licensePlate;
};

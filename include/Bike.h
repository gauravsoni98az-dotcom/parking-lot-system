#pragma once

#include "Vehicle.h"

class Bike : public Vehicle {
public:
    explicit Bike(std::string licensePlate);

    VehicleSize getSize() const override;
};

#pragma once

#include "Vehicle.h"

class Truck : public Vehicle {
public:
    explicit Truck(std::string licensePlate);

    VehicleSize getSize() const override;
};

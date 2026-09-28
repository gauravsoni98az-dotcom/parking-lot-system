#pragma once

#include "Vehicle.h"

class Car : public Vehicle {
public:
    explicit Car(std::string licensePlate);

    VehicleSize getSize() const override;
};
